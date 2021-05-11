#pragma once
#include <string>
#include "Titular.hpp"

class Conta
{
private:
    static int numeroDeContas;

public:
    static int recuperaNumeroDeContas();

private:
    std::string numeroConta;
    Titular titular;
    float saldo = 0;

public:
    Conta (std::string numeroConta, Titular titular);
    ~Conta();

    void sacar (float valorASacar);
    void depositar (float valorADepositar);

    float getSaldo() const;
    std::string getNumeroConta();
};