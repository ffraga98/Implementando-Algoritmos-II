/* 
PRE: **No tiene precondiciones**
POST: recibe una lista por parámetro e indica si esa lista 
está incluida (devuelve true) o no (devuelve false) en la lista que llama al método.
Para comparar se usa el siguiente método: 
a.comparar(b);

Devuelve: 
-1 si a < b, 
1 si a > b,
0 si a = b 
*/

bool incluye (Lista lista){
	
	int aciertos = 0;
	if(longitud > lista -> obtener_longitud()){

		Nodo* nodo_param = lista -> primero;
		Nodo* nodo_lista;
	
		int elemento_encontrado;

		while(nodo_param != nullptr){

			nodo_lista = primero;
			elemento_encontrado = 1;

			while(!(elemento_encontrado == 0) && nodo_lista != nullptr){
		
				elemento_encontrado = nodo_param -> obtener_dato().comparar_con( nodo_lista -> obtener_dato() );
			
				if( elemento_encontrado == 0 ){
					nodo_param = nodo_param -> obtener_siguiente();
					++aciertos;
					nodo_lista = primero;
				}else{
					nodo_lista = nodo_lista -> obtener_siguiente();
				}
			
			}
		
			//Para cortar el while cuando no encontró uno de los elementos.
			if(elemento _encontrado != 0){
				nodo_param = nullptr;
			}
		}
	}

	return aciertos == lista -> obtener_longitud();
}



Nota 1: si necesitás agregar algún otro método que no figura en el archivo .h podés hacerlo.

Nota 2: agregá las precondiciones

Nota 3: podés escribir en la caja de abajo o podés subir un archivo.