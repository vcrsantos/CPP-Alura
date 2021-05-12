#pragma once
#include <string>
#include "CPF.hpp"

class Pessoa{
protected:
    CPF cpf;
    std::string nome; 
    
public:
    Pessoa(CPF cpf, std::string nome);

private:
    void verificaTamanhoNome();
};