#include "MainHelper.h"
#include <iostream>
int main()
{
	// 选择排序测试用例
	//MainHelper::MainHelper::testSelectionSort();

	// 插入排序测试用例
	//MainHelper::MainHelper::testInsertionSort();

	// 归并排序测试用例
	//MainHelper::MainHelper::testQuickSort();

	// 快速排序测试用例
	//MainHelper::MainHelper::testQuickSort2();

	// 堆排序1
	//MainHelper::MainHelper::testMaxHeapSort1();

	// 堆排序2
	//MainHelper::MainHelper::testMaxHeapSort2();

	// 原地堆排序
	//MainHelper::MainHelper::testMaxHeapSort();

	// 二叉搜索树
	//MainHelper::MainHelper::testBinarySearch();

	// 并查集
	//MainHelper::MainHelper::testUnionFind();

	// 快速并查集
	//MainHelper::MainHelper::testQuickUnion();

	// 基于sz优化的快速并查集
	MainHelper::MainHelper::testQuickUnionSz();

	// 基于rank优化的快速并查集
	MainHelper::MainHelper::testQuickUnionRank();

	// 基于路径压缩优化的快速并查集
	MainHelper::MainHelper::testQuickUnionCompress();

	system("pause");
}