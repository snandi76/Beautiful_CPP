using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSH_Attribute
{
    class Test
    {
        [Obsolete("dont use M1 use M2",true)]
        public void M1()
        {
            Console.WriteLine("Obsolete");
        }
        public void M2()
        {
            Console.WriteLine("Use it");
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Test objT = new Test();
            objT.M1();
        }
    }
}
