//
//  MergeSort.h
//  Proj1
//
//  Created by Jack Moore and Julia Calandro on 3/10/15.
//  Copyright (c) 2015 Jack Moore. All rights reserved.
//

#ifndef Proj1_MergeSort_h
#include <vector>

template <class T>
class MergeSort<T>
{
public:
  void sort(std::vector<T> & array, const int begin, const int end);

  void merge(std::vector<T> & array, const int begin, const int middle, const int end);
};

#include "MergeSort.hpp"
#define Proj1_MergeSort_h


#endif
