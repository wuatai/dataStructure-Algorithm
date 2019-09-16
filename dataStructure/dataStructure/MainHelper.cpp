#include "MainHelper.h"
#include "SortingAlgorithm/Sort.h"
#include <iostream>

void MainHelper::MainHelper::printArray(const int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
}

void MainHelper::MainHelper::testSelectionSort()
{
	int testArr[10] = { 3, 6, 7, 2, 4, 10, 5, 9, 1, 8 };
	printArray(testArr, 10);
	Sorting::SortingAlgorithm::selectionSort(testArr, 10);
	std::cout << "\n";
	printArray(testArr, 10);
}