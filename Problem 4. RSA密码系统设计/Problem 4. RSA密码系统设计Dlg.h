
// Problem 4. RSA����ϵͳ���Dlg.h : ͷ�ļ�
//

#pragma once


// CProblem4RSA����ϵͳ���Dlg �Ի���
class CProblem4RSA����ϵͳ���Dlg : public CDialogEx
{
// ����
public:
	CProblem4RSA����ϵͳ���Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROBLEM4RSA_DIALOG };
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
	CString editContent;
	CString editResult;
	CString editEKey;
	CString editDKey;
	CString editN;
	CString editE;
	CString editP;
	CString editQ;
	CString editD;
	CString editBitLen;
	afx_msg void OnBnClickedButton5();
	CString editUsedN;
	afx_msg void OnBnClickedButton6();



	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton1();
};
