#include <iostream>
#include "../include/imprime_erros.hpp"

using namespace std;

void Forca::imprime_erros(const array<char, 5>& chutes_errados){
    cout << "Chutes errados: ";
    for(char letra: chutes_errados){
        cout << letra << " ";
    }
    cout << endl;
}