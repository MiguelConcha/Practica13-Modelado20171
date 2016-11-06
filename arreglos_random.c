#include <stdio.h> //Se incluye el archivo de cabecera que permita imprimir.
#include <time.h> /*Se incluye este archivo de cabecera que incluye la biblioteca relacionada con operaciones 
					de fecha y hora que ervirá para poder generar los números pseudo-aleatorios a partir de 
					la fecha actual.*/
#include <stdlib.h> /*Se inluye el archivo de cabecera de la biblioteca estándar para usar srand()
					 que permite establecer una semilla para generar números pseudo-aleatorios.*/

/*
* Crea un arreglo de enteros de números pseudo-aleatorios.
* --------------------------------------------------------
* Recibe el número de elementos que estarán presentes en el 
* arreglo para poder reservar la memoria contigua para alojarlos.
* Recibe también un par de enteros que delimitan el rango en que
* los números aleatorios deben existir (lo traté de forma inclusiva).
*/
int* arreglo_int(size_t num, int min, int max)
{
	int i; //Declaro la variable iteradora aparte para que algunas versiones del compilador no se quejen.
	srand(time(NULL)); /*La llamada a "time(NULL)" regresa el tiempo de acuerdo con la fecha actual en segundos desde el primero de enero de 1970.
						Luego, este número se emplea como la 'semilla' para generar los números pseudo-aleatorios.*/
	/*Creamos un apuntador de enteros, que es el arreglo, a partir de la memoria que nos da callor (memoria limpia, pero tarda un poco más) con la información 
	del número de elementos que queremos que tenga el arreglo y el tamaño de cada dato del mismo (en este caso son enteros). Puesto que malloc regresa un apuntador
	void, tenemos que hacer el cast a apuntador de entero.*/ 
	int *arreglo = (int*) calloc(num, sizeof(int));
	for(i = 0; i < num; i++){ //Iteramos las posiciones contiguas de memoria que nos dio calloc.
		arreglo[i] = (rand() % (max + 1 - min)) + min; /*y vamos llenando cada posición con un número pseudo-aleatorio (generado a partir de la semilla)
									que puede ir desde cero hasta RAND_MAX, que es aproximadamente 32767, pero varía de acuerdo 
									con la implementación de las bibliotecas. Se efectúa la operación de módulo para que a lo más 
									se tenga el número 1000, luego de hacer unos ajustes, porque el límite superior originalmente es exlusivo.*/
										
	}
	return arreglo; //Regresamos el arreglo --un apuntador a su primer elemento.
}

/*
* Crea un arreglo de enteros de números pseudo-aleatorios.
* --------------------------------------------------------
* Recibe el número de elementos que estarán presentes en el 
* arreglo para poder reservar la memoria contigua para alojarlos.
* Recibe también un par de doubles que delimitan el rango en que
* los números aleatorios deben existir (lo traté de forma inclusiva).
*/
double* arreglo_double(size_t num, double min, double max)
{
	int i; //Declaro la variable iteradora aparte para que algunas versiones del compilador no se quejen.
	srand(time(NULL)); /*La llamada a "time(NULL)" regresa el tiempo de acuerdo con la fecha actual en segundos desde el primero de enero de 1970.
						Luego, este número se emplea como la 'semilla' para generar los números pseudo-aleatorios.*/
	/*Creamos un apuntador de doubles, que es el arreglo, a partir de la memoria que nos da callor (memoria limpia, pero tarda un poco más) con la información 
	del número de elementos que queremos que tenga el arreglo y el tamaño de cada dato del mismo (en este caso son doubles). Puesto que malloc regresa un apuntador
	void, tenemos que hacer el cast a apuntador de double.*/ 
	double *arreglo = (double*) calloc(num, sizeof(double));
	for(i = 0; i < num; i++){ //Iteramos las posiciones contiguas de memoria que nos dio calloc.
		double rango = (max - min); //El rango está dado por los parámetros que recibe la función.
    	double divi = RAND_MAX / rango; /*RAND_MAX, que es aproximadamente 32767, pero varía de acuerdo 
									con la implementación de las bibliotecas, lo dividimos entre el rango para que en efecto
									nuestros números se generen en dicho intervalo.*/
    	double aleatorio = min + (rand() / divi); //Asegurándonos de que sea inclusivo en la cota superior.
		arreglo[i] = aleatorio;	//Cada posición del arreglo (pedazo de memoria contigua reservada por calloc), la llenamos con el número pseudo-aleatorio que contruímos.
	}
	return arreglo; //Regresamos el arreglo --un apuntador a su primer elemento.
}