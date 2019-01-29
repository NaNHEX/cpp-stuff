#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <boost/lexical_cast.hpp>
#include <cassert>

class Ipv4 {
    private:
        int m_mask;
        std::vector<unsigned> m_bytes;
    public:
        Ipv4 () : m_mask(0), m_bytes { 0 }
        {
        }

        Ipv4 (char* ipv4_addr) {
            size_t i(0);
            std::string segment;
            while (ipv4_addr[i]) {
                if (ipv4_addr[i] == '/')
                    break;
                ++i;
            }
            segment += ipv4_addr[++i];
            segment += ipv4_addr[++i];
            std::cout << segment << '\n';
            m_mask = std::stoi(segment);
            assert(m_mask > 0);
            ipv4_addr[i - 2] = '\0';

            std::stringstream addr(ipv4_addr);
            while (getline(addr, segment, '.')) {
                m_bytes.push_back(boost::lexical_cast<unsigned>(segment));
            }
        }

        friend std::ostream& operator<< (std::ostream &out, const Ipv4 &ipv4) {
            for (const auto &byte : ipv4.m_bytes) {
                out << byte;
            }
            out << '/' << ipv4.m_mask;
            return out;
        }
};

enum Ipv4Class {
    A,
    B,
    C,
    D,
    E
};

enum Hex {
    a,
    b,
    c,
    d,
    e,
    f
};

std::string HexTrans (std::string base10) {
    int byte = stoi(base10);
    std::string result;

    do {
        result.push_back(byte & 0xf);
        byte >>= 4;
    } while (byte != 0);

    return result;
}

Ipv4Class GetClass (std::string byte) {
    //TODO
    return A;
}

int main (int argc, char* argv[]) {
    assert(argc > 1 && argc < 3);
    Ipv4 addr(argv[1]);
    std::cout << addr << '\n';
    return 0;
}