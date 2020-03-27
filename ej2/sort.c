/* Materia: Algoritmos y Estructura de Datos II - 2020 FAMAF
    <<<<< LABORATORIO 1 >>>>>
Proyecto download --> http://bit.ly/2WpXVCp

Alumnos:  
    - Greiff, Alejandro Nicolas
    - Vispo, Valentina Solange

Videos de explicacion de quick sort
https://youtu.be/PgBzjlCcFvc
https://www.youtube.com/watch?v=Hoixgm4-P4M
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

/* Implemente el procedimiento quick_sort_rec */
static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    /* needs implementation */
    /* no implementes partition, ya está implementado en sort_helpers.o
       (no se puede leer, pero en sort_helpers.h vas a encontrar información
        para saber cómo usarlo)
    */

    // https://wiki.cs.famaf.unc.edu.ar/lib/exe/fetch.php?media=algo2:main:2020.02.ordenacion.avanzada.pdf

    //partition(a, izq, der);
    unsigned int pivot; // variable del pivot
    printf("izq=%u __  der=%u\n",izq,der);
    fflush(stdout);
    if (der>izq && der != 0u-1u && der != 0) {
        pivot = partition(a, izq, der);
        quick_sort_rec(a, izq, pivot-1u);
        quick_sort_rec(a, pivot+1u, der);
    }
}
/* sort.c : contiene una implementación muy incompleta de quick_sort, falta implementar
quick_sort_rec
*/

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
    /*if (0u < length) 
    { 
        // pi is partitioning index, a[p] is now 
        //   at right place 
        int pi = partition(a, 0u, length); 
  
        // Separately sort elements before 
        // partition and after partition 
        quick_sort_rec(a, 0u, pi - 1); 
        quick_sort_rec(a, pi + 1, length); 
    } */
}

/* unsigned int partition(int a[], unsigned int izq, unsigned int der);
 Permutes elements of a[izq..der] and returns pivot such that:
     - izq <= pivot <= der
     - elements in a[izq,pivot) all 'go_before' (according to function goes_before) a[pivot]
     - a[pivot] 'goes_before' all the elements in a(pivot,der]

*/

/* void quick_sort(int a[], unsigned int length);

    Sort the aay 'a' using the quick_sort_rec algorithm. The resulting sort
    will be ascending according to the goes_before funtion.

    The aay 'a' must have exactly 'length' elements.

*/