
// Problem 2. MD5的实现Dlg.h : 头文件
//

#pragma once


// CProblem2MD5的实现Dlg 对话框
class CProblem2MD5的实现Dlg : public CDialogEx
{
// 构造
public:
	CProblem2MD5的实现Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROBLEM2MD5_DIALOG };
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
	CString editShow;
	CString editRes;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
};
