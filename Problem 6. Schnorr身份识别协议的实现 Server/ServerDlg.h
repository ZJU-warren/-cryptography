
// ServerDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CServerDlg 对话框
class CServerDlg : public CDialogEx
{
// 构造
public:
	CServerDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROBLEM1SERVER_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// Overrides
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	CBrush m_brMine;
	COLORREF m_BlackColor;
	COLORREF m_TextColor;

public:
	CString editKeyIn;
	CString editShow;
	afx_msg void OnBnClickedButtonSend();
	static DWORD WINAPI SockRecv(LPVOID lpParameter);
	static DWORD WINAPI Link(LPVOID lpParameter);
	void SockSend();
	int Main();
	CString editVerifyN;
	CString editVerifyE;
	CString editA;
	CString editP;
	CString editT;
	CEdit editCtShow;
};
