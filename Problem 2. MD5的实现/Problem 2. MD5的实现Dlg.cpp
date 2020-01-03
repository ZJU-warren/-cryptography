
// Problem 2. MD5的实现Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Problem 2. MD5的实现.h"
#include "Problem 2. MD5的实现Dlg.h"
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


// CProblem2MD5的实现Dlg 对话框



CProblem2MD5的实现Dlg::CProblem2MD5的实现Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PROBLEM2MD5_DIALOG, pParent)
	, editShow(_T(""))
	, editRes(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProblem2MD5的实现Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, editShow);
	DDX_Text(pDX, IDC_EDIT1, editRes);
}

BEGIN_MESSAGE_MAP(CProblem2MD5的实现Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CProblem2MD5的实现Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CProblem2MD5的实现Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CProblem2MD5的实现Dlg 消息处理程序

BOOL CProblem2MD5的实现Dlg::OnInitDialog()
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CProblem2MD5的实现Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CProblem2MD5的实现Dlg::OnPaint()
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
HCURSOR CProblem2MD5的实现Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
//--------------------------------------------------------------
char* charSource; //宣告char*
CString cstrT;

void CProblem2MD5的实现Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	cstrT = editShow;
	charSource = (LPSTR)(LPCTSTR)cstrT;
	strcpy(p, charSource);
	int size;
	UNIT64 bitLen;
	Extend(p, size, bitLen);
	Divide(p, size, bitLen);

	a = A, b = B, c = C, d = D;
	Fin(i, 0, size - 1) 
		M[i].MD5();
	sprintf(p,"%08X%08X%08X%08X\n", Reverse(a), Reverse(b), Reverse(c), Reverse(d));
	editRes = p;
	UpdateData(FALSE);
}


void CProblem2MD5的实现Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	cstrT = editShow;
	charSource = (LPSTR)(LPCTSTR)cstrT;
	strcpy(sp, charSource);
	Exchange();
	int size;
	UNIT64 bitLen;
	Extend(p, size, bitLen);
	Divide(p, size, bitLen);

	a = A, b = B, c = C, d = D;
	Fin(i, 0, size - 1)
		M[i].MD5();
	sprintf(p, "%08X%08X%08X%08X\n", Reverse(a), Reverse(b), Reverse(c), Reverse(d));
	editRes = p;
	UpdateData(FALSE);
}
