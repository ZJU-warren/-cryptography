
// CClientDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Problem 1. �����������������ʵ�� Client.h"
#include "CClientDlg.h"
#include "afxdialogex.h"

#include <stdio.h>
#include <winsock2.h>
#include <iostream>
#pragma comment(lib,"ws2_32.lib")

using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

LINT D, N;
LINT p, a, q;
int t;


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


// CClientDlg �Ի���



CClientDlg::CClientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PROBLEM1CLIENT_DIALOG, pParent)
	, editKeyIn(_T(""))
	, editShow(_T(""))
	, editN(_T("8c81a27167e0a69b96a56ef948223b7774b2fc073657a965ae3db8ded2654e3a289dbc1acb7bc0b5c32e917f2728a3d2a357"))
	, editD(_T("764438310bc7047549eb016e272f48cc4f102b9a1eb121db5ad47db915f12ffb4c943bbd234455a03ca426ee1f8c57646c55"))
	, editP(_T("0094ee1a7eb3e4dcf5db880668fd7a5271833a30801ec5f00e86a0df4ed0c87fbed13a7c9c9bf21cfdabb2555f6aef1ab01053ae0196f0a94602b9b484ddb09633f326cbc6c56d6e1d101abe054ff454ec5d3b677292efa0abac30d7d8607dce1dfa8a85cd6511d9a9b889273b1b8b39c34e4469b21472d31932c0e17d89"))
	, editQ(_T("9e457362ff32d61174557ece46cba4acdf6342df"))
	, editA(_T("002ac5c7414fe0a81437044d5054447b9a46376bd110ee5a9db837758a08fb6902db1be84e9b228fe050209631a0c5a24ace5a28b21bcb10ab825627486c542f757231d7b30a01a09731d8cbe5428c28a4b3f61605e18e483ade693954060b7e36c5c411b0b8bff2e909098d26af786bd89d13b1a1f3666c151101315070"))
	, editT(_T("139"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT_KEY_IN, editKeyIn);
	DDX_Text(pDX, IDC_EDIT_SHOW, editShow);
	DDX_Text(pDX, IDC_EDIT4, editN);
	DDX_Text(pDX, IDC_EDIT5, editD);
	DDX_Text(pDX, IDC_EDIT1, editP);
	DDX_Text(pDX, IDC_EDIT2, editQ);
	DDX_Text(pDX, IDC_EDIT3, editA);
	DDX_Text(pDX, IDC_EDIT6, editT);
	DDX_Control(pDX, IDC_EDIT_SHOW, editCtShow);
}

BEGIN_MESSAGE_MAP(CClientDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_LINK, &CClientDlg::OnBnClickedButtonLink)
	ON_BN_CLICKED(IDC_BUTTON_SEND, &CClientDlg::OnBnClickedButtonSend)
	ON_BN_CLICKED(IDC_BUTTON_DISABLE, &CClientDlg::OnBnClickedButtonDisable)
	ON_BN_CLICKED(IDC_BUTTON_LINK, &CClientDlg::OnBnClickedButtonLink)
	ON_BN_CLICKED(IDC_BUTTON_DISABLE, &CClientDlg::OnBnClickedButtonDisable)
	ON_BN_CLICKED(IDC_BUTTON_SEND, &CClientDlg::OnBnClickedButtonSend)
END_MESSAGE_MAP()


// CClientDlg ��Ϣ�������

BOOL CClientDlg::OnInitDialog()
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

void CClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CClientDlg::OnPaint()
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
HCURSOR CClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


/********************************************************************************************************************************************************************/


BOOL CClientDlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN) {
		CClientDlg::OnBnClickedButtonSend();
		return TRUE;
	}
	else
		return CDialog::PreTranslateMessage(pMsg);
}

#define MAX_LEN 5000
HANDLE sendEvent;
char * sendBuf;
SOCKET sClient;

void CClientDlg::OnBnClickedButtonLink()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Link();
}

void CClientDlg::OnBnClickedButtonDisable()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UnLink();
}
bool verify = false;
void CClientDlg::OnBnClickedButtonSend()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (verify) {
		UpdateData(TRUE);
		sendBuf = (LPSTR)(LPCSTR)editKeyIn;
		editShow += (CString)(sendBuf)+(CString)"\r\n";
		UpdateData(FALSE);
		SockSend();
		editKeyIn = "";
		UpdateData(FALSE);
	}
	else {
		editShow += (CString)("��δ��֤�ɹ�") + (CString)"\r\n";
		UpdateData(FALSE);
	}
	editCtShow.LineScroll(editCtShow.GetLineCount());
}





