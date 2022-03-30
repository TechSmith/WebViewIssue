#include "pch.h"
#include "ShowWebView.h"
#include "Interop.h"

// static
void Interop::ShowWebView::Go( HWND hWndParent )
{
   ( gcnew Interop::Show() )->Go( hWndParent );
}
