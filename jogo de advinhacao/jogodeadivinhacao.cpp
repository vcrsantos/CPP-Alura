#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    bool jogar = true;
    bool acertou, maior, nao_acertou;

    char dificuldade, jogar_novamente;

    int numero_de_tentativas, chute, tentativas;

    double pontos, pontos_perdidos;

    cout << "************************************" << endl;
    cout << "* Bem-vindo ao jogo de adivinhação *" << endl;
    cout << "************************************" << endl;

    while (jogar){
        cout << "Escolha o seu nível de dificuldade: " << endl;
        cout << "Fácil (F), Médio (M), Díficil (D)" << endl;
        
        cin >> dificuldade;

        if (dificuldade == 'F' || dificuldade == 'f'){
            numero_de_tentativas = 15;
        }
        else if (dificuldade == 'M' || dificuldade == 'm'){
            numero_de_tentativas = 10;
        }
        else if (dificuldade == 'D' || dificuldade == 'd'){
            numero_de_tentativas = 5;
        }
        else{
            cout << "Opção inválida." << endl;
            return 0;
        }

        srand(time(NULL));
        const int NUMERO_SECRETO = rand()%100;

        pontos = 1000.0;

        nao_acertou = true;

        for (tentativas = 1; tentativas <= numero_de_tentativas; tentativas++)
        {
            cout << "Tentativa " << tentativas << endl;
            cout << "Qual seu chute? ";
            cin >> chute;

            pontos_perdidos = abs(chute - NUMERO_SECRETO)/2.0;
            pontos = pontos - pontos_perdidos;

            cout << "O valor do seu chute é: " << chute << endl;

            acertou = chute == NUMERO_SECRETO;
            maior = chute > NUMERO_SECRETO;

            if(acertou){
                cout << "Parabéns! Você acertou o número secreto!" << endl;
                nao_acertou = false;
                break;
            }
            else if (maior){
                cout << "Seu chute foi maior que o número secreto!" << endl;
            }
            else{
                cout << "Seu chute foi menor que o número secreto!" << endl;
            }
        }

        cout << "Fim de jogo!" << endl;

        if (nao_acertou){
            cout << "Você perdeu! Tente novamente!" << endl;
        }
        else{
            cout << "Você acertou o número secreto em " << tentativas << " tentativas." << endl;
            cout.precision(2);
            cout << fixed;
            cout << "Sua pontuação foi de " << pontos << " pontos." << endl;
        }

        cout << "Deseja jogar novamente? " << endl;
        cout << "Sim (S), Não(N)" << endl;

        cin >> jogar_novamente;

        if (jogar_novamente == 'N' || jogar_novamente == 'n'){
            cout << "Saindo..." << endl;
            return 0;
        }
    }

    return 0;
}