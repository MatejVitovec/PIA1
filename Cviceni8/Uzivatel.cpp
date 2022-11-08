#include "Uzivatel.h"

Uzivatel::Uzivatel()
{

}

Uzivatel::Uzivatel(std::string jmeno, std::string prijmeni, std::string vyska, std::string vek, std::string vzdelani)
{
    setJmeno(jmeno);
    setPrijmeni(prijmeni);
    setVyska(vyska);
    setVek(vek);
    setVzdelani(vzdelani);
}

void Uzivatel::setJmeno(std::string vstup)
{
    vstup[0] = toupper(vstup[0]);
    jmeno = vstup;
}

void Uzivatel::setPrijmeni(std::string vstup)
{
    vstup[0] = toupper(vstup[0]);
    prijmeni = vstup;
}

bool Uzivatel::setVyska(std::string vstup)
{
    //chtelo by to overeni na korektni vstup pro parsovani
    double auxVyska = std::stod(vstup);

    if(auxVyska > 30 && auxVyska < 250)
    {
        vyska = auxVyska;
        return true;
    }
    return false;
}

bool Uzivatel::setVek(std::string vstup)
{
    //chtelo by to overeni na korektni vstup pro parsovani
    int auxVek = std::stoi(vstup);
    if (auxVek > 0.0 && auxVek < 140)
    {
        vek = auxVek;
        return true;
    }
    return false;
}

bool Uzivatel::setVzdelani(std::string vstup)
{
    if (vstup == "zs")
    {
        vzdelani = zs;
        return true;
    }
    else if (vstup == "ss")
    {
        vzdelani = ss;
        return true;
    }
    else if (vstup == "vs")
    {
        vzdelani = vs;
        return true;
    }
    else
    {
        return false;
    }
}

std::string Uzivatel::getVzdelani()
{
    if (vzdelani == zs)
    {
        return "zakladni";
    }
    else if (vzdelani == ss)
    {
        return "stredni";
    }
    else if (vzdelani == vs)
    {
        return "vyskoskolske";
    }
    return "nezadano";
}

bool operator < (const Uzivatel& u1, const Uzivatel& u2)
{
    return u1.prijmeni < u2.prijmeni;
}