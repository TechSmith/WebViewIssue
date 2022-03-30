#pragma once

class CChildFrame : public CMDIChildWnd
{
   DECLARE_DYNCREATE( CChildFrame )

   // Attributes
protected:
   CSplitterWnd m_wndSplitter;

   // Overrides
public:
   virtual BOOL PreCreateWindow( CREATESTRUCT& cs );

   // Generated message map functions
protected:
   DECLARE_MESSAGE_MAP()
};