void CClientDlg::Link()
{
	
	UpdateData(TRUE);
	N.KeyIn((LPSTR)(LPCTSTR)editN, editN.GetLength());
	D.KeyIn((LPSTR)(LPCTSTR)editD, editD.GetLength());
	a.KeyIn((LPSTR)(LPCTSTR)editA, editA.GetLength());
	q.KeyIn((LPSTR)(LPCTSTR)editQ, editQ.GetLength());
	p.KeyIn((LPSTR)(LPCTSTR)editP, editP.GetLength());
	t = _ttoi(editT);
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA data;
	if (WSAStartup(sockVersion, &data) != 0) {
		return;
	}

	sClient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sClient == INVALID_SOCKET) {
		editShow += (CString)"invalid socket !" + (CString)"\r\n";
		UpdateData(FALSE);
		return;
	}

	sockaddr_in serAddr;
	serAddr.sin_family = AF_INET;
	serAddr.sin_port = htons(8888);
	serAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	if (connect(sClient, (sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR) {
		editShow += (CString)"connect error !" + (CString)"\r\n";
		UpdateData(FALSE);
		closesocket(sClient);
		return;
	}
	editShow += (CString)"���ӳɹ���"+(CString)inet_ntoa(serAddr.sin_addr) + (CString)"\r\n";
	UpdateData(FALSE);
	//�������߳�
	CClientDlg *pRecvParam = this; 
	HANDLE rThread = CreateThread(NULL, 0, CClientDlg::SockRecv, (LPVOID)pRecvParam, 0, NULL);
	CloseHandle(rThread);
}

void CClientDlg::UnLink() {
	closesocket(sClient);
	editShow += (CString)"�Ͽ�����\r\n";
	UpdateData(FALSE);
	WSACleanup();
}
LINT r, x, gcd, y, e;
char charSource[MAX_LEN];

void CClientDlg::SockSend()
{
	DWORD sendSize;
	sendSize = send(sClient, sendBuf, strlen(sendBuf), 0);
	memset(sendBuf, 0, sendSize);
};
int timesForSock = 1;
DWORD WINAPI CClientDlg::SockRecv(LPVOID lpParameter)
{
	srand(USHORT(time(0) + ++timesForSock));
	verify = false;
	CClientDlg * user = (CClientDlg*)lpParameter;
	char recvBuf[MAX_LEN];
	int recvSize;
	LINT  isSuss, valSuss;
	valSuss = 0xff11;
	/*s1*/
	LINT m, sigm;
	bool flag1 = false;
	int cnt1 = 0;
	/*s2*/
	LINT r, x, gcd, y, e;
	bool flag2 = false;
	/*s3*/
	LINT s;
	bool flag3 = false;
	int cnt3 = 0;
	/*	��һ�׶Σ�(m, sigm)	*/
	do{
		++timesForSock;
		user->editShow += (CString)"________________��1�׶Σ�ǩ��__________________________" + (CString)"\r\n";
		user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
		/* send m */
		m =  GetOne(40);					//����m
		sigm = LINT::MQPower(m, D, N);	//mv = m^d % N
		//send
		m.Display(charSource);
		sendBuf = charSource;
		user->editShow += (CString)"P : ���� m: " + (CString)charSource + (CString)"\r\n";
		user->SockSend();
		user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
		//conform
		memset(recvBuf, 0, sizeof(recvBuf));
		recvSize = recv(sClient, recvBuf, sizeof(recvBuf), 0);
		isSuss.KeyIn(recvBuf, strlen(recvBuf));
		if (isSuss == valSuss) {
			user->editShow += (CString)"P : �Է��ɹ����� m" + (CString)"\r\n";
			user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
		}
		/* send sigm */
		sigm.Display(charSource);
		sendBuf = charSource;
		user->editShow += (CString)"P : ���� sig(m):" + (CString)charSource + (CString)"\r\n";
		user->SockSend();
		user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
		
		//conform
		memset(recvBuf, 0, sizeof(recvBuf));
		recvSize = recv(sClient, recvBuf, sizeof(recvBuf), 0);
		isSuss.KeyIn(recvBuf, strlen(recvBuf));
		if (isSuss == valSuss) {
			user->editShow += (CString)"P : �Է���֤(m,sig(m))�ɹ�" + (CString)"\r\n";
			user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
			flag1 = true;
		}
		else {
			user->editShow += (CString)"P : �Է���֤(m,sig(m))ʧ��" + (CString)"\r\n";
			user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
		}

		user->editCtShow.LineScroll(user->editCtShow.GetLineCount());
		if (++cnt1 > 3) {
			user->editShow += (CString)"������֤ʧ�ܣ��Ͽ������������" + (CString)"\r\n";
			user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
			user->editCtShow.LineScroll(user->editCtShow.GetLineCount());
			goto Myend;
		}
	} while (!flag1);
	/*	�ڶ��׶Σ���������ս*/
	do {
		++timesForSock;
		user->editShow += (CString)"________________��2�׶Σ���������ս____________________" + (CString)"\r\n";
		user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
		/* r��x����  x = a^r % p */
		r = (Produce(q.val[0] * 8) % (q - one_l) + one_l);
		x = LINT::MQPower(a, r, p);
		//send x
		x.Display(charSource);
		sendBuf = charSource;
		user->editShow += (CString)"P : ���� x: " + (CString)charSource + (CString)"\r\n";
		user->SockSend();
		user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
		//recv e
		memset(recvBuf, 0, sizeof(recvBuf));
		recvSize = recv(sClient, recvBuf, sizeof(recvBuf), 0);
		e.KeyIn(recvBuf, strlen(recvBuf));
		user->editShow += (CString)"P : ���յ� e: " + (CString)recvBuf + (CString)"\r\n";
		user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
		flag2 = true;
		user->editCtShow.LineScroll(user->editCtShow.GetLineCount());
	} while (!flag2);
	/*	�����׶Σ�Ӧ������֤*/
	do {
		++timesForSock;
		user->editShow += (CString)"________________��3�׶Σ���������ս____________________" + (CString)"\r\n";
		user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
		s = (r + (x % q) * (e % q)) % q;
		//send s
		s.Display(charSource);
		sendBuf = charSource;
		user->editShow += (CString)"P : Ӧ�� s: " + (CString)charSource + (CString)"\r\n";
		send(sClient, sendBuf, strlen(sendBuf), 0);
		user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);

		//conform
		memset(recvBuf, 0, sizeof(recvBuf));
		recvSize = recv(sClient, recvBuf, sizeof(recvBuf), 0);
		isSuss.KeyIn(recvBuf, strlen(recvBuf));
		if (isSuss == valSuss) {
			user->editShow += (CString)"P : �Է���֤�ɹ�" + (CString)"\r\n";
			user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
			flag3 = true;
		}
		else {
			user->editShow += (CString)"P : �Է���֤ʧ��" + (CString)"\r\n";
			user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
		}

		user->editCtShow.LineScroll(user->editCtShow.GetLineCount());
		if (++cnt1 > 3) {
			user->editShow += (CString)"������֤ʧ�ܣ��Ͽ������������" + (CString)"\r\n";
			user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
			user->editCtShow.LineScroll(user->editCtShow.GetLineCount());
			goto Myend;
		}

	} while (!flag3);
	verify = true;

	while (verify) {
		memset(recvBuf, 0, sizeof(recvBuf));
		recvSize = recv(sClient, recvBuf, sizeof(recvBuf), 0);
		if (recvSize > 0) {
			user->editShow += (CString)recvBuf + (CString)"\r\n";
			user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
			user->editCtShow.LineScroll(user->editCtShow.GetLineCount());
			memset(recvBuf, 0, sizeof(recvBuf));
		}
		if (recvSize == SOCKET_ERROR)
			break;
	}
Myend:

	verify = false;
	user->editShow += (CString)"SockRecv End\r\n";
	user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
	user->editCtShow.LineScroll(user->editCtShow.GetLineCount());
	return TRUE;
};

