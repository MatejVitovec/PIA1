#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "InputFileParser.h"

InputFileParser::InputFileParser()
{
    std::vector<std::vector<double>> v;
    dataArray = v;
}

void InputFileParser::readFile(std::string path)
{
    std::ifstream stream;
    std::string line;

    stream.open(path, std::ios_base::in);

    if (stream.is_open())
    {
        while (std::getline(stream, line))
        {
            dataIn.push_back(line);
        }
    }
}

void InputFileParser::parse()
{
    int lineIdx = 0;
    bool lastSpace = false;
    std::string aux = "";
    dataArray.push_back(std::vector<double>());

    for (int j = 0; j < dataIn.size(); j++)
    {
        for (int i = 0; i < dataIn[j].size(); i++)
        {
            if (dataIn[j][i] == 35)
            {
                lastSpace = false;
                break;
            }
            else if(dataIn[j][i] == 32)
            {
                if(!lastSpace)
                {
                    double pomocna = stod(aux);

                    dataArray[lineIdx].push_back(std::stod(aux));
                    aux = "";
                    lastSpace = true;
                }
            }
            else if(dataIn[j][i] == 13)
            {
                dataArray[lineIdx].push_back(std::stod(aux));
                aux = "";
                dataArray.push_back(std::vector<double>());
                lineIdx++;
            }
            else
            {
                lastSpace = false;
                aux = aux + dataIn[j][i];
            }


        }
    }
    dataArray[lineIdx].push_back(std::stod(aux));
}

std::vector<std::vector<double>> InputFileParser::getData()
{
    return dataArray;
}

InputFileParser::~InputFileParser()
{
    
}