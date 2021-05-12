#include "Pessoa.hpp"
#include <iostream>

Pessoa::Pessoa(CPF cpf, std::string nome):
cpf(cpf),
nome(nome)
{
    Pessoa::verificaTamanhoNome();
}

void Pessoa::verificaTamanhoNome (){
    if (nome.size() < 5){
        std::cout << "Nome muito curto." << std::endl;
        exit(1);
    }
}