#include "../lista.h"
#include "catch.hpp"

TEST_CASE("1) Intercambio de nodos en la lista."){
//1) Método que, dadas dos posiciones, intercambia sus datos.
	Lista<std::string> lista = Lista<std::string>();
	
	lista.insertar("Hola1",1);
	lista.insertar("Hola2",2);
	lista.insertar("Hola3",3);
	lista.insertar("Hola4",4);

	SECTION("Intercambio posiciones"){

		lista.intercambio_nodos(1,4); //Como los datos pueden ser pesados elijo intercambiar punteros.
		REQUIRE(lista.obtener_dato(1) == "Hola4");
		REQUIRE(lista.obtener_dato(4) == "Hola1");

		lista.intercambio_nodos(1,2);
		REQUIRE(lista.obtener_dato(1) == "Hola2");
		REQUIRE(lista.obtener_dato(2) == "Hola4");


		lista.intercambio_nodos(3,1);
		REQUIRE(lista.obtener_dato(1) == "Hola3");
		REQUIRE(lista.obtener_dato(3) == "Hola2");


		lista.intercambio_nodos(4,3);
		REQUIRE(lista.obtener_dato(3) == "Hola1");
		REQUIRE(lista.obtener_dato(4) == "Hola2");


		lista.intercambio_nodos(1,1);
		REQUIRE(lista.obtener_dato(1) == "Hola3");
		REQUIRE(lista.obtener_dato(2) == "Hola4");
		REQUIRE(lista.obtener_dato(3) == "Hola1");
		REQUIRE(lista.obtener_dato(4) == "Hola2");

	}
}

TEST_CASE("1) Intercambio de contenidos en la lista."){
//1) Método que, dadas dos posiciones, intercambia sus datos.
	Lista<std::string> lista = Lista<std::string>();
	
	lista.insertar("Hola1",1);
	lista.insertar("Hola2",2);
	lista.insertar("Hola3",3);
	lista.insertar("Hola4",4);

	SECTION("Intercambio posiciones"){

		lista.intercambio_datos(1,4); //Como los datos pueden ser pesados elijo intercambiar punteros.
		REQUIRE(lista.obtener_dato(1) == "Hola4");
		REQUIRE(lista.obtener_dato(4) == "Hola1");

		lista.intercambio_datos(1,2);
		REQUIRE(lista.obtener_dato(1) == "Hola2");
		REQUIRE(lista.obtener_dato(2) == "Hola4");


		lista.intercambio_datos(3,1);
		REQUIRE(lista.obtener_dato(1) == "Hola3");
		REQUIRE(lista.obtener_dato(3) == "Hola2");


		lista.intercambio_datos(4,3);
		REQUIRE(lista.obtener_dato(3) == "Hola1");
		REQUIRE(lista.obtener_dato(4) == "Hola2");


		lista.intercambio_datos(1,1);
		REQUIRE(lista.obtener_dato(1) == "Hola3");
		REQUIRE(lista.obtener_dato(2) == "Hola4");
		REQUIRE(lista.obtener_dato(3) == "Hola1");
		REQUIRE(lista.obtener_dato(4) == "Hola2");

	}
}
TEST_CASE("2) Unión de listas"){
//2) Método que une la lista original con otra que se pasa por parámetro, modificando a la
//lista que llama. La lista pasada por parámetro va al final.
	Lista<std::string>* lista = new Lista<std::string>();
	
	SECTION("Union cuando lista esta vacía"){
		Lista<std::string>* lista2 = new Lista<std::string>();
		lista2 -> insertar("Hola5",1);	
		lista2 -> insertar("Hola6",2);	
		lista2 -> insertar("Hola7",3);	
		lista2 -> insertar("Hola8",4);	
		lista -> concatenar(lista2);
		REQUIRE(lista -> obtener_dato(1) ==  "Hola5");
		REQUIRE(lista -> obtener_dato(2) ==  "Hola6");
		REQUIRE(lista -> obtener_dato(3) ==  "Hola7");
		REQUIRE(lista -> obtener_dato(4) ==  "Hola8");
	}

	lista -> insertar("Hola1",1);
	lista -> insertar("Hola2",2);
	lista -> insertar("Hola3",3);
	lista -> insertar("Hola4",4);

	SECTION("Union de lista vacia"){
		Lista<std::string>* lista2 = new Lista<std::string>();
		lista -> concatenar(lista2);
		REQUIRE(lista -> obtener_dato(1) == "Hola1");
		REQUIRE(lista -> obtener_dato(2) == "Hola2");
		REQUIRE(lista -> obtener_dato(3) == "Hola3");
		REQUIRE(lista -> obtener_dato(4) == "Hola4");

	}

	SECTION("Union de lista unitaria"){
		Lista<std::string>* lista2 = new Lista<std::string>();
		lista2 -> insertar("Hola5",1);	
		lista -> concatenar(lista2);
		REQUIRE(lista -> obtener_dato(1) == "Hola1");
		REQUIRE(lista -> obtener_dato(2) == "Hola2");
		REQUIRE(lista -> obtener_dato(3) == "Hola3");
		REQUIRE(lista -> obtener_dato(4) == "Hola4");
		REQUIRE(lista -> obtener_dato(5) == "Hola5");
	}

	SECTION("Union de lista con varios nodos"){
		Lista<std::string>* lista2 = new Lista<std::string>();
		lista2 -> insertar("Hola5",1);	
		lista2 -> insertar("Hola6",2);	
		lista2 -> insertar("Hola7",3);	
		lista2 -> insertar("Hola8",4);	
		lista -> concatenar(lista2);
		REQUIRE(lista -> obtener_dato(1) == "Hola1");
		REQUIRE(lista -> obtener_dato(2) == "Hola2");
		REQUIRE(lista -> obtener_dato(3) == "Hola3");
		REQUIRE(lista -> obtener_dato(4) == "Hola4");
		REQUIRE(lista -> obtener_dato(5) == "Hola5");
		REQUIRE(lista -> obtener_dato(6) == "Hola6");
		REQUIRE(lista -> obtener_dato(7) == "Hola7");
		REQUIRE(lista -> obtener_dato(8) == "Hola8");

	}

	SECTION("Union de lista con ella misma."){
		lista -> concatenar(lista);
		REQUIRE(lista -> obtener_dato(1) == "Hola1");
		REQUIRE(lista -> obtener_dato(2) == "Hola2");
		REQUIRE(lista -> obtener_dato(3) == "Hola3");
		REQUIRE(lista -> obtener_dato(4) == "Hola4");
		REQUIRE(lista -> obtener_dato(5) == "Hola1");
		REQUIRE(lista -> obtener_dato(6) == "Hola2");
		REQUIRE(lista -> obtener_dato(7) == "Hola3");
		REQUIRE(lista -> obtener_dato(8) == "Hola4");

		REQUIRE(lista -> obtener_longitud() == 8);

	}

}

