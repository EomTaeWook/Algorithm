
using DataStructure;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithm
{
    class Program
    {
        static void Main(string[] args)
        {
            PriorityQueue<int> queue = new PriorityQueue<int>(Order.Descending);
            queue.Append(5);
            queue.Append(7);
            queue.Append(3);
            queue.Append(7);
            queue.Append(2);
            queue.Append(6);
            queue.Append(9);
            queue.Append(1);
            queue.Append(4);
            queue.Append(8);

            while (queue.Count > 0)
            {
                Console.WriteLine(queue.Read());
            }
        }
    }
}
