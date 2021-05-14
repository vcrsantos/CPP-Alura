#include "catch/catch.hpp"
#include "../src/Avaliador.hpp"

using namespace std;
Leilao emOrdemCrescente()
{
    // Arrange - Given
    Lance primeiroLance(Usuario("Victor Santos"), 1000);
    Lance segundoLance(Usuario("Amanda Correia"), 2000);
    Leilao leilao("Ford Ka 1.0 2013");
    leilao.recebeLance(primeiroLance);
    leilao.recebeLance(segundoLance);

    return leilao;
}
Leilao emOrdemDescrescente()
{
    // Arrange - Given
    Lance primeiroLance(Usuario("Victor Santos"), 1000.0);
    Lance segundoLance(Usuario("Amanda Correia"), 2000.0);
    Leilao leilao("Ford Ka 1.0 2013");
    leilao.recebeLance(segundoLance);
    leilao.recebeLance(primeiroLance);   

    return leilao; 
}

TEST_CASE("Avaliador"){
    // Arrange - Given (Geral)
    Avaliador leiloeiro;

    SECTION("Leilões em ordem"){
        // Arrange - Given (Especifico para essa SECTION)
        Leilao leilao = GENERATE(emOrdemCrescente(), emOrdemDescrescente());
        
        SECTION("Deve recuperar maior lance de leilao"){
            // Act - When
            leiloeiro.avalia(leilao);

            // Assert - Then
            REQUIRE (2000 == leiloeiro.recuperaMaiorValor());
        }

        SECTION("Deve recuperar menor lance de leilao"){            
            // Act - When
            leiloeiro.avalia(leilao);

            // Assert - Then
            REQUIRE (1000 == leiloeiro.recuperaMenorValor());
        }
    }

    SECTION("Deve recuperar os 3 maiores lances"){
        // Arrange - Given
        Lance primeiroLance(Usuario("Victor Santos"),  1000);
        Lance segundoLance (Usuario("Amanda Correia"), 2000);
        Lance terceiroLance(Usuario("Daniela Gomes"),  1500);
        Lance quartoLance  (Usuario("Bill Silva"),     2500);
        
        Leilao leilao("Ford Ka 1.0 2013");
        
        leilao.recebeLance(segundoLance);
        leilao.recebeLance(primeiroLance);
        leilao.recebeLance(terceiroLance);
        leilao.recebeLance(quartoLance);

        // Act - When
        leiloeiro.avalia(leilao);

        // Assert - Then
        vector<Lance> maiores3Lances = leiloeiro.recuperaMaiores3Lances(); 
        REQUIRE (3 == maiores3Lances.size());
        REQUIRE (2500 == maiores3Lances[0].recuperaValor());
        REQUIRE (2000 == maiores3Lances[1].recuperaValor());
        REQUIRE (1500 == maiores3Lances[2].recuperaValor());
    }
}