#include <iostream>
#include <string>
#include "Conta.hpp"
#include "ContaCorrente.hpp"
#include "ContaPoupanca.hpp"
#include "Titular.hpp"
#include "CPF.hpp"
#include "Funcionario.hpp"
#include "Gerente.hpp"
#include "Caixa.hpp"

using namespace std;

void RealizarSaque (Conta& conta){
    std::variant<Conta::ResultadoSaque, float> resultado = conta.sacar(200);
    if(auto saldo = std::get_if<float>(&resultado)){
        cout << "Novo saldo da conta é: " << *saldo << endl;
    }
}

void FazLogin (Autenticavel& alguem, string senha) 
{
    if (alguem.autentica(senha)){
        cout << "Login realizado com sucesso" << endl;
    } else {
        cout << "Senha inválida" << endl;
    }
}


ostream& operator<< (ostream& cout, const Conta& conta)
{
    Pessoa titular = conta.titular;
    cout << titular.getNome() << ", seu saldo é de: " << conta.getSaldo() << endl;
    return cout;
}

template<typename T>
T Menor(T a, T b)
{
    return a < b ? a : b;
}


int main(){
    Titular titular (CPF("123.123.123-10"), "Victor", "senha123");
    
    ContaCorrente Conta1 ("123456", titular);
    cout << "1 - Conta de " << Conta1.getNumeroConta() << endl;
    Conta1.depositar(500);
    //cout << "    Saldo: " << Conta1.getSaldo() << endl;
    cout << Conta1;

    ContaPoupanca Conta2 ("654321", Titular(CPF("321.321.321-01"), "Amanda", "unicasenha"));

    cout << "2 - Conta de " << Conta2.getNumeroConta() << endl;
    Conta2.depositar(500);
    RealizarSaque(Conta2);
    cout << "    Saldo: " << Conta2.getSaldo() << endl;

    (Conta&) Conta2 += 100;

    cout << "    Saldo: " << Conta2.getSaldo() << endl;

    cout << "A menor conta é: " << Menor<Conta&>(Conta1, Conta2) << endl;


    /*Conta1.tranferePara(Conta2, 200);
    cout << endl << "Transferencia:" << endl;
    cout << "    Conta 1 Saldo: " << Conta1.getSaldo() << endl;
    cout << "    Conta 2 Saldo: " << Conta2.getSaldo() << endl;*/

    ContaCorrente ContaC3("123", titular);
    ContaC3 += Conta1;

    cout << "Saldo ContaC3: " << ContaC3.getSaldo() << endl;
    cout << "Saldo Conta1: " << Conta1.getSaldo() << endl;

    RealizarSaque(Conta1);

    Gerente umGerente(CPF("111.111.111-10"), "Daniela", 4000.0, "olaf123", DiaDaSemana::Terca);

    return 0;
}