VERSION 5.00
Object = "{9FAE7EB9-098B-4952-A234-CF460419D752}#1.0#0"; "XMMT.ocx"
Begin VB.Form Main 
   BorderStyle     =   1  'ŒÅ’è(ŽÀü)
   Caption         =   "XMMR 2 Container"
   ClientHeight    =   5175
   ClientLeft      =   150
   ClientTop       =   840
   ClientWidth     =   7395
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
   ScaleWidth      =   7395
   StartUpPosition =   3  'Windows ‚ÌŠù’è’l
   Begin VB.TextBox Text 
      Height          =   1695
      Index           =   1
      Left            =   0
      MultiLine       =   -1  'True
      ScrollBars      =   2  '‚’¼
      TabIndex        =   24
      Top             =   3480
      Width           =   7455
   End
   Begin XMMTLib.XMMR XMMR 
      Height          =   255
      Index           =   0
      Left            =   6480
      TabIndex        =   22
      Top             =   1320
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
   End
   Begin XMMTLib.XMMBtn BtnM4 
      Height          =   375
      Left            =   1560
      TabIndex        =   21
      Top             =   1320
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
      Left            =   1080
      TabIndex        =   20
      Top             =   1320
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
      Left            =   600
      TabIndex        =   19
      Top             =   1320
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
      Left            =   120
      TabIndex        =   18
      Top             =   1320
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
      Height          =   1695
      Index           =   0
      Left            =   0
      MultiLine       =   -1  'True
      ScrollBars      =   2  '‚’¼
      TabIndex        =   17
      Top             =   1800
      Width           =   7455
   End
   Begin XMMTLib.XMMBtn BtnAFC 
      Height          =   375
      Left            =   1920
      TabIndex        =   15
      Top             =   840
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
      Left            =   1440
      TabIndex        =   14
      Top             =   840
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
   Begin XMMTLib.XMMBtn BtnATC 
      Height          =   375
      Left            =   960
      TabIndex        =   13
      Top             =   840
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
      Caption         =   "ATC"
      FaceColor       =   -2147483633
   End
   Begin XMMTLib.XMMBtn BtnBPF 
      Height          =   375
      Left            =   1920
      TabIndex        =   12
      Top             =   480
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
      Left            =   1440
      TabIndex        =   11
      Top             =   480
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
      Left            =   960
      TabIndex        =   10
      Top             =   480
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
      Left            =   1920
      TabIndex        =   9
      Top             =   120
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
      Left            =   1440
      TabIndex        =   8
      Top             =   120
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
      Left            =   960
      TabIndex        =   7
      Top             =   120
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
      Left            =   120
      TabIndex        =   6
      Top             =   840
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
      Left            =   2520
      TabIndex        =   5
      Top             =   120
      Width           =   255
      _Version        =   65538
      _ExtentX        =   450
      _ExtentY        =   1931
      _StockProps     =   32
      BorderStyle     =   1
   End
   Begin XMMTLib.XMMWater WaterFall 
      Height          =   375
      Left            =   2760
      TabIndex        =   4
      Top             =   840
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
      Left            =   2760
      TabIndex        =   3
      Top             =   120
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
      Left            =   6240
      TabIndex        =   2
      Top             =   120
      Width           =   1095
      _Version        =   65538
      _ExtentX        =   1931
      _ExtentY        =   1931
      _StockProps     =   32
      BorderStyle     =   1
   End
   Begin XMMTLib.XMMBtn BtnTxOff 
      Height          =   375
      Left            =   120
      TabIndex        =   1
      Top             =   480
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
      Left            =   120
      TabIndex        =   0
      Top             =   120
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
      Left            =   6720
      TabIndex        =   23
      Top             =   1320
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
   End
   Begin VB.Label LStatus 
      Caption         =   "Status"
      Height          =   255
      Left            =   2520
      TabIndex        =   16
      Top             =   1320
      Width           =   3615
   End
   Begin VB.Menu KV 
      Caption         =   "&View"
      Begin VB.Menu KVQ 
         Caption         =   "&High XY quality"
      End
   End
   Begin VB.Menu KU 
      Caption         =   "&User"
      Begin VB.Menu KUS 
         Caption         =   "User &1"
         Index           =   0
      End
      Begin VB.Menu KUS 
         Caption         =   "User &2"
         Index           =   1
      End
   End
   Begin VB.Menu KO 
      Caption         =   "&Option"
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
      Begin VB.Menu KP_ 
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

