#include "pch.h"
#include "framework.h"
#include "App.MFC.h"
#include "App.MFCDlg.h"
#include "afxdialogex.h"
#include "..\Interop\ShowWebView.h"

CAppMFCDlg::CAppMFCDlg( CWnd* pParent /*=nullptr*/ )
   : CDialogEx( IDD_APPMFC_DIALOG, pParent )
{
   m_hIcon = AfxGetApp()->LoadIcon( IDR_MAINFRAME );
}

void CAppMFCDlg::DoDataExchange( CDataExchange* pDX )
{
   CDialogEx::DoDataExchange( pDX );
}

BEGIN_MESSAGE_MAP( CAppMFCDlg, CDialogEx )
   ON_WM_PAINT()
   ON_WM_QUERYDRAGICON()
   ON_BN_CLICKED( IDC_BUTTON1, &CAppMFCDlg::OnShowButtonClicked )
END_MESSAGE_MAP()

BOOL CAppMFCDlg::OnInitDialog()
{
   CDialogEx::OnInitDialog();

   SetIcon( m_hIcon, TRUE/*big*/ );
   SetIcon( m_hIcon, FALSE/*small*/ );

   return TRUE;
}

// BN_CLICKED
void CAppMFCDlg::OnShowButtonClicked()
{
   Interop::ShowWebView::Go( GetSafeHwnd() );
}

// WM_PAINT
void CAppMFCDlg::OnPaint()
{
   if ( IsIconic() )
   {
      CPaintDC dc( this ); // device context for painting

      SendMessage( WM_ICONERASEBKGND, reinterpret_cast<WPARAM>( dc.GetSafeHdc() ), 0 );

      // Center icon in client rectangle
      int cxIcon = GetSystemMetrics( SM_CXICON );
      int cyIcon = GetSystemMetrics( SM_CYICON );
      CRect rect;
      GetClientRect( &rect );
      int x = ( rect.Width() - cxIcon + 1 ) / 2;
      int y = ( rect.Height() - cyIcon + 1 ) / 2;

      // Draw the icon
      dc.DrawIcon( x, y, m_hIcon );
   }
   else
   {
      CDialogEx::OnPaint();
   }
}

// WM_QUERYDRAGICON
HCURSOR CAppMFCDlg::OnQueryDragIcon()
{
   return static_cast<HCURSOR>( m_hIcon );
}
