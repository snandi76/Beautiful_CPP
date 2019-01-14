using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//namespace ConCS_Event
//{
//    class Program
//    {
//        static void Main(string[] args)
//        {
//            Subscriber objS = new Subscriber(100);
//            objS.PrintNumber();
//        }
//    }
//    class Pulisher
//    {
//        public delegate void func1(string msg);
//        public event func1 eFunc;

//        public Pulisher()
//        {

//        }

//        public void PrintNumber(int num)
//        {
//            if (eFunc != null)
//                eFunc.Invoke("PrintNumber");

//            Console.WriteLine("Number:{0,-12:NO}",num);
//        }
//        public void PrintMoney(int num)
//        {
//            if (eFunc != null)
//                eFunc.Invoke("PrintMoney");
//            Console.WriteLine("Money: {0:C}",num);
//        }
//    }
//    class Subscriber
//    {
//        private int _value;
//        private Pulisher _publisher;
//        public Subscriber(int val)
//        {
//            _value = val;
//            _publisher = new Pulisher();
//            _publisher.eFunc += eFunSubscribe; 
//        }

//        void eFunSubscribe(string msg)
//        {
//            Console.WriteLine("Print beforre {0}",msg);
//        }
//        public int num
//        {
//            get { return _value; }
//            set { _value = value; }
//        }
//        public void PrintNumber()
//        {
//            _publisher.PrintMoney(_value);
//            _publisher.PrintNumber(_value);
//        }
//    }
//}


namespace Ride
{
    ///<summary>
    ///Base class
    ///</summary>
    public class MyBaseClass
    {
        ///<summary>
        ///Print Name
        ///</summary>
        public string PrintName()
        {
            return "base class";
        }
    }
    ///<summary>
    ///Derived class
    ///</summary>
    public class Derived : MyBaseClass
    {
        public string PrintName()
        {
            return "Derived class";
        }
    }

    class XXX
    {
        public static void Main()
        {
            MyBaseClass obB= new MyBaseClass();
            Derived obD = new Derived();
            
             
        }
    }
}