Const PROFILEEND = 8 - 1
Const USEREND = 2 - 1

Private m_CurrentIndex As Integer
Private m_nmmr(63) As Long
Private m_CurrentSwitch As Long
Private m_ptt(USEREND) As Boolean

Private Sub BtnAFC_OnLButtonClick()
    Call PostMmttySwitch(m_CurrentSwitch Xor swAFC)
End Sub

Private Sub BtnATC_OnLButtonClick()
    Call PostMmttySwitch(m_CurrentSwitch Xor swATC)
End Sub

Private Sub BtnBPF_OnLButtonClick()
    Call PostMmttySwitch(m_CurrentSwitch Xor swBPF)
End Sub

Private Sub BtnHAM_OnLButtonClick()
    Call XMMR(m_CurrentIndex).PostMmttyMessage(RXM_SETHAM, 0)
End Sub

Private Sub BtnLMS_OnLButtonClick()
    Call PostMmttySwitch(m_CurrentSwitch Xor swLMS)
End Sub

Private Sub BtnLMS_OnRButtonClick()
    Call PostMmttySwitch(m_CurrentSwitch Xor swNOT)
End Sub

Private Sub BtnM1_OnLButtonClick()
    Call SendButtonMsg(Chr(13) + " CQ CQ CQ DE CONTAINER CONTAINER PSE K" + Chr(13))
End Sub

Private Sub BtnM2_OnLButtonClick()
    Call SendButtonMsg(Chr(13) + " QRZ? AGN?" + Chr(13))
End Sub

Private Sub BtnM3_OnLButtonClick()
    Call SendButtonMsg(Chr(13) + " QSL, UR 599 25 25 25 BK" + Chr(13))
End Sub

Private Sub BtnM4_OnLButtonClick()
    Call SendButtonMsg(Chr(13) + " QSL, TNX CUL 73, QRZ? DE CONTAINER K" + Chr(13))
End Sub

Private Sub BtnNET_OnLButtonClick()
    Call PostMmttySwitch(m_CurrentSwitch Xor swNET)
End Sub

Private Sub BtnRev_OnLButtonClick()
    Call PostMmttySwitch(m_CurrentSwitch Xor swREV)
End Sub

Private Sub BtnSQ_OnLButtonClick()
    Call PostMmttySwitch(m_CurrentSwitch Xor swSQ)
End Sub

Private Sub BtnTx_OnLButtonClick()
    BtnTx.Caption = "Req"
    If BtnTx.State Then
        BtnTx.State = False
        XMMR(m_CurrentIndex).PTT = True
    Else
        BtnTx.State = True
        Call XMMR(m_CurrentIndex).SetMmttyPTT(1)
    End If
End Sub

Private Sub BtnTxOff_OnLButtonClick()
    If BtnTx.State Then
        BtnTx.Caption = "Req"
    End If
    XMMR(m_CurrentIndex).PTT = False
End Sub

Private Sub BtnType_OnLButtonClick()
    Dim typ As Long
    typ = m_CurrentSwitch And 3
    typ = typ + 1
    If typ >= 4 Then typ = 0
    typ = typ + (m_CurrentSwitch And (Not 3))
    Call PostMmttySwitch(typ)
End Sub

Private Sub BtnUOS_OnLButtonClick()
    Call PostMmttySwitch(m_CurrentSwitch Xor swUOS)
End Sub

Private Sub Form_Load()
    m_CurrentIndex = 0
    m_CurrentSwitch = -1
    XyScope.HighQuality = KVQ.Checked
    Call UpdateMenus
    Dim i As Integer
    For i = 0 To USEREND Step 1
        XMMR(i).Title = "User #" + CStr(i + 1)
    Next i
    XMMR(m_CurrentIndex).bActive = True  'Invoke first MMTTY
    Call ShowStatus
End Sub

Private Sub InputInvokeCommand(MsgStr As String)
    Dim InvokeString As String
    InvokeString = InputBox(MsgStr, , XMMR(m_CurrentIndex).InvokeCommand)
    If Len(InvokeString) Then
        Dim i As Integer
        For i = 0 To USEREND Step 1
            XMMR(i).InvokeCommand = InvokeString
        Next i
        Call KOR_Click
    End If
