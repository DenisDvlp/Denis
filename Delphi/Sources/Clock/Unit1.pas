unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ExtCtrls, ComCtrls, StdCtrls;

type
  TForm1 = class(TForm)
    Image1: TImage;
    Timer1: TTimer;
    Shape1: TShape;
    Label2: TLabel;
    Shape2: TShape;
    Label3: TLabel;
    Shape3: TShape;
    Label4: TLabel;
    Label5: TLabel;
    Shape4: TShape;
    procedure FormCreate(Sender: TObject);
    procedure Timer1Timer(Sender: TObject);
    procedure Image2MouseDown(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure Image2MouseUp(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure Image2MouseMove(Sender: TObject; Shift: TShiftState; X,
      Y: Integer);
    procedure Label1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;
  h,m,s,bordertop,borderbottom,borderleft,borderright,WindowX,WindowY,Radius,ii,asd,m1: integer;
  enablemovewindow: boolean;
implementation

{$R *.dfm}

function hour(s: string): integer;
var temp: string;
    i: integer;
begin
  i:=1;
  temp:='';
  while s[i]<>':' do
  begin
    temp:=temp+s[i];
    i:=i+1;
  end;
  result:=strtoint(temp);
end;

function minute(s: string): integer;
var temp: string;
    i: integer;
begin
  i:=1;
  temp:='';
  while s[i]<>':' do i:=i+1; i:=i+1;
  while s[i]<>':' do
  begin
    temp:=temp+s[i];
    i:=i+1;
  end;
  result:=strtoint(temp);
end;

function second(s: string): integer;
var temp: string;
    i,len: integer;
begin
  i:=1;
  len:=length(s);
  temp:='';
  while s[i]<>':' do i:=i+1; i:=i+1;
  while s[i]<>':' do i:=i+1; i:=i+1;
  while i<=len do
  begin
    temp:=temp+s[i];
    i:=i+1;
  end;
  result:=strtoint(temp);
end;

procedure drawhour(h,m,len,wid: integer; col: tcolor);
var x,y: integer;
begin
  with form1 do
  begin
    x:=(Height div 2)+round(sin((30*h+0.25*m)*3.1415/180)*len);
    y:=(Width div 2)-round(cos((30*h+0.25*m)*3.1415/180)*len);
    Shape3.Top:=y-form1.Shape3.Height div 2;
    Shape3.Left:=x-form1.Shape3.Width div 2;
    Label4.Caption:=inttostr(h);
    Label4.Top:=y-form1.Label4.Height div 2;
    Label4.Left:=x-form1.Label4.Width div 2;
  end;
end;

procedure drawminute(m,s,len,wid: integer; col: tcolor);
var x,y: integer;
begin
  with form1 do
  begin
    x:=(Height div 2)+round(sin((6*m+0.1*s)*3.1415/180)*len);
    y:=(Width div 2)-round(cos((6*m+0.1*s)*3.1415/180)*len);
    Shape2.Top:=y-form1.Shape2.Height div 2;
    Shape2.Left:=x-form1.Shape2.Width div 2;
    Label3.Caption:=inttostr(m);
    Label3.Top:=y-form1.Label3.Height div 2;
    Label3.Left:=x-form1.Label3.Width div 2;
  end;
end;

procedure drawsecond(s,len,wid: integer; col: tcolor);
var x,y: integer;
begin
  with form1 do
  begin
    x:=(Height div 2)+round(sin(s*3.1415/30)*len);
    y:=(Width div 2)-round(cos(s*3.1415/30)*len);
    Shape1.Top:=y-form1.Shape1.Height div 2;
    Shape1.Left:=x-form1.Shape1.Width div 2;
    Label2.Caption:=inttostr(s);
    Label2.Top:=y-form1.Label2.Height div 2;
    Label2.Left:=x-form1.Label2.Width div 2;
  end;
end;

procedure drawmilisecond(s,len,wid: integer; col: tcolor);
var x,y: integer;
begin
  with form1 do
  begin
    x:=(Height div 2)+round(sin(s*3.1415/30)*len);
    y:=(Width div 2)-round(cos(s*3.1415/30)*len);
    Shape4.Top:=y-form1.Shape4.Height div 2;
    Shape4.Left:=x-form1.Shape4.Width div 2;
    //Label5.Caption:=inttostr(s);
    //Label5.Top:=y-form1.Label5.Height div 2;
    //Label5.Left:=x-form1.Label5.Width div 2;
  end;
end;

procedure TForm1.FormCreate(Sender: TObject);
var str: string;
    rTemp  : THandle;
begin
  Canvas.Brush.Style := bsClear;
  Radius := 200;
  Height:=Radius;
  Width:=Radius;
  rTemp := CreateEllipticRgn(0, 0, Radius, Radius);
  SetWindowRgn(Handle, rTemp, True);
  asd:=0;
  m1:=0;

  bordertop:=0;
  borderleft:=0;
  borderbottom:=screen.Height-30;
  borderright:=screen.Width;
  enablemovewindow:=false;

  str:=timetostr(time);
  h:=hour(str);
  m:=minute(str);
  m1:=second(str);
  s:=second(str);
  drawhour(h,m,10,4,clblack);
  drawminute(m,s,35,2,clblack);
  drawsecond(s,60,1,clred);
  drawmilisecond(ii,85,1,clred);
end;

procedure TForm1.Timer1Timer(Sender: TObject);
var str: string;
begin
  str:=timetostr(time);
  h:=hour(str);
  m:=minute(str);
  s:=second(str);
  drawhour(h,m,10,4,clblack);
  drawminute(m,s,35,2,clblack);
  drawsecond(s,60,1,clred);
  drawmilisecond(ii,85,1,clred);ii:=ii+1;
  if ii=60 then ii:=0;
end;

procedure TForm1.Image2MouseDown(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
begin
  if (Button=mbLeft) then
  begin
    enablemovewindow:=true;
    WindowX:=X; WindowY:=Y;
  end;
end;

procedure TForm1.Image2MouseUp(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
begin
  if Button=mbLeft then
  begin
    enablemovewindow:=false;
    if form1.Left<borderleft then form1.Left:=borderleft;
    if form1.Top<bordertop then form1.Top:=bordertop;
    if (form1.Left+form1.Width)>borderright then form1.Left:=borderright-form1.Width;
    if (form1.Top+form1.Height)>borderbottom then form1.Top:=borderbottom-form1.Height;
  end;
end;

procedure TForm1.Image2MouseMove(Sender: TObject; Shift: TShiftState; X,
  Y: Integer);
begin
   if enablemovewindow then
   begin
     form1.Left:=form1.Left-WindowX+X;
     form1.Top:=form1.Top-WindowY+Y;
   end;
end;

procedure TForm1.Label1Click(Sender: TObject);
begin
close;
end;

end.