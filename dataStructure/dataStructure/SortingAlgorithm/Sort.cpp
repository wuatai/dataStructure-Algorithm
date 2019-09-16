#include "Sort.h"
#include <algorithm>

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