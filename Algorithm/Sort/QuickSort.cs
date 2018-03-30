using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithm.Sort
{
    class QuickSort
    {
        public static List<T> Sort<T>(List<T> unSortList) where T : IComparable
        {
            Sort(ref unSortList, 0, unSortList.Count - 1);

            return unSortList;
        }
        private static void Swap<T>(ref List<T> unSortList, int indexA, int indexB)
        {
            var temp = unSortList[indexA];
            unSortList[indexA] = unSortList[indexB];
            unSortList[indexB] = temp;
        }
        private static List<T> Sort<T>(ref List<T> unSortList, int left, int right) where T : IComparable
        {
            var pivot = unSortList[(left + right)/ 2];
            int l = left, r = right;
            while (l <= r)
            {
                while (unSortList[l].CompareTo(pivot) < 0)
                {
                    l++;
                }
                while (unSortList[r].CompareTo(pivot) > 0)
                {
                    r--;
                }
                if (l <= r)
                {
                    Swap(ref unSortList, l, r);
                    l++;
                    r--;
                }
            }
            if (left < r)
                Sort(ref unSortList, left, r);
            if(l < right)
                Sort(ref unSortList, l, right);

            return unSortList;
        }
    }
}
