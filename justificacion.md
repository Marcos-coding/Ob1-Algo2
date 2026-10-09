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
- Sin restricciones de órdenes. / Justificación: ...

## Ejercicio 5
- Resolver en orden temporal O(ElogE) en el peor caso, siendo E la cantidad de senderos.
Orden espacial O(V + E)
/ Justificación: 
- Orden Temporal: El primer for hace E iteraciones de insertar en un heap, que es O(1) promedio, por lo que el primer for es O(E). El segundo for hace hasta E iteraciones en peor caso de eliminar de un heap (O(log e)), hace Find y Merge sobre un MFSet que como se implemento con ambas optimizaciones por lo que son O(1). Por lo que el segundo for termina siendo O(E + E logE), que es lo mismo a O(E logE) como requerido.
- Orden Espacial: Utiliza un heap de tamaño E, para las aristas y un MFSet de largo V, donde se guarda el grupo de cada vertice. Por lo que es O(V + E)


