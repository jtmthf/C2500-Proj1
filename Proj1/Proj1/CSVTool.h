//
//  CSVTool.h
//  Proj1
//
//  Created by Jack Moore on 3/11/15.
//  Copyright (c) 2015 Jack Moore and Julia Calandro. All rights reserved.
//

#ifndef __Proj1__CSVTool__
#define __Proj1__CSVTool__

#include <fstream>
#include <string>
#include <sstream>

class oCSVFile
{
  std::ofstream m_outputFile;
  std::string m_delim;
  char m_separ;
  bool firstColumn;
  
public:
  
  oCSVFile() : m_outputFile(), m_delim("\r\n") {}
  
  oCSVFile(const std::string fileName, const std::string delim = "\r\n", const char separ = ',');
  
  void newLine();
  
  void close();
  
  void open(const std::string fileName);
  
  template <typename T>
  friend oCSVFile& operator << (oCSVFile& file, const T& data)
  {
    std::stringstream format;
    std::string text;
    
    // Write textual data to stringstream
    format << data;
    
    // Write back to string
    text = format.str();
    
    if (!file.firstColumn)
    {
      file.m_outputFile << file.m_separ;
    }
    file.m_outputFile << text;
    
    return file;
  }
};

#endif /* defined(__Proj1__CSVTool__) */
