using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithm.DesignPattern.Command
{
    //Invoke
    class Remote
    {
        List<ICommand> _list;
        public Remote()
        {
            _list = new List<ICommand>();
        }
        public Remote Appand(ICommand command)
        {
            _list.Add(command);
            return this;
        }
        public void PowerOn()
        {
            foreach (var command in _list)
            {
                if (command is PowerOnCommand)
                {
                    command.Execute(); break;

                }
            }
        }
        public void PowerOff()
        {
            foreach (var command in _list)
            {
                if (command is PowerOffCommand)
                {
                    command.Execute(); break;
                }
            }
        }
        public void Click()
        {
            foreach (var command in _list)
            {
                if (command is ButtonCommand)
                {
                    command.Execute(); break;
                }
            }
        }
    }
    class Example
    {
        void Main()
        {
            //IReceiver
            Power power = new Power();
            Button button = new Button();

            //ICommand
            ButtonCommand buttonCommand = new ButtonCommand(button);
            PowerOffCommand powerOffCommand = new PowerOffCommand(power);
            PowerOnCommand powerOnCommand = new PowerOnCommand(power);

            //Invoke
            var remote = new Remote();
            remote.Appand(buttonCommand).Appand(powerOffCommand).Appand(powerOnCommand);

            remote.PowerOff();
            remote.PowerOn();
            remote.Click();
        }
    }
}
