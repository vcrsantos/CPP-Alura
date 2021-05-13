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
    auto resultado = destino.sacar(valor);
    
    if (resultado.index() == 1){
        destino.depositar(valor);
    }
    
}

void ContaCorrente::operator+=(ContaCorrente& contaOrigem) 
{
    contaOrigem.tranferePara(*this, contaOrigem.getSaldo()/2);
}