#include "CPF.hpp"
#include <iostream>


CPF::CPF (std::string cpf):
cpf(cpf)
{
}


std::string CPF::getCPF (){
    return cpf;
}