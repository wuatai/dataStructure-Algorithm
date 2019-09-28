#include "BinaryTree.h"
/*
* 找到了返回index,否则返回-1
*/
int BinaryTree::binarySearch(int arr[], int n, int target)
{
	// 在arr[l,r]中寻找target
	int l = 0, r = n - 1;
	while (l <= r)
	{
		int mid = (r - l) / 2 + l;
		if (arr[mid] == target)
			return mid;
		else if (arr[mid] > target)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
}