# Bitácora — Obligatorio 1

**Integrantes:** Guillermo Bértola (303665), Nombre Apellido (Nº estudiante)

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
