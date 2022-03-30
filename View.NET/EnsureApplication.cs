namespace View.NET
{
   public class EnsureApplication
   {
      public void Ensure()
      {
         if ( _application is null )
         {
            _application = new AnApp();
            //System.Windows.Threading.Dispatcher.Run();
         }
      }

      private static System.Windows.Application _application;
   }
}
