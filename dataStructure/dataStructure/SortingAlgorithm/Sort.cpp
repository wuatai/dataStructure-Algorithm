#include "Sort.h"
#include <algorithm>
#include <ctime>
#include "Heap.h"

/*
* ѡ������˼��
* 1.�������Ϊ2���֣�һ����������ģ�һ����������ġ�
* 2.�ҵ�������СԪ�ص�λ�ã�����������������һ��λ�ã�������ĵ�һ��Ԫ�ؽ���λ�ã���
* 3.ѭ��1��2��ֱ�����򲿷�û����Ԫ�ء�
*/
void Sorting::SortingAlgorithm::selectionSort(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		//������[i,n)Ѱ����Сֵ
		int minIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}
		// ��������������Сֵ��������������ߵ�����
		std::swap(arr[minIndex], arr[i]);
	}
}

/*
* ��������˼��
* 1.�������Ϊ2���֣�һ����������ģ�һ����������ġ�
* 2.2.����������ĵ�һ��Ԫ�أ���������������ĺ���λ�á�
* 3.ѭ��1��2��ֱ�����򲿷�û����Ԫ�ء�
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
	// ��arr[l...r]��Χ�����ݽ��й鲢����
	if (l >= r)
	{
		return;
	}
	int m = l + (r - l) / 2;
	mergeSortSingle(arr, l, m);
	mergeSortSingle(arr, m + 1, r);
	// ������ж���Խ������������
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
			// ��arr[i...i+sz-1]��arr[i+sz...i+sz+sz-1]���й鲢����
			merge(arr, i, i + sz - 1, std::min(i + sz + sz - 1 , n - 1));
		}
	}
}

void Sorting::SortingAlgorithm::merge(int arr[], int l, int m, int r)
{
	// ��arr[l...m]��[m+1...r]���й鲢
	int *temp = new int[r - l + 1];	//temp��index��0��ʼ
	// �ȸ��Ƶ���ʱ����
	for (int i = l; i <= r; i++)
	{
		temp[i - l] = arr[i];
	}

	int i = l, j = m + 1;
	for (int k = l; k <= r; k++)
	{
		if (i > m)
		{
			// ��߲����Ѿ��鲢���
			arr[k] = temp[j - l];
			j++;
		}
		else if (j > r)
		{
			// �ұ߲����Ѿ��鲢���
			arr[k] = temp[i - l];
			i++;
		}
		else if (temp[i - l] < temp[j - l])
		{
			// �������������ߴ����ұ�
			arr[k] = temp[i - l];
			i++;
		}
		else
		{
			// ������������ұߴ������
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
	// ѡ�����Ԫ��
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

// ��arr[l...r]���ֽ���partition����
// ����p���ǵ�arr[l...p-1] < arr[p];arr[p+1...r] > arr[p]
int Sorting::SortingAlgorithm::partition(int arr[], int l, int r)
{
	// ѡ�����Ԫ��
	std::swap(arr[l], arr[rand() % (r - l + 1) + l]);
	int temp = arr[l];
	// arr[l+1...j]<temp;arr[j+1...r]>temp;arr[l]=temp����󽻻�arr[l]��arr[j]
	int j = l;
	for (int i = l + 1; i <= r; i++)
	{
		if (arr[i] < temp)
		{
			std::swap(arr[j + 1], arr[i]);
			j++;
		}
	}
	// ��󽻻�
	std::swap(arr[l], arr[j]);
	return j;
}

/*
* �������Ƚ������ѣ�������ȡ���Ѷ�Ԫ��
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
* ����������heapify����
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
* ԭ�ض�����
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