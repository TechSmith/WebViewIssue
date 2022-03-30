#pragma once

class CAppMDIView : public CView
{
protected:
   DECLARE_DYNCREATE( CAppMDIView )

   // Attributes
public:
   CAppMDIDoc* GetDocument() const;

   // Overrides
public:
   virtual void OnDraw( CDC* pDC );
   virtual BOOL PreCreateWindow( CREATESTRUCT& cs );

   // Generated message map functions
protected:
   DECLARE_MESSAGE_MAP()
};
