#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    std::string arg2 = argv[1];
    int n = std::stoi(arg2);

    for(int i(0); i < n; ++i) {
        for(int j(n-i); j > 0; --j) {
            std::cout << ' ';
            }
        for(int k(0); k < 2*i+1; ++k){
            std::cout << '*';
        }
        std::cout << '\n';
    }

    for(int i(n); i > 0; --i) {
        for(int j(0); j < 2*i+1; ++j) {
            std::cout << '*';
            }
        for(int k(0); k < n; ++k) {
            std::cout << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}