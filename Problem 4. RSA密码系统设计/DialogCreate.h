#pragma once


// DialogCreate 对话框

class DialogCreate : public CDialogEx
{
	DECLARE_DYNAMIC(DialogCreate)

public:
	DialogCreate(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DialogCreate();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
