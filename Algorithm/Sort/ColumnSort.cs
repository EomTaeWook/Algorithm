using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithm.Sort
{
    class ColumnSort
    {
        public static int[,] Sort(int[,] unSortList)
        {
            Sort(ref unSortList);
            Transposed(ref unSortList);
            Sort(ref unSortList);
            ReverseTransposed(ref unSortList);
            Sort(ref unSortList);
            int[,] transposedMatrix = null;
            HalfDivideTransposed(ref unSortList, out transposedMatrix);
            ReverseHalfDivideTransposed(ref transposedMatrix, out unSortList);
            return unSortList;
        }
        private static void Sort(ref int[,] unSortList)
        {
            if (unSortList.Length > 0 && (unSortList.GetLength(0) & 1) == 0)
            {
                for (int i = 0; i < unSortList.GetLength(1); i++)
                {
                    for (int ii = 0; ii < unSortList.GetLength(0); ii++)
                    {
                        for (int iii = 1; iii < unSortList.GetLength(0); iii++)
                        {
                            if (unSortList[iii, i] < unSortList[iii - 1, i])
                            {
                                Swap(ref unSortList, i, iii, i, iii - 1);
                            }
                        }
                    }
                }
            }
        }
        private static void Sort(ref int[,] unSortList, int begin, int end)
        {
            for (int i = begin; i < end; i++)
            {
                for(int ii=0; ii< unSortList.GetLength(0); ii++)
                {
                    for (int iii = 1; iii < unSortList.GetLength(0); iii++)
                    {
                        if (unSortList[iii, i] < unSortList[iii - 1, i])
                        {
                            Swap(ref unSortList, i, iii, i, iii - 1);
                        }
                    }
                }
            }
        }
        private static void ReverseHalfDivideTransposed(ref int[,] unSortList, out int[,] sortList)
        {
            sortList = new int[unSortList.GetLength(0), unSortList.GetLength(1) - 1];
            int row = unSortList.GetLength(0) / 2;
            for (int i = 0; i < row; i++)
            {
                for (int ii = 0; ii < unSortList.GetLength(1)-1; ii++)
                {
                    sortList[i, ii] = unSortList[i + row, ii];
                }
                for (int ii = 1; ii < unSortList.GetLength(1); ii++)
                {
                    sortList[row + i, ii - 1] = unSortList[i, ii];
                }
            }
        }
        private static void HalfDivideTransposed(ref int[,] unSortList, out int[,] transposedMatrix)
        {
            transposedMatrix = new int[unSortList.GetLength(0), unSortList.GetLength(1) + 1];
            int row = unSortList.GetLength(0) / 2;
            for (int i = 0; i < row; i++)
            {
                for (int ii = 0; ii < unSortList.GetLength(1); ii++)
                {
                    transposedMatrix[row + i, ii] = unSortList[i, ii];
                }
                for (int ii = 0; ii < unSortList.GetLength(1); ii++)
                {
                    transposedMatrix[i, ii + 1] = unSortList[row + i, ii];
                }
            }
            Sort(ref transposedMatrix, 1, transposedMatrix.GetLength(1) - 1);
        }
        private static void Transposed(ref int[,] unSortList)
        {
            var transposedMatrix = new int[unSortList.GetLength(0), unSortList.GetLength(1)];
            int row = 0, col = 0;
            for (int i = 0; i < unSortList.GetLength(0); i++)
            {
                if (i != 0 && (i & 1) == 0)
                {
                    row = 0;
                    col++;
                }
                for (int ii = 0; ii < unSortList.GetLength(1); ii++)
                {
                    transposedMatrix[i, ii] = unSortList[row++, col];
                }
            }
            Array.Copy(transposedMatrix, unSortList, transposedMatrix.Length);
        }

        private static void ReverseTransposed(ref int[,] unSortList)
        {
            var transposedMatrix = new int[unSortList.GetLength(0), unSortList.GetLength(1)];
            int row = 0, col = 0;
            for (int i = 0; i < unSortList.GetLength(0); i++)
            {
                if (i != 0 && (i & 1) == 0)
                {
                    row = 0;
                    col++;
                }
                for (int ii = 0; ii < unSortList.GetLength(1); ii++)
                {
                    transposedMatrix[row++, col] = unSortList[i, ii];
                }
            }
            Array.Copy(transposedMatrix, unSortList, transposedMatrix.Length);
        }
        private static void Swap(ref int[,] unSortList, int a_x, int a_y, int b_x, int b_y)
        {
            var temp = unSortList[a_y, a_x];
            unSortList[a_y, a_x] = unSortList[b_y, b_x];
            unSortList[b_y, b_x] = temp;
        }
    }
}
