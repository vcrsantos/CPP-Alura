#include <iostream>
#include <string>
#include <map>
#include <array>
#include "../include/chuta.hpp"
#include "../include/imprime_cabecalho.hpp"
#include "../include/imprime_erros.hpp"
#include "../include/imprime_palavra.hpp"
#include "../include/nao_acertou.hpp"
#include "../include/adiciona_palavra.hpp"
#include "../include/sorteia_palavra.hpp"

using namespace std;
using namespace Forca;

static string palavra_secreta; 
static map<char, bool> chutou;
static array<char, 5> chutes_errados;
int numero_chutes;

int main () {
    imprime_cabecalho();

    palavra_secreta = sorteia_palavra();

    while(nao_acertou(palavra_secreta, chutou) && numero_chutes < 5){
        imprime_erros(chutes_errados);

        imprime_palavra(palavra_secreta, chutou);

        chuta(chutes_errados, chutou, palavra_secreta, numero_chutes);
    }

    cout << "Fim de jogo!" << endl;
    cout << "A palavra secreta era: " << palavra_secreta << endl;
    if(nao_acertou(palavra_secreta, chutou)){
        cout << "Você perdeu! Tente novamente!" << endl;
    }
    else{
        cout << "Parabéns! Você acertou a palavra secreta!" << endl;

        cout << "Você deseja adicionar uma nova palavra ao banco? (S/N) ";
        char resposta;
        cin >> resposta;
        if(resposta == 'S'){
            adiciona_palavra();
        }
    }
    
    cin.get();
}