
// Problem 2. MD5��ʵ��Dlg.h : ͷ�ļ�
//

#pragma once


// CProblem2MD5��ʵ��Dlg �Ի���
class CProblem2MD5��ʵ��Dlg : public CDialogEx
{
// ����
public:
	CProblem2MD5��ʵ��Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROBLEM2MD5_DIALOG };
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
public:
	CString editShow;
	CString editRes;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
};
