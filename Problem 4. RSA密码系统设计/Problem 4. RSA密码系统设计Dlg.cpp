
// Problem 4. RSA����ϵͳ���Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Problem 4. RSA����ϵͳ���.h"
#include "Problem 4. RSA����ϵͳ���Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CProblem4RSA����ϵͳ���Dlg �Ի���

CProblem4RSA����ϵͳ���Dlg::CProblem4RSA����ϵͳ���Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PROBLEM4RSA_DIALOG, pParent)
	, editContent(_T(""))
	, editResult(_T(""))
	, editEKey(_T(""))
	, editDKey(_T(""))
	, editUsedN(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProblem4RSA����ϵͳ���Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_RESOURCE2, editContent);
	DDX_Text(pDX, IDC_RESOURCE, editResult);
	DDX_Text(pDX, IDC_EDIT4, editEKey);
	DDX_Text(pDX, IDC_EDIT3, editDKey);
	DDX_Text(pDX, IDC_EDIT11, editUsedN);
}

BEGIN_MESSAGE_MAP(CProblem4RSA����ϵͳ���Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON5, &CProblem4RSA����ϵͳ���Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CProblem4RSA����ϵͳ���Dlg::OnBnClickedButton6)


	ON_BN_CLICKED(IDC_BUTTON10, &CProblem4RSA����ϵͳ���Dlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON1, &CProblem4RSA����ϵͳ���Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CProblem4RSA����ϵͳ���Dlg ��Ϣ�������

BOOL CProblem4RSA����ϵͳ���Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	srand((USHORT)time(NULL));
	Sieve();
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CProblem4RSA����ϵͳ���Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CProblem4RSA����ϵͳ���Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CProblem4RSA����ϵͳ���Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//---------------------------------------------------------------------
#include "LINT.h"
#include "Miller Rabin.h"

#define TEST(x) 

#define STR_MAX_LEN 12560
char str[STR_MAX_LEN];


void CProblem4RSA����ϵͳ���Dlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	char* charSource; //����char*
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


void CProblem4RSA����ϵͳ���Dlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	char* charSource; //����char*
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


void CProblem4RSA����ϵͳ���Dlg::OnBnClickedButton10()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString temp;
	//temp = editContent;
	editContent = editResult;
	editResult = temp;
	UpdateData(FALSE);
}

void CProblem4RSA����ϵͳ���Dlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DialogCreate *dlg = new DialogCreate;
	dlg->Create(IDD_DIALOG1, NULL);
	dlg->ShowWindow(SW_SHOW);
}
