#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "InputFileParser.h"
#include "PolygonBoundary.h"
#include "Mesh.h"
#include "Solver.h"
#include "ExportVTK.h"


int main(int argc, char** argv)
{
    std::string inputGeometryName = "geom3.txt";
    std::string inputInitName = "init.txt";
    std::string outputDirName = "results";

    if(argc == 4)
    {
        inputGeometryName = argv[1];
        inputInitName = argv[2];
        outputDirName = argv[3];
    }

    InputFileParser geomParser = InputFileParser();
    geomParser.readFile(inputGeometryName);
    geomParser.parse();
    std::vector<std::vector<double>> geomData = geomParser.getData();

    InputFileParser initParser = InputFileParser();
    initParser.readFile(inputInitName);
    initParser.parse();
    std::vector<std::vector<double>> initData = initParser.getData();

    double lambda = initData[0][0];
    double a = lambda/(initData[1][0]*initData[2][0]);
    double dx = initData[3][0];
    double dt = initData[4][0];
    double temp0 = initData[5][0];
    double endTime = initData[6][0];
    int plotEvery = initData[7][0];

    PolygonBoundary boundary = PolygonBoundary(geomData);

    Mesh mesh = Mesh(boundary, dx);

    Solver Temperature = Solver();
    Temperature.Init(mesh, temp0);
    
    int iterationEnd = int (endTime/dt);
    ExportVTK Exp = ExportVTK();
    
    for(int iteration = 0; iteration<iterationEnd; iteration++)
    {
        Temperature.Iter(dt, a, lambda, dx);
        Temperature.Stream();

        if(iteration%plotEvery==0)
        {
            Exp.Out(Temperature, iteration, plotEvery, outputDirName);
        }
    }

    std::cout << "Výpočet proběhl úspěšně!" << std::endl;

    return 0;
}