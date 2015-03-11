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
  std::vector<int> trialSet;

  
  // Open CSV File and write its heasers
  oCSVFile csv("proj1results.csv");
  
  csv << "n"
      << "MS-Worst 1" << "MS-Worst 2" << "MS-Worst 3" << "MS-Worst avg"
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
    
    // Create worst case for Merge Sort. Items are staggered across the array
    std::vector<int> MSWorst(baseSet);
    for (int i = 0; i < n/2; i++)
    {
      MSWorst[i] = MSBest[2*i];
      MSWorst[i + n/2] = MSBest[2*i + 1];
    }
    
    // Create avg case for Heap Sort
    std::vector<int> HSAvg(baseSet);
    
    // Create best case of Heap Sort. Currently observed to be reverse order
    std::vector<int> HSBest(baseSet);
    std::reverse(HSBest.begin(), HSBest.end());
    
    // Create worst case of Heap Sort. Currently observed to be forward order
    std::vector<int> HSWorst(MSBest);
    
    // Write n to csv file
    csv << n;
    
    // Run trials for each Set
    for (int i = 0; i < 3; i++)
    {
      trialSet = std::vector<int>(MSWorst);
      std::chrono::high_resolution_clock::time_point t1 = std::chrono::steady_clock::now();
      mSort.sort(trialSet);
      std::chrono::high_resolution_clock::time_point t2 = std::chrono::steady_clock::now();
      std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
      csv << time_span.count();
    }
    // blank entry for average
    csv << ' ';
    
    for (int i = 0; i < 3; i++)
    {
      trialSet = std::vector<int>(MSAvg);
      std::chrono::high_resolution_clock::time_point t1 = std::chrono::steady_clock::now();
      mSort.sort(trialSet);
      std::chrono::high_resolution_clock::time_point t2 = std::chrono::steady_clock::now();
      std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
      csv << time_span.count();
    }
    // blank entry for average
    csv << ' ';

    for (int i = 0; i < 3; i++)
    {
      trialSet = std::vector<int>(MSBest);
      std::chrono::high_resolution_clock::time_point t1 = std::chrono::steady_clock::now();
      mSort.sort(trialSet);
      std::chrono::high_resolution_clock::time_point t2 = std::chrono::steady_clock::now();
      std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
      csv << time_span.count();
    }
    // blank entry for average
    csv << ' ';
    
    for (int i = 0; i < 3; i++)
    {
      trialSet = std::vector<int>(HSWorst);
      std::chrono::high_resolution_clock::time_point t1 = std::chrono::steady_clock::now();
      hSort.sort(trialSet);
      std::chrono::high_resolution_clock::time_point t2 = std::chrono::steady_clock::now();
      std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
      csv << time_span.count();
    }
    // blank entry for average
    csv << ' ';
    
    for (int i = 0; i < 3; i++)
    {
      trialSet = std::vector<int>(HSAvg);
      std::chrono::high_resolution_clock::time_point t1 = std::chrono::steady_clock::now();
      hSort.sort(trialSet);
      std::chrono::high_resolution_clock::time_point t2 = std::chrono::steady_clock::now();
      std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
      csv << time_span.count();
    }
    // blank entry for average
    csv << ' ';
    
    for (int i = 0; i < 3; i++)
    {
      trialSet = std::vector<int>(HSBest);
      std::chrono::high_resolution_clock::time_point t1 = std::chrono::steady_clock::now();
      hSort.sort(trialSet);
      std::chrono::high_resolution_clock::time_point t2 = std::chrono::steady_clock::now();
      std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
      csv << time_span.count();
    }
    // blank entry for average
    csv << ' ';
    
    baseSet.clear();
  }
  
  return 0;
}
