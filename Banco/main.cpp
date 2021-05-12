#include <iostream>
#include <string>
#include "Conta.hpp"
#include "ContaCorrente.hpp"
#include "ContaPoupanca.hpp"
#include "Titular.hpp"
#include "CPF.hpp"
#include "Funcionario.hpp"

using namespace std;

void RealizarSaque (Conta& conta){
    conta.sacar(200);
}

void FazLogin (Autenticavel& alguem, string senha) 
{
    if (alguem.autentica(senha)){
        cout << "Login realizado com sucesso" << endl;
    } else {
        cout << "Senha inválida" << endl;
    }
}

int main(){
    ContaCorrente Conta1 ("123456", Titular(CPF("123.123.123-10"), "Victor", "senha"));

    cout << "1 - Conta de " << Conta1.getNumeroConta() << endl;
    Conta1.depositar(500);
    RealizarSaque(Conta1);
    cout << "    Saldo: " << Conta1.getSaldo() << endl;

    ContaPoupanca Conta2 ("654321", Titular(CPF("321.321.321-01"), "Amanda", "unicasenha"));

    cout << "2 - Conta de " << Conta2.getNumeroConta() << endl;
    Conta2.depositar(500);
    RealizarSaque(Conta2);
    cout << "    Saldo: " << Conta2.getSaldo() << endl;


    Conta1.tranferePara(Conta2, 200);
    cout << endl << "Transferencia:" << endl;
    cout << "    Conta 1 Saldo: " << Conta1.getSaldo() << endl;
    cout << "    Conta 2 Saldo: " << Conta2.getSaldo() << endl;

    return 0;
}