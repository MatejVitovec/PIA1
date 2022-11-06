#include <cmath>
#include "Tvar.h"

double Tvar::obsah() const
{
    const int maxPocetBunek = 1000;
    
    double intervalX = x_max() - x_min();
    double intervalY = y_max() - y_min();
    double h;

    if (intervalX > intervalY)
    {
        h = (double)intervalX / maxPocetBunek;
    }
    else
    {
        h = (double)intervalY / maxPocetBunek;
    }
    
    int pocetBunekX = (int)std::ceil(intervalX/h) + 1;
    int pocetBunekY = (int)std::ceil(intervalY/h) + 1;

    double x0 = x_min() + h/2;
    double y0 = y_min() + h/2;
    const double ds = (double)(h*h);
    
    double x = x0;
    double y = y0;
    double S = 0.0;

    for (int j = 0; j < pocetBunekY; j++)
    {
        for (int i = 0; i < pocetBunekX; i++)
        {
            if (leziUvnitr(x,y))
            {
                S = S + ds;
            }
            x = x + h;
        }
        x = x0;
        y = y + h;
    }

    return S;
}