#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "error: not enough arguments\n";
        return -1;
    }
    else if (argc > 2) {
        std::cout << "error: too many arguments\n";
        return -1;
    }

    std::string arg2 = argv[1];
    int in = std::stoi(arg2);
    std::vector<int> binary;

    unsigned un;
    if (in < 0) {
        un = unsigned(~(-in)) + 1u;
    }
    else un = unsigned(in);

    do {
        binary.push_back(un & 1);
        un /= 2;
    } while (un != 0);

    for (size_t i(binary.size()); i > 0; --i) {
        std::cout << binary[i-1];
    }
    std::cout << '\n';
    return 0;
}