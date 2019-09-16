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