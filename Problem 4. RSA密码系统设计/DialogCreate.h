#pragma once


// DialogCreate �Ի���

class DialogCreate : public CDialogEx
{
	DECLARE_DYNAMIC(DialogCreate)

public:
	DialogCreate(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DialogCreate();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString editN;
	CString editE;
	CString editP;
	CString editQ;
	CString editD;
	CString editBitLen;
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
};
