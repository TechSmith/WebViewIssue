#pragma once

class CMainFrame : public CMDIFrameWnd
{
   DECLARE_DYNAMIC( CMainFrame )

   // Overrides
public:
   virtual BOOL PreCreateWindow( CREATESTRUCT& cs );

   // Generated message map functions
protected:
   DECLARE_MESSAGE_MAP()
};
