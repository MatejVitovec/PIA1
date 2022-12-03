#ifndef ROBORONE_H
#define ROBORONE_H

#include <vector>
#include <algorithm>
#include "Prohledavac.h"

struct SmerProti
{
    int s;

    const bool operator++()
    {
        if (s > 2)
        {
            s = 0;
        }
        else
        {
            s++;
        }
    }
    
    const SmerProti operator+(int i)
    {
        SmerProti out;
        int ss = s + i;

        if(ss > 3)
        {
            out.s = 0 + (ss%4);
            if(out.s == 4)
            {
                out.s = 0;
            }
        }
        else
        {
            out.s = ss;
        }
        return out;
    }

    const SmerProti operator-(int i)
    {
        SmerProti out;
        int ss = s - i;

        if(ss < 0)
        {
            out.s = 4 + (ss%4);
            if(out.s == 4)
            {
                out.s = 0;
            }
        }
        else
        {
            out.s = ss;
        }
        return out;
    }
};


class RobotOne : public Prohledavac {
public:
    virtual bool start(Bludiste & map);
    virtual bool start(BludisteOdkryte & map);
    virtual bool stop();
    virtual void krok(Bludiste & map);
    virtual void krok(BludisteOdkryte & map);
    virtual std::string jmeno();

private:
    std::vector<Souradnice> historie;
    SmerProti minulySmer;

    bool jdiSmerem(Bludiste & map, SmerProti smer);
    Souradnice urciPlanovanouPolohu(Souradnice poloha, SmerProti smer);

};

#endif