#include <iostream>
#include <cstdlib>
#include <ctime>

int game(int maxnum);

int main() {
    int maxnum;
    std::cout << "Anna suurin mahdollinen luku: ";
    std::cin >> maxnum;

    int guessAmount = game(maxnum);

    std::cout << "Arvasit oikein " << guessAmount << " arvauksen jalkeen\n";
    return 0;
}

int game(int maxnum) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int randomNum = std::rand() % maxnum + 1;

    int guess = 0;
    int guessAmount = 0;

    std::cout << "luku valilta 1-" << maxnum << ". arvaa\n";

    while (true) {
        std::cout << "arvauksesi: ";
        std::cin >> guess;
        guessAmount++;

        if (guess < randomNum) {
            std::cout << "Luku on suurempi kuin " << guess << ". Yrita uudelleen.\n";
        } else if (guess > randomNum) {
            std::cout << "Luku on pienempi kuin " << guess << ". Yrita uudelleen.\n";
        } else {
            std::cout << "Oikein " << randomNum << ".\n";
            break;
        }
    }

    return guessAmount;
}
