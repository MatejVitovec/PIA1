#include <cmath>
#include <iostream>
#include "Kruh.h"

Kruh::Kruh()
{
    x = 0.0;
    y = 0.0;
    r = 1.0;
}

Kruh::Kruh(double xx, double yy , double rr)
{
    x = xx;
    y = yy;
    r = rr;
}

void Kruh::posun(double xx, double yy)
{
    x += xx;
    y += yy;
}

double Kruh::obvod() const
{
    return 2*r*M_PI;
}

double Kruh::obsah() const
{
    return r*r*M_PI;
}

bool Kruh::jeBodvnitr(double xx, double yy) const
{
    double d = std::sqrt(((x-xx)*(x-xx))+((y-yy)*(y-yy)));

    return d < r;
}

void Kruh::vypis() const
{
    std::cout << "Souradnice kruhu x:"<< x << " y:" << y << std::endl;
    std::cout << "Polomer kruhu r: "<< r << std::endl;
}

Kruh::~Kruh()
{
    
}