#ifndef DATABAZOVYSYSTEM_H
#define DATABAZOVYSYSTEM_H

#include <vector>
#include "Uzivatel.h"

class DatabazovySystem
{
    public:
        DatabazovySystem();

        void pridejUzivatele();

        void seradUzivatele();

        void ulozDoSouboru(std::string nazevSouboru);

    private:
        std::vector<Uzivatel> uzivatele; 
};

#endif // DATABAZOVYSYSTEM_H