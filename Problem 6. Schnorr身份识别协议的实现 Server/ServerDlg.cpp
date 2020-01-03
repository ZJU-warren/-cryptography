
// ServerDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Problem 1. 网络聊天程序的设计与实现 Server.h"
#include "ServerDlg.h"
#include "afxdialogex.h"
#include <stdio.h>
#include <winsock2.h>
#include <iostream>
#include <cstdlib>
using namespace std;
#pragma comment(lib,"ws2_32.lib")


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

char strp[] = "94ee1a7eb3e4dcf5db880668fd7a5271833a30801ec5f00e86a0df4ed0c87fbed13a7c9c9bf21cfdabb2555f6aef1ab01053ae0196f0a94602b9b484ddb09633f326cbc6c56d6e1d101abe054ff454ec5d3b677292efa0abac30d7d8607dce1dfa8a85cd6511d9a9b889273b1b8b39c34e4469b21472d31932c0e17d89";
char strq[] = "9e457362ff32d61174557ece46cba4acdf6342df";
char strg[] = "2ac5c7414fe0a81437044d5054447b9a46376bd110ee5a9db837758a08fb6902db1be84e9b228fe050209631a0c5a24ace5a28b21bcb10ab825627486c542f757231d7b30a01a09731d8cbe5428c28a4b3f61605e18e483ade693954060b7e36c5c411b0b8bff2e909098d26af786bd89d13b1a1f3666c151101315070";
char strx[] = "89013b2df641793794134e3fb59c89419985f916";
char stry[] = "a3dcdb147da00ecf71adca38a573403b1c3049de23f0782c3ddd96ed3676a7f832d213794dda3aee0ac045ef31568217bdc4cca4e38b201f48a41dc6ae0bfb036e7d159818c48d01e0538f6b92008b75ff54509b7d2799a8392841a9ea59e17bdd0b8ecafdcd0ea4558ccf1beef09119f12fad673a15ca4fb4f82d307";
LINT E, N;
LINT p, a;
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


// CServerDlg 对话框



CServerDlg::CServerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PROBLEM1SERVER_DIALOG, pParent)
	, editKeyIn(_T(""))
	, editShow(_T(""))
	, editVerifyN(_T("8c81a27167e0a69b96a56ef948223b7774b2fc073657a965ae3db8ded2654e3a289dbc1acb7bc0b5c32e917f2728a3d2a357"))
	, editVerifyE(_T("7ed915980b11e502fc2f72d716ddc1c0aec6fa96f8f6b8be25f9ab82c2f0f421b46d21d538bf1c0c2a1d742fb80166e27d0d"))
	, editA(_T("002ac5c7414fe0a81437044d5054447b9a46376bd110ee5a9db837758a08fb6902db1be84e9b228fe050209631a0c5a24ace5a28b21bcb10ab825627486c542f757231d7b30a01a09731d8cbe5428c28a4b3f61605e18e483ade693954060b7e36c5c411b0b8bff2e909098d26af786bd89d13b1a1f3666c151101315070"))
	, editP(_T("0094ee1a7eb3e4dcf5db880668fd7a5271833a30801ec5f00e86a0df4ed0c87fbed13a7c9c9bf21cfdabb2555f6aef1ab01053ae0196f0a94602b9b484ddb09633f326cbc6c56d6e1d101abe054ff454ec5d3b677292efa0abac30d7d8607dce1dfa8a85cd6511d9a9b889273b1b8b39c34e4469b21472d31932c0e17d89"))
	, editT(_T("139"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_WRITE, editKeyIn);
	DDX_Text(pDX, IDC_EDIT_SHOW, editShow);
	DDX_Text(pDX, IDC_EDIT1, editVerifyN);
	DDX_Text(pDX, IDC_EDIT2, editVerifyE);

	DDX_Text(pDX, IDC_EDIT3, editA);
	DDX_Text(pDX, IDC_EDIT5, editP);
	DDX_Text(pDX, IDC_EDIT6, editT);
	DDX_Control(pDX, IDC_EDIT_SHOW, editCtShow);
}

