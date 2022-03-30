using System.Windows;

namespace App.NET
{
   public partial class MainWindow : Window
   {
      public MainWindow()
      {
         InitializeComponent();

         DataContext = new MainWindowViewModel();
      }
   }
}
