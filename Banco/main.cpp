#include <iostream>
#include <string>
#include "Conta.hpp"
#include "Titular.hpp"
#include "CPF.hpp"

using namespace std;

int main(){
    Conta umaConta ("123456", Titular(CPF("123.123.123-10"), "Victor"));

    cout << "Conta: " << umaConta.getNumeroConta() << endl;

    umaConta.depositar(200);
    cout << "Valor: " << umaConta.getSaldo() << endl;

    umaConta.sacar(50);
    cout << "Valor: " << umaConta.getSaldo() << endl;    

    return 0;
}