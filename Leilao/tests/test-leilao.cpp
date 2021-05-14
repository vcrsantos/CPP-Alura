#include "catch/catch.hpp"
#include "../src/Leilao.hpp"
#include "../src/Usuario.hpp"

TEST_CASE("Leilão não deve receber lances consecutivos do mesmo usuário"){
    // Arrange
    Leilao leilao("Ford Ka 1.0 2013");
    Usuario victor("Victor Santos");

    Lance primeiroLance(victor, 1000);
    Lance segundoLance (victor, 1500);

    // Act
    leilao.recebeLance(primeiroLance);
    leilao.recebeLance(segundoLance);

    // Assert
    REQUIRE(1 == leilao.recuperaLances().size());
    REQUIRE(1000 == leilao.recuperaLances()[0].recuperaValor());
}