using System;
using System.Windows.Input;
using View.NET;

namespace App.NET
{
   public class MainWindowViewModel
   {
      private ICommand _showCommand;
      public ICommand ShowWebViewCommand => _showCommand ?? ( _showCommand = new ShowCommand() );
   }

   public class ShowCommand : ICommand
   {
      public event EventHandler CanExecuteChanged
      {
         add => CommandManager.RequerySuggested += value;
         remove => CommandManager.RequerySuggested -= value;
      }

      public bool CanExecute( object _ ) => true;

      public void Execute( object _ )
      {
         new WebViewPresenter().ShowModal( IntPtr.Zero );
      }
   }
}
