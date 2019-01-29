//Exercice 6
#include <iostream>

int main() {
    unsigned n;
    std::cin >> n;
    std::cout << '\n';

    for(unsigned i(0); i < n; ++i) {
        for(unsigned j(n-i); j > 0; --j) {
            std::cout << ' ';
            }
        for(unsigned k(0); k < 2*i+1; ++k){
            std::cout << '*';
        }
        std::cout << '\n';
    }

    return 0;
}
