#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::vector<int> nacteniDat(std::string cesta)
{
    std::vector<int> vectorCisel;
    std::ifstream soubor(cesta);    
    std::string line;

    while (std::getline(soubor, line))
    {
        vectorCisel.push_back(std::stoi(line));
    }

    return vectorCisel;
}


void prohozeni(std::vector<int>& data, int idx)
{
    int pom = data[idx];
    data[idx] = data[idx-1];
    data[idx-1] = pom;
}

std::vector<int> bubbleSort(std::vector<int> data)
{
    bool zmena = true;
    int velikostPole = data.size();

    while(zmena)
    {
        zmena = false;
        int i = 1;

        while (i <= velikostPole)
        {
            if (data[i] < data[i-1])
            {
                prohozeni(data, i);
                zmena = true;
            }
            i++;
        }        
    }
    
    return data;
}


void ulozeniDoSouboru(std::vector<int> data, std::string nazevSouboru)
{
    std::ofstream zapisDoSouboru(nazevSouboru);

    for (int i = 0; i < data.size(); i++)
    {
        zapisDoSouboru << data[i] << std::endl;
    }
    
}


int main()
{
    std::vector<int> data = nacteniDat("data.txt");
    std::vector<int> setridene = bubbleSort(data);
    ulozeniDoSouboru(setridene, "setridene.txt");

    return 0;
}


