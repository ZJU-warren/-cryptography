
// Problem 5. ELGamal����ǩ������Dlg.h : ͷ�ļ�
//

#pragma once


// CProblem5ELGamal����ǩ������Dlg �Ի���
class CProblem5ELGamal����ǩ������Dlg : public CDialogEx
{
// ����
public:
	CProblem5ELGamal����ǩ������Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROBLEM5ELGAMAL_DIALOG };
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
	CString editMess;
//	CString editRes;
	CString editP;
	CString editG;
	CString editX;
	CString editY;
	CString editBitLen;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CString editR;
	CString editS;
	afx_msg void OnBnClickedButton3();
};