TEST_CASE("3) Metodo que devuelve una lista con la concatenación"){
//3) Método que une la lista original con otra que se pasa por parámetro y devuelve un
//puntero a la nueva lista. La lista pasada por parámetro va al final.
	Lista<std::string>* lista = new Lista<std::string>();
	lista -> insertar("Hola1",1);
	lista -> insertar("Hola2",2);
	lista -> insertar("Hola3",3);
	lista -> insertar("Hola4",4);

	SECTION("Union de la lista con ella misma."){
		Lista<std::string>* lista2 = lista -> lista_concatenada(lista);
		
		REQUIRE(lista2 -> obtener_dato(1) == "Hola1");
		REQUIRE(lista2 -> obtener_dato(2) == "Hola2");
		REQUIRE(lista2 -> obtener_dato(3) == "Hola3");
		REQUIRE(lista2 -> obtener_dato(4) == "Hola4");
		REQUIRE(lista2 -> obtener_dato(5) == "Hola1");
		REQUIRE(lista2 -> obtener_dato(6) == "Hola2");
		REQUIRE(lista2 -> obtener_dato(7) == "Hola3");
		REQUIRE(lista2 -> obtener_dato(8) == "Hola4");
		
		REQUIRE(lista -> obtener_longitud() == 4);
		REQUIRE(lista2 -> obtener_longitud() == 8);

	}

	SECTION("Union de lista vacia"){
		Lista<std::string>* lista2 = new Lista<std::string>();
		Lista<std::string>* lista3 = lista -> lista_concatenada(lista2);
		REQUIRE(lista3 -> obtener_dato(1) == "Hola1");
		REQUIRE(lista3 -> obtener_dato(2) == "Hola2");
		REQUIRE(lista3 -> obtener_dato(3) == "Hola3");
		REQUIRE(lista3 -> obtener_dato(4) == "Hola4");

	}

	SECTION("Union de lista unitaria"){
		Lista<std::string>* lista2 = new Lista<std::string>();
		lista2 -> insertar("Hola5",1);	
		Lista<std::string>* lista3 = lista -> lista_concatenada(lista2);
		REQUIRE(lista3 -> obtener_dato(1) == "Hola1");
		REQUIRE(lista3 -> obtener_dato(2) == "Hola2");
		REQUIRE(lista3 -> obtener_dato(3) == "Hola3");
		REQUIRE(lista3 -> obtener_dato(4) == "Hola4");
		REQUIRE(lista3 -> obtener_dato(5) == "Hola5");
	}

	SECTION("Union de lista con varios nodos"){
		Lista<std::string>* lista2 = new Lista<std::string>();
		lista2 -> insertar("Hola5",1);	
		lista2 -> insertar("Hola6",2);	
		lista2 -> insertar("Hola7",3);	
		lista2 -> insertar("Hola8",4);	
		Lista<std::string>* lista3 = lista -> lista_concatenada(lista2);
		REQUIRE(lista3 -> obtener_dato(1) == "Hola1");
		REQUIRE(lista3 -> obtener_dato(2) == "Hola2");
		REQUIRE(lista3 -> obtener_dato(3) == "Hola3");
		REQUIRE(lista3 -> obtener_dato(4) == "Hola4");
		REQUIRE(lista3 -> obtener_dato(5) == "Hola5");
		REQUIRE(lista3 -> obtener_dato(6) == "Hola6");
		REQUIRE(lista3 -> obtener_dato(7) == "Hola7");
		REQUIRE(lista3 -> obtener_dato(8) == "Hola8");

	}
}

