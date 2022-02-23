#include "../nodo.h"
#include <iostream>
#include "catch.hpp"

TEST_CASE("Inicialitation of Node"){
	Nodo<std::string>* nodo = new Nodo<std::string>("Fer");
	
	SECTION("Creation"){
		REQUIRE(nodo -> obtener_dato() == "Fer");
		REQUIRE(nodo -> obtener_siguiente() == nullptr);
	}

	Nodo<std::string>* nodo2 = new Nodo<std::string>("Fraga");

	SECTION("Inicialitation of siguiente"){
		nodo -> cambiar_siguiente( nodo2 );
		REQUIRE(nodo -> obtener_siguiente() -> obtener_dato() == "Fraga" );
	}
}

TEST_CASE("Modification of atributes"){
	Nodo<std::string>* nodo = new Nodo<std::string>("Fer");
	
	SECTION("Changing dato"){
		nodo -> cambiar_dato("Fraga");
		REQUIRE(nodo -> obtener_dato() == "Fraga");
	}

	SECTION("Changing siguiente"){
		nodo -> cambiar_siguiente(nodo);
		REQUIRE(nodo -> obtener_siguiente() != nullptr);
	}
}