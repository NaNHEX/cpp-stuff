//Exercice 5
#include <iostream>
#include <chrono>
#include <thread>
#include <math.h>
#include <random>

int findTheNumber(int toGuess, int lowRange, int highRange) {
    int possibleGuesses = lowRange + highRange - 1;
    int guess = std::ceil(possibleGuesses / 2.0);
    std::cout << guess << '\n';

    if(guess < toGuess) {
        lowRange = guess + 1;
    }
    else if(guess > toGuess) {
        highRange = guess - 1;
    }
    else if(guess == toGuess) {
        return guess;
    }

    return findTheNumber(toGuess, lowRange, highRange);
}

int main() {
    srand(time(NULL));


    /* int winCount = 0;
    while(winCount < 1000) {
        unsigned int lowestRange = 1;
        unsigned int highestRange = 100;
        unsigned int numberToGuess = rand() % highestRange + 1;
        unsigned int guess = 0;
        int guessCount = 0;

        while(guess != numberToGuess) {
            unsigned int possibleGuesses = lowestRange + highestRange - 1;
            guess = std::ceil(possibleGuesses / 2.0);

            if(guess < numberToGuess) {
                lowestRange = guess + 1;
            }
            else if(guess > numberToGuess) {
                highestRange = guess - 1;
            }
            ++guessCount;
        }
        std::cout << guessCount << '\n';
        ++winCount;
    } */

    int guess = findTheNumber(54, 0, 100);
    std::cout << '\n' << guess << '\n';
    return 0;
}