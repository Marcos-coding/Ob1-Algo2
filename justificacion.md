# Justificación de órdenes — Obligatorio 1

> **Instrucciones** (borrar esta sección antes de entregar): para cada ejercicio cuya
> letra plantea restricciones de órdenes (tiempo o espacio), justificar brevemente por
> qué la solución cumple, indicando qué estructuras de datos o algoritmos se utilizaron.
> Ejemplo: "La letra exige inserción en O(log n); usamos un min-heap sobre arreglo,
> donde flotar/hundir recorren a lo sumo la altura del árbol". Si un ejercicio no tiene
> restricciones de órdenes, indicarlo.

## Ejercicio 1
- Sin restricciones de órdenes. / Justificación: ...

## Ejercicio 2
- Sin restricciones de órdenes. / Justificación: ...

## Ejercicio 3
- Sin restricciones de órdenes. / Justificación: ...

## Ejercicio 4
- Resolver en orden temporal O((V+A)log V) 
Orden espacial O(V+A) 
/ Justificación:
- Orden temporal: Los tres primeros for son de orden lineal ya que contienen solamente operaciones de O(1) promedio. (Insertar a un heap e insertar una arista a un grafo son O(1) promedio). El primer while hace V iteraciones sobre un while. Esto no es O(n^2) ya que el while que se encuentra anidado, itera cada vez sobre un subconjunto de aristas. Por lo que al final ese while termina iterando A veces a lo largo de toda la ejeccucion. Por lo que podemos decir que el conjunto de los while es O(V+A), ademas tienen dentro la operacion eliminar de un heap que es O(log V) por lo que es O((V+A)logV). Luego del bloque while, hay dos bloques for que hacen operaciones de orden constante. En conclusion el bloque de mayor orden, y por ende el orden que nos importa es O((V+A)logA) 
- Orden espacial: Se utiliza un heap de tamaño V, un grafo que tiene V celdas y contiene A aristas por lo que es de O(V + A) y arrays auxiliares de largo V. Por lo que es O(V + A)

## Ejercicio 5
- Resolver en orden temporal O(ElogE) en el peor caso, siendo E la cantidad de senderos.
Orden espacial O(V + E)
/ Justificación: 
- Orden Temporal: El primer for hace E iteraciones de insertar en un heap, que es O(1) promedio, por lo que el primer for es O(E). El segundo for hace hasta E iteraciones en peor caso de eliminar de un heap (O(log e)), hace Find y Merge sobre un MFSet que como se implemento con ambas optimizaciones por lo que son O(1). Por lo que el segundo for termina siendo O(E + E logE), que es lo mismo a O(E logE) como requerido.
- Orden Espacial: Utiliza un heap de tamaño E, para las aristas y un MFSet de largo V, donde se guarda el grupo de cada vertice. Por lo que es O(V + E)


