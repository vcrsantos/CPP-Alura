#include "Gerente.hpp"

Gerente::Gerente (CPF cpf, std::string nome, float salario, std::string senha, DiaDaSemana diaDoPagamento) 
    : Funcionario(cpf, nome, salario, diaDoPagamento), Autenticavel(senha)
{
}

float Gerente::bonificacao () const
{
    return getSalario() * 0.5;
}