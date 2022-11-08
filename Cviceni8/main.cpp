#include <iostream>
#include "DatabazovySystem.h"
#include "Uzivatel.h"


int main()
{
    DatabazovySystem datSys = DatabazovySystem();

    while (1)
    {
        datSys.pridejUzivatele();

        std::cout << "Chcete pridat dalsiho uzivatele? (y/n): ";
        std::string vstup;
        std::cin >> vstup;
        if (vstup == "n")
        {
            break;
        }
    }

    datSys.seradUzivatele();
    
    datSys.ulozDoSouboru("vystup.txt");

    return 0;
}