BEGIN_MESSAGE_MAP(CServerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_SEND, &CServerDlg::OnBnClickedButtonSend)
END_MESSAGE_MAP()


// CServerDlg 消息处理程序

BOOL CServerDlg::OnInitDialog()
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
	//srand((USHORT)time(0));
	Main();
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CServerDlg::OnPaint()
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
HCURSOR CServerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

/********************************************************************************************************************************************************************/
BOOL CServerDlg::PreTranslateMessage(MSG* pMsg){
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN) {
		CServerDlg::OnBnClickedButtonSend();
		return TRUE;
	}
	else
		return CDialog::PreTranslateMessage(pMsg);
}


#define MAX_LEN 5000

HANDLE sendEvent;
char *sendBuf;
SOCKET sClient,slisten;
int State = 0;
bool verify = 0;
USHORT securityT = 7;

char charSource[MAX_LEN];
int CServerDlg::Main() {
	//初始化WSA
	WORD sockVersion = MAKEWORD(2, 2);
	/*  WORD类型 是两个字节。作为数值类型，这两个字节在内存中是逆序保存的，高位在后，低位在前。低字，指的就是低位字节。*/
	WSADATA wsaData;
	int errorCode;
	if (errorCode = WSAStartup(sockVersion, &wsaData))
		return errorCode;
	//创建套接字
	slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (slisten == INVALID_SOCKET) {
		editShow += (CString)"socket error !" + (CString)"\r\n";
		UpdateData(FALSE);
		return 0;
	}
	//绑定IP和端口
	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(8888);
	sin.sin_addr.S_un.S_addr = INADDR_ANY;
	//	INADDR_ANY就是指定地址为0.0.0.0的地址，这个地址事实上表示不确定地址，或“所有地址”、“任意地址”。
	if (bind(slisten, (LPSOCKADDR)&sin, sizeof(sin)) == INVALID_SOCKET) {
		editShow += (CString)"bind error !" + (CString)"\r\n";
		UpdateData(FALSE);
	}
	//开始监听
	if (listen(slisten, 5) == SOCKET_ERROR)
	{
		editShow += (CString)"listen error !" + (CString)"\r\n";
		UpdateData(FALSE);
		return 0;
	}
	
	CServerDlg *pRecvParam = this;
	HANDLE lThread = CreateThread(NULL, 0, Link, pRecvParam, 0, NULL);
	CloseHandle(lThread);
	UpdateData(TRUE);
	N.KeyIn((LPSTR)(LPCTSTR)editVerifyN, editVerifyN.GetLength());
	E.KeyIn((LPSTR)(LPCTSTR)editVerifyE, editVerifyE.GetLength());
	a.KeyIn((LPSTR)(LPCTSTR)editA, editA.GetLength());
	p.KeyIn((LPSTR)(LPCTSTR)editP, editP.GetLength());
	t = _ttoi(editT);
	//closesocket(slisten);
	//WSACleanup();	/* 终止Winsock 2 DLL (Ws2_32.dll) 的使用 */
	return 0;
}
DWORD WINAPI  CServerDlg::Link(LPVOID lpParameter){
	sockaddr_in remoteAddr;
	int nAddrlen = sizeof(remoteAddr);
	CServerDlg * user = (CServerDlg*)lpParameter;
	int cnt = 0;
	char strCnt[10];
	while (true) {
		user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
		sClient = accept(slisten, (SOCKADDR *)&remoteAddr, &nAddrlen);
		++cnt;
		sprintf_s(strCnt, "%d", cnt);
		State = 1;
		user->editShow += (CString)"连接成功：" + (CString)inet_ntoa(remoteAddr.sin_addr) + (CString)"\r\n";
		user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
		//创建收线程
		CServerDlg *pRecvParam = user;
		HANDLE rThread = CreateThread(NULL, 0, SockRecv, pRecvParam, 0, NULL);
		CloseHandle(rThread);
	}
}


