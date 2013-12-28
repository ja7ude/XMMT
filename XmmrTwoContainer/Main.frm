VERSION 5.00
Object = "{9FAE7EB9-098B-4952-A234-CF460419D752}#1.0#0"; "XMMT.ocx"
Begin VB.Form Main 
   BorderStyle     =   1  'ŒÅ’è(ŽÀü)
   Caption         =   "XMMR Two Container"
   ClientHeight    =   5175
   ClientLeft      =   150
   ClientTop       =   840
   ClientWidth     =   9720
   BeginProperty Font 
      Name            =   "MS Sans Serif"
      Size            =   8.25
      Charset         =   0
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   5175
   ScaleWidth      =   9720
   StartUpPosition =   3  'Windows ‚ÌŠù’è’l
   Begin XMMTLib.XMMBtn BtnUSR 
      Height          =   375
      Index           =   0
      Left            =   2340
      TabIndex        =   41
      Top             =   1260
      Width           =   495
      _Version        =   65538
      _ExtentX        =   873
      _ExtentY        =   661
      _StockProps     =   4
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.24
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Caption         =   "U1"
      FaceColor       =   -2147483633
   End
   Begin VB.TextBox Text 
      Height          =   3435
      Index           =   1
      Left            =   4860
      MultiLine       =   -1  'True
      ScrollBars      =   2  '‚’¼
      TabIndex        =   24
      Top             =   1740
      Width           =   4815
   End
   Begin XMMTLib.XMMR XMMR 
      Height          =   255
      Index           =   0
      Left            =   7440
      TabIndex        =   22
      Top             =   1200
      Visible         =   0   'False
      Width           =   240
      _Version        =   65538
      _ExtentX        =   423
      _ExtentY        =   450
      _StockProps     =   0
      bInitialClose   =   0   'False
      bNotifyFFT      =   0   'False
      bNotifyXY       =   0   'False
      bNotifyComChange=   0   'False
      InvokeCommand   =   "MMTTY.EXE -m -Z"
      Title           =   "XMMR/MMTTY engine"
      strCommonMemory =   "MMTTY1"
   End
   Begin XMMTLib.XMMBtn BtnM4 
      Height          =   375
      Index           =   0
      Left            =   1500
      TabIndex        =   21
      Top             =   1260
      Width           =   495
      _Version        =   65538
      _ExtentX        =   873
      _ExtentY        =   661
      _StockProps     =   4
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.24
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Toggled         =   0   'False
      Caption         =   "M4"
      FaceColor       =   -2147483633
   End
   Begin XMMTLib.XMMBtn BtnM3 
      Height          =   375
      Index           =   0
      Left            =   1020
      TabIndex        =   20
      Top             =   1260
      Width           =   495
      _Version        =   65538
      _ExtentX        =   873
      _ExtentY        =   661
      _StockProps     =   4
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.24
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Toggled         =   0   'False
      Caption         =   "M3"
      FaceColor       =   -2147483633
   End
   Begin XMMTLib.XMMBtn BtnM2 
      Height          =   375
      Index           =   0
      Left            =   540
      TabIndex        =   19
      Top             =   1260
      Width           =   495
      _Version        =   65538
      _ExtentX        =   873
      _ExtentY        =   661
      _StockProps     =   4
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.24
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Toggled         =   0   'False
      Caption         =   "M2"
      FaceColor       =   -2147483633
   End
   Begin XMMTLib.XMMBtn BtnM1 
      Height          =   375
      Index           =   0
      Left            =   60
      TabIndex        =   18
      Top             =   1260
      Width           =   495
      _Version        =   65538
      _ExtentX        =   873
      _ExtentY        =   661
      _StockProps     =   4
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.24
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Toggled         =   0   'False
      Caption         =   "M1"
      FaceColor       =   -2147483633
   End
   Begin VB.TextBox Text 
      Height          =   3435
      Index           =   0
      Left            =   60
      MultiLine       =   -1  'True
      ScrollBars      =   2  '‚’¼
      TabIndex        =   17
      Top             =   1740
      Width           =   4815
   End
   Begin XMMTLib.XMMBtn BtnAFC 
      Height          =   375
      Index           =   0
      Left            =   1800
      TabIndex        =   15
      Top             =   780
      Width           =   495
      _Version        =   65538
      _ExtentX        =   873
      _ExtentY        =   661
      _StockProps     =   4
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.24
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Caption         =   "AFC"
      FaceColor       =   -2147483633
   End
   Begin XMMTLib.XMMBtn BtnNET 
      Height          =   375
      Index           =   0
      Left            =   1320
      TabIndex        =   14
      Top             =   780
      Width           =   495
      _Version        =   65538
      _ExtentX        =   873
      _ExtentY        =   661
      _StockProps     =   4
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.24
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Caption         =   "NET"
      FaceColor       =   -2147483633
   End
   Begin XMMTLib.XMMBtn BtnDPF 
      Height          =   375
      Index           =   0
      Left            =   840
      TabIndex        =   13
      Top             =   780
      Width           =   495
      _Version        =   65538
      _ExtentX        =   873
      _ExtentY        =   661
      _StockProps     =   4
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.24
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Caption         =   "DPF"
      FaceColor       =   -2147483633
   End
   Begin XMMTLib.XMMBtn BtnBPF 
      Height          =   375
      Index           =   0
      Left            =   1800
      TabIndex        =   12
      Top             =   420
      Width           =   495
      _Version        =   65538
      _ExtentX        =   873
      _ExtentY        =   661
      _StockProps     =   4
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.24
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Caption         =   "BPF"
      FaceColor       =   -2147483633
   End
   Begin XMMTLib.XMMBtn BtnLMS 
      Height          =   375
      Index           =   0
      Left            =   1320
      TabIndex        =   11
      Top             =   420
      Width           =   495
      _Version        =   65538
      _ExtentX        =   873
      _ExtentY        =   661
      _StockProps     =   4
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.24
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Caption         =   "LMS"
      FaceColor       =   -2147483633
   End
   Begin XMMTLib.XMMBtn BtnSQ 
      Height          =   375
      Index           =   0
      Left            =   840
      TabIndex        =   10
      Top             =   420
      Width           =   495
      _Version        =   65538
      _ExtentX        =   873
      _ExtentY        =   661
      _StockProps     =   4
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.24
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Caption         =   "SQ"
      FaceColor       =   -2147483633
   End
   Begin XMMTLib.XMMBtn BtnHAM 
      Height          =   375
      Index           =   0
      Left            =   1800
      TabIndex        =   9
      Top             =   60
      Width           =   495
      _Version        =   65538
      _ExtentX        =   873
      _ExtentY        =   661
      _StockProps     =   4
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.24
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Toggled         =   0   'False
      Caption         =   "HAM"
      FaceColor       =   -2147483633
   End
   Begin XMMTLib.XMMBtn BtnRev 
      Height          =   375
      Index           =   0
      Left            =   1320
      TabIndex        =   8
      Top             =   60
      Width           =   495
      _Version        =   65538
      _ExtentX        =   873
      _ExtentY        =   661
      _StockProps     =   4
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.24
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Caption         =   "Rev"
      FaceColor       =   -2147483633
   End
   Begin XMMTLib.XMMBtn BtnType 
      Height          =   375
      Index           =   0
      Left            =   840
      TabIndex        =   7
      Top             =   60
      Width           =   495
      _Version        =   65538
      _ExtentX        =   873
      _ExtentY        =   661
      _StockProps     =   4
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.24
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Toggled         =   0   'False
      Caption         =   "Typ"
      FaceColor       =   -2147483633
   End
   Begin XMMTLib.XMMBtn BtnUOS 
      Height          =   375
      Index           =   0
      Left            =   60
      TabIndex        =   6
      Top             =   780
      Width           =   735
      _Version        =   65538
      _ExtentX        =   1296
      _ExtentY        =   661
      _StockProps     =   4
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.24
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Caption         =   "UOS"
      FaceColor       =   -2147483633
   End
   Begin XMMTLib.XMMLvl Level 
      Height          =   1095
      Index           =   0
      Left            =   2340
      TabIndex        =   5
      Top             =   60
      Width           =   255
      _Version        =   65538
      _ExtentX        =   450
      _ExtentY        =   1931
      _StockProps     =   32
      BorderStyle     =   1
   End
   Begin XMMTLib.XMMWater WaterFall 
      Height          =   375
      Left            =   2580
      TabIndex        =   4
      Top             =   780
      Width           =   3495
      _Version        =   65538
      _ExtentX        =   6165
      _ExtentY        =   661
      _StockProps     =   32
      BorderStyle     =   1
      BaseFreq        =   250
      WidthFreq       =   2500
   End
   Begin XMMTLib.XMMSpec Spectram 
      Height          =   735
      Left            =   2580
      TabIndex        =   3
      Top             =   60
      Width           =   3495
      _Version        =   65538
      _ExtentX        =   6165
      _ExtentY        =   1296
      _StockProps     =   36
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      BorderStyle     =   1
      BaseFreq        =   250
      WidthFreq       =   2500
   End
   Begin XMMTLib.XMMXY XyScope 
      Height          =   1095
      Left            =   6060
      TabIndex        =   2
      Top             =   60
      Width           =   1095
      _Version        =   65538
      _ExtentX        =   1931
      _ExtentY        =   1931
      _StockProps     =   32
      BorderStyle     =   1
   End
   Begin XMMTLib.XMMBtn BtnTxOff 
      Height          =   375
      Index           =   0
      Left            =   60
      TabIndex        =   1
      Top             =   420
      Width           =   735
      _Version        =   65538
      _ExtentX        =   1296
      _ExtentY        =   661
      _StockProps     =   4
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.24
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Toggled         =   0   'False
      Caption         =   "TXOFF"
      FaceColor       =   -2147483633
   End
   Begin XMMTLib.XMMBtn BtnTx 
      Height          =   375
      Index           =   0
      Left            =   60
      TabIndex        =   0
      Top             =   60
      Width           =   735
      _Version        =   65538
      _ExtentX        =   1296
      _ExtentY        =   661
      _StockProps     =   4
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.24
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Caption         =   "TX"
      TextColor       =   255
      FaceColor       =   -2147483633
   End
   Begin XMMTLib.XMMR XMMR 
      Height          =   255
      Index           =   1
      Left            =   7440
      TabIndex        =   23
      Top             =   1440
      Visible         =   0   'False
      Width           =   240
      _Version        =   65538
      _ExtentX        =   423
      _ExtentY        =   450
      _StockProps     =   0
      bInitialClose   =   0   'False
      bNotifyFFT      =   0   'False
      bNotifyXY       =   0   'False
      bNotifyComChange=   0   'False
      InvokeCommand   =   "MMTTY.EXE -m -Z"
      Title           =   "XMMR/MMTTY engine"
      strCommonMemory =   "MMTTY2"
   End
   Begin XMMTLib.XMMBtn BtnM4 
      Height          =   375
      Index           =   1
      Left            =   9180
      TabIndex        =   25
      Top             =   1260
      Width           =   495
      _Version        =   65538
      _ExtentX        =   873
      _ExtentY        =   661
      _StockProps     =   4
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.24
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Toggled         =   0   'False
      Caption         =   "M4"
      FaceColor       =   -2147483633
   End
   Begin XMMTLib.XMMBtn BtnM3 
      Height          =   375
      Index           =   1
      Left            =   8700
      TabIndex        =   26
      Top             =   1260
      Width           =   495
      _Version        =   65538
      _ExtentX        =   873
      _ExtentY        =   661
      _StockProps     =   4
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.24
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Toggled         =   0   'False
      Caption         =   "M3"
      FaceColor       =   -2147483633
   End
   Begin XMMTLib.XMMBtn BtnM2 
      Height          =   375
      Index           =   1
      Left            =   8220
      TabIndex        =   27
      Top             =   1260
      Width           =   495
      _Version        =   65538
      _ExtentX        =   873
      _ExtentY        =   661
      _StockProps     =   4
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.24
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Toggled         =   0   'False
      Caption         =   "M2"
      FaceColor       =   -2147483633
   End
   Begin XMMTLib.XMMBtn BtnM1 
      Height          =   375
      Index           =   1
      Left            =   7740
      TabIndex        =   28
      Top             =   1260
      Width           =   495
      _Version        =   65538
      _ExtentX        =   873
      _ExtentY        =   661
      _StockProps     =   4
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.24
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Toggled         =   0   'False
      Caption         =   "M1"
      FaceColor       =   -2147483633
   End
   Begin XMMTLib.XMMBtn BtnAFC 
      Height          =   375
      Index           =   1
      Left            =   9180
      TabIndex        =   29
      Top             =   780
      Width           =   495
      _Version        =   65538
      _ExtentX        =   873
      _ExtentY        =   661
      _StockProps     =   4
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.24
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Caption         =   "AFC"
      FaceColor       =   -2147483633
   End
   Begin XMMTLib.XMMBtn BtnNET 
      Height          =   375
      Index           =   1
      Left            =   8700
      TabIndex        =   30
      Top             =   780
      Width           =   495
      _Version        =   65538
      _ExtentX        =   873
      _ExtentY        =   661
      _StockProps     =   4
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.24
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Caption         =   "NET"
      FaceColor       =   -2147483633
   End
   Begin XMMTLib.XMMBtn BtnDPF 
      Height          =   375
      Index           =   1
      Left            =   8220
      TabIndex        =   31
      Top             =   780
      Width           =   495
      _Version        =   65538
      _ExtentX        =   873
      _ExtentY        =   661
      _StockProps     =   4
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.24
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Caption         =   "DPF"
      FaceColor       =   -2147483633
   End
   Begin XMMTLib.XMMBtn BtnBPF 
      Height          =   375
      Index           =   1
      Left            =   9180
      TabIndex        =   32
      Top             =   420
      Width           =   495
      _Version        =   65538
      _ExtentX        =   873
      _ExtentY        =   661
      _StockProps     =   4
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.24
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Caption         =   "BPF"
      FaceColor       =   -2147483633
   End
   Begin XMMTLib.XMMBtn BtnLMS 
      Height          =   375
      Index           =   1
      Left            =   8700
      TabIndex        =   33
      Top             =   420
      Width           =   495
      _Version        =   65538
      _ExtentX        =   873
      _ExtentY        =   661
      _StockProps     =   4
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.24
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Caption         =   "LMS"
      FaceColor       =   -2147483633
   End
   Begin XMMTLib.XMMBtn BtnSQ 
      Height          =   375
      Index           =   1
      Left            =   8220
      TabIndex        =   34
      Top             =   420
      Width           =   495
      _Version        =   65538
      _ExtentX        =   873
      _ExtentY        =   661
      _StockProps     =   4
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.24
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Caption         =   "SQ"
      FaceColor       =   -2147483633
   End
   Begin XMMTLib.XMMBtn BtnHAM 
      Height          =   375
      Index           =   1
      Left            =   9180
      TabIndex        =   35
      Top             =   60
      Width           =   495
      _Version        =   65538
      _ExtentX        =   873
      _ExtentY        =   661
      _StockProps     =   4
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.24
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Toggled         =   0   'False
      Caption         =   "HAM"
      FaceColor       =   -2147483633
   End
   Begin XMMTLib.XMMBtn BtnRev 
      Height          =   375
      Index           =   1
      Left            =   8700
      TabIndex        =   36
      Top             =   60
      Width           =   495
      _Version        =   65538
      _ExtentX        =   873
      _ExtentY        =   661
      _StockProps     =   4
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.24
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Caption         =   "Rev"
      FaceColor       =   -2147483633
   End
   Begin XMMTLib.XMMBtn BtnType 
      Height          =   375
      Index           =   1
      Left            =   8220
      TabIndex        =   37
      Top             =   60
      Width           =   495
      _Version        =   65538
      _ExtentX        =   873
      _ExtentY        =   661
      _StockProps     =   4
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.24
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Toggled         =   0   'False
      Caption         =   "Typ"
      FaceColor       =   -2147483633
   End
   Begin XMMTLib.XMMBtn BtnUOS 
      Height          =   375
      Index           =   1
      Left            =   7440
      TabIndex        =   38
      Top             =   780
      Width           =   735
      _Version        =   65538
      _ExtentX        =   1296
      _ExtentY        =   661
      _StockProps     =   4
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.24
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Caption         =   "UOS"
      FaceColor       =   -2147483633
   End
   Begin XMMTLib.XMMBtn BtnTxOff 
      Height          =   375
      Index           =   1
      Left            =   7440
      TabIndex        =   39
      Top             =   420
      Width           =   735
      _Version        =   65538
      _ExtentX        =   1296
      _ExtentY        =   661
      _StockProps     =   4
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.24
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Toggled         =   0   'False
      Caption         =   "TXOFF"
      FaceColor       =   -2147483633
   End
   Begin XMMTLib.XMMBtn BtnTx 
      Height          =   375
      Index           =   1
      Left            =   7440
      TabIndex        =   40
      Top             =   60
      Width           =   735
      _Version        =   65538
      _ExtentX        =   1296
      _ExtentY        =   661
      _StockProps     =   4
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.24
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Caption         =   "TX"
      TextColor       =   255
      FaceColor       =   -2147483633
   End
   Begin XMMTLib.XMMBtn BtnUSR 
      Height          =   375
      Index           =   1
      Left            =   6900
      TabIndex        =   42
      Top             =   1260
      Width           =   495
      _Version        =   65538
      _ExtentX        =   873
      _ExtentY        =   661
      _StockProps     =   4
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.24
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Caption         =   "U2"
      FaceColor       =   -2147483633
   End
   Begin XMMTLib.XMMLvl Level 
      Height          =   1095
      Index           =   1
      Left            =   7140
      TabIndex        =   43
      Top             =   60
      Width           =   255
      _Version        =   65538
      _ExtentX        =   450
      _ExtentY        =   1931
      _StockProps     =   32
      BorderStyle     =   1
   End
   Begin VB.Label LStatus 
      Caption         =   "Status"
      Height          =   255
      Left            =   3240
      TabIndex        =   16
      Top             =   1320
      Width           =   3375
   End
   Begin VB.Menu KV 
      Caption         =   "&View"
      Begin VB.Menu KVQ 
         Caption         =   "&High XY quality"
      End
   End
   Begin VB.Menu KO 
      Caption         =   "&Options"
      Begin VB.Menu KOS 
         Caption         =   "&Setup engine..."
      End
      Begin VB.Menu KO_ 
         Caption         =   "-"
      End
      Begin VB.Menu KOI 
         Caption         =   "&Invoking command"
      End
      Begin VB.Menu KOR 
         Caption         =   "&Reconnect"
      End
   End
   Begin VB.Menu KP 
      Caption         =   "&Profiles"
      Begin VB.Menu KPS 
         Caption         =   "#1"
         Index           =   0
      End
      Begin VB.Menu KPS 
         Caption         =   "#2"
         Index           =   1
      End
      Begin VB.Menu KPS 
         Caption         =   "#3"
         Index           =   2
      End
      Begin VB.Menu KPS 
         Caption         =   "#4"
         Index           =   3
      End
      Begin VB.Menu KPS 
         Caption         =   "#5"
         Index           =   4
      End
      Begin VB.Menu KPS 
         Caption         =   "#6"
         Index           =   5
      End
      Begin VB.Menu KPS 
         Caption         =   "#7"
         Index           =   6
      End
      Begin VB.Menu KPS 
         Caption         =   "#8"
         Index           =   7
      End
      Begin VB.Menu KP_1 
         Caption         =   "-"
      End
      Begin VB.Menu KPD 
         Caption         =   "MMTTY default"
      End
      Begin VB.Menu KP_2 
         Caption         =   "-"
      End
      Begin VB.Menu KPR 
         Caption         =   "&Load file..."
      End
      Begin VB.Menu KPW 
         Caption         =   "&Write file..."
      End
   End
