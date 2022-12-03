#include "RobotOne.h"

bool RobotOne::start(Bludiste & map) { 

    // Tady muzete doplnit kod pro inicializaci robota

    historie.clear();
    historie.push_back(map.poloha());
    minulySmer.s = 0;

    return true; 
}

bool RobotOne::start(BludisteOdkryte & map) { 

    // Tady muzete doplnit kod pro inicializaci robota pri prochazeni znameho bludiste

    return true; 
}

bool RobotOne::stop() {

    // Tady muzete doplnit kod pro zastaveni robota

    return true;
}

void RobotOne::krok(Bludiste & map) { 
    
    // Tato metoda se bude opakovat, dokud robot nedosahne cile nebo maximalniho poctu kroku

    SmerProti auxSmer = minulySmer - 1;


    if(!(std::find(historie.begin(), historie.end(), urciPlanovanouPolohu(map.poloha(), auxSmer)) != historie.end()) && jdiSmerem(map, auxSmer))
    {
        historie.push_back(map.poloha());
        minulySmer = auxSmer;
    }    
    else if (!(std::find(historie.begin(), historie.end(), urciPlanovanouPolohu(map.poloha(), auxSmer+1)) != historie.end()) && jdiSmerem(map, auxSmer+1))
    {
        historie.push_back(map.poloha());
        minulySmer = auxSmer + 1;
    }        
    else if (!(std::find(historie.begin(), historie.end(), urciPlanovanouPolohu(map.poloha(), auxSmer+2)) != historie.end()) && jdiSmerem(map, auxSmer+2))
    {
        historie.push_back(map.poloha());
        minulySmer = auxSmer + 2;
    }
    else if (!(std::find(historie.begin(), historie.end(), urciPlanovanouPolohu(map.poloha(), auxSmer+3)) != historie.end()) && jdiSmerem(map, auxSmer+3))
    {
        historie.push_back(map.poloha());
        minulySmer = auxSmer + 3;
    }
    else
    {
        //pokud se musi vracet
        if(jdiSmerem(map, auxSmer))
        {
            historie.push_back(map.poloha());
            minulySmer = auxSmer;
        }    
        else if (jdiSmerem(map, auxSmer+1))
        {
            historie.push_back(map.poloha());
            minulySmer = auxSmer + 1;
        }        
        else if (jdiSmerem(map, auxSmer+2))
        {
            historie.push_back(map.poloha());
            minulySmer = auxSmer + 1;
        }
        else if (jdiSmerem(map, auxSmer+3))
        {
            historie.push_back(map.poloha());
            minulySmer = auxSmer + 1;
        }
    }

}

void RobotOne::krok(BludisteOdkryte & map) { 
    
    // Tato metoda se bude opakovat, dokud robot nedosahne cile nebo maximalniho poctu kroku
    // Verze pro odkryte bludiste

}

std::string RobotOne::jmeno() {

    // Tato metoda by mela vratit jmeno robota
    return "RobotOne";
}

bool RobotOne::jdiSmerem(Bludiste & map, SmerProti smer)
{
    if (smer.s == 0)
    {
        return map.vpravo();
    }
    else if (smer.s == 1)
    {
        return map.nahoru();
    }
    else if (smer.s == 2)
    {
        return map.vlevo();
    }
    else
    {
        return map.dolu();
    }    
}


Souradnice RobotOne::urciPlanovanouPolohu(Souradnice poloha, SmerProti smer)
{
    if(smer.s == 0)
    {
        poloha.x += 1;
    }
    else if(smer.s == 1)
    {
        poloha.y += 1;
    }
    else if(smer.s == 2)
    {
        poloha.x -= 1;
    }
    else
    {
        poloha.y -= 1;
    }

    return poloha;
}