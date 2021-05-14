#pragma once
#include "Leilao.hpp"

class Avaliador
{
private:
    float maiorValor = INT64_MIN;
    float menorValor = INT64_MAX;
    std::vector<Lance> maiores3Lances;

private:
    static bool ordenaLances(const Lance&, const Lance&);

public:
    Avaliador();
    void avalia(Leilao);
    float recuperaMaiorValor() const;
    float recuperaMenorValor() const;
    std::vector<Lance> recuperaMaiores3Lances() const;
};