End
Attribute VB_Name = "Main"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Declare Sub CopyMemory Lib "kernel32" Alias "RtlMoveMemory" (Destination As Any, Source As Any, ByVal Length As Long)
Private Declare Function SendMessage Lib "user32" Alias "SendMessageA" (ByVal hwnd As Long, ByVal wMsg As Long, ByVal wParam As Long, lParam As Any) As Long

Const swAFC = &H4         '// b2 AFC
Const swNET = &H8         '// b3 NET
Const swATC = &H10        '// b4 ATC
Const swBPF = &H20        '// b5 BPF
Const swLMS = &H40        '// b6 LMS/Notch
Const swSQ = &H80         '// b7 SQ
Const swREV = &H100       '// b8 Rev
Const swUOS = &H200       '// b9 UOS
Const swNOT = &H2000      '// b13  Notch/LMS
Const swTWO = &H4000      '// b14
Const swDPF = &H80000     '// b19

Const DEFAULTINVOKECOMMAND = "MMTTY.EXE -m -Z"

Const PROFILEEND = 8 - 1
Const USEREND = 2 - 1

Private m_CurrentIndex As Integer
Private m_nmmr(63, USEREND) As Long
Private m_CurrentSwitch(USEREND) As Long

Private Function MAKELONG(ByVal low As Long, ByVal high As Long) As Long
    MAKELONG = low + high * 65536
