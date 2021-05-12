#include "Caixa.hpp"

Caixa::Caixa (CPF cpf, std::string nome, float salario) : Funcionario(cpf, nome, salario)
{
}

float Caixa::bonificacao () 
{
    return getSalario() * 0.1;
}