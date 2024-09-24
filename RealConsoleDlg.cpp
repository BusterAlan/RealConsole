
// RealConsoleDlg.cpp: archivo de implementación
//

#include "pch.h"
#include "framework.h"
#include "RealConsole.h"
#include "RealConsoleDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cuadro de diálogo CAboutDlg utilizado para el comando Acerca de

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Compatibilidad con DDX/DDV

// Implementación
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cuadro de diálogo de CRealConsoleDlg



CRealConsoleDlg::CRealConsoleDlg(CWnd* pParent /*= nullptr*/)
	: CDialogEx(IDD_REALCONSOLE_DIALOG, pParent)
	, result(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRealConsoleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_BOX, result);
	DDX_Control(pDX, IDC_TRIG, m_comboTrig);
}

BEGIN_MESSAGE_MAP(CRealConsoleDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ONE, &CRealConsoleDlg::OnOne)
	ON_BN_CLICKED(IDC_BUTTON_TWO, &CRealConsoleDlg::OnTwo)
	ON_BN_CLICKED(IDC_BUTTON_SUM, &CRealConsoleDlg::OnSum)
	ON_BN_CLICKED(IDC_BUTTON1, &CRealConsoleDlg::OnThree)
	ON_BN_CLICKED(IDC_BUTTON2, &CRealConsoleDlg::OnFour)
	ON_BN_CLICKED(IDC_BUTTON3, &CRealConsoleDlg::OnFive)
	ON_BN_CLICKED(IDC_BUTTON4, &CRealConsoleDlg::OnSix)
	ON_BN_CLICKED(IDC_BUTTON5, &CRealConsoleDlg::OnSeven)
	ON_BN_CLICKED(IDC_BUTTON6, &CRealConsoleDlg::OnEight)
	ON_BN_CLICKED(IDC_BUTTON7, &CRealConsoleDlg::OnNine)
	ON_BN_CLICKED(IDC_BUTTON8, &CRealConsoleDlg::OnZero)
	ON_BN_CLICKED(IDC_BUTTON9, &CRealConsoleDlg::OnMinus)
	ON_BN_CLICKED(IDC_BUTTON10, &CRealConsoleDlg::OnMultiply)
	ON_BN_CLICKED(IDC_BUTTON11, &CRealConsoleDlg::OnDivision)
	ON_BN_CLICKED(IDC_BUTTON12, &CRealConsoleDlg::OnDot)
	ON_CBN_SELCHANGE(IDC_TRIG, &CRealConsoleDlg::OnTrigComboBox)
	ON_BN_CLICKED(IDC_BUTTON16, &CRealConsoleDlg::OnClearEverything)
END_MESSAGE_MAP()

// Controladores de mensajes de CMFCEmptyDlg

BOOL CRealConsoleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Agregar el elemento de menú "Acerca de..." al menú del sistema.

	// IDM_ABOUTBOX debe estar en el intervalo de comandos del sistema.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Establecer el icono para este cuadro de diálogo.  El marco de trabajo realiza esta operación
	//  automáticamente cuando la ventana principal de la aplicación no es un cuadro de diálogo
	SetIcon(m_hIcon, TRUE);			// Establecer icono grande
	SetIcon(m_hIcon, FALSE);		// Establecer icono pequeño

	// TODO: agregar aquí inicialización adicional

	m_comboTrig.SetCueBanner(_T("Trigonometry"));

	return TRUE;  // Devuelve TRUE  a menos que establezca el foco en un control
}

void CRealConsoleDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// Si agrega un botón Minimizar al cuadro de diálogo, necesitará el siguiente código
//  para dibujar el icono.  Para aplicaciones MFC que utilicen el modelo de documentos y vistas,
//  esta operación la realiza automáticamente el marco de trabajo.

void CRealConsoleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Contexto de dispositivo para dibujo

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrar icono en el rectángulo de cliente
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dibujar el icono
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// El sistema llama a esta función para obtener el cursor que se muestra mientras el usuario arrastra
//  la ventana minimizada.
HCURSOR CRealConsoleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CRealConsoleDlg::OnOne()
{
	UpdateData(true);
	result.Append(_T("1"));
	UpdateData(false);
}