TEST_CASE("4) Método que revierte la lista"){
//4) Método que revierte la lista, modificándola (el último elemento pasa al primer lugar, etc).
	Lista<std::string>* lista = new Lista<std::string>();
	lista -> insertar("Hola1",1); 
	SECTION("Revertir una lista con un elemento"){
		lista -> revertir();
		REQUIRE(lista -> obtener_dato(1) == "Hola1");
	}
	
	lista -> insertar("Hola2",1); 
	SECTION("Revertir una lista con dos elementos"){
		lista -> revertir();
		REQUIRE(lista -> obtener_dato(1) == "Hola1");
		REQUIRE(lista -> obtener_dato(2) == "Hola2");
	}

	lista -> insertar("Hola3",1); 
	lista -> insertar("Hola4",1); 
	lista -> insertar("Hola5",1); 
	lista -> insertar("Hola6",1); 
	lista -> insertar("Hola7",1); 

	SECTION("Revertir una lista con multiples elementos"){
		lista -> revertir();
		REQUIRE(lista -> obtener_dato(1) == "Hola1");
		REQUIRE(lista -> obtener_dato(2) == "Hola2");
		REQUIRE(lista -> obtener_dato(3) == "Hola3");
		REQUIRE(lista -> obtener_dato(4) == "Hola4");
		REQUIRE(lista -> obtener_dato(5) == "Hola5");
		REQUIRE(lista -> obtener_dato(6) == "Hola6");
		REQUIRE(lista -> obtener_dato(7) == "Hola7");
	}
}

TEST_CASE("5) Crea una lista de ella misma revertida."){
//5) Método que revierte la lista en una nueva lista, y devuelve un puntero de la misma.
	Lista<std::string>* lista = new Lista<std::string>();
	Lista<std::string>* lista2 = new Lista<std::string>();
	lista -> insertar("Hola1",1); 
	SECTION("Revertir una lista con un elemento"){
		lista2 = lista -> lista_revertida();
		REQUIRE(lista2 -> obtener_dato(1) == "Hola1");
	}
	
	lista -> insertar("Hola2",1); 
	SECTION("Revertir una lista con dos elementos"){
		lista2 = lista -> lista_revertida();
		REQUIRE(lista -> obtener_dato(2) == "Hola1");
		REQUIRE(lista -> obtener_dato(1) == "Hola2");
		REQUIRE(lista2 -> obtener_dato(1) == "Hola1");
		REQUIRE(lista2 -> obtener_dato(2) == "Hola2");
	}

	lista -> insertar("Hola3",1); 
	lista -> insertar("Hola4",1); 
	lista -> insertar("Hola5",1); 
	lista -> insertar("Hola6",1); 
	lista -> insertar("Hola7",1); 

	SECTION("Revertir una lista con multiples elementos"){
		lista2 = lista -> lista_revertida();
		REQUIRE(lista -> obtener_dato(7) == "Hola1");
		REQUIRE(lista -> obtener_dato(6) == "Hola2");
		REQUIRE(lista -> obtener_dato(5) == "Hola3");
		REQUIRE(lista -> obtener_dato(4) == "Hola4");
		REQUIRE(lista -> obtener_dato(3) == "Hola5");
		REQUIRE(lista -> obtener_dato(2) == "Hola6");
		REQUIRE(lista -> obtener_dato(1) == "Hola7");
		REQUIRE(lista2 -> obtener_dato(1) == "Hola1");
		REQUIRE(lista2 -> obtener_dato(2) == "Hola2");
		REQUIRE(lista2 -> obtener_dato(3) == "Hola3");
		REQUIRE(lista2 -> obtener_dato(4) == "Hola4");
		REQUIRE(lista2 -> obtener_dato(5) == "Hola5");
		REQUIRE(lista2 -> obtener_dato(6) == "Hola6");
		REQUIRE(lista2 -> obtener_dato(7) == "Hola7");
	}
}


