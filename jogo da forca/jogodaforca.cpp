#include <iostream>
#include <string>
#include <map> 
#include <vector> 
#include <fstream> 
#include <ctime> 
#include <cstdlib> 

using namespace std;

string palavra_secreta = "MELANCIA";
map<char, bool> chutou;
vector<char> chutes_errados;


bool letra_existe (char chute){
    for (char letra : palavra_secreta){
        if (chute == letra){
            return true;
        }
    }

    return false;
}

bool nao_acertou (){
    for (char letra : palavra_secreta){
        if(!chutou[letra]){
            return true;
        }
    }
    return false;
}

bool nao_enforcou(){
    return chutes_errados.size() < 6;
}

void imprime_cabecalho (){
    cout << "******************************" << endl;
    cout << "* Bem-vindo ao jogo da forca *" << endl;
    cout << "******************************" << endl;
    cout << endl;
}

void imprime_erros(){
    cout << "Chutes errados: ";
    for(char letra:  chutes_errados){
        cout << letra << " ";
    }
    cout << endl;
}

void imprime_palavra(){
    for(char letra:  palavra_secreta){
        if(chutou[letra]){
            cout << letra << " ";
        }
        else{
            cout << "_ ";
        }
    }
    cout << endl;
}

void imprime_forca(){
    int quantidade_erros;
    quantidade_erros = chutes_errados.size();

    cout << "______" << endl;
    cout << "|    | " << endl;

    if (quantidade_erros == 0){
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        return;
    }

    if (quantidade_erros == 1){ //cabeça
        cout << "|    O" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        return;
    }

    if (quantidade_erros == 2){ //corpo
        cout << "|    O" << endl;
        cout << "|    |" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        return;
    }

    if (quantidade_erros == 3){ //braço E
        cout << "|    O" << endl;
        cout << "|   /|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        return;
    }

    if (quantidade_erros == 4){ //braco D
        cout << "|    O" << endl;
        cout << "|   /|\\" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        return;
    }

    if (quantidade_erros == 5){ //perna E
        cout << "|    O" << endl;
        cout << "|   /|\\" << endl;
        cout << "|   /" << endl;
        cout << "|" << endl;
        return;
    }

    if (quantidade_erros == 6){ //perna D
        cout << "|    O" << endl;
        cout << "|   /|\\" << endl;
        cout << "|   / \\" << endl;
        cout << "|" << endl;
        return;
    }
}

void chuta(){
    char chute;
    
    cout << "Seu chute: ";
    cin >> chute;
    chute = toupper(chute);
    chutou[chute] = true;

    if (letra_existe(chute)){
        cout << "Você acertou! Seu chute está na palavra!" << endl;
    }
    else{
        cout << "Você errou! Seu chute não está na palavra!" << endl;
        chutes_errados.push_back(chute);
    }

    cout << endl;
}

vector<string> le_arquivo(){
    ifstream arquivo;
    int quantidade_palavras;
    string palavra_lida;

    vector<string> palavras_do_arquivo;

    arquivo.open("palavras.txt");
    
    if(arquivo.is_open()){
        arquivo >> quantidade_palavras;
        for (int i=0; i<quantidade_palavras; i++){
            arquivo >> palavra_lida;
            palavras_do_arquivo.push_back(palavra_lida);
        }

        arquivo.close();
        return palavras_do_arquivo;
    }
    else{
        cout << "Não foi possível acessar o banco de palavras." << endl;
        exit(0);
    }
}

void sorteia_palavra(){
    vector<string> palavras = le_arquivo();

    srand(time(NULL));
    int indice_sorteado = rand() % palavras.size();

    palavra_secreta = palavras[indice_sorteado];
}

void salva_arquivo(vector<string> nova_lista){
    ofstream arquivo;
    arquivo.open("palavras.txt");

    if (arquivo.is_open()){
        arquivo << nova_lista.size() << endl;
        for (string palavra : nova_lista){
            arquivo << palavra << endl;
        }
        arquivo.close();
    }
    else{
        cout << "Não foi possível acessa banco de palavras." << endl;
    }
}

void adiciona_palavra(){
    cout << "Digite a nova palavra: ";

    string nova_palavra;
    cin >> nova_palavra;

    vector<string> lista_palavras = le_arquivo();
    lista_palavras.push_back(nova_palavra);

    salva_arquivo(lista_palavras);
}

bool jogando_novamente(){
    cout << "Deseja jogar novamente? (S/N)" << endl;
    char jogar_novamente;
    cin >> jogar_novamente;
    if(jogar_novamente == 'N' || jogar_novamente == 'n'){
       return false;
    }
    
    chutou.clear();
    chutes_errados.clear();
    system("clear");
    return true;
    
}


int main(){    
    while(true){
        imprime_cabecalho();

        sorteia_palavra();

        while (nao_acertou() && nao_enforcou()){
            imprime_forca();

            imprime_erros();

            imprime_palavra();

            chuta();

            system("clear");
        }

        cout << "Fim de Jogo!" << endl;
        cout << "A palavra era: " << palavra_secreta << endl;

        if (nao_acertou()){
            imprime_forca();
            cout << "Você perdeu! Tente Novamente!" << endl;
        }
        else{
            cout << "Parabéns! Você acertou a palavra secreta!" << endl;
            cout << "Deseja adicionar uma nova palavra no banco? (S/N)" << endl ;
            char resposta;
            cin >> resposta;
            if ( resposta == 'S' || resposta == 's'){
                adiciona_palavra();
            }
        }

        if (!jogando_novamente())
            return 0;
    }
}