End Sub

Private Sub KOI_Click()
    InputInvokeCommand ("Enter Invoking command:")
End Sub

Private Sub KOR_Click()
    Dim Index As Integer
    Index = m_CurrentIndex
    XMMR(Index).bActive = False
    Call KUS_Click(Index)
End Sub

Private Sub KOS_Click()
    Call XMMR(m_CurrentIndex).PostMmttyMessage(RXM_SHOWSETUP, 0)
End Sub

Private Sub UpdateUserMenu()
    Dim i As Integer
    For i = 0 To USEREND Step 1
        Dim T$
        T$ = "User &" + CStr(i + 1)
        If XMMR(i).bActive Then
            T$ = T$ + " Connected to HWND[" + Hex$(XMMR(i).hWndMmtty) + "]"
        End If
        KUS(i).Caption = T$
        KUS(i).Checked = (i = m_CurrentIndex)
    Next i
    Call ShowStatus
    BtnTx.State = m_ptt(m_CurrentIndex)
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
    KPW.Enabled = bFlag
    KOS.Enabled = bFlag
End Sub

Private Sub KPR_Click()
    Call XMMR(m_CurrentIndex).PostMmttyMessage(RXM_PROFILE, 3 * 65536)
End Sub

Private Sub KPS_Click(Index As Integer)
    Call XMMR(m_CurrentIndex).PostMmttyMessage(RXM_PROFILE, Index)
End Sub

Private Sub KPW_Click()
    Call XMMR(m_CurrentIndex).PostMmttyMessage(RXM_PROFILE, 4 * 65536)
End Sub

Private Sub KU_Click()
    Call UpdateUserMenu
End Sub

Private Sub KUS_Click(Index As Integer)
    Call EnableSharedMemory(m_CurrentIndex, False)
    m_CurrentIndex = Index
    If XMMR(Index).bActive Then
        Call EnableSharedMemory(m_CurrentIndex, True)
    Else
        XMMR(Index).bActive = True
    End If
    Call UpdateUserMenu
End Sub

Private Sub KVQ_Click()
    XyScope.HighQuality = Not XyScope.HighQuality
    KVQ.Checked = XyScope.HighQuality
End Sub

Private Sub Level_OnLMouseDown(ByVal Level As Integer)
    Call XMMR(m_CurrentIndex).PostMmttyMessage(RXM_SETSQLVL, Level)
End Sub

Private Sub Level_OnLMouseMove(ByVal Level As Integer)
    Call Level_OnLMouseDown(Level)
End Sub

Private Sub Level_OnLMouseUp(ByVal Level As Integer)
    Call Level_OnLMouseDown(Level)
End Sub

Private Sub Spectram_OnLMouseDown(ByVal freq As Integer)
    If freq < 300 Then freq = 300
    Dim Spacefreq As Long
    Spacefreq = m_nmmr(xr_spacefreq) - m_nmmr(xr_markfreq) + freq
    If Spacefreq > 2700 Then
        Dim offset As Long
        offset = Spacefreq - 2700
        Spacefreq = Spacefreq - offset
        freq = freq - offset
    End If
    Call XMMR(m_CurrentIndex).PostMmttyMessage(RXM_SETMARK, freq)
    Call XMMR(m_CurrentIndex).PostMmttyMessage(RXM_SETSPACE, Spacefreq)
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
    If (m_CurrentSwitch And (swLMS Or swNOT)) <> (swLMS Or swNOT) Then
        Call PostMmttySwitch(m_CurrentSwitch Or swLMS Or swNOT)
    End If
End Sub

Private Sub Spectram_OnRMouseMove(ByVal freq As Integer)
    If (m_CurrentSwitch And swTWO) = 0 Then Call Spectram_OnRMouseDown(freq)
End Sub

Private Sub Spectram_OnRMouseUp(ByVal freq As Integer)
    If (m_CurrentSwitch And swTWO) = 0 Then Call Spectram_OnRMouseDown(freq)
End Sub

