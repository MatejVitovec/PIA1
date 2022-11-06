#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::string jmeno;
    std::string prijmeni;
    float vyska;
    int vek;
    std::string vzdelani;

    std::cout << "Zadejte krestni jmeno:";
    std::cin >> jmeno;

    std::cout << "Zadejte prijmeni:";
    std::cin >> prijmeni;

    while(1)
    {
        std::cout << "Zadejte vysku v cm:";
        std::cin >> vyska;
        if (vyska > 0 && vyska < 300)
        {
            break;
        }
        std::cout << "Zadali jste spatnou vysku" << std::endl;
    }

    while(1)
    {
        std::cout << "Zadejte vek:";
        std::cin >> vek;
        if (vyska > 0 && vek < 130)
        {
            break;
        }
        std::cout << "Zadali jste spatny vek" << std::endl;
    }

    while(1)
    {
        std::cout << "Zadejte vydelani (zs, ss, vs):";
        std::cin >> vzdelani;
        if (vzdelani == "zs")
        {
            break;
        }
        else if (vzdelani == "ss")
        {
            break;
        }
        else if (vzdelani == "vs")
        {
            break;
        }
        std::cout << "Zadali jste vydelani ve satnem formatu" << std::endl;
    }


    std::string nazevSouboru = jmeno;
    nazevSouboru += prijmeni;
    nazevSouboru += ".txt";

    std::ofstream zapisDoSouboru(nazevSouboru);

    zapisDoSouboru << "jmeno: " << jmeno << std::endl;
    zapisDoSouboru << "prijmeni: " << prijmeni << std::endl;
    zapisDoSouboru << "vyska: " << vyska << std::endl;
    zapisDoSouboru << "vek: " << vek << std::endl;
    zapisDoSouboru << "vzdelani: " << vzdelani << std::endl;


    return 0;
}