End Function

Private Sub BtnAFC_OnLButtonClick(Index As Integer)
    Call XMMR(Index).SetMmttySwitch(m_CurrentSwitch(Index) Xor swAFC)
End Sub

Private Sub BtnDPF_OnLButtonClick(Index As Integer)
    Call XMMR(Index).SetMmttySwitch(m_CurrentSwitch(Index) Xor swDPF)
End Sub

Private Sub BtnBPF_OnLButtonClick(Index As Integer)
    Call XMMR(Index).SetMmttySwitch(m_CurrentSwitch(Index) Xor swBPF)
End Sub

Private Sub BtnHAM_OnLButtonClick(Index As Integer)
    Call XMMR(Index).PostMmttyMessage(RXM_SETHAM, 0)
End Sub

Private Sub BtnLMS_OnLButtonClick(Index As Integer)
    Call XMMR(Index).SetMmttySwitch(m_CurrentSwitch(Index) Xor swLMS)
End Sub

Private Sub BtnLMS_OnRButtonClick(Index As Integer)
    Call XMMR(Index).SetMmttySwitch(m_CurrentSwitch(Index) Xor swNOT)
End Sub

Private Sub BtnM1_OnLButtonClick(Index As Integer)
    Call SendButtonMsg(Index, Chr(13) + " CQ CQ CQ DE CONTAINER CONTAINER PSE K" + Chr(13))
