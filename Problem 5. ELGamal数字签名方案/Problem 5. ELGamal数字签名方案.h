
// Problem 5. ELGamal����ǩ������.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CProblem5ELGamal����ǩ������App: 
// �йش����ʵ�֣������ Problem 5. ELGamal����ǩ������.cpp
//

class CProblem5ELGamal����ǩ������App : public CWinApp
{
public:
	CProblem5ELGamal����ǩ������App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CProblem5ELGamal����ǩ������App theApp;