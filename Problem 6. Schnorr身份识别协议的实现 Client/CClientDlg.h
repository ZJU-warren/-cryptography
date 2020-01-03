
// CClientDlg.h : 头文件
//
#pragma once
#include "afxwin.h"


// CClientDlg 对话框
class CClientDlg : public CDialogEx
{
// 构造
public:
	CClientDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROBLEM1CLIENT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

// Overrides
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);

public:
	afx_msg void OnBnClickedButtonLink();
	afx_msg void OnBnClickedButtonDisable();
	afx_msg void OnBnClickedButtonSend();
	CString editKeyIn;
	CString editShow;
	void SockSend();
	static DWORD WINAPI SockRecv(LPVOID lpParameter);
	void Link();
	void UnLink();
	CString editN;
	CString editD;
	CString editP;
	CString editQ;
	CString editA;
	CString editT;
	CEdit editCtShow;
};
