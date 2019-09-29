#ifndef _MAIN_HELPER_H
#define _MAIN_HELPER_H
#include <string>

namespace MainHelper
{
	class MainHelper
	{
	public:
		static void printArray(const int arr[], const int n);
		static int *genRandomArr(const int n, const int rangL, const int rangR);
		static void testSortTime(std::string sortName, void (*sort)(int arr[], int n), int arr[], int n);
		static bool isSorted(const int arr[], int n);
		static int *genOrderRandomArr(const int n, const int swapTimes);
	public:
		static void testSelectionSort();
		static void testInsertionSort();
		static void testInsertionSortEx();
		static void testMergeSort();
		static void testMergeDownToUp();
		static void testQuickSort();
		static void testQuickSort2();

		static void testMaxHeap();
		static void testMaxHeapSort1();
		static void testMaxHeapSort2();
		static void testMaxHeapSort();

		static void testBinarySearch();
		static void testUnionFind();
		static void testQuickUnion();
		static void testQuickUnionSz();
		static void testQuickUnionRank();
		static void testQuickUnionCompress();
	};
}

#endif