End Sub

Private Sub BtnM2_OnLButtonClick(Index As Integer)
    Call SendButtonMsg(Index, Chr(13) + " QRZ? AGN?" + Chr(13))
End Sub

Private Sub BtnM3_OnLButtonClick(Index As Integer)
    Call SendButtonMsg(Index, Chr(13) + " QSL, UR 599 25 25 25 BK" + Chr(13))
End Sub

Private Sub BtnM4_OnLButtonClick(Index As Integer)
    Call SendButtonMsg(Index, Chr(13) + " QSL, TNX CUL 73, QRZ? DE CONTAINER K" + Chr(13))
End Sub

Private Sub BtnNET_OnLButtonClick(Index As Integer)
    Call XMMR(Index).SetMmttySwitch(m_CurrentSwitch(Index) Xor swNET)
End Sub

Private Sub BtnRev_OnLButtonClick(Index As Integer)
    Call XMMR(Index).SetMmttySwitch(m_CurrentSwitch(Index) Xor swREV)
End Sub

Private Sub BtnSQ_OnLButtonClick(Index As Integer)
    Call XMMR(Index).SetMmttySwitch(m_CurrentSwitch(Index) Xor swSQ)
End Sub

Private Sub BtnTx_OnLButtonClick(Index As Integer)
    BtnTx(Index).Caption = "Req"
    If BtnTx(Index).State Then
        BtnTx(Index).State = False
        XMMR(Index).PTT = True
    Else
        BtnTx(Index).State = True
        Call XMMR(Index).SetMmttyPTT(1)
    End If
