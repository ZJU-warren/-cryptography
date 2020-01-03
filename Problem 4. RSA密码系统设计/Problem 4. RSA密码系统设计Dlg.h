
// Problem 4. RSA密码系统设计Dlg.h : 头文件
//

#pragma once


// CProblem4RSA密码系统设计Dlg 对话框
class CProblem4RSA密码系统设计Dlg : public CDialogEx
{
// 构造
public:
	CProblem4RSA密码系统设计Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROBLEM4RSA_DIALOG };
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
