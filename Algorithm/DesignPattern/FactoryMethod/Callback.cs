using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithm.DesignPattern.FactoryMethod
{
    class CallbackA : ICallback
    {
        public void InitCallback()
        {
            Console.WriteLine("InitCallback A");
        }
    }
    class CallbackB : ICallback
    {
        public void InitCallback()
        {
            Console.WriteLine("InitCallback B");
        }
    }
}
