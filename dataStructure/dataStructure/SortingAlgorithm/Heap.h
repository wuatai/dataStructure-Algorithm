#ifndef _MAX_HEAP_H_
#define _MAX_HEAP_H
#include <string>

namespace Heap
{
	class MaxHeap
	{
	public:
		MaxHeap(int capacity)
		{
			_data = new int[capacity + 1];
			_count = 0;
			_capacity = capacity;
		}
		MaxHeap(int arr[], int n);
		~MaxHeap(){ delete[] _data; }
		int size(){ return _count; }
		bool isEmpty(){ return _count == 0; }

		// 添加元素
		void insert(int item);

		// 取出最大值
		int extractMax();
		
		void testPrint();
	private:
		int* _data;
		int _count;
		int _capacity;
	private:
		void shiftDown(int k);
		void shiftUp(int k);
		void putNumberInLine(int num, std::string &line, int index_cur_level, int cur_tree_width, bool isLeft);
		void putBranchInLine(std::string &line, int index_cur_level, int cur_tree_width);
	};
}

#endif