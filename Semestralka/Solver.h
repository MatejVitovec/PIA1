#ifndef SOLVER_H
#define SOLVER_H
#include <vector>
#include "Mesh.h"

#pragma once

class Solver
{
public:
    Mesh mesh;
    std::vector<std::vector<double>> U_n;
    std::vector<std::vector<double>> U_n1;

    Solver();
    void Init(Mesh mesh_input, double T0);
    void Iter(double timestep, double a, double lambda, double h);
    void Stream();

    ~Solver();

private:

};

#endif