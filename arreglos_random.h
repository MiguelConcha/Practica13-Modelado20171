#ifndef ARREGLOS_RANDOM_H
#define ARREGLOS_RANDOM_H

#include <stdlib.h>
#include <time.h>

//No es necesario ya que stdlib.h y stdio.h lo trae
#include <stddef.h>

/*  Crea un arreglo de enteros(en el heap) con números aleatorios
    num indica el tamaño del arreglo
    min indica el mínimo número aleatorio permitido en el arreglo
    max indica el máximo número aleatorio permitido en el arreglo
*/
int* arreglo_int(size_t num, int min, int max);

/*  Crea un arreglo de doubles(en el heap) con números aleatorios
    num indica el tamaño del arreglo
    min indica el mínimo número aleatorio permitido en el arreglo
    max indica el máximo número aleatorio permitido en el arreglo
*/
double* arreglo_double(size_t num, double min, double max);

#endif // ARREGLOS_RANDOM_H