void CServerDlg::OnBnClickedButtonSend()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	sendBuf = (LPSTR)(LPCSTR)editKeyIn;
	UpdateData(FALSE);
	if(State)
		SockSend();
	editKeyIn = "";
	UpdateData(FALSE);
	editCtShow.LineScroll(editCtShow.GetLineCount());
}

void CServerDlg::SockSend()
{
	if (!verify) {
		editShow += (CString)"对方身份未核实!" + (CString)"\r\n";
		UpdateData(FALSE);
	}
	else if (State) {
		DWORD sendSize;
		sendSize = send(sClient, sendBuf, strlen(sendBuf), 0);
		editShow += (CString)sendBuf + (CString)"\r\n";
		UpdateData(FALSE);
		memset(sendBuf, 0, sendSize);
	}
	editCtShow.LineScroll(editCtShow.GetLineCount());
};
int timesForSock = 1;
DWORD WINAPI  CServerDlg::SockRecv(LPVOID lpParameter)
{
	srand(USHORT(time(0) + ++timesForSock));
	verify = false;
	CServerDlg * user = (CServerDlg*)lpParameter;
	char recvBuf[MAX_LEN];
	int recvSize;			// error  DWORD 因为 recv返回 int 范围 > DWORD 正溢
	LINT  isSuss, valSuss;
	/*s1*/
	valSuss = 0xff11;
	LINT m, sigm;
	bool flag1 = false;
	int cnt1 = 0;
	/*s2*/
	LINT  y, x, s, gcd,e;
	bool flag2 = false;

	/*s3*/
	//LINT  y, x, s, gcd;
	bool flag3 = false;
	int cnt3 = 0;
	/*	第一阶段：(m, sigm)	*/
	do{
		++timesForSock;
		user->editShow += (CString)"________________第1阶段：签名__________________________" + (CString)"\r\n";
		user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);

		/* recv m */
		//recv
		memset(recvBuf, 0, sizeof(recvBuf));
		recvSize = recv(sClient, recvBuf, sizeof(recvBuf), 0);
		m.KeyIn(recvBuf, strlen(recvBuf));
		user->editShow += (CString)"V : 接收到 m: " + (CString)recvBuf + (CString)"\r\n";
		user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);

		//conform
		valSuss.Display(charSource);
		sendBuf = charSource;
		send(sClient, sendBuf, strlen(sendBuf), 0);
		user->editShow += (CString)"V : 回复已成功接收到 m" + (CString)"\r\n";
		user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
		
		/* recv sigm */
		//recv
		memset(recvBuf, 0, sizeof(recvBuf));
		recvSize = recv(sClient, recvBuf, sizeof(recvBuf), 0);
		sigm.KeyIn(recvBuf, strlen(recvBuf));
		user->editShow += (CString)"V : 接收到 sig(m): " + (CString)recvBuf + (CString)"\r\n";
		user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
		
		//verify (m,sig(m))
		
		if (LINT::MQPower(sigm, E, N) == m) { //sigm^e % N
			user->editShow += (CString)"V : 签名验证成功" + (CString)"\r\n";
			valSuss.Display(charSource);
			flag1 = true;
		}
		else {
			user->editShow += (CString)"V : 签名验证失败" + (CString)"\r\n";
			((LINT)nul_l).Display(charSource);
		}
		user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
		sendBuf = charSource;
		send(sClient, sendBuf, strlen(sendBuf), 0);
		//user->editShow += (CString)"V : 回复验证结果" + (CString)"\r\n";
		//user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);

		user->editCtShow.LineScroll(user->editCtShow.GetLineCount());
		if (++cnt1 > 3) {
			user->editShow += (CString)"三次验证失败，断开与客户连接" + (CString)"\r\n";
			user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
			user->editCtShow.LineScroll(user->editCtShow.GetLineCount());
			goto Myend;
		}
	} while (!flag1);

	/*	第二阶段：请求与挑战	*/
	do {
		++timesForSock;
		user->editShow += (CString)"________________第2阶段：请求与挑战____________________" + (CString)"\r\n";
		user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
		//recv x
		memset(recvBuf, 0, sizeof(recvBuf));
		recvSize = recv(sClient, recvBuf, sizeof(recvBuf), 0);
		x.KeyIn(recvBuf, strlen(recvBuf));
		user->editShow += (CString)"V : 接收到 x: " + (CString)recvBuf + (CString)"\r\n";
		user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
		/* e生成  1 < e < 2^t */
		LINT  et;
		e = one_l;
		et = GetOne(t);
		if (e < et)	e = et;
		//send e
		e.Display(charSource);
		sendBuf = charSource;
		user->editShow += (CString)"V : 挑战 e: " + (CString)charSource + (CString)"\r\n";
		send(sClient, sendBuf, strlen(sendBuf), 0);
		user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
		flag2 = true;
		user->editCtShow.LineScroll(user->editCtShow.GetLineCount());
	} while (!flag2);

	/*	第三阶段：应答与验证*/
	do {
		++timesForSock;
		user->editShow += (CString)"________________第3阶段：请求与挑战____________________" + (CString)"\r\n";
		user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
		//recv s
		memset(recvBuf, 0, sizeof(recvBuf));
		recvSize = recv(sClient, recvBuf, sizeof(recvBuf), 0);
		s.KeyIn(recvBuf, strlen(recvBuf));
		user->editShow += (CString)"V : 接收到 s: " + (CString)recvBuf + (CString)"\r\n";
		user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);

		//verify (s)
		/*	验证		*/
		LINT::Inv(LINT::MQPower(a, x, p), p, gcd, y);
		LINT t1 = LINT::MQPower(a, s, p);
		LINT t2 = LINT::MQPower(y, e, p);
		LINT res = (t1 * t2) % p - x;
		//res.Display();
		if (res == nul_l) {
			user->editShow += (CString)"V : 身份验证成功" + (CString)"\r\n";
			valSuss.Display(charSource);
			flag3 = true;
		}
		else {
			user->editShow += (CString)"V : 身份验证失败" + (CString)"\r\n";
			((LINT)nul_l).Display(charSource);
		}
		user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
		sendBuf = charSource;
		send(sClient, sendBuf, strlen(sendBuf), 0);
		//user->editShow += (CString)"V : 回复验证结果" + (CString)"\r\n";
		//user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
		user->editCtShow.LineScroll(user->editCtShow.GetLineCount());
		if (++cnt3 > 3) {
			user->editShow += (CString)"三次身份验证失败，断开与客户连接" + (CString)"\r\n";
			user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
			user->editCtShow.LineScroll(user->editCtShow.GetLineCount());
			goto Myend;
		}
		
	} while (!flag3);
	verify = true;

	while (verify && State)
	{
		//把接受的数据显示出来
		memset(recvBuf, 0, sizeof(recvBuf));
		recvSize = recv(sClient, recvBuf, sizeof(recvBuf), 0);
		if (recvSize > 0) {
			user->editShow += (CString)recvBuf + (CString)"\r\n";
			user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
			user->editCtShow.LineScroll(user->editCtShow.GetLineCount());
			memset(recvBuf, 0, recvSize);
		}
		if (recvSize <= 0) {
			State = 0;
			verify = false;
			break;
		}
	}
Myend:
	verify = false;
	closesocket(sClient);
	user->editShow += (CString)"SockRecv End\r\n";
	user->GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(user->editShow);
	user->editCtShow.LineScroll(user->editCtShow.GetLineCount());
	return TRUE;
};

/********************************************************************************************************************************************************************/