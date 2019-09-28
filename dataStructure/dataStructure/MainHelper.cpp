#include "MainHelper.h"
#include <iostream>
#include <ctime>
#include <cassert>
#include "SortingAlgorithm/Sort.h"
#include "SortingAlgorithm/Heap.h"
#include "SortingAlgorithm/BinaryTree.h"

void MainHelper::MainHelper::printArray(const int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
}

void MainHelper::MainHelper::testSelectionSort()
{
	int n = 10000;
	int *testArr = genOrderRandomArr(n, 100);
	testSortTime("selectionSort", Sorting::SortingAlgorithm::selectionSort, testArr, n);
}

void MainHelper::MainHelper::testInsertionSort()
{
	int n = 10000;
	int *testArr = genRandomArr(n, 1, n);
	testSortTime("insertionSort", Sorting::SortingAlgorithm::insertionSort, testArr, n);
}

void MainHelper::MainHelper::testInsertionSortEx()
{
	int n = 10000;
	int *testArr = genOrderRandomArr(n, 100);
	testSortTime("insertionSort", Sorting::SortingAlgorithm::insertionSortEx, testArr, n);
}

void MainHelper::MainHelper::testMergeDownToUp()
{
	int n = 100000;
	int *testArr = genRandomArr(n, 1, n);
	testSortTime("testMergeDownToUp", Sorting::SortingAlgorithm::mergeSortDownToUp, testArr, n);
}

void MainHelper::MainHelper::testQuickSort()
{
	int n = 100000;
	int *testArr = genRandomArr(n, 1, 100);
	testSortTime("testQuickSort", Sorting::SortingAlgorithm::quickSort, testArr, n);
}

void MainHelper::MainHelper::testQuickSort2()
{
	int n = 100000;
	int *testArr = genRandomArr(n, 1, 100);
	testSortTime("testQuickSort2", Sorting::SortingAlgorithm::quickSort2, testArr, n);
}

void MainHelper::MainHelper::testMergeSort()
{
	int n = 10000;
	int *testArr = genRandomArr(n, 1, n);
	testSortTime("testMergeSort", Sorting::SortingAlgorithm::mergeSort, testArr, n);
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

int* MainHelper::MainHelper::genOrderRandomArr(const int n, const int swapTimes)
{
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = i;
	}
	srand(time(NULL));
	for (int i = 0; i < swapTimes; i++)
	{
		int x = rand() % n;
		int y = rand() % n;
		std::swap(arr[x], arr[y]);
	}
	return arr;
}

void MainHelper::MainHelper::testMaxHeap()
{
	Heap::MaxHeap maxHeap = Heap::MaxHeap(100);
	//std::cout << maxHeap.size() << std::endl;
	srand(time(NULL));
	for (int i = 0; i < 31; i++)
	{
		maxHeap.insert(rand() % 100);
	}

	maxHeap.testPrint();

	while (!maxHeap.isEmpty())
	{
		std::cout << maxHeap.extractMax() << " ";
	}
}

void MainHelper::MainHelper::testMaxHeapSort1()
{
	int n = 100000;
	int *testArr = genRandomArr(n, 1, 100);
	testSortTime("testMaxHeapSort1", Sorting::SortingAlgorithm::heapSort1, testArr, n);
}

void MainHelper::MainHelper::testMaxHeapSort2()
{
	int n = 100000;
	int *testArr = genRandomArr(n, 1, 100);
	testSortTime("testMaxHeapSort2", Sorting::SortingAlgorithm::heapSort2, testArr, n);
}

void MainHelper::MainHelper::testMaxHeapSort()
{
	int n = 100000;
	int *testArr = genRandomArr(n, 1, 100);
	testSortTime("testMaxHeapSort", Sorting::SortingAlgorithm::heapSort, testArr, n);
}

void MainHelper::MainHelper::testBinarySearch()
{
	BinaryTree::BinarySearchTree<std::string, int> tree;
	tree.insert("China", 2);
	tree.insert("Japan", 3);
	tree.insert("DiDi", 3);
	tree.insert("USA", 4);
	tree.insert("Korea", 5);
	tree.remove("Japan");
	int *result = tree.search("China");
	std::cout << "Search Result:" << *result << std::endl;

	std::cout << "preOrder:";
	tree.preOrder();
	std::cout << std::endl;

	std::cout << "inOrder:";
	tree.inOrder();
	std::cout << std::endl;

	std::cout << "postOrder:";
	tree.postOrder();
	std::cout << std::endl;

	std::cout << "levelOrder:";
	tree.levelOrder();
	std::cout << std::endl;
}