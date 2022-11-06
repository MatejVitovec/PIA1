#include <iostream>
#include <memory>
#include "Tvar.h"
#include "Kruh.h"
#include "Kyticka.h"
//#include "Srdce.h"

int main()
{
    std::shared_ptr<Tvar> utvar;

    int utvar_id;
    std::cout << "Vyberte druh utvaru (1 - kruh, 2 - kyticka, 3 - srdce): " << std::endl;
    std::cin >> utvar_id;

    if (utvar_id == 1)
    {
        utvar = std::make_shared<Kruh>(0.0, 0.0, 2.0);
    }
    else if (utvar_id == 2)
    {
        utvar = std::make_shared<Kyticka>(0.0,0.0,6.0);
    }
    //else if (utvar_id == 3) {
    //    utvar = std::make_shared<Srdce>(0.0,0.0);
    //}
    else {
	    std::cout << "Neznamy tvar.\n";
	    return 1; 
    }

    double obsah = utvar->obsah();

    std::cout << "Obsah utvaru je " << obsah << std::endl;

    return 0;
}