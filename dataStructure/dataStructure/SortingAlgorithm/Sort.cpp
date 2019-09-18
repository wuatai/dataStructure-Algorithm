#include "Sort.h"
#include <algorithm>

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