#include <vector>
#include "../include/le_arquivo.hpp"
#include "../include/sorteia_palavra.hpp"

using namespace std;

string Forca::sorteia_palavra(){
    vector<string> palavras = Forca::le_arquivo();

    srand(time(NULL));
    int indice_sorteado = rand() % palavras.size();

    return palavras[indice_sorteado];
}
