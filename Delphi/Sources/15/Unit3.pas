unit Unit3;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ExtCtrls;

type
  TForm1 = class(TForm)
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    Button1: TButton;
    Shape1: TShape;
    Label49: TLabel;
    Label51: TLabel;
    Label5: TLabel;
    Label6: TLabel;
    Label7: TLabel;
    Label8: TLabel;
    Label9: TLabel;
    Label10: TLabel;
    Label11: TLabel;
    Label12: TLabel;
    Label13: TLabel;
    Label14: TLabel;
    Label15: TLabel;
    procedure FormMouseMove(Sender: TObject; Shift: TShiftState; X,
      Y: Integer);
    procedure FormCreate(Sender: TObject);
    procedure FormMouseDown(Sender: TObject; Butto: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure FormMouseUp(Sender: TObject; Butto: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure Button1Click(Sender: TObject);

  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;
  A,B: array [1..32] of integer;
  i,emptyX, emptyY, numer: integer;
  lmouse: boolean;
  procedure button(t: real; x,y: integer);
  procedure buttonpos(t: real; x,y: integer);
  procedure what();
implementation

{$R *.dfm}
procedure what();
var i,col: integer;
    bl: boolean;
begin
  bl:=false;
  i:=1;
  col:=0;
  while i<32 do
  begin
    if(A[i]<>B[i]) or
    (A[i+1]<>B[i+1]) then bl:=true else col:=col+16;
    i:=i+2;
  end;
  form1.Color:=rgb(round(0.6*(256-col)),round(0.6*col),0);
  if bl=false then
  begin
    form1.Label51.Visible:=false;
    form1.Label51.Caption:='';
    form1.Label49.Caption:='���� ��������� � '+inttostr(numer)+' ����(��)';
  end;
end;

procedure buttonpos(t: real; x,y: integer);
begin
x:=x-30;
y:=y-30;
if t=1 then
begin
form1.Label1.left:=x;
form1.Label1.top:=y;
end else
if t=2 then
begin
form1.Label2.left:=x;
form1.Label2.top:=y;
end else
if t=3 then
begin
form1.Label3.left:=x;
form1.Label3.top:=y;
end else
if t=4 then
begin
form1.Label4.left:=x;
form1.Label4.top:=y;
end else
if t=5 then
begin
form1.Label5.left:=x;
form1.Label5.top:=y;
end else
if t=6 then
begin
form1.Label6.left:=x;
form1.Label6.top:=y;
end else
if t=7 then
begin
form1.Label7.left:=x;
form1.Label7.top:=y;
end else
if t=8 then
begin
form1.Label8.left:=x;
form1.Label8.top:=y;
end else
if t=9 then
begin
form1.Label9.left:=x;
form1.Label9.top:=y;
end else
if t=10 then
begin
form1.Label10.left:=x;
form1.Label10.top:=y;
end else
if t=11 then
begin
form1.Label11.left:=x;
form1.Label11.top:=y;
end else
if t=12 then
begin
form1.Label12.left:=x;
form1.Label12.top:=y;
end else
if t=13 then
begin
form1.Label13.left:=x;
form1.Label13.top:=y;
end else
if t=14 then
begin
form1.Label14.left:=x;
form1.Label14.top:=y;
end else
if t=15 then
begin
form1.Label15.left:=x;
form1.Label15.top:=y;
end {else
if t=16 then
begin
form1.Label16.left:=x;
form1.Label16.top:=y;
end else
if t=17 then
begin
form1.Label17.left:=x;
form1.Label17.top:=y;
end else
if t=18 then
begin
form1.Label18.left:=x;
form1.Label18.top:=y;
end else
if t=19 then
begin
form1.Label19.left:=x;
form1.Label19.top:=y;
end else
if t=20 then
begin
form1.Label20.left:=x;
form1.Label20.top:=y;
end else
if t=21 then
begin
form1.Label21.left:=x;
form1.Label21.top:=y;
end else
if t=22 then
begin
form1.Label22.left:=x;
form1.Label22.top:=y;
end else
if t=23 then
begin
form1.Label23.left:=x;
form1.Label23.top:=y;
end else
if t=24 then
begin
form1.Label24.left:=x;
form1.Label24.top:=y;
end else
if t=25 then
begin
form1.Label25.left:=x;
form1.Label25.top:=y;
end else
if t=26 then
begin
form1.Label26.left:=x;
form1.Label26.top:=y;
end else
if t=27 then
begin
form1.Label27.left:=x;
form1.Label27.top:=y;
end else
if t=28 then
begin
form1.Label28.left:=x;
form1.Label28.top:=y;
end else
if t=29 then
begin
form1.Label29.left:=x;
form1.Label29.top:=y;
end else
if t=30 then
begin
form1.Label30.left:=x;
form1.Label30.top:=y;
end else
if t=31 then
begin
form1.Label31.left:=x;
form1.Label31.top:=y;
end else
if t=32 then
begin
form1.Label32.left:=x;
form1.Label32.top:=y;
end else
if t=33 then
begin
form1.Label33.left:=x;
form1.Label33.top:=y;
end else
if t=34 then
begin
form1.Label34.left:=x;
form1.Label34.top:=y;
end else
if t=35 then
begin
form1.Label35.left:=x;
form1.Label35.top:=y;
end else
if t=36 then
begin
form1.Label36.left:=x;
form1.Label36.top:=y;
end else
if t=37 then
begin
form1.Label37.left:=x;
form1.Label37.top:=y;
end else
if t=38 then
begin
form1.Label38.left:=x;
form1.Label38.top:=y;
end else
if t=39 then
begin
form1.Label39.left:=x;
form1.Label39.top:=y;
end else
if t=40 then
begin
form1.Label40.left:=x;
form1.Label40.top:=y;
end else
if t=41 then
begin
form1.Label41.left:=x;
form1.Label41.top:=y;
end else
if t=42 then
begin
form1.Label42.left:=x;
form1.Label42.top:=y;
end else
if t=43 then
begin
form1.Label43.left:=x;
form1.Label43.top:=y;
end else
if t=44 then
begin
form1.Label44.left:=x;
form1.Label44.top:=y;
end else
if t=45 then
begin
form1.Label45.left:=x;
form1.Label45.top:=y;
end else
if t=46 then
begin
form1.Label46.left:=x;
form1.Label46.top:=y;
end else
if t=47 then
begin
form1.Label47.left:=x;
form1.Label47.top:=y;
end else
if t=48 then
begin
form1.Label48.left:=x;
form1.Label48.top:=y;
end};
end;
procedure Button(t: real; x,y: integer);
begin
x:=x-30;
y:=y-30;
if t=1 then
begin
form1.Label1.left:=A[1]+x;
form1.Label1.top:=A[2]+y;
end else
if t=2 then
begin
form1.Label2.left:=A[3]+x;
form1.Label2.top:=A[4]+y;
end else
if t=3 then
begin
form1.Label3.left:=A[5]+x;
form1.Label3.top:=A[6]+y;
end else
if t=4 then
begin
form1.Label4.left:=A[7]+x;
form1.Label4.top:=A[8]+y;
end else
if t=5 then
begin
form1.Label5.left:=A[9]+x;
form1.Label5.top:=A[10]+y;
end else
if t=6 then
begin
form1.Label6.left:=A[11]+x;
form1.Label6.top:=A[12]+y;
end else
if t=7 then
begin
form1.Label7.left:=A[13]+x;
form1.Label7.top:=A[14]+y;
end else
if t=8 then
begin
form1.Label8.left:=A[15]+x;
form1.Label8.top:=A[16]+y;
end else
if t=9 then
begin
form1.Label9.left:=A[17]+x;
form1.Label9.top:=A[18]+y;
end else
if t=10 then
begin
form1.Label10.left:=A[19]+x;
form1.Label10.top:=A[20]+y;
end else
if t=11 then
begin
form1.Label11.left:=A[21]+x;
form1.Label11.top:=A[22]+y;
end else
if t=12 then
begin
form1.Label12.left:=A[23]+x;
form1.Label12.top:=A[24]+y;
end else
if t=13 then
begin
form1.Label13.left:=A[25]+x;
form1.Label13.top:=A[26]+y;
end else
if t=14 then
begin
form1.Label14.left:=A[27]+x;
form1.Label14.top:=A[28]+y;
end else
if t=15 then
begin
form1.Label15.left:=A[29]+x;
form1.Label15.top:=A[30]+y;
end {else
if t=16 then
begin
form1.Label16.left:=A[31]+x;
form1.Label16.top:=A[32]+y;
end else
if t=17 then
begin
form1.Label17.left:=A[33]+x;
form1.Label17.top:=A[34]+y;
end else
if t=18 then
begin
form1.Label18.left:=A[35]+x;
form1.Label18.top:=A[36]+y;
end else
if t=19 then
begin
form1.Label19.left:=A[37]+x;
form1.Label19.top:=A[38]+y;
end else
if t=20 then
begin
form1.Label20.left:=A[39]+x;
form1.Label20.top:=A[40]+y;
end else
if t=21 then
begin
form1.Label21.left:=A[41]+x;
form1.Label21.top:=A[42]+y;
end else
if t=22 then
begin
form1.Label22.left:=A[43]+x;
form1.Label22.top:=A[44]+y;
end else
if t=23 then
begin
form1.Label23.left:=A[45]+x;
form1.Label23.top:=A[46]+y;
end else
if t=24 then
begin
form1.Label24.left:=A[47]+x;
form1.Label24.top:=A[48]+y;
end else
if t=25 then
begin
form1.Label25.left:=A[49]+x;
form1.Label25.top:=A[50]+y;
end else
if t=26 then
begin
form1.Label26.left:=A[51]+x;
form1.Label26.top:=A[52]+y;
end else
if t=27 then
begin
form1.Label27.left:=A[53]+x;
form1.Label27.top:=A[54]+y;
end else
if t=28 then
begin
form1.Label28.left:=A[55]+x;
form1.Label28.top:=A[56]+y;
end else
if t=29 then
begin
form1.Label29.left:=A[57]+x;
form1.Label29.top:=A[58]+y;
end else
if t=30 then
begin
form1.Label30.left:=A[59]+x;
form1.Label30.top:=A[60]+y;
end else
if t=31 then
begin
form1.Label31.left:=A[61]+x;
form1.Label31.top:=A[62]+y;
end else
if t=32 then
begin
form1.Label32.left:=A[63]+x;
form1.Label32.top:=A[64]+y;
end else
if t=33 then
begin
form1.Label33.left:=A[65]+x;
form1.Label33.top:=A[66]+y;
end else
if t=34 then
begin
form1.Label34.left:=A[67]+x;
form1.Label34.top:=A[68]+y;
end else
if t=35 then
begin
form1.Label35.left:=A[69]+x;
form1.Label35.top:=A[70]+y;
end else
if t=36 then
begin
form1.Label36.left:=A[71]+x;
form1.Label36.top:=A[72]+y;
end else
if t=37 then
begin
form1.Label37.left:=A[73]+x;
form1.Label37.top:=A[74]+y;
end else
if t=38 then
begin
form1.Label38.left:=A[75]+x;
form1.Label38.top:=A[76]+y;
end else
if t=39 then
begin
form1.Label39.left:=A[77]+x;
form1.Label39.top:=A[78]+y;
end else
if t=40 then
begin
form1.Label40.left:=A[79]+x;
form1.Label40.top:=A[80]+y;
end else
if t=41 then
begin
form1.Label41.left:=A[81]+x;
form1.Label41.top:=A[82]+y;
end else
if t=42 then
begin
form1.Label42.left:=A[83]+x;
form1.Label42.top:=A[84]+y;
end else
if t=43 then
begin
form1.Label43.left:=A[85]+x;
form1.Label43.top:=A[86]+y;
end else
if t=44 then
begin
form1.Label44.left:=A[87]+x;
form1.Label44.top:=A[88]+y;
end else
if t=45 then
begin
form1.Label45.left:=A[89]+x;
form1.Label45.top:=A[90]+y;
end else
if t=46 then
begin
form1.Label46.left:=A[91]+x;
form1.Label46.top:=A[92]+y;
end else
if t=47 then
begin
form1.Label47.left:=A[93]+x;
form1.Label47.top:=A[94]+y;
end else
if t=48 then
begin
form1.Label48.left:=A[95]+x;
form1.Label48.top:=A[96]+y;
end};
end;
procedure TForm1.FormMouseMove(Sender: TObject; Shift: TShiftState; X,
  Y: Integer);
  var rad:integer;
      h: real;
      new: real;
begin
rad:=70;
i:=1;
while i<30 do
begin
h:=sqrt(sqr(A[i]-x)+sqr(A[i+1]-y));
if h=0 then h:=1;
if rad=0 then rad:=1;
new:=(rad-h)*10/rad/h;
  if lmouse=true then
  if h<=rad then
  if(x>=A[i])then
    if(y>=A[i+1])then
    begin
      button((i+1)/2, round((x-A[i])*new), round((y-A[i+1])*new));
      h:=sqrt(sqr(A[i]+round((x-A[i])*new)-emptyX)+sqr(A[i+1]+round((y-A[i+1])*new)-emptyY));
      if h<=70 then
      begin
        h:=sqrt(sqr(A[i]+round((x-A[i])*new)-X)+sqr(A[i+1]+round((y-A[i+1])*new)-Y));
        if h<=30 then
        begin
          buttonpos((i+1)/2, emptyX,emptyY);
          emptyX:=A[i]+emptyX;
          A[i]:=emptyX-A[i];
          emptyX:=emptyX-A[i];
          emptyY:=A[i+1]+emptyY;
          A[i+1]:=emptyY-A[i+1];
          emptyY:=emptyY-A[i+1];
          numer:=numer+1;
          Label51.Caption:=inttostr(numer);
          what();
        end;
      end;
    end
    else
    begin
      button((i+1)/2, round((x-A[i])*new),-round((A[i+1]-y)*new));
      h:=sqrt(sqr(A[i]+round((x-A[i])*new)-emptyX)+sqr(A[i+1]-round((A[i+1]-y)*new)-emptyY));
      if h<=70 then
      begin
        h:=sqrt(sqr(A[i]+round((x-A[i])*new)-X)+sqr(A[i+1]-round((A[i+1]-y)*new)-Y));
        if h<=30 then
        begin
          buttonpos((i+1)/2, emptyX,emptyY);
          emptyX:=A[i]+emptyX;
          A[i]:=emptyX-A[i];
          emptyX:=emptyX-A[i];
          emptyY:=A[i+1]+emptyY;
          A[i+1]:=emptyY-A[i+1];
          emptyY:=emptyY-A[i+1];
          numer:=numer+1;
          Label51.Caption:=inttostr(numer);
          what();
        end;
      end;
    end
  else
    if(y>=A[i+1])then
    begin
      button((i+1)/2,-round((A[i]-x)*new), round((y-A[i+1])*new));
      h:=sqrt(sqr(A[i]-round((A[i]-x)*new)-emptyX)+sqr(A[i+1]+round((y-A[i+1])*new)-emptyY));
      if h<=70 then
      begin
        h:=sqrt(sqr(A[i]-round((A[i]-x)*new)-X)+sqr(A[i+1]+round((y-A[i+1])*new)-Y));
        if h<=30 then
        begin
          buttonpos((i+1)/2, emptyX,emptyY);
          emptyX:=A[i]+emptyX;
          A[i]:=emptyX-A[i];
          emptyX:=emptyX-A[i];
          emptyY:=A[i+1]+emptyY;
          A[i+1]:=emptyY-A[i+1];
          emptyY:=emptyY-A[i+1];
          numer:=numer+1;
          Label51.Caption:=inttostr(numer);
          what();
        end;
      end;
    end
    else
    begin
      button((i+1)/2,-round((A[i]-x)*new),-round((A[i+1]-y)*new));
      h:=sqrt(sqr(A[i]-round((A[i]-x)*new)-emptyX)+sqr(A[i+1]-round((A[i+1]-y)*new)-emptyY));
      if h<=70 then
      begin
        h:=sqrt(sqr(A[i]-round((A[i]-x)*new)-X)+sqr(A[i+1]-round((A[i+1]-y)*new)-Y));
        if h<=30 then
        begin
          buttonpos((i+1)/2, emptyX,emptyY);
          emptyX:=A[i]+emptyX;
          A[i]:=emptyX-A[i];
          emptyX:=emptyX-A[i];
          emptyY:=A[i+1]+emptyY;
          A[i+1]:=emptyY-A[i+1];
          emptyY:=emptyY-A[i+1];
          numer:=numer+1;
          Label51.Caption:=inttostr(numer);
          what();
        end;
      end;
    end
 else
 button((i+1)/2,0,0)
 else
 button((i+1)/2,0,0);
i:=i+2;
end;
end;

procedure TForm1.FormCreate(Sender: TObject);
var x,y,k,j: integer;
begin
x:=40;
y:=40;
i:=1;
numer:=0;
Label51.Caption:='0';
Label49.Caption:='����� �����:';
Randomize;
Color:=rgb(0,round(0.6*256),0);
Shape1.Brush.Color:=rgb(0,round(0.6*256),0);
Label49.Color:=rgb(0,round(0.6*256),0);
Label51.Color:=rgb(0,round(0.6*256),0);
for k:=1 to 4 do
begin
  for j:=1 to 4 do
  begin
    A[i]:=x;
    A[i+1]:=y;
    B[i]:=x;
    B[i+1]:=y;
    x:=x+70;
    i:=i+2;
  end;
  y:=y+70;
  x:=40;
end;
emptyX:=A[31];
emptyY:=A[32];
end;

procedure TForm1.FormMouseDown(Sender: TObject; Butto: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
begin
  if (butto = mbLeft) then lmouse:=true;
end;

procedure TForm1.FormMouseUp(Sender: TObject; Butto: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
begin
  if (butto = mbLeft) then lmouse:=false;
end;
procedure TForm1.Button1Click(Sender: TObject);
var k,rand: integer;
    bl,blu: boolean;
begin
  numer:=0;
  Label51.Visible:=true;
  Label51.Caption:='0';
  Label49.Caption:='����� �����:';
  k:=1;
  bl:=false;
  while k<32 do
  begin
    A[k]:=B[k];
    A[k+1]:=B[k+1];
    k:=k+2;
  end;
  k:=1;
  while (k<=100000) or (bl=false) do
  begin
    rand:=random(4);
    case rand of
    0:begin
        if((A[31]=40)and(A[32]=40))or((A[31]=110)and(A[32]=40))or
         ((A[31]=180)and(A[32]=40))or((A[31]=250)and(A[32]=40))then
        begin end else
        begin
          i:=1;
          blu:=false;
          while (blu=false) do
          begin
            if(A[i]=A[31])and(A[i+1]=(A[32]-70))then
            begin
              A[32]:=A[32]-70;
              A[i+1]:=A[i+1]+70;
              blu:=true
            end else i:=i+2;
          end;
        end;
      end;
    1:begin
        if((A[31]=40)and(A[32]=250))or((A[31]=110)and(A[32]=250))or
         ((A[31]=180)and(A[32]=250))or((A[31]=250)and(A[32]=250))then
        begin end else
        begin
          i:=1;
          blu:=false;
          while (blu=false) do
          begin
            if(A[i]=A[31])and(A[i+1]=(A[32]+70))then
            begin
              A[32]:=A[32]+70;
              A[i+1]:=A[i+1]-70;
              blu:=true
            end else i:=i+2;
          end;
        end;
      end;
    2:begin
        if((A[31]=40)and(A[32]=40))or((A[31]=40)and(A[32]=110))or
         ((A[31]=40)and(A[32]=180))or((A[31]=40)and(A[32]=250))then
        begin end else
        begin
          i:=1;
          blu:=false;
          while (blu=false) do
          begin
            if(A[i]=(A[31]-70))and(A[i+1]=A[32])then
            begin
              A[31]:=A[31]-70;
              A[i]:=A[i]+70;
              blu:=true
            end else i:=i+2;
          end;
        end;
      end;
    3:begin
        if((A[31]=250)and(A[32]=40))or((A[31]=250)and(A[32]=110))or
         ((A[31]=250)and(A[32]=180))or((A[31]=250)and(A[32]=250))then
        begin end else
        begin
          i:=1;
          blu:=false;
          while (blu=false) do
          begin
            if(A[i]=(A[31]+70))and(A[i+1]=A[32])then
            begin
              A[31]:=A[31]+70;
              A[i]:=A[i]-70;
              blu:=true
            end else i:=i+2;
          end;
        end;
      end;
    end;
    if (A[31]=250)and(A[32]=250) then bl:=true else bl:=false;
    k:=k+1;
  end;
  k:=1;
  while k<32 do begin button((k+1)/2,0,0); k:=k+2; end;
  emptyX:=A[31];
  emptyY:=A[32];
  what();
end;

end.


