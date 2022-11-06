#include <iostream>
#include "Kruh.h"

int main()
{
    Kruh k(7.0,5.0, 3.0);
    k.posun(-1,2);

    k.vypis();
    std::cout << "Obvod kruhu: " << k.obvod() << std::endl;
    std::cout << "Obsah kruhu: " << k.obsah() << std::endl;    
    std::cout << std::endl;
    std::cout << "Je bod (5, 6) uvnitr: " << (k.jeBodvnitr(6.0, 6.0) ? "Ano" : "Ne") << std::endl;
    std::cout << "Je bod (3, 2) uvnitr: " << (k.jeBodvnitr(3.0, 2.0) ? "Ano" : "Ne") << std::endl;
}