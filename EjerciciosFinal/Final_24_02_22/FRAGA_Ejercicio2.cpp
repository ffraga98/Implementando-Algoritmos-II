/*
Considerar como implementada la clase Restaurante a partir de la siguiente interfaz: */
class Restaurante {

public:
//Crea un restaurante con su nombre, el precio promedio por cubierto
// y una lista de platos que sirve
Restaurante (string nombre, int precio_promedio, Lista<string>* platos);
/*devuelve el nombre del restaurante */
string obtener_nombre(); 

/* devuelve el precio promedio */
int obtener_precio_promedio (); 

/* devuelve ptr a la lista de platos */
Lista<string>* obtener_platos (); 

};

/*
Implementar el método recomendar_restaurantes de la clase Buscador_restaurantes, según:
*/

class Buscador_restaurantes {

public:

/* 
Pre: La lista posee elementos bien formados.
Post: busca en “restaurantes” aquellos que tienen por lo menos dos platos de la lista “platos_deseados”
y un precio promedio menor o igual a precio_maximo.
Devuelve un puntero a la lista con los restaurantes que cumplen con estas características.

*/

Lista<Restaurante *>* Buscador_restaurantes::recomendar_restaurantes (Lista<Restaurante *>* restaurantes, 
Lista<string>* platos_deseados, int precio_maximo){
	Lista<Restaurante *>* restaurantes_recomendados = new Lista<Restaurante*>();

	Restaurante* restaurante;
	restaurantes -> reiniciar();
	while( restaurantes -> hay_siguiente() ){
		restaurante = restaurantes -> siguiente();
		if(restaurante -> obtener_precio_promedio() <= precio_maximo){
			if( cumple_platos_deseados(restaurante, platos_deseados) ){
				restaurantes_recomendados -> insertar(restaurante, restaurantes_recomendados -> obtener_longitud() + 1 )
			}
		}
	}

	return restaurantes_recomendados;	
}


};

//PRE: El restaurante y la lista de platos deseados son válidos
//POS: Devuelve true si hay dos elementos de platos_deseados que se encuentran en la lista
// de platos del restaurante.
bool cumple_platos_deseados(Restaurante* restaurante, Lista<string>* platos_deseados){
	int aciertos = 0;
	Lista<string>* platos_restaurante = restaurante -> obtener_platos();
	platos_deseados -> reiniciar();

	string plato_deseado;
	string plato;
	bool encontrado;
	
	while(!(aciertos == 2) && platos_deseados -> hay_siguiente()){
	
		plato_deseado = platos_deseados -> siguiente();
		encontrado = false;
		platos_restaurante -> reiniciar();
	
		while( platos_restaurante -> hay_siguiente() && !encontrado ){
	
			plato = platos_restaurante -> siguiente();
	
			if(plato_deseado == plato){
				encontrado == true;
				++aciertos;
			}
		}
	}

	return aciertos == 2;
}