End Sub

Private Sub BtnTxOff_OnLButtonClick(Index As Integer)
    If BtnTx(Index).State Then
        BtnTx(Index).Caption = "Req"
    End If
    XMMR(Index).PTT = False
End Sub

Private Sub BtnType_OnLButtonClick(Index As Integer)
    Dim typ As Long
    typ = m_CurrentSwitch(Index) And 3
    typ = typ + 1
    If typ >= 4 Then typ = 0
    typ = typ + (m_CurrentSwitch(Index) And (Not 3))
    Call XMMR(Index).SetMmttySwitch(typ)
End Sub

Private Sub BtnUOS_OnLButtonClick(Index As Integer)
    Call XMMR(Index).SetMmttySwitch(m_CurrentSwitch(Index) Xor swUOS)
End Sub

Private Sub BtnUSR_OnLButtonClick(Index As Integer)
    If Not BtnUSR(Index).State Then
        Index = Index + 1
        If Index > USEREND Then Index = 0
    End If
    Call EnableSharedMemory(m_CurrentIndex, False)
    m_CurrentIndex = Index
    If Not (XMMR(Index).bActive) Then
        XMMR(Index).bActive = True
    Else
        Call EnableSharedMemory(m_CurrentIndex, True)
    End If
    Call UpdateUserButton
