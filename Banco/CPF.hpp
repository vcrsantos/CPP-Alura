#pragma once
#include <string>

class CPF
{
    private:
        std::string cpf;

    public:
        CPF(std::string cpf);

        std::string getCPF();
};