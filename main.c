/*Incluye las funciones de b_sort.c y arreglos_random.c*/
/*Al incluir estos archivos de cabecera, se incluyen a su vez
los demás archivos de cabecera que están especificados como
directivas del preprocesador dentro de ellos, en caso de que aún
no hayan sido incluídos. Las comillas simpleas únicamente buscan
estos archivos de cabecera en el mismo directorio en el que se 
encuentra el archivo.*/
#include "b_sort.h"
#include "arreglos_random.h"

/*Declara las funciones que vamos a ocupar*/
// función que compara dos enteros
int cmp_int(const void *a, const void *b);
// función que compara dos doubles
int cmp_double(const void *a, const void *b);
// función que imprime una lista de enteros de tamaño num
void imprime_int(int *arreglo, size_t num);
// función que imprime una lista de doubles de tamaño num
void imprime_double(double *arreglo, size_t num);


int main() //Declaración del main, que es la entrada y salida del programa y dictamina su ejecución.
{
    // Se inicializan 2 arreglos, uno de ints y otro de doubles
    int *arr1 = arreglo_int(20, 0, 10); //Ambos arreglos son de tamaño 20 y tienen números pseudo-aleatorios entre 0 10, inclusivo.
    double *arr2 = arreglo_double(20, 0, 10);

    // Se imprime ordena e imprime el primer arreglo
    imprime_int(arr1, 20);
    bsort(arr1, 20, sizeof(int), &cmp_int); //Se ordena el arreglo de enteros con el algoritmo de ordenamiento BubbleSort.
    imprime_int(arr1, 20);

    // Se imprime ordena e imprime el segundo arreglo
    imprime_double(arr2, 20);
    bsort(arr2, 20, sizeof(double), &cmp_double); //Se ordena el arreglo de doubles con el algoritmo de ordenamiento BubbleSort.
    imprime_double(arr2, 20);

    // Se libera la memoria que ocupan los arreglos ordenados
    free(arr1); /* Desaloja la memoria contigua que fue reservada
                por malloc, calloc o realloc (en este caso fue 
                calloc, para asegurarnos de que la memoria estuviera limpia).
                Esto se tiene que hacer porque C no tiene un recolector de basura
                propiamente y no se encarga de limpiar la memoria que reservó en caso
                de que ya no se vaya a usar.*/
    free(arr2);

    //Se regresa el estado de salida satisfactorio del programa.
    return 0;
}

/*
* Comparador de enteros
* ---------------------
* Recibe un par de apuntadores de tipo void.
* Regresa un número mayor a 0 en caso de que
* el primer entero sea mayor que el segundo; 
* regresa un número menor a cero en caso de que el 
* primer número sea mayor que el segundo; 
* regresa cero en caso de que sean iguales.
*/
int cmp_int(const void *a, const void *b) //Los apuntadores son de tipo void, pues presentan la ventaja de que pueden estar asociados a cualquier tipo de dato.
{
    int uno = *((int*)a); //Se convierten a apuntadores de enteros ya que estamos comparando enteros.
    int dos = *((int*)b); /*Y en ambos casos se tiene que dereferenciar el apuntador 
                            para ver el valor contenido en la dirección de memoria a la que apunta 
                            para almacenar dicho valor en las variables enteras.*/
    return uno-dos; /*La resta de los números es una forma elegante de 
                    regresar el valor correspondiente a la comparación del orden
                    en una sola línea.*/
}

/*
* Comparador de doubles.
* ---------------------
* Recibe un par de apuntadores de tipo void.
* Regresa un número mayor a 0 en caso de que
* el primer double sea mayor que el segundo; 
* regresa un número menor a cero en caso de que el 
* primer número sea mayor que el segundo; 
* regresa cero en caso de que sean iguales.
*/
int cmp_double(const void *a, const void *b)  //Los apuntadores son de tipo void, pues presentan la ventaja de que pueden estar asociados a cualquier tipo de dato.
{
    double uno = *((double*)a); //Se convierten a apuntadores de doubles ya que estamos comparando este tipo de dato.
    double dos = *((double*)b); /*Y en ambos casos se tiene que dereferenciar el apuntador 
                            para ver el valor contenido en la dirección de memoria a la que apunta 
                            para almacenar dicho valor en las variables de tipo double.*/
    /*En este caso es preferible checar explícitamente
    el orden de los dos elementos dado que la sustracción puede
    resultar en errores de precisión debido a la manera en que los doubles (punto flotante)
    son cíclicos ya que no se puede represenar a los reales con la computadora.*/
    if(uno > dos){
        return 1; //En caso de que el primero sea mayor que el segundo, regresamos un entero mayor a cero.
    }
    else if(uno < dos){
        return -1; //En caso de que el primero sea menor que el segundo, regresamos un entero menor a cero.
    }
    else{
        return 0; //Si son iguales (por la tricotomía del orden en los reales, es la única condición que falta), regresamos cero.
    }
}

/*
* Imprime un arreglo de enteros.
* ------------------------------
* Recibe un apuntador a la primera posición en 
* memoria contigua donde están alojados los enteros, 
* además del tamaño mismo del arreglo (en cuanto a número de
* elementos que hay en él) para saber hasta donde se tiene que iterar.
*/
void imprime_int(int *arreglo, size_t num)
{
    int i; //Declaramos de forma separada la variable para iterar para que algunas versiones del compilador no se quejen.  
    printf("["); //Delimita el inicio del arreglo para visualizarlo mejor.  
    for(int i= 0; i < num-1; i++){ //Iteramos hasta una posición previa al último elemento del arreglo, pues estos elementos son seguidos de una coma. 
        printf("%d%s", arreglo[i], ", "); //Se imprime el entero que corresponde a la iteración, seguido de la coma. 
    }
    printf("%d%s\n\n",arreglo[num-1], "]"); //El último elemento se tiene que tratar de forma separada porque no va seguido de una coma, pero sí del delimitador del fin del arreglo y de un par de saltos de línea. 
}

/*
* Imprime un arreglo de doubles.
* ------------------------------
* Recibe un apuntador a la primera posición en 
* memoria contigua donde están alojados los doubles, 
* además del tamaño mismo del arreglo (en cuanto a número de
* elementos que hay en él) para saber hasta donde se tiene que iterar.
*/
void imprime_double(double *arreglo, size_t num)
{
    int i; //Declaramos de forma separada la variable para iterar para que algunas versiones del compilador no se quejen. 
    printf("["); //Delimita el inicio del arreglo para visualizarlo mejor. 
    for(int i= 0; i < num-1; i++){ //Iteramos hasta una posición previa al último elemento del arreglo, pues estos elementos son seguidos de una coma.
        printf("%.5f%s", arreglo[i], ", "); //Se imprime el double que corresponde a la iteración, seguido de la coma.
    }
    printf("%.5f%s\n\n", arreglo[num-1], "]" ); //El último elemento se tiene que tratar de forma separada porque no va seguido de una coma, pero sí del delimitador del fin del arreglo y de un par de saltos de línea.
}