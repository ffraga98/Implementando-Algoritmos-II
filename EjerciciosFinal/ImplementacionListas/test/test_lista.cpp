#include "../lista.h"
#include <iostream>
#include "catch.hpp"


TEST_CASE("Testing all methods of Lista"){
	Lista<std::string>* lista = new Lista<std::string>();

	SECTION("Inicialitation of Lista"){
		REQUIRE(lista -> obtener_longitud() == 0);
		//REQUIRE(lista -> obtener_nodo(1) == nullptr);
	} 

	SECTION("method: vacia()"){
		REQUIRE(lista -> vacia() == true);
		lista -> insertar("Fer",1);
		REQUIRE(lista -> vacia() != true);
	} 

	SECTION("method: obtener_longitud()"){
		REQUIRE(lista -> obtener_longitud() == 0);
		lista -> insertar("Fer",1);
		REQUIRE(lista -> obtener_longitud() == 1);
		lista -> insertar("Fraga",2);
		REQUIRE(lista -> obtener_longitud() == 2);
	} 
/*
	SECTION("method: obtener_nodo(int pos)"){
		REQUIRE(lista -> obtener_nodo(1) == nullptr);
		lista -> insertar("Fer",1);
		REQUIRE(lista -> obtener_nodo(1) -> obtener_dato() == "Fer");
		lista -> insertar("Fraga",2);
		REQUIRE(lista -> obtener_nodo(1) -> obtener_dato() == "Fer");
		REQUIRE(lista -> obtener_nodo(2) -> obtener_dato() == "Fraga");

		lista -> insertar("102369",3);
		REQUIRE(lista -> obtener_nodo(1) -> obtener_dato() == "Fer");
		REQUIRE(lista -> obtener_nodo(2) -> obtener_dato() == "Fraga");
		REQUIRE(lista -> obtener_nodo(3) -> obtener_dato() == "102369");
		REQUIRE(lista -> obtener_nodo(3) -> obtener_siguiente() == nullptr);

	} 
*/

	SECTION("method: insertar(T d, int pos)"){
		lista -> insertar("Fernando", 1);
		REQUIRE( lista -> obtener_longitud() == 1);
		REQUIRE( lista -> obtener_dato(1) == "Fernando");

		lista -> insertar("Fraga", 2);
		REQUIRE( lista -> obtener_dato(2) == "Fraga");
		REQUIRE( lista -> obtener_longitud() == 2);

		lista -> insertar("102369", 1);
		REQUIRE( lista -> obtener_dato(1) == "102369");
		REQUIRE( lista -> obtener_longitud() == 3);

		lista -> insertar("Fer", 2);
		REQUIRE( lista -> obtener_dato(2) == "Fer");
		REQUIRE( lista -> obtener_longitud() == 4);
	}
 	
 	SECTION("method: eliminar(int pos)"){
 		lista -> insertar("Hola4",1);
 		lista -> insertar("Hola3",1);
 		lista -> insertar("Hola2",1);
 		lista -> insertar("Hola1",1);

 		lista -> eliminar(3);
 		REQUIRE(lista -> obtener_dato(3) == "Hola4" );
 	
 		lista -> eliminar(1);
 		REQUIRE(lista -> obtener_dato(1) == "Hola2" );

 		lista -> eliminar(2);
 		REQUIRE(lista -> obtener_longitud() == 1);
 	
 	}


 	 SECTION("method: cambiar_dato(T d,int pos)"){
 		lista -> insertar("Hola4",1);
 		lista -> insertar("Hola3",1);
 		lista -> insertar("Hola2",1);
 		lista -> insertar("Hola1",1);

		lista -> cambiar_dato("1",1);
 		REQUIRE(lista -> obtener_dato(1) == "1" );

 		lista -> cambiar_dato("2",2);
 		REQUIRE(lista -> obtener_dato(2) == "2" );

 		lista -> cambiar_dato("3",3);
 		REQUIRE(lista -> obtener_dato(3) == "3" );
 
 		lista -> cambiar_dato("4",4);
 		REQUIRE(lista -> obtener_dato(4) == "4" );
 	
 	}

	lista -> insertar("Hola1",1);
	Lista<std::string>* lista2 = lista;
 	SECTION("Copy constructor"){
 		lista2 -> insertar("Hola2",1);

 		REQUIRE(lista -> obtener_longitud() == 1);
 		REQUIRE(lista2 -> obtener_longitud() == 2);
 	}

}