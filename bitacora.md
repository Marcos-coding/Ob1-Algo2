# Bitácora — Obligatorio 1

**Integrantes:** Marcos Bellini (304138), Guillermo Bértola (303665)

> **Instrucciones** (borrar esta sección antes de entregar): agregar una entrada por
> cada día trabajado, indicando la fecha y quién trabajó (un integrante o "En conjunto").
> Registrar el proceso real: ideas exploradas, decisiones y su justificación, partes de
> implementaciones, bugs encontrados y cómo se corrigieron, resultados de pruebas y dudas
> abiertas. Si se usó IA ese día, indicar herramienta, consulta y qué se hizo con la
> respuesta. Una bitácora escrita íntegramente el día de la entrega implica pérdida de puntos.

## 2026-09-03 — Guillermo

- Ejemplo: Leí la letra del ejercicio 1. Primera idea: ... pero la restricción de
  complejidad pide ..., así que ...
- Lei la letra del ejercicio 2. Pense en que la tabla fuera un array a cabezales de listas y ahi guardar la cantidad de palabras guardadas por buckets pero mas simple que cada nodo se encargue de saber cuantas palabras tiene adelante. La funcion de hash no le tiene que importar el orden de las letras => no se usa el indice que recorre la palabra para hashear. Se aprovechan las coliciones de la misma palabra para llevar la cuenta de palabras, pero si dos palabras distintas coinciden en el bucket hay un error grave. **(Si se le asignara a cada letra un primo diferente y el hash fuera hacer el producto de los primos se conseguiria un numero unico para cada combinacion de letras, problema "zzz...zz" seria (101)^20 con el overflow puede volver a haber colisiones tambien con el modulo)** conclusion: hay que buscar una forma de manejar coliciones de palabras diferentes. Comienzo a implementar una primera version del TAD cajonera, sujeta a cambios al pensar una mejor solucion.

## AAAA-MM-DD — En conjunto

- Ejemplo: Implementamos ... Bug: ... Lo corregimos ...
- Pasan los casos de prueba 1 a 4 del ejercicio 1.

## 2026-09-03 - Marcos Bellini

- Comencé a implementar el AVL del ejercicio 1, utilizando las ideas y código discutidos en clase. Para ello creé un template AVL genérico con las funciones de agregar, buscar y rango, con los órdenes de tiempo de ejecución esperados. Tuve complicaciones al separar la clase en un archivo .h y uno .cpp para la implementación del template, pero lo pude terminar. La clase AVL contiene una clase privada Nodo, sobre la cual corren los algoritmos de inserción, búsqueda e impresión de rango. El árbol AVL contiene un nodo como raíz y al requerir de sus operaciones, se las llama.
- Para la inserción, se inserta el nodo como en un ABB normal, pero luego se actualizan las alturas de los nodos y se hacen rotaciones si es necesario. En este proceso, a lo sumo se recorre una rama entera del árbol, que como está en su mayoría balanceado. Por lo que es O(log(n))
- Para la búsqueda, es como en un ABB, no hay diferencias. También es O(log(n))
- Para el rango, también funciona como en un ABB. Se recorren nodos del árbol recursivamente hasta que haya uno en el intervalo [min, max]. Cuando se lo encuentra, sea éste Z, se recorren todos sus descendientes en orden, por lo que primero se va por Z->izq, luego se imprime Z y luego se va por Z->der.

## 2026-09-04 — Guillermo

-Luego de la lectura del obli intento encontrar la funcion de hash perfect utilizando la idea del dia anterior.

## 2026-09-04 - Marcos Bellini

- Me encontré con errores de compilación en el AVL. Para resolverlos, ordené el código en el .h y el .cpp con ayuda de chatgpt (solo para debugging) para que no tuviera problemas con la clase AVL (separación de especificación e implementación) y ahí compiló.
  -Luego descubrí que estaba usando el tamaño de número equivocado para las monedas; en vez de usar int tengo que usar long long para que no se salga de rango. Además, corregí la lectura de archivo por consola con el comando cin, que estaba leyendo mal las líneas.
- También corregí el código de la función "rango" del AVL, que a veces no funcionaba bien.
- Ahora, al hacer los tests y comparar con diff, el programa funciona con buena parte de las entradas (100.in.txt, 1000.in.txt, etc), pero en algunos archivos devuelve "segmentation fault".

## 2026-09-07 - En conjunto

- Resolvimos el error en el código del AVL, resulta que estaba haciendo mal las comparaciones del valor a la hora de hacer las rotaciones. Ahora funciona bien en todos los casos. También iniciamos la estructura del heap (archivo .h y .cpp con las funciones básicas), con lo que vimos en clase, ya que no es necesario hacer muchas adaptaciones. Se hicieron las implementaciones de esas funciones

## 2026-09-07 - Marcos

- Tuve algunos problemas con la ejecución del ejercicio 3, probablemente por usar el tipo de entero equivocado. Ahora uso el tipo long long para todos los tamaños de archivo en el Heap (porque llega a 2^63 como máximo), se resolvió el problema.
- Ahora hay otro error en los tests (da el número equivocado) a partir del 10000.txt, queda diagnosticar el problema.
- Resulta que el error estaba en que, al hundir o flotar un elemento en el heap, se lo tomaba como long en vez de long long, lo que alteraba el valor original. Ahora funciona bien, lo raro es que de vez en cuando aparece un "segmentation fault" al probar con el 1000000.in.txt
- En el ejercicio 2 se hizo el main para resolver el problema. En el primer conjunto de pruebas hubo errores. Nos dimos por vencidos con la funcion de hash perfecta pasamos a implementarlo con la posibilidad que haya varios cajones en cada bucket, en el que la palabra verifica que pertenece a él antes de entrar, si no entra se itera por la lista del bucket. Para hacer comparaciones en O(1) usamos un array como estructura auxiliar como en el parcial de Algoritmos 1

