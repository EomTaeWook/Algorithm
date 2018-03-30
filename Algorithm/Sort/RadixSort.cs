using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithm.Sort
{
    class RadixSort
    {
        public static List<int> Sort(List<int> unSortList)
        {
            return Sort(ref unSortList);
        }
        private static List<int> Sort(ref List<int> unSortList)
        {
            List<Queue<int>> _positiveBucket = new List<Queue<int>>();
            List<Queue<int>> _negativeBucket = new List<Queue<int>>();
            for (int i = 0; i < 11; i++)
            {
                _positiveBucket.Add(new Queue<int>());
                _negativeBucket.Add(new Queue<int>());
            }
            var digit = unSortList.Max().ToString().Length;
            int div = 1, idx = -1;
            for (int i = 0; i < digit; i++, div *= 10)
            {
                for (int ii = 0; ii < unSortList.Count; ii++)
                {
                    idx = unSortList[ii]/ div % 10;
                    if (idx >= 0)
                        _positiveBucket[idx].Enqueue(unSortList[ii]);
                    else
                        _negativeBucket[idx * -1].Enqueue(unSortList[ii]);
                }
                idx = 0;
                for(int ii= _negativeBucket.Count - 1; ii>=0; ii--)
                {
                    while (_negativeBucket[ii].Count > 0)
                        unSortList[idx++] = _negativeBucket[ii].Dequeue();
                }
                for (int ii = 0; ii< _positiveBucket.Count; ii++)
                {
                    while (_positiveBucket[ii].Count > 0)
                        unSortList[idx++] = _positiveBucket[ii].Dequeue();
                }
            }
            return unSortList;
        }
    }
}
