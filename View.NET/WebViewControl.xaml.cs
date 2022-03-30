using System;
using System.IO;
using System.Windows;
using System.Windows.Controls;
using Microsoft.Web.WebView2.Core;

namespace View.NET
{
   public partial class WebViewControl : UserControl, IDisposable
   {
      public WebViewControl()
      {
         InitializeComponent();

         Unloaded += ( _, __ ) => Dispose();

         WebView.CoreWebView2InitializationCompleted += InitializationCompleted;
         WebView.NavigationStarting += NavigationStarting;
         WebView.NavigationCompleted += NavigationCompleted;
      }

      #region Dependency properties

      public static readonly DependencyProperty SourceProperty =
         DependencyProperty.Register( nameof( Source ),
            typeof( Uri ),
            typeof( WebViewControl ),
            new PropertyMetadata( OnSourcePropertyChanged ) );

      public Uri Source
      {
         get => (Uri)GetValue( SourceProperty );
         set => SetValue( SourceProperty, value );
      }

      private static void OnSourcePropertyChanged( object sender, DependencyPropertyChangedEventArgs e ) => ( (WebViewControl)sender ).InitializeWebView();

      #endregion

      #region Initialization

      private bool _webViewInitialized;
      private static readonly string WebView2Cache = Path.GetTempPath();
      private async void InitializeWebView()
      {
         if ( Source is null || WebView is null || _webViewInitialized )
         {
            return;
         }

         try
         {
            var options = new CoreWebView2EnvironmentOptions( additionalBrowserArguments: "--disable-features=msSmartScreenProtection" );
            var environment = await CoreWebView2Environment.CreateAsync( options: options, userDataFolder: WebView2Cache );
            if ( environment == null )
            {
               return;
            }

            var currentApp = Application.Current;

            try
            {
               await WebView.EnsureCoreWebView2Async( environment );

               WebView.CoreWebView2.Navigate( Source.AbsoluteUri );
               _webViewInitialized = true;
            }
            catch ( Exception ex )
            {
               ShowException( ex );
            }
         }
         catch ( Exception ex )
         {
            ShowException( ex );
         }
      }

      #endregion

      #region Navigation Events

      private void InitializationCompleted( object sender, CoreWebView2InitializationCompletedEventArgs e )
      {
         Dispatcher?.Invoke( InitializationCompletedImpl );
      }

      private void InitializationCompletedImpl()
      {
         try
         {
            if ( WebView?.CoreWebView2?.Settings is null )
            {
               return;
            }

            WebView.CoreWebView2.Settings.AreDefaultContextMenusEnabled = false;
            WebView.CoreWebView2.Settings.AreDefaultScriptDialogsEnabled = false;
            WebView.CoreWebView2.Settings.AreDevToolsEnabled = false;
         }
         catch ( Exception ex )
         {
            ShowException( ex );
         }
      }

      private void NavigationStarting( object sender, CoreWebView2NavigationStartingEventArgs e )
      {
         WebView.Visibility = Visibility.Collapsed;
      }

      private void NavigationCompleted( object sender, CoreWebView2NavigationCompletedEventArgs e )
      {
         if ( !e.IsSuccess && e.WebErrorStatus != CoreWebView2WebErrorStatus.OperationCanceled )
         {
            return;
         }

         WebView.Visibility = Visibility.Visible;

         try
         {
            Dispatcher.Invoke( WebView.Focus );
         }
         catch ( Exception ex )
         {
            ShowException( ex );
         }
      }

      #endregion

      #region IDisposable

      public void Dispose()
      {
         Dispose( true );
         GC.SuppressFinalize( this );
      }

      protected virtual void Dispose( bool disposing )
      {
         if ( disposing )
         {
            WebView.CoreWebView2InitializationCompleted -= InitializationCompleted;
            WebView.NavigationStarting -= NavigationStarting;
            WebView.NavigationCompleted -= NavigationCompleted;

            WebView?.Dispose();
         }
      }

      #endregion

      private static void ShowException( Exception ex )
      {
         var message = ex.Message;
         if ( !( ex.InnerException is null ) )
         {
            message += "\n" + ex.InnerException.Message;
         }

         message += "\n" + ex.StackTrace;

         MessageBox.Show( message );
      }
   }
}
