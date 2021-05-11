#include "Titular.hpp"
#include <iostream>


Titular::Titular (CPF cpf, std::string nome):
cpf(cpf),
nome(nome)
{
    Titular::verificaTamanhoNome();
}

std::string Titular::getNome(){
    return nome;
}


void Titular::verificaTamanhoNome (){
    if (nome.size() < 5){
        std::cout << "Nome muito curto." << std::endl;
        exit(1);
    }
}
