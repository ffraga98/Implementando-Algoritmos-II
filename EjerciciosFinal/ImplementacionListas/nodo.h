#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

template<typename T>
class Nodo {
private:
    // atributos
    T dato;
    Nodo* siguiente;

public:

    // Constructor con parametro
    // PRE: d es un Dato valido
    // POS: crea un Nodo con d como dato y NULL en siguiente
    Nodo (T d): dato(d), siguiente(nullptr){}

    // Cambia el dato
    // PRE: d es un Dato valido
    // POS: cambia el dato actual por d
    void cambiar_dato (T d){
        dato = d;
    }

    // Cambia el siguiente
    // PRE: s es un puntero a Nodo valido
    // POS: cambia el siguiente por s
    void cambiar_siguiente (Nodo* s){
        siguiente = s;
    }

    // Obtiene el dato
    // PRE:
    // POS: devuelve el dato
    T obtener_dato( ){ 
        return dato;
    }

    // Obtiene el siguiente
    // PRE:
    // POS: devuelve el puntero siguiente
    Nodo* obtener_siguiente( ){ 
        return siguiente;
    }

    int comparar_con(Nodo* nodo2){
        int resultado = 0;
        T dato2 = nodo2 -> obtener_dato();
        
        if(dato > dato2 )
            resultado = 1;
        else if( dato < dato2)
            resultado = -1;
        
        return resultado;
    }

};


#endif // NODO_H_INCLUDED