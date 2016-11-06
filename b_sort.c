#include <stdlib.h> /*En este caso no necesitamos el archivo de cabecera de input-output, 
					solamente la biblioteca estándar para tener acceso a la función 
					sizeof().*/

/*
* Algoritmo de ordenamiento de complejidad O(n^2).
* --------------------------------------------------------------------------------------------------
* Recibe como parámetros un apuntador de tipo void (para que pueda ser de cualquier tipo)(un arreglo),
* el número de elementos almacenados en el arreglo para saber cuántas posiciones contiguas de memoria
* se van a estar comparando, el número de bytes del tipo de elementos almacenados en el arreglo para saber
* cómo se van a tratar, y un apuntador a la función comparadora que recibe dos apuntadores a los elementos 
* que se van a comparar (en su firma son apuntadores a void para que sea general y puedan apuntar a cualquier tipo,
* pero en el empleo de la función se tendrá que dar como parámtro actual el apuntador al tipo de dato concreto), y regresa
* un entero este apuntador a función (ver main.c para ver la lógica de este entero que regresan las funciones comparadoras).
*
* El algoritmo de ordenamiento hace varios recorridos sobre el arreglo y checa si el elemento
* actual es menor o igual que el que le sigue, pues de lo contrario se tienen que intercambiar.
*/
void bsort(void* base, size_t num, size_t size, int (*compar)(const void*, const void*))
{
	int j,k; //Declaramos fuera de los blucles las variables iteradoras para que no haya anomalías con algunas versiones del compilador.
	if(size == sizeof(int)){ //Verificamos si los elementos del arreglo son de tipo entero al comparar el tamaño de bytes de éstos y del tamaño de bytes dado como parámetro.
		for(j = 0; j < num -1; j++){ //Una primera variable se refiere a los índices del arreglo, desde el primero hasta el último. 
			for( k = 0; k < num-j-1; k++){ /*La segunda varaible itera desde el primer índice hasta uno antes de la primera variable.
											Esto es debido a que una sutil optimización del algoritmo sugiera no tener que 
											iterar hasta el final del arreglo cada vez, pues se asegura que el elemento que ocupe el último lugar, 
											luego el penúltimo, etc., ya estará en la posición en la que va en la medida en que estas iteraciones 
											se vayan llevando a cabo.*/ 
				/*Se llama a la función comparadora para checar si el elemento que está una posición más adelante en el arreglo (es el apuntador de tipo double)
				apuntado al elemento recorrido k+1 veces del inicio), es menor que el previo a él, en cuyo caso requieren ser intercambiados.*/
				if((*compar)((int*)base+k+1, (int*)base+k) < 0){ 
					//INTERCAMBIO
					int aux = *((int*)base+k+1); //Creamos una variable entera auxliar que toma el valor del elemento que está más adelante en el arreglo, para lo cual se tiene que dereferenciar el puntero luego de hacer el cast al tipo de dato entero porque era void. 
	  				*((int*)base+k+1) = *((int*)base+k); //Ahora, en la posición de memoria que se acaba de desocupar almacenamos lo que estaba en la previa a esta dirección de memoria, para lo cual el valor es consultado siguiendo el mismo proceso de casting y dereferenciación del puntero que en el paso previo. 
	  				*((int*)base+k) = aux; //Finalmente, en la segunda posición del arreglo metemos el valor que almacenamos temproaralmente en la variable auxiliar, completando el swap/intercambio. 
				}
			}
		}
	}else if(size == sizeof(double)){ //Verificamos si los elementos del arreglo son de tipo double al comparar el tamaño de bytes de éstos y del tamaño de bytes dado como parámetro.
		for(j = 0; j < num -1; j++){ //Una primera variable se refiere a los índices del arreglo, desde el primero hasta el último. 
			for( k = 0; k < num-j-1; k++){ /*La segunda varaible itera desde el primer índice hasta uno antes de la primera variable.
											Esto es debido a que una sutil optimización del algoritmo sugiera no tener que 
											iterar hasta el final del arreglo cada vez, pues se asegura que el elemento que ocupe el último lugar, 
											luego el penúltimo, etc., ya estará en la posición en la que va en la medida en que estas iteraciones 
											se vayan llevando a cabo.*/ 
				/*Se llama a la función comparadora para checar si el elemento que está una posición más adelante en el arreglo (es el apuntador de tipo double)
				apuntado al elemento recorrido k+1 veces del inicio), es menor que el previo a él, en cuyo caso requieren ser intercambiados.*/
				if((*compar)((double*)base+k+1, (double*)base+k) < 0){ 
					//INTERCAMBIO
					double aux = *((double*)base+k+1); //Creamos una variable double auxliar que toma el valor del elemento que está más adelante en el arreglo, para lo cual se tiene que dereferenciar el puntero luego de hacer el cast al tipo de dato double porque era void. 
	  				*((double*)base+k+1) = *((double*)base+k); //Ahora, en la posición de memoria que se acaba de desocupar almacenamos lo que estaba en la previa a esta dirección de memoria, para lo cual el valor es consultado siguiendo el mismo proceso de casting y dereferenciación del puntero que en el paso previo. 
	  				*((double*)base+k) = aux; //Finalmente, en la segunda posición del arreglo metemos el valor que almacenamos temproaralmente en la variable auxiliar, completando el swap/intercambio.
				}
			}
		}
	} /*No se puso la segunda condición como en 'else' para tener la posibilidad de aumentar
		las posibilidades de este algoritmo al darle mantenimiento y poder comparar otros tipos de datos luego
		de definir las funciones comparadoras necesarias.*/
}