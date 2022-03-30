#include "pch.h"
#include "framework.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "App.MDI.h"
#include "MainFrm.h"
#include "ChildFrm.h"
#include "App.MDIDoc.h"
#include "App.MDIView.h"
#include "..\Interop\ShowWebView.h"

CAppMDIApp theApp;

BEGIN_MESSAGE_MAP( CAppMDIApp, CWinApp )
   ON_COMMAND( ID_FILE_NEW, &CWinApp::OnFileNew )
   ON_COMMAND( ID_FILE_OPEN, &CWinApp::OnFileOpen )
   ON_COMMAND( ID_FILE_OPENWEBVIEW, &CAppMDIApp::OnFileOpenwebview )
END_MESSAGE_MAP()

CAppMDIApp::CAppMDIApp() noexcept
{
   SetAppID( _T( "AppMDI.AppID.NoVersion" ) );
}

BOOL CAppMDIApp::InitInstance()
{
   INITCOMMONCONTROLSEX initControls{};
   initControls.dwSize = sizeof( initControls );
   initControls.dwICC = ICC_WIN95_CLASSES;
   InitCommonControlsEx( &initControls );

   CWinApp::InitInstance();

   EnableTaskbarInteraction( FALSE );

   CMultiDocTemplate* pDocTemplate;
   pDocTemplate = new CMultiDocTemplate( IDR_AppMDITYPE,
                                         RUNTIME_CLASS( CAppMDIDoc ),
                                         RUNTIME_CLASS( CChildFrame ), // custom MDI child frame
                                         RUNTIME_CLASS( CAppMDIView ) );
   if ( !pDocTemplate )
      return FALSE;

   AddDocTemplate( pDocTemplate );

   // create main MDI Frame window
   CMainFrame* pMainFrame = new CMainFrame;
   if ( !pMainFrame || !pMainFrame->LoadFrame( IDR_MAINFRAME ) )
   {
      delete pMainFrame;
      return FALSE;
   }
   m_pMainWnd = pMainFrame;

   // Parse command line for standard shell commands, DDE, file open
   CCommandLineInfo cmdInfo;
   ParseCommandLine( cmdInfo );

   if ( !ProcessShellCommand( cmdInfo ) )
      return FALSE;

   pMainFrame->ShowWindow( m_nCmdShow );
   pMainFrame->UpdateWindow();

   return TRUE;
}

int CAppMDIApp::ExitInstance()
{
   return CWinApp::ExitInstance();
}

// CAppMDIApp message handlers

void CAppMDIApp::OnFileOpenwebview()
{
   Interop::ShowWebView::Go( m_pMainWnd->GetSafeHwnd() );
}
