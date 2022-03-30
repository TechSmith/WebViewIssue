#include "pch.h"
#include "framework.h"
#include "App.MDIDoc.h"
#include "App.MDIView.h"

IMPLEMENT_DYNCREATE( CAppMDIView, CView )

BEGIN_MESSAGE_MAP( CAppMDIView, CView )
END_MESSAGE_MAP()

BOOL CAppMDIView::PreCreateWindow( CREATESTRUCT& cs )
{
   return CView::PreCreateWindow( cs );
}

void CAppMDIView::OnDraw( CDC* /*pDC*/ )
{
   CAppMDIDoc* pDoc = GetDocument();
   ASSERT_VALID( pDoc );
   if ( !pDoc )
      return;
}

CAppMDIDoc* CAppMDIView::GetDocument() const // non-debug version is inline
{
   ASSERT( m_pDocument->IsKindOf( RUNTIME_CLASS( CAppMDIDoc ) ) );
   return (CAppMDIDoc*)m_pDocument;
}

// CAppMDIView message handlers