End Sub

Private Sub Form_Load()
    m_CurrentIndex = 0
    XyScope.HighQuality = KVQ.Checked
    Call UpdateMenus
    Dim i As Integer
    For i = 0 To USEREND Step 1
        XMMR(i).Title = "User #" + CStr(i + 1)
        XMMR(i).InvokeCommand = DEFAULTINVOKECOMMAND
        XMMR(i).bInitialClose = False
        m_CurrentSwitch(i) = -1
    Next i
    XMMR(0).bActive = True  ' Invoke first MMTTY
    Call ShowStatus
End Sub

Private Sub InputInvokeCommand(MsgStr As String)
    Dim InvokeString As String
    InvokeString = InputBox(MsgStr, , XMMR(m_CurrentIndex).InvokeCommand)
    If Len(InvokeString) Then
        Dim i As Integer
        For i = 0 To USEREND Step 1
            XMMR(i).InvokeCommand = InvokeString
            XMMR(i).bActive = False
        Next i
        m_CurrentIndex = 0
        XMMR(0).bActive = True  ' Invoke first MMTTY
        Call ShowStatus
    End If
End Sub

Private Sub KOI_Click()
    InputInvokeCommand ("Enter Invoking command:")
End Sub

Private Sub KOR_Click()
    Dim Index As Integer
    Index = m_CurrentIndex
    XMMR(Index).bActive = False
    XMMR(Index).bActive = True
End Sub

Private Sub KOS_Click()
    Call XMMR(m_CurrentIndex).PostMmttyMessage(RXM_SHOWSETUP, 0)
End Sub

Private Sub UpdateMenus()
    Dim i As Integer
    For i = 0 To PROFILEEND Step 1
        KPS(i).Caption = "&" + CStr(i + 1) + " " + XMMR(m_CurrentIndex).Profiles(i)
        KPS(i).Enabled = Len(XMMR(m_CurrentIndex).Profiles(i)) <> 0
    Next i
    Dim bFlag As Boolean
    bFlag = XMMR(m_CurrentIndex).bActive
    KPR.Enabled = bFlag
    KPD.Enabled = bFlag
    KPW.Enabled = bFlag
    KOS.Enabled = bFlag
End Sub

Private Sub KPD_Click()
    Call XMMR(m_CurrentIndex).PostMmttyMessage(RXM_PROFILE, MAKELONG(1025, 0))
End Sub

Private Sub KPR_Click()
    Call XMMR(m_CurrentIndex).PostMmttyMessage(RXM_PROFILE, MAKELONG(0, 3))
End Sub

Private Sub KPS_Click(Index As Integer)
    Call XMMR(m_CurrentIndex).PostMmttyMessage(RXM_PROFILE, MAKELONG(Index, 0))
End Sub

Private Sub KPW_Click()
    Call XMMR(m_CurrentIndex).PostMmttyMessage(RXM_PROFILE, MAKELONG(0, 4))
End Sub

Private Sub KVQ_Click()
    XyScope.HighQuality = Not XyScope.HighQuality
    KVQ.Checked = XyScope.HighQuality
End Sub

Private Sub Level_OnLMouseDown(Index As Integer, ByVal Level As Integer)
    Call XMMR(Index).PostMmttyMessage(RXM_SETSQLVL, Level)
End Sub

Private Sub Level_OnLMouseMove(Index As Integer, ByVal Level As Integer)
    Call Level_OnLMouseDown(Index, Level)
End Sub

Private Sub Level_OnLMouseUp(Index As Integer, ByVal Level As Integer)
    Call Level_OnLMouseDown(Index, Level)
