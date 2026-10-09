# Justificación de órdenes — Obligatorio 1

## Ejercicio 1

- Las operaciones de Alta y Buscar deben ser O(log k) en el peor caso, donde k es el número de piezas registradas. Por lo tanto, utilizamos un árbol AVL donde las operaciones de búsqueda e inserción son O(log k) peor caso, debido al autobalanceo. Como un árbol binario de búsqueda tiene ramas de largo promedio log(k), el AVL garantiza que estas ramas no excedan esa longitud.
- La operación de Rango exige O((log k) + R), donde R es el número de piezas registradas que están en el rango. Como el órden de la búsqueda es O(log k), ese es el tiempo que tarda (en el peor caso) en encontrar un nodo perteneciente al rango, si lo hay. Luego, al haber R elementos en el rango correspondiente, la impresión en orden de esos elementos será en O(R). Por lo que el orden total es O((log k) + R).
- No hay restricciones de orden espacial

## Ejercicio 2

* No hay restricciones de tiempo para crear la tabla, por lo que podemos buscar un número primo superior a la cantidad de esperados para establecerlo como largo de tabla.
* Como se pide un órden de ejecución de O(L) para agregar y buscar una palabra, se utiliza una función de hash buena, de forma que incluso si el hashing es abierto, la cantidad de cajones por cada bucket sea O(1) en general. La función de hash elegida implica asignar un número primo a cada letra del alfabeto, empezando con 2 para la letra 'a', 3 para 'b', etc. El número hash empieza siendo 1, y se multiplica por todos los primos correspondientes a cada letra de la palabra (si hay M letras iguales, se multiplica por ese primo M veces).
* Por último se normaliza el hash con el largo de la tabla, que es un número primo superior a (N * 2), en donde N es la cantidad de palabras esperadas. Esto se hace para evitar que el factor de carga supere 0.5 en caso promedio y el órden de búsqueda sea constante.
* Cuando se agrega un cajón, se ordenan los caracteres de la palabra con Counting Sort que es O(L), y se la almacena en el cajón con su cantidad 1. Esto asegura que cualquier otra palabra que pertenezca a ese cajón, si se la ordena, sea igual a la del cajón.
* Para verificar si una palabra pertenece a un cajón existente, se calcula su hash en O(L), y también se ordenan sus caracteres. Entonces, por cada cajón de ese bucket, se compara la palabra con la del cajón. Si son iguales se suma la cantidad en 1, y si no hay cajón que cumpla, se crea uno nuevo. Por lo tanto, si asumimos que hay O(1) cajones para buscar, el orden de inserción y búsqueda es O(L)
* Para los retornos, la cantidad de cajones se le suma 1 cuando se agrega un cajón nuevo, siendo O(1). Cuando a un cajón ya existente se le suma en 1 la cantidad de palabras, se la compara con la cantidad máxima de palabras que es maxCajon. Si es mayor, se la actualiza en O(1).
* Al haber N palabras en total, el orden de ejecución de este problema es O(N).

- No hay restricciones de orden espacial

## Ejercicio 3

- El orden temporal del ejercicio completo debe ser O(N * log N), donde N es el número de archivos. Para elegir los 2 archivos más chicos en cualquier momento se utiliza un Heap-Min, cuyo órden de inserción es O(1) promedio y O(log N) en el peor caso. Mientras que el orden de eliminación es O(log N) en cualquier caso. Por cada unión de 2 archivos, se sacan ambos con orden O(log N) y se inserta su suma en orden O(log N). Por cada iteración, se eliminan 2 archivos y se inserta 1, por lo que se requieren N iteraciones para obtener el último archivo, lo que es O(N) . La suma de archivos y el costo son operaciones en O(1) que no afectan al orden total.
- Combinando esto, el orden temporal es O(N * log N)
- El orden espacial es O(N) porque en el Heap, que es la única estructura utilizada, se almacenan como mucho N archivos a la vez.

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
