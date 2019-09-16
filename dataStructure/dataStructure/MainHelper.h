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
	public:
		static void testSelectionSort();
		
	};
}

#endif