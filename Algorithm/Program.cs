
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
            queue.Enqueue(5);
            queue.Enqueue(7);
            queue.Enqueue(3);
            queue.Enqueue(7);
            queue.Enqueue(2);
            queue.Enqueue(6);
            queue.Enqueue(9);
            queue.Enqueue(1);
            queue.Enqueue(4);
            queue.Enqueue(8);

            while (queue.Count > 0)
            {
                Console.WriteLine(queue.Dequeue());
            }
        }
    }
}
