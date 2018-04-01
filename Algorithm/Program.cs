
using Algorithm.DesignPattern.Command;
using Algorithm.DesignPattern.FactoryMethod;
using Algorithm.Sort;
using DataStructure;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithm
{
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
            foreach(var command in _list)
            {
                if(command is PowerOnCommand)
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
    class Program
    {
        static void Main(string[] args)
        {

            //var factory = new Factory();
            //var callbackA = factory.Create(Factory.CallbackType.CallbackA);
            //callbackA.InitCallback();

            //var callbackB = factory.Create(Factory.CallbackType.CallbackB);
            //callbackB.InitCallback();

            var unSortArray = new int[,] { 
                { 10,14,5 },
                { 8,7,17 },
                { 12,1,6 },
                { 16,9,11 },
                { 4,15,2 },
                { 18,3,13}};
            
            for (int i = 0; i < unSortArray.GetLength(0); i++)
            {
                for (int ii = 0; ii < unSortArray.GetLength(1); ii++)
                    Console.Write(unSortArray[i, ii].ToString().PadLeft(2, ' ') + " ");
                Console.WriteLine();
            }
            Console.WriteLine();
            var sortList = ColumnSort.Sort(unSortArray);
            for (int i = 0; i < sortList.GetLength(0); i++)
            {
                for (int ii = 0; ii < sortList.GetLength(1); ii++)
                    Console.Write(sortList[i, ii].ToString().PadLeft(2, ' ') + " ");
                Console.WriteLine();
            }
            Console.ReadKey();
            
            ////-4 0, 2 5 6 11 18 22 51 167
            //int[] array = new int []{ 2, 5, -4, 11, 0, 18, 22, 167, 51, 6 };

            //List<int> list = new List<int>();
            //list.AddRange(array);

            //var sortList = RadixSort.Sort(list);

            //foreach(var value in sortList)
            //{
            //    Console.WriteLine(value);
            //}




            ////IReceiver
            //Power power = new Power();
            //Button button = new Button();

            ////ICommand
            //ButtonCommand buttonCommand = new ButtonCommand(button);
            //PowerOffCommand powerOffCommand = new PowerOffCommand(power);
            //PowerOnCommand powerOnCommand = new PowerOnCommand(power);

            ////Invoke
            //var remote = new Remote();
            //remote.Appand(buttonCommand).Appand(powerOffCommand).Appand(powerOnCommand);

            //remote.PowerOff();
            //remote.PowerOn();
            //remote.Click();
        }
    }
}
