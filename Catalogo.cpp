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

    int count = 0, num = 0;

    while (std::getline(file, line) && num < 2) {
        std::istringstream words(line);
        Monster            miMonstruo;
        while (std::getline(words, word, ',')) {
            switch (count) {
                case 0: {
                    miMonstruo.setName(word);
                    break;
                }
                case 1: {
                    float numero = std::stod(word);
                    miMonstruo.setCR(numero);
                    break;
                }
                case 2: {
                    miMonstruo.setType(word);
                    break;
                }
                case 3: {
                    miMonstruo.setSize(word);
                    break;
                }
                case 4: {
                    int numero = std::stoi(word);
                    miMonstruo.setAC(numero);
                    break;
                }
                case 5: {
                    int numero = std::stoi(word);
                    miMonstruo.setHP(numero);
                    break;
                }
                case 6: {
                    miMonstruo.setAlign(word);
                    break;
                }
                default:
                    break;
                    ;
            }
            count++;
        }
        catalogoMonstruos.insertar(miMonstruo);
        count = 0;
    }

    return true;
}

Monster Catalogo::getRandomMonster() {
    NodeBT<Monster> *randomNode = catalogoMonstruos.getRandomNode();  // Obtener el nodo aleatorio
    if (randomNode != nullptr) {
        return randomNode->dato;  // Devolver el Monster almacenado en el nodo
    }
    throw std::runtime_error("No hay monstruos en el catálogo.");
}
