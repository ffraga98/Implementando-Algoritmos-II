**1)** Matriz de Adyacencia


Al ser un grafo dirigido, la matriz **no** es simetrica.

El **1** representa que existe una arista que comunica del nodo `fila` al nodo `columna`


		a 	b	c	d	e 	f	g 
	a   0   1   1   1   0   0   0
	b   0   0   0   0   1   0   0
	c   0   0   0   0   0   0   0
	d   0   0   0   0   0   0   1
	e   0   0   0   1   0   1   0
	f   0   0   0   1   0   0   0
	g   0   0   0   0   0   1   0


**2)** Recorrido en profundidad.
	
	a -> b -> e -> d -> g -> f -> c

Para la resolución de este ejercicio, comenzamos por la fila `a` y buscamos los nodos adyacentes, es decir, las columnas que tengan un `1`.
En este primer caso, tenemos que son 3 las columnas que tienen una arista, por lo tanto, elegimos por orden alfabetico. Es por esto que el siguiente nodo adyacente es `b`.

Para continuar con el recorrido, hacemos lo mismo pero esta vez desde el nodo `b`; solo hay una coincidencia en la columna `e`, por lo tanto, el nodo `e` es el siguiente.

En el nodo `e`, tenemos dos casos posibles y otra vez se decide por orden alfabetico.

El siguiente nodo es `d`, el cual solo tiene como nodo adyacente a `g`, el cual sólo tiene un `1` en la columna de `f`, por lo tanto, es el siguiente a `g`.

El nodo `f` no tiene nodos adyacentes que falten por recorren, por eso, volvemos al nodo por el que comenzamos y continuamos con algun nodo que no hayamos visitado como es el caso de `c`.

El nodo `c` es el último nodo que faltaba recorrer, por lo que termió el recorrido.

**3)** Linealización de grafo 

La linealización de un grafo se resuelve mediante un recorrido topológico del grafo, pero para que esto sea posible, se necesita tener un digrafo **sin circuitos**, el cual no es el caso del presentado en este ejercicio.