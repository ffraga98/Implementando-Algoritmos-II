#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include<iostream>
#include "nodo.h"

const int LISTA_VACIA = 0;

template <typename T>
class Lista {

private:
    // atributos
    Nodo<T>* primero;
    int longitud;

public:
    // Constructor sin parametros
    // PRE:
    // POS: crea una Lista de longitud 0 y primero apunta a NULL
    Lista (): primero(nullptr), longitud(LISTA_VACIA){};

    // Constructor de copia
    // PRE: lista es una Lista valida
    // POS: crea una Lista igual a lista
    Lista (const Lista& lista){
        int i = 1;
        Nodo<T>* nodo = lista.obtener_nodo(i);
        T dato;
        while( nodo != nullptr){
            dato = nodo -> obtener_dato();
            insertar(dato,i); //Podriamos mejorar la eficiencia 
            //si tenemos el nodo recien agregado. Debería modularizar el insertar().
            nodo = nodo -> obtener_siguiente();
            ++i;
        }
        
    };

    // Destructor
    // PRE:
    // POS: libera la memoria solicitada
    ~Lista (){
        while(primero != nullptr){
            eliminar(1);
        }
    };

    // Lista vacia?
    // PRE:
    // POS: devuelve verdadero si la lista esta vacia, falso de lo contrario
    bool vacia( ){
        return longitud == LISTA_VACIA;
    };

    // obtener longitud de la lista
    // PRE:
    // POS: devuelve la longitud de la lista
    int obtener_longitud( ) const{
        return longitud;
    };

    // insertar un dato en cierta posicion
    // PRE: d dato valido y 0 < pos <= longitud + 1
    // POS: inserta el Dato d en la posicion pos (la 1 es la primera),
    //      inrementa en 1 la longitud
    void insertar (T d, int pos){
        Nodo<T>* nuevo_nodo = new Nodo<T>(d);

        if(pos == 1){
            nuevo_nodo -> cambiar_siguiente(primero);
            primero = nuevo_nodo;
        }else{
            nuevo_nodo -> cambiar_siguiente( obtener_nodo(pos) );
            this -> obtener_nodo(pos - 1 ) -> cambiar_siguiente(nuevo_nodo);
        }

        ++longitud;
    };

    // eliminar un Nodo en cierta posicion
    // PRE: 0 < pos <= longitud
    // POS: elimina el Nodo en la posicion pos (la 1 es la primera),
    //      libera memoria y decrementa en uno la longitud
    void eliminar(int pos){        
        Nodo<T>* nodo2;
        Nodo<T>* nodo3;
        
        if(pos == 1){
            nodo2 = primero;
            nodo3 = nodo2 -> obtener_siguiente();
            primero = nodo3;
        }else{
            Nodo<T>* nodo1 = obtener_nodo(pos - 1);
            nodo2 = nodo1 -> obtener_siguiente();
            nodo3 = nodo2 -> obtener_siguiente();
            nodo1 -> cambiar_siguiente( nodo3 );
        }

        delete nodo2;
        --longitud;
    }

    // obtiene el DAto en cierta posicion
    // PRE: 0 < pos <= longitud
    // POS: devuelve el dato que esta en la posicion pos (la 1 es la primera)
    T obtener_dato (int pos){
        return obtener_nodo(pos) -> obtener_dato();
    }; 

    // cambia el DAto que esta en cierta posicion
    // PRE: 0 < pos <= longitud
    // POS: cambia el dato que esta en la posicion pos (la 1 es la primera)
    void cambiar_dato (T d, int pos){
        obtener_nodo(pos) -> cambiar_dato(d);
    };

