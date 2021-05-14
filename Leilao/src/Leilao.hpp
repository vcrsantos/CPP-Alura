#pragma once
#include <vector>
#include <string>
#include "Lance.hpp"

class Leilao
{
private:
    std::vector<Lance> lances;
    std::string descricao;

public:
    Leilao(std::string descricao);
    const std::vector<Lance>& recuperaLances() const;
    void recebeLance(const Lance& lance);
private:
    bool comparaUltimoUsuario(const Lance& lance) const;
};
