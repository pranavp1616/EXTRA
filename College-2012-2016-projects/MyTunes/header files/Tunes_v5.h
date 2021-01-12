
// Tunes_v5.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CTunes_v5App:
// See Tunes_v5.cpp for the implementation of this class
//

class CTunes_v5App : public CWinApp
{
public:
	CTunes_v5App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CTunes_v5App theApp;