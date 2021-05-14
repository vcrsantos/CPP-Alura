#include "Leilao.hpp"

Leilao::Leilao(std::string descricao): descricao(descricao)
{
    
}

const std::vector<Lance>& Leilao::recuperaLances() const
{
    return lances;
}

bool Leilao::comparaUltimoUsuario(const Lance& lance) const
{
    return lances.back().recuperaNomeUsuario() != lance.recuperaNomeUsuario();
}

void Leilao::recebeLance(const Lance& lance)
{
    if(lances.size() == 0 || comparaUltimoUsuario(lance)){
        lances.push_back(lance);
    }
    
}
