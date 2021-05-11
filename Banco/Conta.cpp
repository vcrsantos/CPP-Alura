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


void Conta::sacar (float valorASacar){
    if (valorASacar < 0){
        std::cout << "Não pode sacar valor negativo." << std::endl;
        return;
    }
    if (valorASacar > saldo){
        std::cout << "Saldo insuficiente." << std::endl;
        return;
    }

    saldo -= valorASacar;
}

void Conta::depositar (float valorADepositar){
    if (valorADepositar < 0){
        std::cout << "Não pode sacar valor negativo." << std::endl;
        return;
    }

    saldo += valorADepositar;
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
