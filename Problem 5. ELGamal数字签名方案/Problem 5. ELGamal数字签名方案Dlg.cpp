
// Problem 5. ELGamal����ǩ������Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Problem 5. ELGamal����ǩ������.h"
#include "Problem 5. ELGamal����ǩ������Dlg.h"
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


// CProblem5ELGamal����ǩ������Dlg �Ի���



CProblem5ELGamal����ǩ������Dlg::CProblem5ELGamal����ǩ������Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PROBLEM5ELGAMAL_DIALOG, pParent)
	, editMess(_T(""))
	, editP(_T(""))
	, editG(_T(""))
	, editX(_T(""))
	, editY(_T(""))
	, editBitLen(_T(""))
	, editR(_T(""))
	, editS(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProblem5ELGamal����ǩ������Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT4, editMess);
	//  DDX_Text(pDX, IDC_EDIT5, editRes);
	DDX_Text(pDX, IDC_EDIT1, editP);
	DDX_Text(pDX, IDC_EDIT2, editG);
	DDX_Text(pDX, IDC_EDIT6, editX);
	DDX_Text(pDX, IDC_EDIT7, editY);
	DDX_Text(pDX, IDC_EDIT3, editBitLen);
	DDX_Text(pDX, IDC_EDIT5, editR);
	DDX_Text(pDX, IDC_EDIT8, editS);
}

BEGIN_MESSAGE_MAP(CProblem5ELGamal����ǩ������Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CProblem5ELGamal����ǩ������Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CProblem5ELGamal����ǩ������Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CProblem5ELGamal����ǩ������Dlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CProblem5ELGamal����ǩ������Dlg ��Ϣ�������

BOOL CProblem5ELGamal����ǩ������Dlg::OnInitDialog()
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

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CProblem5ELGamal����ǩ������Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CProblem5ELGamal����ǩ������Dlg::OnPaint()
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
HCURSOR CProblem5ELGamal����ǩ������Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


#define STR_MAX_LEN 12560
char str[STR_MAX_LEN];
LINT p, g, x, y;
LINT pd1 , gcd;
void CProblem5ELGamal����ǩ������Dlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	/* ���ɴ�����p �� �䱾ԭԪ g*/
	//�����ɰ�ȫ����q
	UpdateData(TRUE);
	clock_t start_time, end_time;
	start_time = clock();
	int len = _ttoi(editBitLen);
	if (len < 15) {
		AfxMessageBox(_T("λ������С��15"));
		return;
	}
	if (len > 300) {
		AfxMessageBox(_T("λ�����ɴ���300"));
		return;
	}
	bool flag = false;
	LINT tp;
	do {
		tp = Produce(len);
		p = tp * two_l + one_l;
		if (MiLLer_Rabin(p, 10, len))
			flag = true;
	} while (!flag);
	//����g
	flag = false;
	//char temp[2000] = {};
	//int cntmy = 0;
	do {
		//temp[cntmy++] = 'T';
		g = Produce(rand()%(len - 10) + 2);
		if (LINT::MQPower(g, two_l, p) != one_l
			&& LINT::MQPower(g, tp, p) != one_l)
			flag = true;
	} while (!flag);
	memset(str, 0, sizeof str);
	p.Display(str);
	editP = str;

	memset(str, 0, sizeof str);
	g.Display(str);
	editG = str;

	// ��Կ���� x,y
	x = GetOne(len - 5) + one_l;
	y = LINT::MQPower(g, x, p);
	pd1 = p - one_l;
	memset(str, 0, sizeof str);
	x.Display(str);
	editX = str;

	memset(str, 0, sizeof str);
	y.Display(str);
	editY = str;
	UpdateData(FALSE);

	end_time = clock();
	//cout << "Running time is: " << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;//�������ʱ��
	sprintf(str, "%.2lf", static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000);
	AfxMessageBox(_T("���ɳɹ�����ʱ��" + (CString)str + "ms"));
}

LINT m, sigm, r, k, invK, temp, s;
void CProblem5ELGamal����ǩ������Dlg::OnBnClickedButton2()
{
	UpdateData(TRUE);
	CString cstrT;
	char * charSource;
	cstrT = editMess;
	charSource = (LPSTR)(LPCTSTR)cstrT;
	m.KeyIn(charSource, cstrT.GetLength());

	cstrT = editP;
	charSource = (LPSTR)(LPCTSTR)cstrT;
	p.KeyIn(charSource, cstrT.GetLength());

	cstrT = editG;
	charSource = (LPSTR)(LPCTSTR)cstrT;
	g.KeyIn(charSource, cstrT.GetLength());

	cstrT = editX;
	charSource = (LPSTR)(LPCTSTR)cstrT;
	x.KeyIn(charSource, cstrT.GetLength());

	cstrT = editY;
	charSource = (LPSTR)(LPCTSTR)cstrT;
	y.KeyIn(charSource, cstrT.GetLength());

	//AfxMessageBox((CString)charSource);
	LINT k;
	int len = _ttoi(editBitLen);
	do {
		k = GetOne(len - 5);
		LINT::GCD(k, pd1, gcd);
		//gcd.Display();
	} while (gcd != one_l);

	r = LINT::MQPower(g, k, p);
	
	memset(str, 0, sizeof str);
	r.Display(str);
	editR = str;

	temp = (m + pd1 - ((x % pd1) * (r % pd1)) % pd1) % pd1;
	LINT::Inv(k, pd1, gcd, invK);
	s = (temp * invK) % pd1;

	memset(str, 0, sizeof str);
	s.Display(str);
	editS = str;
	UpdateData(FALSE);
}


void CProblem5ELGamal����ǩ������Dlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//ǩ����֤
	UpdateData(TRUE);
	CString cstrT;
	char * charSource;

	cstrT = editP;
	charSource = (LPSTR)(LPCTSTR)cstrT;
	p.KeyIn(charSource, cstrT.GetLength());

	cstrT = editG;
	charSource = (LPSTR)(LPCTSTR)cstrT;
	g.KeyIn(charSource, cstrT.GetLength());

	cstrT = editX;
	charSource = (LPSTR)(LPCTSTR)cstrT;
	x.KeyIn(charSource, cstrT.GetLength());

	cstrT = editY;
	charSource = (LPSTR)(LPCTSTR)cstrT;
	y.KeyIn(charSource, cstrT.GetLength());

	cstrT = editR;
	charSource = (LPSTR)(LPCTSTR)cstrT;
	r.KeyIn(charSource, cstrT.GetLength());

	cstrT = editS;
	charSource = (LPSTR)(LPCTSTR)cstrT;
	s.KeyIn(charSource, cstrT.GetLength());

	LINT res = LINT::MQPower(y, r, p);
	res = (res * LINT::MQPower(r, s, p)) % p;
	res = (res + p - (LINT::MQPower(g, m, p) % p)) % p;

	if (res == nul_l)	
		AfxMessageBox(_T("��֤�ɹ���"));
	else
		AfxMessageBox(_T("��֤ʧ�ܣ�"));
}
