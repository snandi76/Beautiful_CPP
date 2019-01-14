using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ServiceModel;
namespace MyHost
{
    class Program
    {
        static void Main(string[] args)
        {
            using (ServiceHost host = new ServiceHost(typeof(MyServiceProj.TestService)))
            {
                host.Open();
                Console.WriteLine("Started My Service");
                Console.ReadLine();
            }
        }
    }
}
