#include "Heap.h"
#include <iostream>
#include <cassert>
#include <cmath>
#include <string>
#include <algorithm>

// Heapify操作，用数组初始化maxHeap之后，从_count / 2开始，每个元素进行shiftDown操作，就形成了最大堆
Heap::MaxHeap::MaxHeap(int arr[], int n)
{
	_data = new int[n + 1];
	_capacity = n;
	for (int i = 0; i < n; i++)
	{
		_data[i + 1] = arr[i];
	}
	_count = n;
	for (int i = _count / 2; i >= 1; i--)
	{
		shiftDown(i);
	}
}

void Heap::MaxHeap::insert(int item)
{
	assert(_count + 1 <= _capacity); 
	_data[_count + 1] = item;
	_count++;
	shiftUp(_count);
}

int Heap::MaxHeap::extractMax()
{
	assert(_count > 0);
	int ret = _data[1];

	std::swap(_data[1], _data[_count]);
	_count--;
	shiftDown(1);
	return ret;
}

void Heap::MaxHeap::shiftUp(int k)
{
	while (k > 1 && _data[k / 2] < _data[k])
	{
		std::swap(_data[k / 2], _data[k]);
		k /= 2;
	}
}

void Heap::MaxHeap::shiftDown(int k)
{
	while (2 * k <= _count)
	{
		int j = 2 * k;	//在此轮循环中，_data[k]和_data[j]交换
		if (j+1 <= _count && _data[j+1] > _data[j])
		{
			j += 1;
		}
		if (_data[k] >= _data[j])
		{
			break;
		}
		std::swap(_data[k], _data[j]);
		k = j;
	}
}

void Heap::MaxHeap::putNumberInLine(int num, std::string &line, int index_cur_level, int cur_tree_width, bool isLeft){

	int sub_tree_width = (cur_tree_width - 1) / 2;
	int offset = index_cur_level * (cur_tree_width + 1) + sub_tree_width;
	assert(offset + 1 < line.size());
	if (num >= 10) {
		line[offset + 0] = '0' + num / 10;
		line[offset + 1] = '0' + num % 10;
	}
	else{
		if (isLeft)
			line[offset + 0] = '0' + num;
		else
			line[offset + 1] = '0' + num;
	}
}

void Heap::MaxHeap::putBranchInLine(std::string &line, int index_cur_level, int cur_tree_width){

	int sub_tree_width = (cur_tree_width - 1) / 2;
	int sub_sub_tree_width = (sub_tree_width - 1) / 2;
	int offset_left = index_cur_level * (cur_tree_width + 1) + sub_sub_tree_width;
	assert(offset_left + 1 < line.size());
	int offset_right = index_cur_level * (cur_tree_width + 1) + sub_tree_width + 1 + sub_sub_tree_width;
	assert(offset_right < line.size());

	line[offset_left + 1] = '/';
	line[offset_right + 0] = '\\';
}

void Heap::MaxHeap::testPrint(){

	// 我们的testPrint只能打印100个元素以内的堆的树状信息
	if (size() >= 100){
		std::cout << "This print function can only work for less than 100 int";
		return;
	}

	std::cout << "The max heap size is: " << size() << std::endl;
	std::cout << "Data in the max heap: ";
	for (int i = 1; i <= size(); i++){
		// 我们的testPrint要求堆中的所有整数在[0, 100)的范围内
		assert(_data[i] >= 0 && _data[i] < 100);
		std::cout << _data[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	int n = size();
	int max_level = 0;
	int number_per_level = 1;
	while (n > 0) {
		max_level += 1;
		n -= number_per_level;
		number_per_level *= 2;
	}

	int max_level_number = int(pow(2, max_level - 1));
	int cur_tree_max_level_number = max_level_number;
	int index = 1;
	for (int level = 0; level < max_level; level++){
		std::string line1 = std::string(max_level_number * 3 - 1, ' ');
		int cur_level_number = std::min(_count - int(pow(2, level)) + 1, int(pow(2, level)));
		bool isLeft = true;
		for (int index_cur_level = 0; index_cur_level < cur_level_number; index++, index_cur_level++){
			putNumberInLine(_data[index], line1, index_cur_level, cur_tree_max_level_number * 3 - 1, isLeft);
			isLeft = !isLeft;
		}
		std::cout << line1 << std::endl;

		if (level == max_level - 1)
			break;

		std::string line2 = std::string(max_level_number * 3 - 1, ' ');
		for (int index_cur_level = 0; index_cur_level < cur_level_number; index_cur_level++)
			putBranchInLine(line2, index_cur_level, cur_tree_max_level_number * 3 - 1);
		std::cout << line2 << std::endl;

		cur_tree_max_level_number /= 2;
	}
}