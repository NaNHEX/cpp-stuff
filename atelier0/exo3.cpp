//Exercice 3
#include <iostream>
#include <random>
#include <algorithm>


class Dices {
    private:
        static const unsigned short m_size = 3;
        unsigned short m_dices[m_size];
    public:
        Dices() {
            srand(time(NULL));
            for(int i(0); i < m_size; ++i) {
                m_dices[i] = rand() % 6 + 1;
            }
        }

        void printDices() {
            for(int i(0); i < m_size; ++i){
                std::cout << "dice " << i + 1 << " : " << m_dices[i] << '\n';
            }
        }

        bool is421() {
                if(std::find(m_dices, m_dices + m_size, 4) != m_dices + m_size
                   && std::find(m_dices, m_dices + m_size, 2) != m_dices + m_size
                   && std::find(m_dices, m_dices + m_size, 1) != m_dices + m_size) {
                   return true;
                }
                else {
                    return false;
                }
        }

        void rerollDice(unsigned short number) {
            m_dices[number - 1] = rand() % 6 + 1;
        }

        //TODO:
        int play() {
            int rerollCounter = 0;
            while(!is421()) {
                for(int i(0); i < m_size; ++i) {
                    printDices();
                    if((m_dices[i] != 4 || m_dices[i] != 2 || m_dices[i] != 1)) {
                        rerollDice(i);
                        ++rerollCounter;
                    }
                }
            }
            return rerollCounter;
        }
};

int main() {
    Dices dices;
    int counter = dices.play();
    dices.printDices();
    std::cout << counter << "rerolls!\n";
    return 0;
}