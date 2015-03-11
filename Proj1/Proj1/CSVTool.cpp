//
//  CSVTool.cpp
//  Proj1
//
//  Created by Jack Moore on 3/11/15.
//  Copyright (c) 2015 Jack Moore and Julia Calandro. All rights reserved.
//

#include "CSVTool.h"


oCSVFile::oCSVFile(const std::string fileName, const std::string delim, const char separ)
{
  m_outputFile.open(fileName);
  m_delim = delim;
  m_separ = separ;
}

void oCSVFile::newLine()
{
  m_outputFile << m_delim;
}

void oCSVFile::close()
{
  m_outputFile.close();
}

void oCSVFile::open(const std::string fileName)
{
  m_outputFile.open(fileName);
}