    void intercambio_datos(int pos1, int pos2){
        if(pos1 != pos2){

            if( pos1 > pos2){
                int aux = pos2;
                pos2 = pos1;
                pos1 = aux;
            }

            Nodo<T>* nodo1 = this -> obtener_nodo(pos1);
            Nodo<T>* nodo2 = nodo1;
            while( pos1 < pos2 ){
                nodo2 = nodo2 -> obtener_siguiente();
                ++pos1;
            }
            T dato_aux = nodo1 -> obtener_dato();
            nodo1 -> cambiar_dato(nodo2 -> obtener_dato());
            nodo2 -> cambiar_dato(dato_aux);
        }
    }
    //PRE
    //POS
    //Podria hacer facilmente intercambiar datos con los metodos cambiar_dato(),
    // pero si el dato es pesado es preferible intercambiar punteros.
    //Complejo.
    void intercambio_nodos(int pos1, int pos2){
        if(pos1 != pos2){

            if( pos1 > pos2){
                int aux = pos2;
                pos2 = pos1;
                pos1 = aux;
            }

            Nodo<T>* nodo1; 
            Nodo<T>* nodo2 = primero;

            if( pos1 != 1){
                nodo1 = obtener_nodo(pos1 - 1);
                nodo2 = nodo1 -> obtener_siguiente();
            }

            Nodo<T>* nodo3;
            Nodo<T>* nodo4;
            if( pos2-pos1 == 1){
                nodo3 = nodo2 -> obtener_siguiente();
                nodo4 = nodo3 -> obtener_siguiente();

                nodo1 -> cambiar_siguiente(nodo3);
                nodo2 -> cambiar_siguiente(nodo4);
                nodo3 -> cambiar_siguiente(nodo2);
            }else{
                Nodo<T>* nodo5;
                Nodo<T>* nodo6;
                nodo3 = nodo2 -> obtener_siguiente();
                nodo4 = obtener_nodo(pos2 - 1);
                nodo5 = nodo4 -> obtener_siguiente();
                nodo6 = nodo5 -> obtener_siguiente();

                if(pos1 == 1){
                    primero = nodo5;
                }else{
                    nodo1 -> cambiar_siguiente(nodo5); 
                }

                nodo2 -> cambiar_siguiente(nodo6); 
                nodo4 -> cambiar_siguiente(nodo2);
                nodo5 -> cambiar_siguiente(nodo3);

            }

        }
    }

    //PRE
    //POS
    void concatenar(const Lista<T>* lista2){
        int largo = lista2 -> obtener_longitud();
        if(largo){
            Nodo<T>* nodo_lista2 = lista2 -> obtener_nodo(1);//Se puede?

            if(longitud == 0){ //En caso de que la lista esté vacía.
                this -> insertar(nodo_lista2 -> obtener_dato(),1);
                nodo_lista2 = nodo_lista2 -> obtener_siguiente();
                --largo; //Porque hay uno de la lista que ya fue concatenado.
            }
            
            Nodo<T>* ultimo_nodo = this -> obtener_nodo(longitud);
            Nodo<T>* aux;
            
            //Podriamos insertar sin mas pero no sería eficiente.
            int largo_final = longitud + largo;
            while( longitud < largo_final ){ //Podriamos usar nullptr pero si le pasamos la propia lista, sería un loop infinito
                aux = new Nodo<T>(nodo_lista2 -> obtener_dato());
                ultimo_nodo -> cambiar_siguiente(aux);
                ultimo_nodo = aux;
                nodo_lista2 = nodo_lista2 -> obtener_siguiente();
                ++longitud;
            }
        }
    }

    //PRE
    //POS
    Lista<T>* lista_concatenada(const Lista<T>* lista2){
        Lista<T>* lista = new Lista<T>(*this);
        lista -> concatenar(lista2); //lol
        return lista;
    }

    //PRE
    //POS
    void revertir(){
        if(longitud > 1){
            int i = longitud;
            Nodo<T>* nodo = obtener_nodo(longitud);
            while(i > 1){
                apuntar_anterior(i--);
            }
            primero ->  cambiar_siguiente(nullptr);
            primero = nodo;

        }
    }

    //PRE
    //POS
    Lista<T>* lista_revertida(){
        Lista<T>* lista = new Lista<T>();
        Nodo<T>* nodo = obtener_nodo(1);
        while(nodo != nullptr){
            lista -> insertar(nodo -> obtener_dato(),1);
            nodo = nodo -> obtener_siguiente();
        }

        return lista;
    }
   
    //PRE
    //POS

