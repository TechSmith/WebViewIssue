#include "pch.h"
#include "framework.h"
#include "App.MDI.h"
#include "ChildFrm.h"

IMPLEMENT_DYNCREATE( CChildFrame, CMDIChildWnd )

BEGIN_MESSAGE_MAP( CChildFrame, CMDIChildWnd )
END_MESSAGE_MAP()

BOOL CChildFrame::PreCreateWindow( CREATESTRUCT& cs )
{
   if ( !CMDIChildWnd::PreCreateWindow( cs ) )
      return FALSE;

   return TRUE;
}

// CChildFrame message handlers
