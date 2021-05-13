#pragma once
#include <string>
#include <utility>
#include <variant>
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
    enum ResultadoSaque
    {
        ValorNegativo, SaldoInsuficiente
    };

    Conta (std::string numeroConta, Titular titular);
    virtual ~Conta();

    std::variant <ResultadoSaque, float> sacar (float valorASacar);
    void depositar (float valorADepositar);

    void operator+=(float valorADepositar);
    bool operator<(const Conta& conta);

    float getSaldo() const;
    std::string getNumeroConta();

    virtual float taxaDeSaque() const = 0;

    friend std::ostream& operator<< (std::ostream& cout, const Conta& conta);
};