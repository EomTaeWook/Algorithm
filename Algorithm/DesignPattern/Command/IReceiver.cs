using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithm.DesignPattern.Command
{
    public interface IReceiver
    {
    }

    //ExampleClass
    class Button : DesignPattern.Command.IReceiver
    {
        public void Btn_Click()
        {
            Console.WriteLine("Btn Click");
        }
    }
    class Power : DesignPattern.Command.IReceiver
    {
        public void On()
        {
            Console.WriteLine("PowerOn");
        }
        public void Off()
        {
            Console.WriteLine("PowerOff");
        }
    }
}
