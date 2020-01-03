
// Problem 4. RSA密码系统设计Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Problem 4. RSA密码系统设计.h"
#include "Problem 4. RSA密码系统设计Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CProblem4RSA密码系统设计Dlg 对话框

CProblem4RSA密码系统设计Dlg::CProblem4RSA密码系统设计Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PROBLEM4RSA_DIALOG, pParent)
	, editContent(_T(""))
	, editResult(_T(""))
	, editEKey(_T(""))
	, editDKey(_T(""))
	, editUsedN(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProblem4RSA密码系统设计Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_RESOURCE2, editContent);
	DDX_Text(pDX, IDC_RESOURCE, editResult);
	DDX_Text(pDX, IDC_EDIT4, editEKey);
	DDX_Text(pDX, IDC_EDIT3, editDKey);
	DDX_Text(pDX, IDC_EDIT11, editUsedN);
}

BEGIN_MESSAGE_MAP(CProblem4RSA密码系统设计Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON5, &CProblem4RSA密码系统设计Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CProblem4RSA密码系统设计Dlg::OnBnClickedButton6)


	ON_BN_CLICKED(IDC_BUTTON10, &CProblem4RSA密码系统设计Dlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON1, &CProblem4RSA密码系统设计Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CProblem4RSA密码系统设计Dlg 消息处理程序

BOOL CProblem4RSA密码系统设计Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	srand((USHORT)time(NULL));
	Sieve();
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CProblem4RSA密码系统设计Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CProblem4RSA密码系统设计Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CProblem4RSA密码系统设计Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//---------------------------------------------------------------------
#include "LINT.h"
#include "Miller Rabin.h"

#define TEST(x) 

#define STR_MAX_LEN 12560
char str[STR_MAX_LEN];


void CProblem4RSA密码系统设计Dlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	char* charSource; //宣告char*
	LINT eKey, N, m, c;
	CString cstrT;
	
	cstrT = editEKey;
	charSource = (LPSTR)(LPCTSTR)cstrT;
	eKey.KeyIn(charSource, cstrT.GetLength());

	cstrT = editUsedN;
	charSource = (LPSTR)(LPCTSTR)cstrT;
	N.KeyIn(charSource, cstrT.GetLength());

	cstrT = editContent;
	charSource = (LPSTR)(LPCTSTR)cstrT;

	m.StrKeyIn(charSource, cstrT.GetLength());

	c = LINT::MQPower(m, eKey, N);
	charSource = new char[STR_MAX_LEN];
	c.Display(charSource);
	editResult = charSource;

	UpdateData(FALSE);
	delete[] charSource;
}


void CProblem4RSA密码系统设计Dlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	char* charSource; //宣告char*
	LINT dKey, N, c, m;
	CString cstrT;

	cstrT = editDKey;
	charSource = (LPSTR)(LPCTSTR)cstrT;
	dKey.KeyIn(charSource, cstrT.GetLength());

	cstrT = editUsedN;
	charSource = (LPSTR)(LPCTSTR)cstrT;
	N.KeyIn(charSource, cstrT.GetLength());

	cstrT = editContent;
	charSource = (LPSTR)(LPCTSTR)cstrT;
	c.KeyIn(charSource, cstrT.GetLength());

	m = LINT::MQPower(c, dKey, N);
	charSource = new char[STR_MAX_LEN];
	m.StrDisplay(charSource);
	editResult = charSource;
	UpdateData(FALSE);
	delete[] charSource;
}


void CProblem4RSA密码系统设计Dlg::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString temp;
	//temp = editContent;
	editContent = editResult;
	editResult = temp;
	UpdateData(FALSE);
}

void CProblem4RSA密码系统设计Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	// TODO: 在此添加控件通知处理程序代码
	DialogCreate *dlg = new DialogCreate;
	dlg->Create(IDD_DIALOG1, NULL);
	dlg->ShowWindow(SW_SHOW);
}
