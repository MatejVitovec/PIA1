#include <iostream>
#include <algorithm>
#include <fstream>

#include "DatabazovySystem.h"

DatabazovySystem::DatabazovySystem()
{

}

void DatabazovySystem::pridejUzivatele()
{
    Uzivatel auxUzivatel;

    std::string vstupJmeno;
    std::string vstupPrijmeni;
    std::string vstupVyska;
    std::string vstupVek;
    std::string vstupVzdelani;

    std::cout << "Zadejte jmeno:";
    std::cin >> vstupJmeno;
    auxUzivatel.setJmeno(vstupJmeno);

    std::cout << "Zadejte prijmeni:";
    std::cin >> vstupPrijmeni;
    auxUzivatel.setPrijmeni(vstupPrijmeni);

    std::cout << "Zadejte vysku v cm:";
    while(1)
    {        
        std::cin >> vstupVyska;
        if (auxUzivatel.setVyska(vstupVyska))
        {
            break;
        }
        std::cout << std::endl;
        std::cout << "Zadali jste spatnou vysku, zadejte znovu: ";
    }

    std::cout << "Zadejte vek: ";
    while(1)
    {        
        std::cin >> vstupVek;
        if (auxUzivatel.setVek(vstupVek))
        {
            break;
        }
        std::cout << std::endl;
        std::cout << "Zadali jste spatny vek, zadejte znovu: ";
    }

    std::cout << "Zadejte vzdelani (zs, ss, vs): ";
    while(1)
    {        
        std::cin >> vstupVzdelani;
        if (auxUzivatel.setVzdelani(vstupVzdelani))
        {
            break;
        }
        std::cout << std::endl;
        std::cout << "Zadali jste spatny vek, zadejte znovu: ";
    }

    uzivatele.push_back(auxUzivatel);
}

void DatabazovySystem::seradUzivatele()
{
    std::sort(uzivatele.begin(), uzivatele.end());
}

void DatabazovySystem::ulozDoSouboru(std::string nazevSouboru)
{
    std::ofstream vystupniSouboor(nazevSouboru);
    //writeToFile << domLen << std::endl;
    

    for (int i = 0; i < uzivatele.size(); i++)
    {
        vystupniSouboor << uzivatele[i].prijmeni << ", " << uzivatele[i].jmeno << ", " << uzivatele[i].vyska << ", " << uzivatele[i].vek << ", " << uzivatele[i].vzdelani << std::endl;
        
    }
    
    vystupniSouboor.close();
}