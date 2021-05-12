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

protected:
    float saldo = 0;

public:
    Conta (std::string numeroConta, Titular titular);
    virtual ~Conta();

    void sacar (float valorASacar);
    void depositar (float valorADepositar);

    float getSaldo() const;
    std::string getNumeroConta();

    virtual float taxaDeSaque() const = 0;
};