
// Problem 4. RSA����ϵͳ���.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CProblem4RSA����ϵͳ���App: 
// �йش����ʵ�֣������ Problem 4. RSA����ϵͳ���.cpp
//

class CProblem4RSA����ϵͳ���App : public CWinApp
{
public:
	CProblem4RSA����ϵͳ���App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CProblem4RSA����ϵͳ���App theApp;