End Sub

Private Sub Spectram_OnLMouseDown(ByVal freq As Integer)
    If freq < 300 Then freq = 300
    Dim spacefreq As Long
    spacefreq = m_nmmr(xr_spacefreq, m_CurrentIndex) - m_nmmr(xr_markfreq, m_CurrentIndex) + freq
    If spacefreq > 2700 Then
        Dim offset As Long
        offset = spacefreq - 2700
        spacefreq = spacefreq - offset
        freq = freq - offset
    End If
    Call XMMR(m_CurrentIndex).PostMmttyMessage(RXM_SETMARK, freq)
    Call XMMR(m_CurrentIndex).PostMmttyMessage(RXM_SETSPACE, spacefreq)
End Sub

Private Sub Spectram_OnLMouseMove(ByVal freq As Integer)
    Call Spectram_OnLMouseDown(freq)
End Sub

Private Sub Spectram_OnLMouseUp(ByVal freq As Integer)
    Call Spectram_OnLMouseDown(freq)
End Sub

Private Sub Spectram_OnRMouseDown(ByVal freq As Integer)
    If freq < 300 Then freq = 300
    If freq > 2700 Then freq = 2700
    Call XMMR(m_CurrentIndex).PostMmttyMessage(RXM_NOTCH, freq)
    If (m_CurrentSwitch(m_CurrentIndex) And (swLMS Or swNOT)) <> (swLMS Or swNOT) Then
        m_nmmr(xr_codeswitch, m_CurrentIndex) = m_CurrentSwitch(m_CurrentIndex) Or swLMS Or swNOT
        Call UpdateButtonState(m_CurrentIndex)
        Call PostMmttySwitch(m_CurrentSwitch(m_CurrentIndex))
    End If
End Sub

Private Sub Spectram_OnRMouseMove(ByVal freq As Integer)
    If (m_CurrentSwitch(m_CurrentIndex) And swTWO) = 0 Then Call Spectram_OnRMouseDown(freq)
End Sub

Private Sub Spectram_OnRMouseUp(ByVal freq As Integer)
    If (m_CurrentSwitch(m_CurrentIndex) And swTWO) = 0 Then Call Spectram_OnRMouseDown(freq)
End Sub

Private Sub Text_GotFocus(Index As Integer)
    Text(Index).SelStart = Len(Text(Index).Text): Text(Index).SelLength = 0
    BtnTx(m_CurrentIndex).SetFocus
End Sub

Private Sub WaterFall_OnLMouseDown(ByVal freq As Integer)
    Call Spectram_OnLMouseDown(freq)
End Sub

Private Sub WaterFall_OnLMouseMove(ByVal freq As Integer)
    Call Spectram_OnLMouseDown(freq)
End Sub

Private Sub WaterFall_OnLMouseUp(ByVal freq As Integer)
    Call Spectram_OnLMouseDown(freq)
End Sub

Private Sub WaterFall_OnRMouseDown(ByVal freq As Integer)
    Call Spectram_OnRMouseDown(freq)
End Sub

Private Sub WaterFall_OnRMouseMove(ByVal freq As Integer)
    Call Spectram_OnRMouseMove(freq)
End Sub

Private Sub WaterFall_OnRMouseUp(ByVal freq As Integer)
    Call Spectram_OnRMouseUp(freq)
End Sub

Private Sub ShowStatus()
    Dim T$
    T$ = "User #" + CStr(m_CurrentIndex + 1)
    If XMMR(m_CurrentIndex).bActive Then
        LStatus.Caption = "Spectram is showing " + T$
    ElseIf XMMR(m_CurrentIndex).bInvoking Then
        LStatus.Caption = T$ + " Invoking..."
    Else
        LStatus.Caption = T$ + " Disconnected"
    End If
End Sub

Private Sub PostMmttySwitch(cs As Long)
    Call XMMR(m_CurrentIndex).SetMmttySwitch(cs)
End Sub

Private Sub SendButtonMsg(Index As Integer, MsgStr As String)
    Call XMMR(Index).SendString(MsgStr)
    Call XMMR(Index).SetMmttyPTT(1)    'Flush TX buffer and RX
End Sub

Private Sub UpdateButtonState(Index As Integer)
    If m_CurrentSwitch(Index) <> m_nmmr(xr_codeswitch, Index) Then
        m_CurrentSwitch(Index) = m_nmmr(xr_codeswitch, Index)
        BtnUOS(Index).State = m_CurrentSwitch(Index) And swUOS
        BtnRev(Index).State = m_CurrentSwitch(Index) And swREV
        BtnSQ(Index).State = m_CurrentSwitch(Index) And swSQ
        BtnLMS(Index).State = m_CurrentSwitch(Index) And swLMS
        BtnBPF(Index).State = m_CurrentSwitch(Index) And swBPF
        BtnNET(Index).State = m_CurrentSwitch(Index) And swNET
        BtnAFC(Index).State = m_CurrentSwitch(Index) And swAFC
        BtnDPF(Index).State = m_CurrentSwitch(Index) And swDPF
        If (m_CurrentSwitch(Index) And swNOT) Then BtnLMS(Index).Caption = "NOT" Else BtnLMS(Index).Caption = "LMS"
        Select Case (m_CurrentSwitch(Index) And 3)
            Case 0
                BtnType(Index).Caption = "IIR"
            Case 1
                BtnType(Index).Caption = "FIR"
            Case 2
                BtnType(Index).Caption = "PLL"
            Case Else
                BtnType(Index).Caption = "FFT"
        End Select
    End If