## 2026-09-08 — Guillermo

- Termino de implementar el hash abierto. Pasa el primer conjunto de pruebas

## 2026-09-09 En conjunto

- Empezamos a pensar el ejercicio 4. Necesitamos un MinHeap para ordenar las prioridades de los módulos, pero para saber cuál se compila primero se requiere de un grafo. Como el número de módulos llega a ser 500000, una matriz de adyacencia tendría 500000^2 = 250000 millones de entradas booleanas, lo cual es infactible (además el orden espacial es V + A, no V^2). Por lo que usaremos listas de adyacencia para implementarlo. De esta forma, se almacenan las A aristas dirigidas (las dependencias) en el grafo y los V vértices (módulos).

## 2026-09-12 - Marcos

- Comencé a implementar algunas funciones del grafo dirigido del ejercicio 4. Me di cuenta que preciso un array para almacenar la cantidad de aristas de entrada por cada vértice, para poder buscar los vértices que tienen 0 aristas y así hacer un ordenamiento topológico. Si no hay ninguno que comple con esto, o se terminó de recorrer el grafo, o hay un ciclo y no hay solución.
  Termino de implementar el hash abierto. Pasa el primer conjunto de pruebas

## 2026-09-15 - Guillermo

Vengo con boceto de solucion al ejercicio 4, escribo un seudocodigo. La idea es tener un grafo con las dependencias que ademas tenga un array que tenga los grados de incidencia de cada vertice. Se cargan los datos al grafo y de ahi se insertan al heap los vertices cuyos grado de incidencia sea cero. Se hace un while el heap no sea vacio, se desencola un vertice y para todos los adyacentes al vertice se les reduce 1 en su grado de incidencia, si alguno llega a grado 0 se lo inserta al heap. Loop hasta procesar todo el grafo. Todavia no defini donde guardar la informacion de la prioridad de cada modulo, en el heap no puede ser porque no se van a ingrasar los datos al comienzo y no me doy cuenta de como poner ese dato en la representacion del grafo sin un array auxiliar. Me queda la duda de si tener el array de grados auxiliar cumple con el orden de espacio, hay que analizar si se puede o no usar.

## 2026-09-16 - Guillermo

Implemento el pseudocodigo de la ultima vez. Pongo las prioridades es un array auxiliar. Lo implementado no separa bien lo que es responsabilidad del tad y lo que es responsabilidad del main, queda aprolijar el codigo y separar lo que debe y no estar en main. Falta adaptar el heap para que ordene por prioridad y despues el valor.

## 2026-09-18 - En conjunto

- Decidimos crear una clase de Heap template para poder usar los mismos metodos en el ejercicio 3 y el 4, pero con estructuras diferentes. Para ello, el Heap-Min debe comparar objetos genericos (nodos) en vez de enteros, a lo cual tenemos que crear clases para los nodos de archivo (ejercicio 3) y dependencias (ejercicio 4) y sus comparadores. Hicimos una prueba y funciona el concepto.
- El ejercicio 4 da problemas en ejecución, da números muy grandes que no deberían ser posibles.

## 2026-09-19 Marcos

- Corregí algunos errores en la implementación del ejercicio 4. Para empezar, el array de grados de incidencia en el grafo no se inicializaba en 0, pudiendo haber valores residuales. También arreglé la indexación de algunos arrays, como el de prioridades (en main) y aristas en el grafo, porque los vértices comienzan a contarse en 1, no en 0. Esto no afecta al orden de espacio O(V + A) ya que se agrega un lugar vacío en la posición 0. Ahora funciona mejor, pero da error en la mitad de las pruebas.

## 2026-09-20 - Guillermo

- Termino con el heap, y actualizo el codigo del main al heap nuevo. Hago todos los array relacionados a vertices de largo V+1 para que el vertice v, se enucentre en la pos v del array (y no en la v-1). Ahi quedo funcionando para todos los casos sin ciclos. Para detectar ciclos lo que hago es procesar el grado dos veces, la primera no imprime nada y cuando termina se verifica que el array de grados quede todo en 0, en caso de que si, es porque no hay ciclos, se restableze el array de ordenes (Que es lo unico que se modifica) y se vuelve a hacer el codigo pero imprimiendo los modulos en orden de ejecucion, en caso de que el array no quede todo en 0 es porque hay un ciclo, se imprime imposible y termina.

## 2026-10-2 - Guillermo

- Empiezo y termino el ejercicio 5 en clase de practico. Se adapto el heap a trabajar con aristas, se implemento el MFset como visto en clase, y se implemento el pseudocodigo de kruscal visto en clase. No cree el grafo, era redundante solo se necesitaban las aristas y la suma del peso.

## 2026-10-9 - En conjunto

- Optimizamos el código del ejercicio 4 para chequear ciclos una vez sola. En el orden que van saliendo los vértices, se cargan en un array de largo V + 1 (de las posiciones 1 a N), y si se detecta un ciclo en medio de la ejecución, se descarta el array. Si no hay, se imprime el resultado línea a línea luego de ejecutar el algoritmo.
- Completamos la justificación de órdenes del informe.
