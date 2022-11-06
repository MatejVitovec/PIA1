#include <iostream>
#include <fstream>
#include <forward_list>
#include <string>

std::forward_list<int> nacteniDat(std::string cesta)
{
    std::forward_list<int> vectorCisel = {0};
    std::ifstream soubor(cesta);    
    std::string line;

    std::forward_list<int>::iterator it = vectorCisel.begin();
    std::getline(soubor, line);
    *it = std::stoi(line);

    while(std::getline(soubor, line))
    {
        vectorCisel.insert_after(it,std::stoi(line));
        it++;
    }

    return vectorCisel;
}


std::forward_list<int> bubbleSort(std::forward_list<int> data)
{
    bool zmena = true;

    while(zmena)
    {
        zmena = false;

        std::forward_list<int>::iterator it = data.begin();
        std::forward_list<int>::iterator itOld = it;
        it++;

        do
        {            
            if (*it < *itOld)
            {
                int pom = *it;
                *it = *itOld;
                *itOld = pom;
                
                zmena = true;
            }
            itOld = it;
            it++;
        } while(it != data.end());
    }
    
    return data;
}


void ulozeniDoSouboru(std::forward_list<int> data, std::string nazevSouboru)
{
    std::ofstream zapisDoSouboru(nazevSouboru);

    for(std::forward_list<int>::iterator it = data.begin(); it != data.end(); it++)
    {
        zapisDoSouboru << *it << std::endl;
    }    
}


int main()
{
    std::forward_list<int> data = nacteniDat("data.txt");
    std::forward_list<int> setridene = bubbleSort(data);
    ulozeniDoSouboru(setridene, "setridene.txt");

    return 0;
}


