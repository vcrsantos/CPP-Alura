#include <iostream>
#include "../include/le_arquivo.hpp"
#include "../include/salva_arquivo.hpp"
#include "../include/adiciona_palavra.hpp"

void Forca::adiciona_palavra() {
    cout << "Digite a nova palavra, usando letras maiúsculas." << endl;
    string nova_palavra;
    cin >> nova_palavra;

    vector<string> lista_palavras = Forca::le_arquivo();
    lista_palavras.push_back(nova_palavra);

    Forca::salva_arquivo(lista_palavras);
}