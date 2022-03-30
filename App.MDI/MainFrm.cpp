#include "pch.h"
#include "framework.h"
#include "App.MDI.h"
#include "MainFrm.h"

IMPLEMENT_DYNAMIC( CMainFrame, CMDIFrameWnd )

BEGIN_MESSAGE_MAP( CMainFrame, CMDIFrameWnd )
END_MESSAGE_MAP()

BOOL CMainFrame::PreCreateWindow( CREATESTRUCT& cs )
{
   if ( !CMDIFrameWnd::PreCreateWindow( cs ) )
      return FALSE;

   cs.style = WS_OVERLAPPED | WS_CAPTION | FWS_ADDTOTITLE | WS_THICKFRAME | WS_SYSMENU;

   return TRUE;
}

// CMainFrame message handlers
