#include "Titular.hpp"
#include <iostream>


Titular::Titular (CPF cpf, std::string nome, std::string senha) 
    : Pessoa(cpf,nome), Autenticavel(senha)
{
}