
// CClientDlg.h : ͷ�ļ�
//
#pragma once
#include "afxwin.h"


// CClientDlg �Ի���
class CClientDlg : public CDialogEx
{
// ����
public:
	CClientDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROBLEM1CLIENT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
