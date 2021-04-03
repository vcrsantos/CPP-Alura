#include <iostream>
#include <string>
#include <map>
#include "../include/imprime_palavra.hpp"

using namespace std;

void Forca::imprime_palavra (const string& palavra_secreta, const map<char, bool>& chutou){
    for(char letra : palavra_secreta){
        if(chutou.find(letra) == chutou.end() || !chutou.at(letra)){
            cout << "_ ";
        }
        else{
            cout << letra << " ";
        }
    }
    cout << endl;
}