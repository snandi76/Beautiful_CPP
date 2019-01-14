using System;
using System.Reflection;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SunNS
{
    class Program
    {
        static void Main(string[] args)
        {
            Type type = typeof(Employee);
            PropertyInfo[] piTest = type.GetProperties();
            foreach(PropertyInfo piTmp in piTest)
            {
                Console.WriteLine(piTmp);
            }
        }
    }
    class Employee
    {
        public int iEid { get; set; }
        public string strName { get; set; }
        public Employee()
        {
            Random random = new Random();
            iEid = random.Next();
            strName = String.Empty;
        }
        public void PrintEmpDetails()
        {
            Console.WriteLine("Eid-{0}|Name-{1}",iEid,strName);
        }
    }
}
