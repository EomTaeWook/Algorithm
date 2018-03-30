using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Algorithm.Sort
{
    class CountingSort
    {
        public static List<int> Sort(List<int> unSortList)
        {
            return Sort(ref unSortList);
        }
        private static List<int> Sort(ref List<int> unSortList)
        {
            List<int> _countList = new List<int>();
            int max = unSortList.Max();
            _countList.AddRange(Enumerable.Repeat(0, max + 1));
            foreach (var value in unSortList)
                _countList[value]++;

            for (int i=1; i< _countList.Count; i++)
                _countList[i] += _countList[i - 1];

            List<int> _sortList = new List<int>(new int[unSortList.Count]);
            for(int i=0; i< unSortList.Count; i++)
            {
                _sortList[_countList[unSortList[i]] - 1] = unSortList[i];
                _countList[unSortList[i]]--;
            }
            return _sortList;
        }
    }
}