//
//  main.cpp
//  Proj1
//
//  Created by Jack Moore and Julia Calandro on 3/10/15.
//  Copyright (c) 2015 Jack Moore. All rights reserved.
//

#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
#include "CSVTool.h"
#include "MergeSort.h"
#include "HeapSort.h"

int main(int argc, const char * argv[])
{
  MergeSort<int> mSort;
  HeapSort<int> hSort;
  srand((unsigned)time(NULL));
  
  // Open CSV File and write its heasers
  oCSVFile csv("proj1results.csv");
  
  csv << "MS-Worst 1" << "MS-Worst 2" << "MS-Worst 3" << "MS-Worst avg"
      << "MS-Averg 1" << "MS-Averg 2" << "MS-Averg 3" << "MS-Averg avg"
      << "MS-Bestc 1" << "MS-Bestc 2" << "MS-Bestc 3" << "MS-Bestc avg"
      << "HS-Worst 1" << "HS-Worst 2" << "HS-Worst 3" << "HS-Worst avg"
      << "HS-Averg 1" << "HS-Averg 2" << "HS-Averg 3" << "HS-Averg avg"
      << "HS-Bestc 1" << "HS-Bestc 2" << "HS-Bestc 3" << "HS-Bestc avg";
  csv.newLine();
  
  // Begin primary for loop increasing at exp rate
  for (int n = 2; n < 1048577; n*=2)
  {
    // Generate random set of size n. Will be avg case for both sorts
    std::vector<int> baseSet;
    for (int i = 0; i < n; i++)
    {
      baseSet.push_back(rand());
    }
    
    // Create avg case for Merge Sort
    std::vector<int> MSAvg(baseSet);
    
    // Create best case for Merge Sort
    std::vector<int> MSBest(baseSet);
    std::sort(MSBest.begin(), MSBest.end());
    
    // Create worst case for Merge Sort
    std::vector<int> MSWorst(baseSet);
    for (int i = 0; i < n/2; i++)
    {
      MSWorst[i] = MSBest[2*i];
      MSWorst[i + n/2] = MSBest[2*i + 1];
    }
    
  }
  
  return 0;
}
