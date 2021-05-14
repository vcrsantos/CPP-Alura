#include "catch/catch.hpp"
#include "../src/Usuario.hpp"

TEST_CASE("Usuário deve saber informar seu primeiro nome"){
    SECTION("Usuário com dois nomes"){
        Usuario victor("Victor Santos");

        std::string primeiroNome = victor.recuperaPrimeiroNome();

        REQUIRE("Victor" == primeiroNome);
    }

    SECTION("Usuário com um nome"){
        Usuario victor("Victor");

        std::string nome = victor.recuperaPrimeiroNome();

        REQUIRE("Victor" == nome);
    }
}