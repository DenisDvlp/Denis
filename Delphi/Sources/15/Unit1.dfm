object Form1: TForm1
  Left = 195
  Top = 129
  Width = 225
  Height = 251
  Caption = 'Calculator'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnKeyPress = FormKeyPress
  PixelsPerInch = 96
  TextHeight = 13
  object e1: TEdit
    Left = 8
    Top = 8
    Width = 201
    Height = 21
    BiDiMode = bdRightToLeft
    ParentBiDiMode = False
    ReadOnly = True
    TabOrder = 0
    OnKeyPress = FormKeyPress
  end
  object b7: TButton
    Left = 8
    Top = 56
    Width = 33
    Height = 33
    HelpType = htKeyword
    Caption = '7'
    ParentShowHint = False
    ShowHint = False
    TabOrder = 1
    OnClick = b7Click
    OnKeyPress = FormKeyPress
  end
  object b8: TButton
    Left = 48
    Top = 56
    Width = 33
    Height = 33
    Caption = '8'
    TabOrder = 2
    OnClick = b8Click
    OnKeyPress = FormKeyPress
  end
  object b9: TButton
    Left = 88
    Top = 56
    Width = 33
    Height = 33
    Caption = '9'
    TabOrder = 3
    OnClick = b9Click
    OnKeyPress = FormKeyPress
  end
  object b4: TButton
    Left = 8
    Top = 96
    Width = 33
    Height = 33
    Caption = '4'
    TabOrder = 4
    OnClick = b4Click
    OnKeyPress = FormKeyPress
  end
  object b5: TButton
    Left = 48
    Top = 96
    Width = 33
    Height = 33
    Caption = '5'
    TabOrder = 5
    OnClick = b5Click
    OnKeyPress = FormKeyPress
  end
  object b6: TButton
    Left = 88
    Top = 96
    Width = 33
    Height = 33
    Caption = '6'
    TabOrder = 6
    OnClick = b6Click
    OnKeyPress = FormKeyPress
  end
  object b1: TButton
    Left = 8
    Top = 136
    Width = 33
    Height = 33
    Caption = '1'
    TabOrder = 7
    OnClick = b1Click
    OnKeyPress = FormKeyPress
  end
  object b2: TButton
    Left = 48
    Top = 136
    Width = 33
    Height = 33
    Caption = '2'
    TabOrder = 8
    OnClick = b2Click
    OnKeyPress = FormKeyPress
  end
  object b3: TButton
    Left = 88
    Top = 136
    Width = 33
    Height = 33
    Caption = '3'
    TabOrder = 9
    OnClick = b3Click
    OnKeyPress = FormKeyPress
  end
  object bdel: TButton
    Left = 136
    Top = 56
    Width = 33
    Height = 33
    Caption = '/'
    TabOrder = 10
    OnClick = bdelClick
    OnKeyPress = FormKeyPress
  end
  object bum: TButton
    Left = 136
    Top = 96
    Width = 33
    Height = 33
    Caption = '*'
    TabOrder = 11
    OnClick = bumClick
    OnKeyPress = FormKeyPress
  end
  object bmin: TButton
    Left = 136
    Top = 136
    Width = 33
    Height = 33
    Caption = '-'
    TabOrder = 12
    OnClick = bminClick
    OnKeyPress = FormKeyPress
  end
  object bt: TButton
    Left = 8
    Top = 176
    Width = 33
    Height = 33
    Caption = '.'
    TabOrder = 13
    OnClick = btClick
    OnKeyPress = FormKeyPress
  end
  object b0: TButton
    Left = 48
    Top = 176
    Width = 33
    Height = 33
    Caption = '0'
    TabOrder = 14
    OnClick = b0Click
    OnKeyPress = FormKeyPress
  end
  object bpm: TButton
    Left = 88
    Top = 176
    Width = 33
    Height = 33
    Caption = '+/-'
    TabOrder = 15
    OnKeyPress = FormKeyPress
  end
  object bpl: TButton
    Left = 136
    Top = 176
    Width = 33
    Height = 33
    Caption = '+'
    TabOrder = 16
    OnClick = bplClick
    OnKeyPress = FormKeyPress
  end
  object brav: TButton
    Left = 176
    Top = 136
    Width = 33
    Height = 73
    Caption = '='
    TabOrder = 17
    OnClick = bravClick
    OnKeyPress = FormKeyPress
  end
  object bsqrt: TButton
    Left = 176
    Top = 96
    Width = 33
    Height = 33
    Caption = 'sqrt'
    TabOrder = 18
    OnKeyPress = FormKeyPress
  end
  object C: TButton
    Left = 176
    Top = 56
    Width = 33
    Height = 33
    Caption = 'C'
    TabOrder = 19
    OnClick = CClick
    OnKeyPress = FormKeyPress
  end
  object e2: TEdit
    Left = 8
    Top = 32
    Width = 201
    Height = 21
    BiDiMode = bdRightToLeft
    ParentBiDiMode = False
    ReadOnly = True
    TabOrder = 20
    OnKeyPress = FormKeyPress
  end
end
