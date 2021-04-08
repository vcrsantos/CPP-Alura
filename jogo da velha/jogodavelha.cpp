#include <iostream>
#include <array>
#include <cstdlib>
#include <map>

using namespace std;

char tabuleiro [9];
bool posicao_preenchida [9];
map <char, bool> vencedor;

void inicia_tabuleiro(){
    for (int i = 0; i<9; i++){
        tabuleiro[i] = '_';
        posicao_preenchida[i] = false;
    }
}

void imprime_tabuleiro(){
    for (int i = 0; i<9; i+=3){
        cout << tabuleiro[i];
        cout << "|";
        cout << tabuleiro[i+1];
        cout << "|";
        cout << tabuleiro[i+2];
        cout << endl;
    }
}

bool foi_preenchido(int posicao){
    return tabuleiro[posicao] != '_';
}

char verifica_tabuleiro(){
    if (posicao_preenchida[0]){
        if (tabuleiro[0]==tabuleiro[1])
            if (tabuleiro[0]==tabuleiro[2])
                return tabuleiro[0];

        if (tabuleiro[0]==tabuleiro[3])
            if (tabuleiro[0]==tabuleiro[6])
                return tabuleiro[0];

        if (tabuleiro[0]==tabuleiro[4])
            if (tabuleiro[0]==tabuleiro[8])
                return tabuleiro[0];
    }

    if (posicao_preenchida[4]){
        if (tabuleiro[3]==tabuleiro[4])
            if (tabuleiro[3]==tabuleiro[5])
                return tabuleiro[3];

        if (tabuleiro[1]==tabuleiro[4])
            if (tabuleiro[1]==tabuleiro[7])
                return tabuleiro[1];

        if (tabuleiro[2]==tabuleiro[4])
            if (tabuleiro[2]==tabuleiro[6])
            return tabuleiro[2];
    }

    if (posicao_preenchida[8]){
        if (tabuleiro[6]==tabuleiro[7])
            if (tabuleiro[6]==tabuleiro[8])
                return tabuleiro[6];
        
        if (tabuleiro[2]==tabuleiro[5])
            if (tabuleiro[2]==tabuleiro[8])
                return tabuleiro[2];
    }

    return 'N';
}

bool velha(){
    for (int i = 0; i<9; i++){
        if(!posicao_preenchida[i])
            return false;
    }
    return true;
}

bool continua_jogo(){
    if (verifica_tabuleiro() != 'N' || velha())
        return false;

    return true;
}

void le_entrada(char jogador){
    int entrada;
    
    cout << endl;
    if(jogador == 'X')
        cout << "Vez do X, ";
    else
        cout << "Vez do O, ";

    cout << "digite a posição: ";
    cin >> entrada;

    while(foi_preenchido(entrada)){
        cout << "Posição já preenchida! Tente novamente." << endl;
        cout << "Digite a posição: ";
        cin >> entrada;
    }

    tabuleiro[entrada] = jogador;
    posicao_preenchida[entrada] = true; 
}

int main(){
    inicia_tabuleiro();

    while(continua_jogo()){
        imprime_tabuleiro();
        le_entrada('X');
        system("clear");  

        if (!continua_jogo())
            break;

        imprime_tabuleiro();
        le_entrada('O');
        system("clear");     
    }


    cout << "***Fim de jogo!***" << endl;
    imprime_tabuleiro();
    cout << endl;
    cout << "O vencedor é o " << verifica_tabuleiro() << endl;



    return 0;
}