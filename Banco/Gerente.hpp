#include "Funcionario.hpp"
#include "Autenticavel.hpp"

class Gerente final: public Funcionario, Autenticavel 
{
public:
    Gerente(CPF cpf, std::string nome, float salario, std::string senha);
    float bonificacao() const;
};