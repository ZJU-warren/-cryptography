
// ServerDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CServerDlg �Ի���
class CServerDlg : public CDialogEx
{
// ����
public:
	CServerDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROBLEM1SERVER_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// Overrides
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