TEST_CASE("6) Merge entre dos listas ordernadas, modificando la lista quedando ordenada y sin elementos repetidos"){
/*
6) Método que recibe una lista por parámetro, ambas (la original y la del parámetro) están
ordenadas, se hace un merge entre las dos, modificando la original, que tiene que quedar
ordenada y sin elementos repetidos. Para comparar se usa un método de Dato
(comparar), ejemplo a.comparar_con(b). Este método devuelve -1 si a es menor que b; 1,
si a es mayor que b; y 0 si son iguales.
*/
	Lista<std::string>* lista = new Lista<std::string>();
	lista -> insertar("Hola1", 1);
	lista -> insertar("Hola3", 2);
	lista -> insertar("Hola6", 3);
	Lista<std::string>* lista2 = new Lista<std::string>();


	SECTION("Merge consigo misma"){
		lista -> merge(lista);
		REQUIRE(lista -> obtener_dato(1) == "Hola1");
		REQUIRE(lista -> obtener_dato(2) == "Hola3");
		REQUIRE(lista -> obtener_dato(3) == "Hola6");
	}

	SECTION("Merge con una lista de multiples elementos"){
		lista2 -> insertar("Hola2", 1);
		lista2 -> insertar("Hola3", 2);
		lista2 -> insertar("Hola4", 3);
		lista -> merge(lista2);
		REQUIRE(lista -> obtener_dato(1) == "Hola1");
		REQUIRE(lista -> obtener_dato(2) == "Hola2");
		REQUIRE(lista -> obtener_dato(3) == "Hola3");
		REQUIRE(lista -> obtener_dato(4) == "Hola4");
		REQUIRE(lista -> obtener_dato(5) == "Hola6");
		REQUIRE(lista -> obtener_longitud() == 5);
	}

	SECTION("Merge con una lista de mismos elementos"){
		lista2 -> insertar("Hola1", 1);
		lista2 -> insertar("Hola3", 2);
		lista2 -> insertar("Hola6", 3);
		lista -> merge(lista2);
		REQUIRE(lista -> obtener_longitud() == 3);
		REQUIRE(lista -> obtener_dato(1) == "Hola1");
		REQUIRE(lista -> obtener_dato(2) == "Hola3");
		REQUIRE(lista -> obtener_dato(3) == "Hola6");
	}

	SECTION("Merge con una lista con elementos mas chicos"){
		lista2 -> insertar("Hola0", 1);
		lista2 -> insertar("Hola01", 2);
		lista2 -> insertar("Hola02", 3);
		lista -> merge(lista2);
		REQUIRE(lista -> obtener_longitud() == 6);
		REQUIRE(lista -> obtener_dato(1) == "Hola0");
		REQUIRE(lista -> obtener_dato(2) == "Hola01");
		REQUIRE(lista -> obtener_dato(3) == "Hola02");
		REQUIRE(lista -> obtener_dato(4) == "Hola1");
		REQUIRE(lista -> obtener_dato(5) == "Hola3");
		REQUIRE(lista -> obtener_dato(6) == "Hola6");
	}


}

