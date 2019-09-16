#include "MainHelper.h"
#include "SortingAlgorithm/Sort.h"
#include <iostream>
#include <ctime>
#include <cassert>

void MainHelper::MainHelper::printArray(const int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
}

void MainHelper::MainHelper::testSelectionSort()
{
	int n = 100000;
	int *testArr = genRandomArr(n, 1, n);
	testSortTime("selectionSort", Sorting::SortingAlgorithm::selectionSort, testArr, n);
}

int* MainHelper::MainHelper::genRandomArr(const int n, const int rangL, const int rangR)
{
	assert(rangL <= rangR);
	int *arr = new int[n];
	std::srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (rangR - rangL + 1) + rangL;
	}
	return arr;
}

void MainHelper::MainHelper::testSortTime(std::string sortName, void (*sort)(int arr[], int n), int arr[], int n)
{
	clock_t startTime = clock();
	sort(arr, n);
	clock_t endTime = clock();
	assert(isSorted(arr, n));
	std::cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << std::endl;
}

bool MainHelper::MainHelper::isSorted(const int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] > arr[i+1])
		{
			return false;
		}
	}
	return true;
}