void CRealConsoleDlg::OnTwo()
{
	UpdateData(true);
	result.Append(_T("2"));
	UpdateData(false);
}

void CRealConsoleDlg::OnThree()
{
	UpdateData(true);
	result.Append(_T("3"));
	UpdateData(false);
}


void CRealConsoleDlg::OnFour()
{
	UpdateData(true);
	result.Append(_T("4"));
	UpdateData(false);
}


void CRealConsoleDlg::OnFive()
{
	UpdateData(true);
	result.Append(_T("5"));
	UpdateData(false);
}

void CRealConsoleDlg::OnSix()
{
	UpdateData(true);
	result.Append(_T("6"));
	UpdateData(false);
}

void CRealConsoleDlg::OnSeven()
{
	UpdateData(true);
	result.Append(_T("7"));
	UpdateData(false);
}

void CRealConsoleDlg::OnEight()
{
	UpdateData(true);
	result.Append(_T("8"));
	UpdateData(false);
}

void CRealConsoleDlg::OnNine()
{
	UpdateData(true);
	result.Append(_T("9"));
	UpdateData(false);
}

void CRealConsoleDlg::OnZero()
{
	UpdateData(true);
	result.Append(_T("0"));
	UpdateData(false);
}

void CRealConsoleDlg::OnSum()
{
	if (isFirstOperand) {
		op1 = _ttof(result);
		op = '+';
		isFirstOperand = false;
		UpdateData(true);
		result = "";
		UpdateData(false);
	}
	else {
		op2 = _ttof(result);
		sum = op1 + op2;
		UpdateData(true);
		if (sum == static_cast<int>(sum)) {
			result.Format(_T("%.0f"), sum);
		}
		else {
			result.Format(_T("%f"), sum);
		}
		UpdateData(false);
		isFirstOperand = true;
	}
}


void CRealConsoleDlg::OnMinus()
{
	if (isFirstOperand) {

		op1 = _ttof(result);
		op = '-';
		isFirstOperand = false;
		UpdateData(true);
		result = "";
		UpdateData(false);

	}
	else {

		op2 = _ttof(result);
		sum = op1 - op2;
		UpdateData(true);
		if (sum == static_cast<int>(sum)) {
			result.Format(_T("%.0f"), sum);
		}
		else {
			result.Format(_T("%f"), sum);
		}
		UpdateData(false);
		isFirstOperand = true;

	}
}

void CRealConsoleDlg::OnMultiply()
{
	if (isFirstOperand) {

		op1 = _ttof(result);
		op = '*';
		isFirstOperand = false;
		UpdateData(true);
		result = "";
		UpdateData(false);

	}
	else {

		op2 = _ttof(result);
		sum = op1 * op2;
		UpdateData(true);
		if (sum == static_cast<int>(sum)) {
			result.Format(_T("%.0f"), sum);
		}
		else {
			result.Format(_T("%f"), sum);
		}
		UpdateData(false);
		isFirstOperand = true;

	}
}

void CRealConsoleDlg::OnDivision()
{
	if (isFirstOperand) {

		op1 = _ttof(result);
		op = '/';
		isFirstOperand = false;
		UpdateData(true);
		result = "";
		UpdateData(false);

	}
	else {

		op2 = _ttof(result);
		sum = op1 / op2;
		UpdateData(true);
		if (sum == static_cast<int>(sum)) {
			result.Format(_T("%.0f"), sum);
		}
		else {
			result.Format(_T("%f"), sum);
		}
		UpdateData(false);
		isFirstOperand = true;

	}
}

void CRealConsoleDlg::OnDot()
{
	UpdateData(true);
	result.Append(_T("."));
	isDotWithoutValue = true;
	UpdateData(false);
}

void CRealConsoleDlg::OnTrigComboBox() {

	// int sel = m_comboTrig.GetCurSel();
	CString strSel;
	// m_comboTrig.GetLBText(sel, strSel);

	if (strSel == _T("Seno"))
	{
		// Lógica para calcular el seno
	}
	else if (strSel == _T("Coseno"))
	{
		// Lógica para calcular el coseno
	}
	else if (strSel == _T("Tangente"))
	{
		// Lógica para calcular la tangente
	}

}


void CRealConsoleDlg::OnClearEverything()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
}
