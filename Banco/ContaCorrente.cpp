#include "ContaCorrente.hpp"
#include <iostream>

ContaCorrente::ContaCorrente (std::string numeroConta, Titular titular) : 
Conta(numeroConta, titular)
{
}

float ContaCorrente::taxaDeSaque () const
{
    return 0.05;
}

void ContaCorrente::tranferePara(Conta& destino, float valor)
{
    sacar(valor);
    destino.depositar(valor);
}