Private Sub Text_Click(Index As Integer)
    BtnTx.SetFocus
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
    If XMMR(m_CurrentIndex).bActive Then
        LStatus.Caption = "User #" + CStr(m_CurrentIndex + 1) + " Connected to MMTTY " + XMMR(m_CurrentIndex).verMMTTY
    ElseIf XMMR(m_CurrentIndex).bInvoking Then
        LStatus.Caption = "User #" + CStr(m_CurrentIndex + 1) + " Invoking..."
    Else
        LStatus.Caption = "User #" + CStr(m_CurrentIndex + 1) + " Disconnected"
    End If
End Sub

Private Sub PostMmttySwitch(cs As Long)
    Call XMMR(m_CurrentIndex).SetMmttySwitch(cs)
End Sub

Private Sub SendButtonMsg(MsgStr As String)
    Call XMMR(m_CurrentIndex).SendString(MsgStr)
    Call XMMR(m_CurrentIndex).SetMmttyPTT(1)    'Flush TX buffer and RX
End Sub

Private Sub UpdateButtonState()
    If m_CurrentSwitch <> m_nmmr(xr_codeswitch) Then
        m_CurrentSwitch = m_nmmr(xr_codeswitch)
        BtnUOS.State = m_CurrentSwitch And swUOS
        BtnRev.State = m_CurrentSwitch And swREV
        BtnSQ.State = m_CurrentSwitch And swSQ
        BtnLMS.State = m_CurrentSwitch And swLMS
        BtnBPF.State = m_CurrentSwitch And swBPF
        BtnATC.State = m_CurrentSwitch And swATC
        BtnNET.State = m_CurrentSwitch And swNET
        BtnAFC.State = m_CurrentSwitch And swAFC
        If (m_CurrentSwitch And swNOT) Then BtnLMS.Caption = "NOT" Else BtnLMS.Caption = "LMS"
        Select Case (m_CurrentSwitch And 3)
            Case 0
                BtnType.Caption = "IIR"
            Case 1
                BtnType.Caption = "FIR"
            Case 2
                BtnType.Caption = "PLL"
            Case Else
                BtnType.Caption = "FFT"
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
    m_ptt(Index) = False
    If Index = m_CurrentIndex Then
        XyScope.DemSampleFreq = XMMR(Index).smpDemFreq
        Call EnableSharedMemory(Index, True)
        Call UpdateMenus
    Else
        Call EnableSharedMemory(Index, False)
    End If
    Call UpdateUserMenu
End Sub


Private Sub XMMR_OnDisconnected(Index As Integer, ByVal status As Integer)
    If Index = m_CurrentIndex Then
        Select Case status
        Case 0
            LStatus.Caption = "User #" + CStr(Index + 1) + " MMTTY closing failed."
        Case 1
            Dim i As Integer
            For i = 0 To USEREND Step 1
                If XMMR(i).bActive Then
                    m_CurrentIndex = i
                    Call EnableSharedMemory(m_CurrentIndex, True)
                    Exit For
                End If
            Next i
            Call UpdateUserMenu
        Case 2
            LStatus.Caption = "User #" + CStr(Index + 1) + " MMTTY invoking failed."
            InputInvokeCommand ("Probably, MMTTY was not invoked." _
                                + Chr(13) + Chr(10) + Chr(13) + Chr(10) _
                                + "Enter full path name." _
                                + Chr(13) + Chr(10) _
                                + "Or copy MMTTY.EXE to the current folder.")
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
    If Index = m_CurrentIndex Then
        Call CopyMemory(m_nmmr(0), pNMMR, 64 * 4)
        Call Level.DrawByNMMR(pNMMR)
        Call Spectram.UpdateByNMMR(pNMMR)
        Call UpdateButtonState
        If (m_nmmr(xr_codeview) And &H1000) = 0 Then
            Call XMMR(m_CurrentIndex).SetMmttyView(m_nmmr(xr_codeview) Or &H1000)
        End If
    End If
End Sub

Private Sub XMMR_OnNotifyXY(Index As Integer, pXY As Long)
    If Index = m_CurrentIndex Then
        Call XyScope.Draw(pXY)
    End If
End Sub

Private Sub XMMR_OnPttEvent(Index As Integer, ByVal btx As Integer)
    m_ptt(Index) = (btx <> 0)
    If Index = m_CurrentIndex Then
        If btx Then
            BtnTx.State = True
        Else
            BtnTx.State = False
        End If
        BtnTx.Caption = "TX"
    End If
End Sub
