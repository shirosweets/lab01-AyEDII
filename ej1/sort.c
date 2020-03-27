/* Materia: Algoritmos y Estructura de Datos II - 2020 FAMAF
    <<<<< LABORATORIO 1 >>>>>
Proyecto download --> http://bit.ly/2WpXVCp

Alumnos:  
    - Greiff, Alejandro Nicolas
    - Vispo, Valentina Solange
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

//  implementes el procedimiento insert El algoritmo debe ordenar con respecto a la relación 
// goes_before, provista por sort_helpers.h


static void insert(int a[], unsigned int i) {
    /* needs implementation */
    for (int j=i; (goes_before(a[j], a[j-1]) && j>0); j--){ // goes_before ordena quitando el signo
        /* Exchanges elements of array 'a' in the given positions 'i' and 'j'
        Array remains the same if the two positions are the same */
        swap(a, j-1, j);
    }
}

void insertion_sort(int a[], unsigned int length) { /* Funcion insertion sort*/
    for (unsigned int i = 1u; i < length; ++i) {
        /* needs implementation */
        insert(a, i);
        /* Verificar el cumplimiento del invariante del "ciclo for del procedimiento
        insertion_sort" */
        assert(array_is_sorted(a, i)); // Verifica si el arreglo a esta ordenado ascendentemente
    }
}

/* void insertion_sort(int a[], unsigned int length);
    Sort the array 'a' using the Insertion sort algorithm. The resulting sort
    will be ascending according to the goes_before funtion.

    The array 'a' must have exactly 'length' elements.
*/

/* bool goes_before(int x, int y);
    Abstract total order for sorting algorithms 

bool array_is_sorted(int a[], unsigned int length);
    Checks if the array 'a' is in ascending order 

void swap(int a[], unsigned int i, unsigned int j);
    Exchanges elements of array 'a' in the given positions 'i' and 'j'
    Array remains the same if the two positions are the same
*/
