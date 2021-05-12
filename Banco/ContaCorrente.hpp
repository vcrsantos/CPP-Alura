#include "Conta.hpp"
#include "Titular.hpp"

class ContaCorrente final : public Conta{
public:
    ContaCorrente(std::string numeroConta, Titular titular);
    float taxaDeSaque() const override;
    void tranferePara(Conta& conta, float valor);
};