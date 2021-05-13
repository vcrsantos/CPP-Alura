#include "Caixa.hpp"

Caixa::Caixa (CPF cpf, std::string nome, float salario, DiaDaSemana diaDoPagamento) 
    : Funcionario(cpf, nome, salario, diaDoPagamento)
{
}

float Caixa::bonificacao () 
{
    return getSalario() * 0.1;
}