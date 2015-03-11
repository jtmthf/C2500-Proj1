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
bool HeapSort<T>::isMaxHeap(const std::vector<T> array, const int i)
{
	for(i; i < (array.size())/2; i++)
	{
		if(array[2i] > array[i] || array[2i+1] > array[i])
			return false;
	}
	int k = array.size()/2;
	if(array[k] < array(array.size()))
		return false;
	if(2k < array.size() && array[k] < array[array.size() - 1])
		return false;
	return true;
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
	//array(1..array.size() is an array of numbers)
	heap_size = array.size();
	for(int i = (array.size())/2; i >= 0 ; i--)
	{
		//Invariant: array(i+1..array.size()) satisfies the MaxHeap property
		//assert(isMaxHeap(array, i+1));
		max_heapify(array, i);
		//Invariant: array(i..array.size()) satisfies the MaxHeap property
		//assert(isMaxHeap(array, i));		
	}
	//Post Condition: All elements in array(1..array.end()) satisfy the MaxHeap property.
	//Therefore, A(1..array.end()) is a MaxHeap.
	return;
}

template <class T>
void HeapSort<T>::heap_sort(std::vector<T> & array)
{
	heap_size = array.size();
	build_max_heap(array);
	for(int i = array.size(); i > 0; i--)
	{
		//Invariant: array(1..i) is max heap, and array(i+1..array.end()) is sorted
		//assert(is_sorted(array, array[i+1], array.end()));
		int temp = array[i];
		array[i] = array[0];
		array[0] = temp;
		heap_size = heap_size - 1;
		max_heapify(array, 0);
		//Invariant: array(1..i-1) is max heap, and array(k..array.end()) is sorted
		//assert(is_sorted(array, array[i], array.end()));
	}
	//Post Condition: array(1..array.end()) is sorted
	return;
}

#endif
