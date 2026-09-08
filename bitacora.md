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
Termino de implementar el hash abierto. Pasa el primer conjunto de pruebas
