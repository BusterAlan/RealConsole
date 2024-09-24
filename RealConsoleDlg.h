
// RealConsoleDlg.h: archivo de encabezado
//

#pragma once


// Cuadro de diálogo de CRealConsoleDlg
class CRealConsoleDlg : public CDialogEx
{
// Construcción
public:
	CRealConsoleDlg(CWnd* pParent = nullptr);	// Constructor estándar

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_REALCONSOLE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Compatibilidad con DDX/DDV


// Implementación
protected:
	HICON m_hIcon;

	// Funciones de asignación de mensajes generadas
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	float op1;
	float op2;
	float sum;
	char op;
	boolean isFirstOperand = true;
	boolean isDotWithoutValue = false;
	CString result;
	afx_msg void OnOne();
	afx_msg void OnTwo();
	afx_msg void OnSum();
	afx_msg void OnThree();
	afx_msg void OnFour();
	afx_msg void OnFive();
	afx_msg void OnSix();
	afx_msg void OnSeven();
	afx_msg void OnEight();
	afx_msg void OnNine();
	afx_msg void OnZero();
	afx_msg void OnMinus();
	afx_msg void OnMultiply();
	afx_msg void OnDivision();
	afx_msg void OnDot();
	afx_msg void OnTrigComboBox();
	CComboBox m_comboTrig;
	afx_msg void OnClearEverything();
};
