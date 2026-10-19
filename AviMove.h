// AviMove.h : main header file for the AVIMOVE DLL
//

#if !defined(AFX_AVIMOVE_H__3E494DAA_8F74_490A_84D9_6FE7EBC4C428__INCLUDED_)
#define AFX_AVIMOVE_H__3E494DAA_8F74_490A_84D9_6FE7EBC4C428__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
//#include "AviMove_i.h"

/////////////////////////////////////////////////////////////////////////////
// CAviMoveApp
// See AviMove.cpp for the implementation of this class
//

class CAviMoveApp : public CWinApp
{
public:
	CAviMoveApp();

	//CString GetAviMoveVersion();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAviMoveApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CAviMoveApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	// CAviMoveApp initialization
	//BOOL InitInstance(void);
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AVIMOVE_H__3E494DAA_8F74_490A_84D9_6FE7EBC4C428__INCLUDED_)
