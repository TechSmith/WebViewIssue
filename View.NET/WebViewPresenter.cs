using System;
using System.Windows.Interop;

namespace View.NET
{
   public class WebViewPresenter
   {
      private const string TestUrl = "https://news.ycombinator.com/";

      public void ShowModeless()
      {
         var window = new WebViewHostWindow()
         {
            DataContext = new WebViewHostViewModel { Url = TestUrl }
         };

         window.Show();
      }

      public void ShowModal( IntPtr hWndParent )
      {
         var window = new WebViewHostWindow()
         {
            DataContext = new WebViewHostViewModel { Url = TestUrl }
         };

         _ = new WindowInteropHelper( window ) { Owner = hWndParent };

         _ = window.ShowDialog();
      }
   }
}
