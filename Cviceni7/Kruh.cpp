#include <cmath>
#include "Tvar.h"
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

//double Kruh::obsah() const
//{
//    return r*r*M_PI;
//}

bool Kruh::leziUvnitr(double xx, double yy) const
{
    double dist = std::sqrt(((x-xx)*(x-xx))+((y-yy)*(y-yy)));

    return dist < r;
}

double Kruh::x_min() const
{
    return x - r;
}
double Kruh::x_max() const
{
    return x + r;
}
double Kruh::y_min() const
{
    return y - r;
}
double Kruh::y_max() const
{
    return y + r;
}
