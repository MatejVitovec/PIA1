#include <cmath>
#include "Tvar.h"
#include "Kyticka.h"

Kyticka::Kyticka()
{
    x = 0.0;
    y = 0.0;
    f = 1.0;
}

Kyticka::Kyticka(double xx, double yy , double ff)
{
    x = xx;
    y = yy;
    f = ff;
}

bool Kyticka::leziUvnitr(double xx, double yy) const
{    
    return sqrt((x+xx)*(x+xx) + (y + yy)*(y + yy)) < fabs(sin(f*atan2((yy-y),(xx-x))));
}

double Kyticka::x_min() const
{
    return -1;
}
double Kyticka::x_max() const
{
    return 1;
}
double Kyticka::y_min() const
{
    return -1;
}
double Kyticka::y_max() const
{
    return 1;
}
