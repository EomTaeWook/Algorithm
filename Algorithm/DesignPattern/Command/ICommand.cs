using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithm.DesignPattern.Command
{
    public interface ICommand
    {
        void Execute();
        void Undo();
    }

    //ExampleClass
    class ButtonCommand : DesignPattern.Command.ICommand
    {
        Button _receiver;
        public ButtonCommand(DesignPattern.Command.IReceiver receiver)
        {
            _receiver = receiver as Button;
        }
        public void Execute()
        {
            Console.WriteLine("Execute ButtonCommand");
            _receiver.Btn_Click();
        }

        public void Undo()
        {
            Console.WriteLine("Undo PowerCommand");
        }
    }
    class PowerOffCommand : DesignPattern.Command.ICommand
    {
        Power _receiver;
        public PowerOffCommand(DesignPattern.Command.IReceiver receiver)
        {
            _receiver = receiver as Power;
        }

        public void Execute()
        {
            Console.WriteLine("Execute PowerOffCommand");
            _receiver.Off();
        }
        public void Undo()
        {
            Console.WriteLine("Undo PowerOffCommand");
            _receiver.On();
        }
    }
    class PowerOnCommand : DesignPattern.Command.ICommand
    {
        private Power _receiver;
        public PowerOnCommand(Power receiver)
        {
            _receiver = receiver;
        }

        public void Execute()
        {
            Console.WriteLine("Execute PowerOnCommand");
            _receiver.On();
        }
        public void Undo()
        {
            Console.WriteLine("Undo PowerOnCommand");
            _receiver.Off();
        }
    }
}
