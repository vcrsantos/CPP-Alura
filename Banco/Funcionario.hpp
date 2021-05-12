#pragma once
#include <string>
#include "CPF.hpp"
#include "Funcionario.hpp"
#include "Pessoa.hpp"

class Funcionario : public Pessoa
{
private:
    float salario;   

public:
    Funcionario (CPF cpf, std::string nome, float salario);
    std::string getNome() const;
    virtual float bonificacao() const = 0;
    float getSalario() const;
};