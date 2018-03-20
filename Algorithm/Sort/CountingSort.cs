using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Algorithm.Sort
{
    class CountingSort
    {
        public static List<int> Sort(List<int> unsortList)
        {
            return Sort(ref unsortList);
        }
        private static List<int> Sort(ref List<int> unsortList)
        {
            List<int> _countList = new List<int>();
            int max = unsortList.Max();
            _countList.AddRange(Enumerable.Repeat(0, max + 1));
            foreach (var value in unsortList)
                _countList[value]++;

            for (int i=1; i< _countList.Count; i++)
                _countList[i] += _countList[i - 1];

            List<int> _sortList = new List<int>(new int[unsortList.Count]);
            for(int i=0; i< unsortList.Count; i++)
            {
                _sortList[_countList[unsortList[i]] - 1] = unsortList[i];
                _countList[unsortList[i]]--;
            }
            return _sortList;
        }
    }
}