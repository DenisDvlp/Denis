#pragma once
#include "Picture.h"

using byte = unsigned char;

class Font {
public:
  bool isBold = false;
  byte size = 0;
  virtual ~Font() = default;
  virtual Picture getPicture(int code) const { return {}; }
  virtual int getCharWidth(int code) const { return {}; }
  virtual int getCharHeight() const { return {}; }
  virtual int getSpaceWidth() const { return {}; }
  virtual int getCharSpaceWidth() const { return {}; }
};
