#ifndef _SORTING_H_
#define _SORTING_H_
namespace Sorting
{
	class SortingAlgorithm
	{
	public:
		// —°‘Ò≈≈–Ú
		static void selectionSort(int arr[], int n);
		// ≤Â»Î≈≈–Ú
		static void insertionSort(int arr[], int n);
		static void insertionSortEx(int arr[], int n);
		// πÈ≤¢≈≈–Ú
		static void mergeSort(int arr[], int n);
		static void mergeSortDownToUp(int arr[], int n);
		// øÏÀŸ≈≈–Ú
		static void quickSort(int arr[], int n);
		// À´¬∑øÏ≈≈
		static void quickSort2(int arr[], int n);
		// ∂—≈≈–Ú
		static void heapSort1(int arr[], int n);
		static void heapSort2(int arr[], int n);
		// ‘≠µÿ∂—≈≈–Ú
		static void heapSort(int arr[], int n);
	private:
		static void mergeSortSingle(int arr[], int l, int r);
		static void merge(int arr[], int l, int m, int r);
		static void quickSortSingle(int arr[], int l ,int r);
		static int partition(int arr[], int l, int r);
		static void quickSortSingle2(int arr[], int l, int r);
		static int partition2(int arr[], int l, int r);
		static void shiftDown(int arr[], int n, int k);
	};
}
#endif