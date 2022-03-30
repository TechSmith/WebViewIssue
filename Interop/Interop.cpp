#include "pch.h"
#include "Interop.h"

using namespace System::Windows::Interop;
using namespace View::NET;

Interop::Show::Show()
{
   System::Threading::Thread::CurrentThread->SetApartmentState( System::Threading::ApartmentState::STA );

   // When testing with Microsoft.Web.WebView2 1.0.1054.31 (11/29/2021),
   // enable this in an attempt to resolve the exception:
   // "EnsureCoreWebView2Async cannot be used before the application's event loop has started running."
   // (this doesn't fix it) :(
   //( gcnew EnsureApplication() )->Ensure();
}

void Interop::Show::Go( HWND hWndParent )
{
   const enum { a, b, c } plan = a;

   switch ( plan )
   {
      case a:
      {
         // Assigns a System.Windows.Window.Owner
         ( gcnew WebViewPresenter() )->ShowModal( IntPtr( hWndParent ) );
         break;
      }
      case b:
      {
         // Does System.Windows.Window.Show() [modeless dialog]
         // This works! :)
         ( gcnew WebViewPresenter() )->ShowModeless();
         break;
      }
      case c:
      {
         // Initializes and displays window from here (C++/CLI)
         WebViewHostViewModel^ viewModel = gcnew WebViewHostViewModel();
         viewModel->Url = "https://news.ycombinator.com/";

         WebViewHostWindow^ window = gcnew WebViewHostWindow();
         window->DataContext = viewModel;

         auto h = gcnew WindowInteropHelper( window );
         h->Owner = IntPtr( hWndParent );

         window->ShowDialog();
         //window->Show();
         break;
      }
   }
}
