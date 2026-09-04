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

## 2026-09-04 - Marcos Bellini
- Me encontré con errores de compilación en el AVL. Para resolverlos, ordené el código en el .h y el .cpp con ayuda de chatgpt para que no tuviera problemas con la clase AVL (separación de especificación e implementación) y ahí compiló. 
-Luego descubrí que estaba usando el tamaño de número equivocado para las monedas; en vez de usar int tengo que usar long long para que no se salga de rango. Además, corregí la lectura de archivo por consola con el comando cin, que estaba leyendo mal las líneas.

- También corregí el código de la función "rango" del AVL, que a veces no funcionaba bien.
- Ahora, al hacer los tests y comparar con diff, el programa funciona con buena parte de las entradas (100.in.txt, 1000.in.txt, etc), pero en algunos archivos devuelve "segmentation fault".