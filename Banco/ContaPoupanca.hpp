#include "Conta.hpp"
#include "Titular.hpp"

class ContaPoupanca final : public Conta{
public:
    ContaPoupanca(std::string numeroConta, Titular titular);
    float taxaDeSaque () const override;
};