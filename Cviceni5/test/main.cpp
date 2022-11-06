#include <iostream>
#include <vector>

int main() {
    std::vector<int> a = {1,2,3,5,9};
    for(std::vector<int>::iterator it = a.begin(); it != a.end(); it++)
    {
        *it = *it + 1;
        std::cout << *it << "\n";
    }
    
    return 0;
}
