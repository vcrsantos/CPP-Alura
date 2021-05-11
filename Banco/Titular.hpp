#pragma once
#include <string>
#include "CPF.hpp"

class Titular
{
private:
    CPF cpf;
    std::string nome;

public:
    Titular(CPF cpf, std::string nome);

    std::string getCPF();
    std::string getNome();
    
private:
    void verificaTamanhoNome();

};