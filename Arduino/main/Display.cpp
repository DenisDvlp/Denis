#include "Display.h"
#include <avr/pgmspace.h>

// Pin configuration.
static constexpr uint8_t PIN_RESET = 14;
static constexpr uint8_t PIN_DC = 18;
static constexpr uint8_t PIN_CS = 10;
static constexpr uint8_t SPI_PIN_MOSI = 11; // connect to the DIN pin of OLED
static constexpr uint8_t SPI_PIN_SCK = 13; // connect to the CLK pin of OLED

// Display dimentions.
static constexpr int DISPLAY_WIDTH = 128;
static constexpr int DISPLAY_HEIGHT = 64;
static constexpr int DISPLAY_NUM_PAGE = 8;

// Other constants
static constexpr int BITS_IN_BYTE = 8;
static constexpr int BUF_SIZE = DISPLAY_WIDTH * DISPLAY_HEIGHT / BITS_IN_BYTE;

Display::Display() :
  // ������ �������� ������ �� �������� �������� ������ �� �������
  // ��� ������� �� ���� ��� ����������� ��������
  Settings(/*Speed up to 16M Hz*/8000000, MSBFIRST, SPI_MODE0)
{}

void Display::init()
{
  // Difference between SSD1306and SH1106:
  // - The SH1106 controller has an internal RAM of 132x64 pixel.
  //   The SSD1306 controller only has 128x64 pixel.
  // - The SSD1306 has an expanded command set over the SH1106.
  //   The SSD1306 also has capability for automatic scrolling.The SH1106 hasn't.
  // - The SH1106 only supports page addressing mode.
  //   The SSD1306 supports special horizontal and vertical addressing modes.

  pinMode(PIN_RESET, OUTPUT);
  pinMode(PIN_DC, OUTPUT);
  pinMode(PIN_CS, OUTPUT);
  SPI.begin();

  // http://microsin.net/adminstuff/hardware/ssd1306-oled-controller.html

  // GDDRAM - Graphic Display Data RAM
  // COM - Common Drivers 
  // SEG - Segment Drivers

  // D/C - Data/Command
  // DC ������� ����� ���������� ����� ������������:
  // 0 - ������� (non-graphics data)
  // 1 - ������, ������� ����� �������� � GDDRAM (The GDDRAM column address pointer will be increased by one automatically after each data write.)

  // CS(aka SS) ������� ������ ���������� ���������� ����� ������������:
  // 0 - ���������� ��������� ������
  // 1 - ���������� ���������� ������
  digitalWrite(PIN_CS, LOW);
  digitalWrite(PIN_RESET, HIGH);
  delay(10);
  digitalWrite(PIN_RESET, LOW);
  delay(10);
  digitalWrite(PIN_RESET, HIGH);


  // ��������� �������� ������/������ �� �������. ������ ��� ���� ��� � ������, ������ ��� �����������,
  // ��� ������ ��� ��������� ���������� ����� �������� SPI,
  // ����� ����� ��������� �������� ����� ������ ������� ������/������.
  SPI.beginTransaction(Settings);

  // set command flag for the following commands
  digitalWrite(PIN_DC, LOW);

  // ��������� �����
  command(0xAE);//--turn off oled panel

  // ��������� ������ ��������� ��������
  // 0xB0 + X[2:0]:
  // 0-7 ����� ��������� �������� GDDRAM(PAGE0~PAGE7)
  // ����������: ��� ������� ������������ ������ ��� Page Addressing Mode.
  //command(0xB0);

  // ������������� ������� �������� �������� ���������� ������ ������� ��� ������ ��������� �������
  // 0x00 + X[3:0]:
  // 0-F (�� ��������� 0)
  // ����������: ��� ������� ������������ ������ ��� Page Addressing Mode.
  //command(0x02);//---set low column address

  // ������������� ������� �������� �������� ���������� ������ ������� ��� ������ ��������� �������.
  // 0x10 + X[3:0]:
  // 0-F (�� ��������� 0)
  // ����������: ��� ������� ������������ ������ ��� Page Addressing Mode.
  //command(0x10);//---set high column address

  // X[5:0]: 0-63 - ������� ��������� ������
  command(0x40);//--set start line address  Set Mapping GDDRAM Display Start Line (0x00~0x3F)

  // ��������� ��������� ������.
  // X[7:0]:
  // 0-255 - ��������, ��� 0 ��� ����������. (127 �� ���������)
  command(0x81, 100);//--set contrast control register

  // ��������� ����������� �� �����������.
  // 0xA0 + X[0]:
  // 1 - ���� ������� ����� ������� 
  // 0 - ���� ������� ������ ������
  command(0xA1);//--Set SEG/Column Mapping (0xA1, 0xA0)

  // ��������� ����������� �� ���������.
  // 0xC8 - ���� ����� ������ ����, ������������ �� COM[N-1] �� COM0, ��� N - MUX ratio.
  // 0xC0 - ���� ����� ����� �����, ������������ �� COM0 �� COM[N-1]. (�� ���������)
  command(0xC8);//Set COM/Row Scan Direction  (0xC8, 0xC0)

  // � ������ �������� �������� ������� �� ����� ���������, � ���������� �����.
  // 0xA6 + X[0]:
  // 0 - ���������� (�� ���������)
  // 1 - ���������������
  command(0xA7);//--set display normal(0xA6)/inverse(0xA7)

  // ���������� ����� ������������ �� ������ ����� �����. �� ��� ���� �� ����� ����������
  // 0x00-0x3F - ���������� ������� �����.
  // ��������� ������������ ������������������� (MUX ratio) ��� N+1 MUX.
  // X[5:0]:
  // 0-14 - �����������
  // 15-63 - 16MUX �� 64MUX, ��� - 63 ��� 64MUX. (63 �� ���������)
  command(0xA8, 63);//--set multiplex ratio(1 to 64) and 1/64 duty

  // �����
  command(0xAD, 0x8B); // Set Charge Pump

  command(0x32); /* set VPP 8V (0x30-0x33)*/

  //����� �������� ����� �� ���������
  // X[5:0]:
  // 0-64 - ����� ������ ����� �� ����� ������ ����� (0 �� ���������)
  command(0xD3, 0);//-set display offset. Shift Mapping GDDRAM Counter (0x00~0x3F) not offset

  // ������� ������.
  // X[3:0] F:
  // 0-F - ���������� ������� ����������� ����������, ��� - 0 ����������� �������
  // X[7:4] D:
  // 0-F - ����������� ������� �� 1 �� 16, ��� - 0 ��� 1
  // �������. ������� ������ = F / (D � 54 � N), ��� N ��������������� �������� 0xA8
  command(0xD5, 0x80);//--set display clock divide ratio/oscillator frequency. Set divide ratio, Set Clock as 100 Frames/Sec

  // ��������� ������� Phase 1 � Phase 2
  // X[3:0]:
  // 0 - �����������
  // 1-15 ��������� ������� Phase 1 (2 �� ���������)
  // X[7:4]:
  // 0 - �����������
  // 1-15 ��������� ������� Phase 2 (2 �� ���������)
  command(0xD9, 0xF2);//--set Pre-Charge / Discharge period

  // ������������ ������� COM.
  // 0x02 + X[5:4]:
  // X[4]:
  // 0 - ������������ ���������������� ������� COM.
  // 1 - �������������� ������������ ������� COM. (�� ���������)
  // X[5]:
  // 0 - Disable COM Left / Right remap.(�� ���������)
  // 1 - Enable COM Left / Right remap.
  command(0xDA, 0x12);//--set com pins hardware configuration

  // ��� ������� ����������� ����� ���������� ���������� VCOMH.
  // X[6:4]:
  // 0x00 ~0.65 � VCC
  // 0x20 ~0.77 � VCC (�� ���������)
  // 0x30 ~0.83 � VCC
  command(0xDB, 0x40);//--Set VCOMH Deselect Level

  // Memory Addressing Mode
  // 0 - Horizontal Addressing Mode
  // 1 - Vertical Addressing Mode
  // 2 - Page Addressing Mode (�������� �� ��������� ����� ������)
  // 3 - ������������ �����
  // SH1106 ������������ ������ Page Addressing Mode
  //command(0x20, 0x00);//-Set Page Addressing Mode

  // ������������� ������� �������� �������� ���������� ������ ������� ��� ������ ��������� �������
  // 0x00 + X[3:0]:
  // 0-F (�� ��������� 0)
  // ����������: ��� ������� ������������ ������ ��� Page Addressing Mode.
  // SH1106 ����� 132x64 RAM, � ����� ����������� ������������ RAM, ������ ������ ������� ����� ����� (2,0)
  //command(0x02);//---set low column address

  // ������������� ������� �������� �������� ���������� ������ ������� ��� ������ ��������� �������.
  // 0x10 + X[3:0]:
  // 0-F (�� ��������� 0)
  // ����������: ��� ������� ������������ ������ ��� Page Addressing Mode.
  //command(0x10);//---set high column address

  // ��������� ������ ���������� � ��������� �������.
  // A[6:0]:
  // 0-127 - ����� ���������� ������� (�� ��������� 0).
  // B[6:0]:
  // 0-127 - ����� ��������� ������� (�� ��������� 127).
  // ����������: ��� ������� ������������ ������ ��� ������� �������������� ��� ������������ ���������.
  // �� �������� ��� SH1106
  //command(0x21, 0, 127);//---Set Column Address

  // ��������� ������ ��������� � �������� ��������.
  // A[2:0]:
  // 0-7 - ����� ���������� ������� (�� ��������� 0).
  // B[2:0]:
  // 0-7 - ����� ��������� ������� (�� ��������� 7).
  // ����������: ��� ������� ������������ ������ ��� ������� �������������� ��� ������������ ���������.
  // �� �������� ��� SH1106
  //command(0x22, 0, 7);//---Set Page Address

  // ������������ ��� ������� �� ������.
  // ����� ����� ���� ���� ��������� � ���������� ������� �� ������� ����� ���������.
  // 0xA4 + X[0]:
  // 0 - ��� (�� ���������)
  // 1 - ��
  command(0xA4);// Disable Entire Display On

  // �������� �����
  command(0xAF);//--turn on oled panel

  delay(100);
}

