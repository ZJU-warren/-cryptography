
// CClientDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Problem 1. 网络聊天程序的设计与实现 Client.h"
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


// CClientDlg 对话框



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


// CClientDlg 消息处理程序

BOOL CClientDlg::OnInitDialog()
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CClientDlg::OnPaint()
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
	// TODO: 在此添加控件通知处理程序代码
	Link();
}

void CClientDlg::OnBnClickedButtonDisable()
{
	// TODO: 在此添加控件通知处理程序代码
	UnLink();
}
bool verify = false;
void CClientDlg::OnBnClickedButtonSend()
{
	// TODO: 在此添加控件通知处理程序代码
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
		editShow += (CString)("尚未验证成功") + (CString)"\r\n";
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
	editShow += (CString)"连接成功："+(CString)inet_ntoa(serAddr.sin_addr) + (CString)"\r\n";
	UpdateData(FALSE);
	//创建收线程
	CClientDlg *pRecvParam = this; 
	HANDLE rThread = CreateThread(NULL, 0, CClientDlg::SockRecv, (LPVOID)pRecvParam, 0, NULL);
	CloseHandle(rThread);
}

void CClientDlg::UnLink() {
	closesocket(sClient);
	editShow += (CString)"断开连接\r\n";
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
	/*	第一阶段：(m, sigm)	*/
	do{
		++timesForSock;
		user->editShow += (CString)"________________第1阶段：签名__________________________" + (CString)"\r\n";
		user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
		/* send m */
		m =  GetOne(40);					//生成m
		sigm = LINT::MQPower(m, D, N);	//mv = m^d % N
		//send
		m.Display(charSource);
		sendBuf = charSource;
		user->editShow += (CString)"P : 发送 m: " + (CString)charSource + (CString)"\r\n";
		user->SockSend();
		user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
		//conform
		memset(recvBuf, 0, sizeof(recvBuf));
		recvSize = recv(sClient, recvBuf, sizeof(recvBuf), 0);
		isSuss.KeyIn(recvBuf, strlen(recvBuf));
		if (isSuss == valSuss) {
			user->editShow += (CString)"P : 对方成功接收 m" + (CString)"\r\n";
			user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
		}
		/* send sigm */
		sigm.Display(charSource);
		sendBuf = charSource;
		user->editShow += (CString)"P : 发送 sig(m):" + (CString)charSource + (CString)"\r\n";
		user->SockSend();
		user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
		
		//conform
		memset(recvBuf, 0, sizeof(recvBuf));
		recvSize = recv(sClient, recvBuf, sizeof(recvBuf), 0);
		isSuss.KeyIn(recvBuf, strlen(recvBuf));
		if (isSuss == valSuss) {
			user->editShow += (CString)"P : 对方验证(m,sig(m))成功" + (CString)"\r\n";
			user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
			flag1 = true;
		}
		else {
			user->editShow += (CString)"P : 对方验证(m,sig(m))失败" + (CString)"\r\n";
			user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
		}

		user->editCtShow.LineScroll(user->editCtShow.GetLineCount());
		if (++cnt1 > 3) {
			user->editShow += (CString)"三次验证失败，断开与服务器连接" + (CString)"\r\n";
			user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
			user->editCtShow.LineScroll(user->editCtShow.GetLineCount());
			goto Myend;
		}
	} while (!flag1);
	/*	第二阶段：请求与挑战*/
	do {
		++timesForSock;
		user->editShow += (CString)"________________第2阶段：请求与挑战____________________" + (CString)"\r\n";
		user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
		/* r、x生成  x = a^r % p */
		r = (Produce(q.val[0] * 8) % (q - one_l) + one_l);
		x = LINT::MQPower(a, r, p);
		//send x
		x.Display(charSource);
		sendBuf = charSource;
		user->editShow += (CString)"P : 请求 x: " + (CString)charSource + (CString)"\r\n";
		user->SockSend();
		user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
		//recv e
		memset(recvBuf, 0, sizeof(recvBuf));
		recvSize = recv(sClient, recvBuf, sizeof(recvBuf), 0);
		e.KeyIn(recvBuf, strlen(recvBuf));
		user->editShow += (CString)"P : 接收到 e: " + (CString)recvBuf + (CString)"\r\n";
		user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
		flag2 = true;
		user->editCtShow.LineScroll(user->editCtShow.GetLineCount());
	} while (!flag2);
	/*	第三阶段：应答与验证*/
	do {
		++timesForSock;
		user->editShow += (CString)"________________第3阶段：请求与挑战____________________" + (CString)"\r\n";
		user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
		s = (r + (x % q) * (e % q)) % q;
		//send s
		s.Display(charSource);
		sendBuf = charSource;
		user->editShow += (CString)"P : 应答 s: " + (CString)charSource + (CString)"\r\n";
		send(sClient, sendBuf, strlen(sendBuf), 0);
		user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);

		//conform
		memset(recvBuf, 0, sizeof(recvBuf));
		recvSize = recv(sClient, recvBuf, sizeof(recvBuf), 0);
		isSuss.KeyIn(recvBuf, strlen(recvBuf));
		if (isSuss == valSuss) {
			user->editShow += (CString)"P : 对方验证成功" + (CString)"\r\n";
			user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
			flag3 = true;
		}
		else {
			user->editShow += (CString)"P : 对方验证失败" + (CString)"\r\n";
			user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
		}

		user->editCtShow.LineScroll(user->editCtShow.GetLineCount());
		if (++cnt1 > 3) {
			user->editShow += (CString)"三次验证失败，断开与服务器连接" + (CString)"\r\n";
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
用户界面线程和工作者线程都是由AfxBeginThread创建的。现在，考察该函数：MFC提供了两个重载版的AfxBeginThread，一个用于用户界面线程，另一个用于工作者线程，分别有如下的原型和过程：
用户界面线程的AfxBeginThread
用户界面线程的AfxBeginThread的原型如下：
CWinThread* AFXAPI AfxBeginThread(
	CRuntimeClass* pThreadClass,
	int nPriority,
	UINT nStackSize,
	DWORD dwCreateFlags,
	LPSECURITY_ATTRIBUTES lpSecurityAttrs)
	其中：
	参数1是从CWinThread派生的RUNTIME_CLASS类；
	参数2指定线程优先级，如果为0，则与创建该线程的线程相同；
	参数3指定线程的堆栈大小，如果为0，则与创建该线程的线程相同；
	参数4是一个创建标识，如果是CREATE_SUSPENDED，则在悬挂状态创建线程，在线程创建后线程挂起，否则线程在创建后开始线程的执行。
	参数5表示线程的安全属性，NT下有用。

	工作者线程的AfxBeginThread
	工作者线程的AfxBeginThread的原型如下：
	CWinThread* AFXAPI AfxBeginThread(
		AFX_THREADPROC pfnThreadProc,
		LPVOID pParam,
		int nPriority,
		UINT nStackSize,
		DWORD dwCreateFlags,
		LPSECURITY_ATTRIBUTES lpSecurityAttrs)
	其中：
	参数1  线程的入口函数, 声明一定要如下: UINT MyThreadFunction(LPVOID pParam);
参数2 传递入线程的参数, 注意它的类型为:LPVOID, 所以我们可以传递一个结构体入线程.
参数3、4、5分别指定线程的优先级、堆栈大小、创建标识、安全属性，含义同用户界面线程。
*/