
// Problem 4. RSA密码系统设计.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// CProblem4RSA密码系统设计App: 
// 有关此类的实现，请参阅 Problem 4. RSA密码系统设计.cpp
//

class CProblem4RSA密码系统设计App : public CWinApp
{
public:
	CProblem4RSA密码系统设计App();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CProblem4RSA密码系统设计App theApp;