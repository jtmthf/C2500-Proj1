//
//  HeapSort.hpp
//  Proj1
//
//  Created by Jack Moore on 3/10/15.
//  Copyright (c) 2015 Jack Moore and Julia Calandro. All rights reserved.
//

#ifndef Proj1_HeapSort_hpp
#define Proj1_HeapSort_hpp

template <class T>
T HeapSort<T>::left(const int i)
{
	return 2i;
}

template <class T>
T HeapSort<T>::right(const int i)
{
	return 2i+1;
}

template <class T>
void HeapSort<T>::max_heapify(std::vector<T> & array, const int i)
{
	int left = left(i);
	int right = right(i);
	int largest;

	if(left <= heap_size && array[left] > array[i])
	{
		largest = left;
	}
	else
	{
		largest = i;
	}
	if(right <= heap_size && array[right] > array[largest])
	{
		largest = right;
	}
	if(largest != i)
	{
		int temp = array[i];
		array[i] = array[largest];
		array[largest] = temp;

		max_heapify(array, largest);
	}
	return;
}

template <class T>
void HeapSort<T>::build_max_heap(std::vector<T> & array)
{
	heap_size = array.size();
	// i>=1 ? or i>1 ?
	for(int i = (array.size())/2; i >= 0 ; i--)
	{
		max_heapify(array, i);
	}
	return;
}

//NEEDS INVARIANTS AND ASSERTS
template <class T>
void HeapSort<T>::heap_sort(std::vector<T> & array)
{
	heap_size = array.size();
	build_max_heap(array);
	for(int i = array.size(); i > 0; i--)
	{
		//Invariant: array(1..k) is max heap, and array(k+1..n) is sorted
		//assert(is_sorted(array, k+1, n))
		int temp = array[i];
		array[i] = array[0];
		array[0] = temp;
		heap_size = heap_size - 1;
		max_heapify(array, 0);
		//Invariant: array(1..k-1) is max heap
	}
	return;
}

#endif
