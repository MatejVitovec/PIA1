#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    std::vector<int> vectorCisel;

    int cislaOd = 1847;
    int cislaDo = 6383;
    int pocetCisel = 0;
    int suma = 0;
    float prumer = 0;

    std::ifstream soubor("data.txt");    
    std::string line;

    while (std::getline(soubor, line))
    {
        vectorCisel.push_back(std::stoi(line));
    }

    for (int i = 0; i < vectorCisel.size(); i++)
    {
        if (vectorCisel[i] > cislaOd && vectorCisel[i] < cislaDo)
        {
            pocetCisel++;
            suma += vectorCisel[i];
        }
    }
    prumer = (float)suma / pocetCisel;
    
    std::cout << "Pocet cisel ze zedaneho intervalu: " << pocetCisel << std::endl;
    std::cout << "Prumer cisel ze zadaneho intervalu: " << prumer << std::endl;
    
    return 0;
}