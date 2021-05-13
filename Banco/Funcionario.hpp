#pragma once
#include <string>
#include "CPF.hpp"
#include "Funcionario.hpp"
#include "Pessoa.hpp"
#include "DiaDaSemana.hpp"

class Funcionario : public Pessoa<CPF>
{
private:
    float salario;
    //0 - Domingo, 1 - Segunda ...
    DiaDaSemana diaDoPagamento;

public:
    Funcionario (CPF cpf, std::string nome, float salario, DiaDaSemana diaDoPagamento);
    std::string getNome() const;
    virtual float bonificacao() const = 0;
    float getSalario() const;
};