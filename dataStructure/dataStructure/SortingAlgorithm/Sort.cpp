#include "Sort.h"
#include <algorithm>
#include <ctime>
#include "Heap.h"

/*
* 选择排序思想
* 1.将数组分为2部分，一部分是有序的，一部分是无序的。
* 2.找到无序最小元素的位置，放在有序数组的最后一个位置（与无序的第一个元素交换位置）。
* 3.循环1和2，直到无序部分没有了元素。
*/
void Sorting::SortingAlgorithm::selectionSort(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		//在区间[i,n)寻找最小值
		int minIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}
		// 交换无序区的最小值和无序区的最左边的数据
		std::swap(arr[minIndex], arr[i]);
	}
}

/*
* 插入排序思想
* 1.将数组分为2部分，一部分是有序的，一部分是无序的。
* 2.2.把无序数组的第一个元素，插入在有序数组的合适位置。
* 3.循环1和2，直到无序部分没有了元素。
*/
void Sorting::SortingAlgorithm::insertionSort(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				std::swap(arr[j], arr[j - 1]);
			}
			else
			{
				break;
			}
		}
	}
}

void Sorting::SortingAlgorithm::insertionSortEx(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int num = arr[i];
		int j = i;
		for ( ; j > 0 && arr[j - 1] > num; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = num;
	}
}

void Sorting::SortingAlgorithm::mergeSort(int arr[], int n)
{
	mergeSortSingle(arr, 0, n - 1);
}

void Sorting::SortingAlgorithm::mergeSortSingle(int arr[], int l, int r)
{
	// 对arr[l...r]范围的数据进行归并排序
	if (l >= r)
	{
		return;
	}
	int m = l + (r - l) / 2;
	mergeSortSingle(arr, l, m);
	mergeSortSingle(arr, m + 1, r);
	// 下面的判断针对近乎有序的数组
	if (arr[m] > arr[m + 1])
	{
		merge(arr, l, m, r);
	}
}

void Sorting::SortingAlgorithm::mergeSortDownToUp(int arr[], int n)
{
	for (int sz = 1; sz <= n; sz += sz)
	{
		for (int i = 0; i + sz < n; i += sz + sz)
		{
			// 对arr[i...i+sz-1]和arr[i+sz...i+sz+sz-1]进行归并操作
			merge(arr, i, i + sz - 1, std::min(i + sz + sz - 1 , n - 1));
		}
	}
}

void Sorting::SortingAlgorithm::merge(int arr[], int l, int m, int r)
{
	// 对arr[l...m]和[m+1...r]进行归并
	int *temp = new int[r - l + 1];	//temp的index从0开始
	// 先复制到临时数组
	for (int i = l; i <= r; i++)
	{
		temp[i - l] = arr[i];
	}

	int i = l, j = m + 1;
	for (int k = l; k <= r; k++)
	{
		if (i > m)
		{
			// 左边部分已经归并完成
			arr[k] = temp[j - l];
			j++;
		}
		else if (j > r)
		{
			// 右边部分已经归并完成
			arr[k] = temp[i - l];
			i++;
		}
		else if (temp[i - l] < temp[j - l])
		{
			// 正常情况并且左边大于右边
			arr[k] = temp[i - l];
			i++;
		}
		else
		{
			// 正常情况并且右边大于左边
			arr[k] = temp[j - l];
			j++;
		}
	}
}

void Sorting::SortingAlgorithm::quickSort(int arr[], int n)
{
	srand(time(NULL));
	quickSortSingle(arr, 0 , n - 1);
}

void Sorting::SortingAlgorithm::quickSort2(int arr[], int n)
{
	srand(time(NULL));
	quickSortSingle2(arr, 0, n - 1);
}

void Sorting::SortingAlgorithm::quickSortSingle2(int arr[], int l, int r)
{
	if (l >= r)
	{
		return;
	}
	int p = partition2(arr, l, r);
	quickSortSingle2(arr, l, p - 1);
	quickSortSingle2(arr, p + 1, r);
}

int Sorting::SortingAlgorithm::partition2(int arr[], int l, int r)
{
	// 选用随机元素
	std::swap(arr[l], arr[rand() % (r - l + 1) + l]);
	int temp = arr[l];
	// arr[l+1...i)<=temp;arr(j...r]>=temp
	int i = l+1, j=r;
	while (true)
	{
		while ( i <= r && arr[i] < temp) i++;
		while ( j >= l + 1 && arr[j] > temp) j--;
		if (i > j) break;
		std::swap(arr[i], arr[j]);
		i++;
		j--;
	}
	std::swap(arr[l],arr[j]);
	return j;
}

void Sorting::SortingAlgorithm::quickSortSingle(int arr[], int l, int r)
{
	if (l >= r)
	{
		return;
	}
	int p = partition(arr, l, r);
	quickSortSingle(arr, l, p - 1);
	quickSortSingle(arr, p + 1, r);
}

// 对arr[l...r]部分进行partition操作
// 返回p，是的arr[l...p-1] < arr[p];arr[p+1...r] > arr[p]
int Sorting::SortingAlgorithm::partition(int arr[], int l, int r)
{
	// 选用随机元素
	std::swap(arr[l], arr[rand() % (r - l + 1) + l]);
	int temp = arr[l];
	// arr[l+1...j]<temp;arr[j+1...r]>temp;arr[l]=temp，最后交换arr[l]和arr[j]
	int j = l;
	for (int i = l + 1; i <= r; i++)
	{
		if (arr[i] < temp)
		{
			std::swap(arr[j + 1], arr[i]);
			j++;
		}
	}
	// 最后交换
	std::swap(arr[l], arr[j]);
	return j;
}

/*
* 堆排序，先建立最大堆，再依次取出堆顶元素
*/
void Sorting::SortingAlgorithm::heapSort1(int arr[], int n)
{
	Heap::MaxHeap maxHeap(n);
	for (int i = 0; i < n; i++)
	{
		maxHeap.insert(arr[i]);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		arr[i] = maxHeap.extractMax();
	}
}

/*
* 堆排序，利用heapify操作
*/
void Sorting::SortingAlgorithm::heapSort2(int arr[], int n)
{
	Heap::MaxHeap maxHeap(arr, n);
	for (int i = n - 1; i >= 0; i--)
	{
		arr[i] = maxHeap.extractMax();
	}
}

/*
* 原地堆排序
*/
void Sorting::SortingAlgorithm::heapSort(int arr[], int n)
{
	// heapify
	for (int i = (n-1)/2; i >= 0; i--)
	{
		shiftDown(arr, n, i);
	}
	for (int i = n - 1; i > 0; i--)
	{
		std::swap(arr[i], arr[0]);
		shiftDown(arr, i, 0);
	}
}

void Sorting::SortingAlgorithm::shiftDown(int arr[], int n, int k)
{
	while (k * 2 + 1 < n)
	{
		int j = 2 * k + 1;
		if (j+1< n && arr[j+1] > arr[j])
		{
			j += 1;
		}
		if (arr[k] >= arr[j])
		{
			break;
		}
		std::swap(arr[j], arr[k]);
		k = j;
	}
}