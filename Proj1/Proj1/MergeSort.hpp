//
//  MergeSort.hpp
//  Proj1
//
//  Created by Jack Moore on 3/10/15.
//  Copyright (c) 2015 Jack Moore and Julia Calandro. All rights reserved.
//

#ifndef Proj1_MergeSort_hpp
#define Proj1_MergeSort_hpp

template <class T>
void MergeSort<T>::sort(std::vector<T> & array, const int begin, const int end)
{
	if (begin < end)
	{
		int middle = (begin + end) / 2;
		sort(array, begin, middle);
		sort(array, middle+1, end);
		merge(array, begin, middle, end);
	}
	return;
}

template <class T>
void MergeSort<T>::merge(std::vector<T> & array, const int begin, const int middle, const int end)
{
	//Declare "Left" vector that contains everything from array(begin to middle)
	std::vector<T> Left(array.begin(), array.begin() + middle);
	//Declare "Right" vector that contains everything from array(middle+1 to end)
	std::vector<T> Right(array.begin() + middle + 1, array.begin() + end);

	int i = begin;
	int j = middle + 1;
	//I(k-1): Loop Invariant: A[p..k-1] is sorted
	//assert(is_sorted(array, begin, k-1))

	for(int k = begin; k <= end; k++)
	{	
	// k <= end && I(k-1): Loop Invariant: array[begin..k-1] is sorted
	//assert(is_sorted(array, begin, k-1))
		if (i <= middle && j <= end)
		{
			if(Left[i] <= Right[j])
			{
				array[k] = Left[i];
				i++;
			}
			else
			{
				array[k] = Right[j];
				j++;
			}
		}
		else
		{
			if(i <= middle)
			{
				array[k] = Left[i];
				i++;
			}
			else
			{
				array[k] = Right[j];
				j++;
			}
		}
		//I(k): array[begin..k] is sorted
		//assert(is_sorted(array, begin, k))
	}
	//Post Condition: k = end + 1 and I(r): array[begin..end] is sorted
	//assert(is_sorted(array, begin, end))

	return;
}


#endif
