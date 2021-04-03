#include <iostream>
#include "../include/letra_existe.hpp"
#include "../include/chuta.hpp"

using namespace std;

void Forca::chuta(array<char, 5>& chutes_errados, map<char, bool>& chutou, string& palavra_secreta, int& numero_chutes){
    cout << "Seu chute: ";
    char chute;
    cin >> chute;

    chutou[chute] = true;

    if(Forca::letra_existe(chute, palavra_secreta)){
        cout << "Você acertou! Seu chute está na palavra." << endl;
    }
    else{
        cout << "Você errou! Seu chute não está na palavra." << endl;
        chutes_errados[numero_chutes] = chute;
        numero_chutes ++;
    }
    cout << endl;
}