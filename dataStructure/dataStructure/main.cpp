#include "MainHelper.h"
#include <iostream>
int main()
{
	// ѡ�������������
	//MainHelper::MainHelper::testSelectionSort();

	// ���������������
	//MainHelper::MainHelper::testInsertionSort();

	// �鲢�����������
	//MainHelper::MainHelper::testQuickSort();

	// ���������������
	//MainHelper::MainHelper::testQuickSort2();

	// ������1
	//MainHelper::MainHelper::testMaxHeapSort1();

	// ������2
	//MainHelper::MainHelper::testMaxHeapSort2();

	// ԭ�ض�����
	//MainHelper::MainHelper::testMaxHeapSort();

	// ����������
	//MainHelper::MainHelper::testBinarySearch();

	// ���鼯
	//MainHelper::MainHelper::testUnionFind();

	// ���ٲ��鼯
	//MainHelper::MainHelper::testQuickUnion();

	// ����sz�Ż��Ŀ��ٲ��鼯
	MainHelper::MainHelper::testQuickUnionSz();

	// ����rank�Ż��Ŀ��ٲ��鼯
	MainHelper::MainHelper::testQuickUnionRank();

	// ����·��ѹ���Ż��Ŀ��ٲ��鼯
	MainHelper::MainHelper::testQuickUnionCompress();

	system("pause");
}