    //Con el insertar(T dato, int pos) se resuelve facil, pero quiero ahorrarme iteraciones.
    void merge(const Lista<T>* lista){
        if(lista != this){
            Nodo<T>* nodo_lista1 = primero;
            Nodo<T>* nodo_lista2 = lista -> primero;
            Nodo<T>* nodo_anterior;

            T d2 = nodo_lista2 -> obtener_dato();
            int resultado = nodo_lista1 -> comparar_con(nodo_lista2);

            //caso particular, en caso de insertar cual es el primer elemento y actualizar el primero. 
            switch(resultado){
                case 1:
                    insertar(d2,1);
                    nodo_lista2 = nodo_lista2 -> obtener_siguiente();
                    nodo_anterior = primero;
                    break;
                case 0:
                    nodo_lista2 = nodo_lista2 -> obtener_siguiente();
                case -1:
                    nodo_anterior = nodo_lista1;
                    nodo_lista1 = nodo_lista1 -> obtener_siguiente();
                default:
                    break;

            }
            
            //T d1;
            while( nodo_lista1 != nullptr && nodo_lista2 != nullptr){
                //d1 = nodo_lista1 -> obtener_dato();
                switch(nodo_lista1 -> comparar_con(nodo_lista2)){ //Deberian ser los datos que se comparasen.
                //d1.comparar_con(d2);
                    case 1:
                        d2 = nodo_lista2 -> obtener_dato();
                        insertar_siguiente(nodo_anterior, d2);
                        nodo_lista2 = nodo_lista2 -> obtener_siguiente();
                        break;
                    case 0:
                        nodo_lista2 = nodo_lista2 -> obtener_siguiente();
                    case -1:
                        nodo_anterior = nodo_lista1;
                        nodo_lista1 = nodo_lista1 -> obtener_siguiente();
                    default:
                        break;
                }
            }
            //Como estamos trabajando sobre lista1, si el no llego al nullptr,
            // ya no tenemos que agregar nada mas.
            while(nodo_lista2 != nullptr){ 
                d2 = nodo_lista2 -> obtener_dato();
                    if( nodo_lista2 -> comparar_con(nodo_anterior) == 1){
                        insertar_siguiente(nodo_anterior,d2);
                        nodo_anterior = nodo_lista2;
                    }
                nodo_lista2 = nodo_lista2 -> obtener_siguiente();
            }
        }
    }


    void eliminar_dato(T dato){
        bool encontrado = false;
        int i = 1;
        Nodo<T>* nodo = primero;
        while( !encontrado && nodo != nullptr){
            if( nodo -> obtener_dato() == dato){
                encontrado = true;
                eliminar(i); //Podria hacer un metodo que reciba el nodo anterior
                // y eliminar el nodo siguiente.
            }else{
                nodo = nodo -> obtener_siguiente();
                ++i;
            }
        }
    }

    void eliminar_datos(T dato){
        int i = 1;
        Nodo<T>* nodo = primero;
        T dato_nodo;
        while(nodo != nullptr){
            dato_nodo = nodo -> obtener_dato();
            nodo = nodo -> obtener_siguiente();
            if( dato_nodo == dato){
                eliminar(i);
                 //Podria hacer un metodo que reciba el nodo anterior
                // y eliminar el nodo siguiente.
                //Ahora la lista es mas corta.
            }else{
                ++i;
            }
        }
    }

    void restar_listas(Lista<T>* lista){
        Nodo<T>* nodo = lista -> primero;
        while( nodo != nullptr){
            eliminar_datos( nodo -> obtener_dato());
            nodo = nodo -> obtener_siguiente();
        }
    }


private:
    // devuelve un puntero al Nodo en cierta posicion
    // PRE: 0 < pos <= longitud
    // POS: devuelve un puntero al Nodo que esta en la posicion pos (la 1 es la primera)
    Nodo<T>* obtener_nodo (int pos) const{
        Nodo<T>* nodo = primero;
        for(int i = 1; i <= pos -1 ; i++)
            nodo = nodo -> obtener_siguiente();

        return nodo;
    };

    // PRE: 0 < pos <= longitud
    // POS: Apunta el nodo pos al pos-1
   void apuntar_anterior(int pos){ 
            Nodo<T>* siguiente_nodo = this -> obtener_nodo(pos - 1);
            Nodo<T>* aux = siguiente_nodo -> obtener_siguiente();
            aux -> cambiar_siguiente(siguiente_nodo);
   }

   //PRE:
   //POS: Inserta a continuacion del nodo, un nodo con el dato.
   void insertar_siguiente(Nodo<T>*& nodo, T dato){
        Nodo<T>* aux = new Nodo<T>(dato);
        aux -> cambiar_siguiente(nodo -> obtener_siguiente());
        nodo -> cambiar_siguiente(aux);
        nodo = aux;
        ++longitud;
   }

};



#endif // LISTA_H_INCLUDED