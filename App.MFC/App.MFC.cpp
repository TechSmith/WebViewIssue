#include "pch.h"
#include "framework.h"
#include "App.MFC.h"
#include "App.MFCDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CAppMFCApp theApp;

BEGIN_MESSAGE_MAP( CAppMFCApp, CWinApp )
END_MESSAGE_MAP()

BOOL CAppMFCApp::InitInstance()
{
   INITCOMMONCONTROLSEX initControls{};
   initControls.dwSize = sizeof( initControls );
   initControls.dwICC = ICC_WIN95_CLASSES;
   InitCommonControlsEx( &initControls );

   CWinApp::InitInstance();

   CAppMFCDlg dlg;
   m_pMainWnd = &dlg;
   (void)dlg.DoModal();

   return FALSE/*exit*/;
}