/*
AfxBeginThread
�û������̺߳͹������̶߳�����AfxBeginThread�����ġ����ڣ�����ú�����MFC�ṩ���������ذ��AfxBeginThread��һ�������û������̣߳���һ�����ڹ������̣߳��ֱ������µ�ԭ�ͺ͹��̣�
�û������̵߳�AfxBeginThread
�û������̵߳�AfxBeginThread��ԭ�����£�
CWinThread* AFXAPI AfxBeginThread(
	CRuntimeClass* pThreadClass,
	int nPriority,
	UINT nStackSize,
	DWORD dwCreateFlags,
	LPSECURITY_ATTRIBUTES lpSecurityAttrs)
	���У�
	����1�Ǵ�CWinThread������RUNTIME_CLASS�ࣻ
	����2ָ���߳����ȼ������Ϊ0�����봴�����̵߳��߳���ͬ��
	����3ָ���̵߳Ķ�ջ��С�����Ϊ0�����봴�����̵߳��߳���ͬ��
	����4��һ��������ʶ�������CREATE_SUSPENDED����������״̬�����̣߳����̴߳������̹߳��𣬷����߳��ڴ�����ʼ�̵߳�ִ�С�
	����5��ʾ�̵߳İ�ȫ���ԣ�NT�����á�

	�������̵߳�AfxBeginThread
	�������̵߳�AfxBeginThread��ԭ�����£�
	CWinThread* AFXAPI AfxBeginThread(
		AFX_THREADPROC pfnThreadProc,
		LPVOID pParam,
		int nPriority,
		UINT nStackSize,
		DWORD dwCreateFlags,
		LPSECURITY_ATTRIBUTES lpSecurityAttrs)
	���У�
	����1  �̵߳���ں���, ����һ��Ҫ����: UINT MyThreadFunction(LPVOID pParam);
����2 �������̵߳Ĳ���, ע����������Ϊ:LPVOID, �������ǿ��Դ���һ���ṹ�����߳�.
����3��4��5�ֱ�ָ���̵߳����ȼ�����ջ��С��������ʶ����ȫ���ԣ�����ͬ�û������̡߳�
*/