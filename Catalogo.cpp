#include "Catalogo.h"

bool Catalogo::loadFromCSV(const std::string &filename) {
    std::ifstream file;
    std::string   line, word;

    file.open(filename, std::ifstream::in);

    if (!file.is_open())
        return false;

    if (!std::getline(file, line)) {
        file.close();
        return false;
    }

    int num = 0;

    while (std::getline(file, line) && num < 2) {
        std::istringstream words(line);
        while (std::getline(words, word, ','))
            std::cout << word << std::endl;
        num++;
    }

    return true;
}
