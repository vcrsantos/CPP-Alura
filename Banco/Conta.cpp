#include "Conta.hpp"
#include <iostream>

int Conta::numeroDeContas = 0;

Conta::Conta (std::string numeroConta, Titular titular):
    numeroConta(numeroConta),
    titular(titular)
{
    numeroDeContas ++;
}


Conta::~Conta(){
    numeroDeContas --;
}

std::variant <Conta::ResultadoSaque, float> Conta::sacar (float valorASacar){
    if (valorASacar < 0){
        std::cout << "Não pode sacar valor negativo." << std::endl;
        return ValorNegativo;
    } 

    float tarifaDeSaque = valorASacar * taxaDeSaque();
    float valorDoSaque = valorASacar + tarifaDeSaque;

    if (valorASacar > saldo){
        std::cout << "Saldo insuficiente." << std::endl;
        return SaldoInsuficiente;
    }

    saldo -= valorDoSaque;
    return saldo;
}

void Conta::depositar (float valorADepositar){
    if (valorADepositar < 0){
        std::cout << "Não pode sacar valor negativo." << std::endl;
        return;
    }

    saldo += valorADepositar;
}


void Conta::operator+=(float valorADepositar)
{
    depositar(valorADepositar);
}

bool Conta::operator<(const Conta& conta)
{
    return this->saldo < conta.saldo;
}


float Conta::getSaldo() const{
    return saldo;
}

std::string Conta::getNumeroConta(){
    return numeroConta;
}

int Conta::recuperaNumeroDeContas(){
    return numeroDeContas;
}
