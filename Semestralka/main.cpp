#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "InputFileParser.h"
#include "PolygonBoundary.h"
#include "Mesh.h"


int main()
{
    InputFileParser parser1 = InputFileParser();
    parser1.readFile("data.txt");
    parser1.parse();
    std::vector<std::vector<int>> data1 = parser1.getData();

    PolygonBoundary boundary1 = PolygonBoundary(data1);

    Mesh mesh1 = Mesh(boundary1);

    // debug
    /*std::ofstream zapisDoSouboru("vystup.txt");    
    for (int j = 0; j < mesh1.nodeList.size(); j++)
    {
        for (int i = 0; i < mesh1.nodeList[j].size(); i++)
        {
            int vystup = (int)mesh1.nodeList[j][i];
            
            if (vystup > 1)
            {
                //vystup = (mesh1.boundaryNodeList[mesh1.nodeList[j][i]].param1);
                if(mesh1.boundaryNodeList[mesh1.nodeList[j][i]].orientation == Mesh::top)
                {
                    vystup = 2;
                }
                else if(mesh1.boundaryNodeList[mesh1.nodeList[j][i]].orientation == Mesh::right)
                {
                    vystup = 3;
                }
                else if(mesh1.boundaryNodeList[mesh1.nodeList[j][i]].orientation == Mesh::bottom)
                {
                    vystup = 4;
                }
                else if(mesh1.boundaryNodeList[mesh1.nodeList[j][i]].orientation == Mesh::left)
                {
                    vystup = 5;
                }
                else if(mesh1.boundaryNodeList[mesh1.nodeList[j][i]].orientation == Mesh::topRight)
                {
                    vystup = 6;
                }
                else if(mesh1.boundaryNodeList[mesh1.nodeList[j][i]].orientation == Mesh::bottomRight)
                {
                    vystup = 7;
                }
                else if(mesh1.boundaryNodeList[mesh1.nodeList[j][i]].orientation == Mesh::bottomLeft)
                {
                    vystup = 8;
                }
                else if(mesh1.boundaryNodeList[mesh1.nodeList[j][i]].orientation == Mesh::topLeft)
                {
                    vystup = 9;
                }
            }

            zapisDoSouboru << vystup << " ";
        }
        zapisDoSouboru << std::endl;
    }*/
    
    return 0;
}