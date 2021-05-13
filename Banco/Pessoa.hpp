#pragma once
#include <string>
#include <iostream>

template<typename Documento>
class Pessoa{
protected:
    Documento documento;
    std::string nome; 
    
public:
    Pessoa(Documento documento, std::string nome):
    documento(documento),
    nome(nome)
    {
        Pessoa::verificaTamanhoNome();
    }

    std::string getNome() const
    {
        return nome;
    }

private:
    void verificaTamanhoNome()
    {
        if (nome.size() < 5){
            std::cout << "Nome muito curto." << std::endl;
            exit(1);
        }
    }
};