void Display::refresh()
{

  uint8_t page = 0;
  const uint8_t* buf = buffer;
  const uint8_t* end = buffer + DISPLAY_WIDTH * DISPLAY_NUM_PAGE;
  while (buf != end)
  {
    fillPage(page++, buf);
    buf += DISPLAY_WIDTH;
  }
}

Buffer Display::getBuffer()
{
  return { buffer, DISPLAY_WIDTH, DISPLAY_HEIGHT };
}

// This function is an improved version of `SPIClass::transfer` function. See all details in it. This version doesn't erase the data. of the given buffer.
void Display::transfer(const uint8_t* buf, size_t count) {
  while (count--) {
    SPDR = *(buf++);
    while (!(SPSR & _BV(SPIF)));
  }
}

// This function is an improved version of `SPIClass::transfer` function. See all details in it. This version returns `void`.
// NOTE: This function is designed to be invoked from `init` function only.
// To use it from other places you should set command flag explicitly: digitalWrite(PIN_DC, LOW);
void Display::command(uint8_t cmd) {
  SPDR = cmd;
  asm volatile("nop");
  while (!(SPSR & _BV(SPIF)));
}

// See function above.
void Display::command(uint8_t cmd, uint8_t data) {
  command(cmd);
  command(data);
}

void Display::fillPage(uint8_t pageNum, const uint8_t* buf)
{
  digitalWrite(PIN_DC, LOW); // set command flag
  command(0xB0 + pageNum); // set page address
  command(0x02, 0x10);     // set LOW and HIGH column address
  digitalWrite(PIN_DC, HIGH); // set data flag
  transfer(buf, DISPLAY_WIDTH);
}
