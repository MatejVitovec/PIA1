#ifndef UZIVATEL_H
#define UZIVATEL_H

#include <string>

class Uzivatel
{
    enum VzdelaniTyp {zs, ss, vs};

    public:
        Uzivatel();
        Uzivatel(std::string jmeno, std::string prijmeni, std::string vyska, std::string vek, std::string vzdelani);

        void setJmeno(std::string vstup);
        void setPrijmeni(std::string vstup);
        bool setVyska(std::string vstup);
        bool setVek(std::string vstup);
        bool setVzdelani(std::string vstup);

        std::string getVzdelani();

        std::string jmeno;
        std::string prijmeni;
        double vyska;
        int vek;
        VzdelaniTyp vzdelani;
};

bool operator < (const Uzivatel& u1, const Uzivatel& u2);


#endif // UZIVATEL_H