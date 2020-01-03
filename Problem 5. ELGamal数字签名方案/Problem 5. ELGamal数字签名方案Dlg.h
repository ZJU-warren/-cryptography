
// Problem 5. ELGamal数字签名方案Dlg.h : 头文件
//

#pragma once


// CProblem5ELGamal数字签名方案Dlg 对话框
class CProblem5ELGamal数字签名方案Dlg : public CDialogEx
{
// 构造
public:
	CProblem5ELGamal数字签名方案Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROBLEM5ELGAMAL_DIALOG };
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