TEST_CASE("7) Elimina un dato que es pasado por parametro, eliminando solo la primer ocurrencia."){
	Lista<std::string>* lista = new Lista<std::string>();
	lista -> insertar("Hola1", 1);
	lista -> insertar("Hola3", 2);
	lista -> insertar("Hola5", 3);
	lista -> insertar("Hola6", 4);


	SECTION("Elimino Hola1"){
		lista -> eliminar_dato("Hola1");
		REQUIRE(lista -> obtener_dato(1) == "Hola3");
		REQUIRE(lista -> obtener_dato(2) == "Hola5");
		REQUIRE(lista -> obtener_dato(3) == "Hola6");
		REQUIRE(lista -> obtener_longitud() == 3);

	}

	SECTION("Elimino Hola3"){
		lista -> eliminar_dato("Hola3");
		REQUIRE(lista -> obtener_dato(1) == "Hola1");
		REQUIRE(lista -> obtener_dato(2) == "Hola5");
		REQUIRE(lista -> obtener_dato(3) == "Hola6");
		REQUIRE(lista -> obtener_longitud() == 3);

	}

	SECTION("Elimino Hola5"){
		lista -> eliminar_dato("Hola5");
		REQUIRE(lista -> obtener_dato(1) == "Hola1");
		REQUIRE(lista -> obtener_dato(2) == "Hola3");
		REQUIRE(lista -> obtener_dato(3) == "Hola6");
		REQUIRE(lista -> obtener_longitud() == 3);


	}

	SECTION("Elimino Hola6"){
		lista -> eliminar_dato("Hola6");
		REQUIRE(lista -> obtener_dato(1) == "Hola1");
		REQUIRE(lista -> obtener_dato(2) == "Hola3");
		REQUIRE(lista -> obtener_dato(3) == "Hola5");
		REQUIRE(lista -> obtener_longitud() == 3);
	}

	SECTION("Elimino toda la lista"){
		lista -> eliminar_dato("Hola1");
		lista -> eliminar_dato("Hola3");
		lista -> eliminar_dato("Hola5");
		lista -> eliminar_dato("Hola6");
		REQUIRE(lista -> obtener_longitud() == 0);

	}

	SECTION("Elimino la primer ocurrencia"){
		lista -> insertar("Hola6", 2);
		lista -> eliminar_dato("Hola6");
		REQUIRE(lista -> obtener_dato(1) == "Hola1");
		REQUIRE(lista -> obtener_dato(2) == "Hola3");
		REQUIRE(lista -> obtener_dato(3) == "Hola5");
		REQUIRE(lista -> obtener_dato(4) == "Hola6");
		REQUIRE(lista -> obtener_longitud() == 4);
	}

}
TEST_CASE("8) Eliminar todas las ocurrencias."){
//8) Método que elimina todas las ocurrencias del dato.
	Lista<std::string>* lista = new Lista<std::string>();

	SECTION("La lista es de todas las ocurrencias."){
		lista -> insertar("Hola1", 1);
		lista -> insertar("Hola1", 1);
		lista -> insertar("Hola1", 1);
		lista -> insertar("Hola1", 1);
		lista -> eliminar_datos("Hola1");
		REQUIRE(lista -> obtener_longitud() == 0);

	}

	lista -> insertar("Hola1", 1);
	lista -> insertar("Hola3", 2);
	lista -> insertar("Hola3", 3);
	lista -> insertar("Hola6", 4);

	SECTION("Elimino Hola3"){
		lista -> eliminar_datos("Hola3");
		REQUIRE(lista -> obtener_dato(1) == "Hola1");
		REQUIRE(lista -> obtener_dato(2) == "Hola6");
		REQUIRE(lista -> obtener_longitud() == 2);

	}
}


TEST_CASE("9) Resta de conjuntos"){
/*
9) Método que recibe una lista por parámetro y devuelve un puntero a una nueva lista que
es A – B (los elementos de A que no están en B), donde A es la lista original y B es la del
parámetro.
*/

	Lista<std::string>* listaA = new Lista<std::string>();
	Lista<std::string>* listaB = new Lista<std::string>();

	SECTION("La lista es de todas las ocurrencias."){
		listaA -> insertar("1",1); //
		listaA -> insertar("2",1);
		listaA -> insertar("3",1);
		listaA -> insertar("4",1); //
		listaA -> insertar("5",1); //

		listaB -> insertar("1",1); 
		listaB -> insertar("4",2); 
		listaB -> insertar("5",3);	
		listaB -> insertar("6",2);
		listaB -> insertar("7",3);

		listaA -> restar_listas(listaB);
		REQUIRE(listaA -> obtener_longitud() == 2 );
		REQUIRE(listaA -> obtener_dato(1) == "3");
		REQUIRE(listaA -> obtener_dato(2) == "2");
	}
}
