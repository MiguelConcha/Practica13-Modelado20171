# Practica13-Modelado20171

__Bubble Sort para arreglos de tipo int y double implementado en C__

Se efectuó una implementación análoga al qsort, pero llevando a cabo el algoritmo de ordenamiento BubbleSort O(n^2) para ordenar un arreglo.

`void bsort(void* base, size_t num, size_t size, int (*compar)(const void*, const void*))`

La función recibe: 

* *void base, que es un apuntador al primer elemento del arreglo, es decir, a la primera posición de memoria contigua que se estará evaluando y en conjunto representa el arreglo. Es de tipo void, pues permite apuntar a cualquier tipo de dato, lo que le aporta flexibilidad a este algortimo bsort.
* size_t num, que se refiere al número de elementos que están alojados en el arreglo.
* size_t size, que es el tamaño en bytes de los elementos alojados en el arreglo.
* int (*compar)(const void*, const void*), que es un apuntador a una función comparadora que:
 * Recibe un par de apuntadores al tipo de dato que se está comparando (por ello en la firma es void).
 * Regresa: 
 
  Un entero menor a cero si el primer elemento es menor que el segundo.
  Un entero mayor a cero si el primer elemento es mayor que el segundo. 
  Cero en caso de que sean el mismo elemento.
  
Además, se implementó la funcionalidad de poder generar arreglos de tipo entero o double con elementos pseudo-aleatorios a partir de la semilla de time(NULL) --segundos transcurridos desde del 1ero. de enero de 1970, en un rango a partir de la cota inferior y superior dadas como parámetros a dicha función. El rango es inclusivo.
