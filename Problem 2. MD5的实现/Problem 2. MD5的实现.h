
// Problem 2. MD5��ʵ��.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CProblem2MD5��ʵ��App: 
// �йش����ʵ�֣������ Problem 2. MD5��ʵ��.cpp
//

class CProblem2MD5��ʵ��App : public CWinApp
{
public:
	CProblem2MD5��ʵ��App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CProblem2MD5��ʵ��App theApp;