End Sub


Private Sub AddChar(ByVal Index As Integer, strChar As String)
    If strChar = vbCr Then strChar = strChar & vbLf
    Text(Index).SelStart = Len(Text(Index).Text)
    Text(Index).SelLength = 0
    Text(Index).SelText = strChar
    Text(Index).SelStart = Len(Text(Index).Text)
    Text(Index).SelLength = 0
End Sub
Private Sub XMMR_OnCharRcvd(Index As Integer, ByVal bChar As Integer)
    If bChar <> 10 Then
        Call AddChar(Index, Chr$(bChar))
    End If
End Sub

Private Sub EnableSharedMemory(ByVal Index As Integer, ByVal bFlag As Boolean)
    Call XMMR(Index).PostMmttyMessage(RXM_ENBSHARED, bFlag)
    XMMR(Index).bNotifyFFT = bFlag
    XMMR(Index).bNotifyXY = bFlag
    XMMR(Index).bNotifyComChange = bFlag
End Sub

Private Sub XMMR_OnConnected(Index As Integer)
    If Index = m_CurrentIndex Then
        XyScope.DemSampleFreq = XMMR(Index).smpDemFreq
        Call EnableSharedMemory(Index, True)
        Call UpdateMenus
    Else
        Call EnableSharedMemory(Index, False)
    End If
    Call UpdateUserButton
    
    ' Set initial frequency
    Dim markfreq As Long
    If Index Then markfreq = 2125 Else markfreq = 1445
    Call XMMR(Index).PostMmttyMessage(RXM_SETDEFFREQ, MAKELONG(markfreq, 170))
    Call XMMR(Index).PostMmttyMessage(RXM_SETHAM, 0)
    
    ' Invoke Next MMTTY
    Dim i As Integer
    For i = 0 To USEREND Step 1
        If Not XMMR(i).bActive Then
            XMMR(i).bActive = True
            Exit For
        End If
    Next i
End Sub


Private Sub XMMR_OnDisconnected(Index As Integer, ByVal status As Integer)
    If Index = m_CurrentIndex Then
        Select Case status
        Case 0
            LStatus.Caption = "User #" + CStr(Index + 1) + " MMTTY closing failed."
        Case 1
            Call UpdateUserButton
        Case 2
            LStatus.Caption = "User #" + CStr(Index + 1) + " MMTTY invoking failed."
            InputInvokeCommand ("Probably, MMTTY was not invoked." _
                                + Chr(13) + Chr(10) + Chr(13) + Chr(10) _
                                + "Enter full path name." _
                                + Chr(13) + Chr(10) _
                                + "Or copy mmtty.exe and userpara.ini to the current folder.")
        End Select
    End If
End Sub

Private Sub XMMR_OnNotifyFFT(Index As Integer, pFFT As Integer, ByVal size As Integer, ByVal sampfreq As Integer)
    If Index = m_CurrentIndex Then
        Call Spectram.Draw(pFFT, size, sampfreq)
        Call WaterFall.Draw(pFFT, size, sampfreq)
    End If
End Sub

Private Sub XMMR_OnNotifyNMMR(Index As Integer, pNMMR As Long)
    Call CopyMemory(m_nmmr(0, Index), pNMMR, 64 * 4)
    Call UpdateButtonState(Index)
    Call Level(Index).DrawByNMMR(pNMMR)
    If Index = m_CurrentIndex Then
        Call Spectram.UpdateByNMMR(pNMMR)
        If (m_nmmr(xr_codeview, Index) And &H1000) = 0 Then
            Call XMMR(Index).SetMmttyView(m_nmmr(xr_codeview, Index) Or &H1000)
        End If
    End If
End Sub

Private Sub XMMR_OnNotifyXY(Index As Integer, pXY As Long)
    If Index = m_CurrentIndex Then
        Call XyScope.Draw(pXY)
    End If
End Sub

Private Sub XMMR_OnPttEvent(Index As Integer, ByVal btx As Integer)
    BtnTx(Index).State = btx <> 0
    BtnTx(Index).Caption = "TX"
End Sub

Private Sub UpdateUserButton()
    BtnUSR(0).State = (m_CurrentIndex = 0)
    BtnUSR(1).State = (m_CurrentIndex = 1)
    Call ShowStatus
End Sub
