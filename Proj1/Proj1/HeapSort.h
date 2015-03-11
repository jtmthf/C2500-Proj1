//
//  HeapSort.h
//  Proj1
//
//  Created by Jack Moore on 3/10/15.
//  Copyright (c) 2015 Jack Moore and Julia Calandro. All rights reserved.
//

#ifndef Proj1_HeapSort_h
#include <vector>

template <class T>
class HeapSort<T>
{
private:
	int heap_size;

public:
	T left(const int i);

	T right(const int i);	

	bool isMaxHeap(const std::vector<T> array, const int i);

	void max_heapify(std::vector<T> & array, const int i);

	void build_max_heap(std::vector<T> & array);

	void heap_sort(std::vector<T> & array);
};

#include "HeapSort.hpp"

#define Proj1_HeapSort_h


#endif
