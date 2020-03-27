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


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {    /* Needs implementation */
    /* Permutes elements of a[izq..der] and returns pivot such that:
     - izq <= pivot <= der
     - elements in a[izq,pivot) all 'go_before' (according to function goes_before) a[pivot]
     - a[pivot] 'goes_before' all the elements in a(pivot,der]
    */
    unsigned int i, j, pivot;
    pivot = izq;
    i = izq + 1;
    j = der;
    while (goes_before(i,j))
    {
        if (goes_before (a[i],a[pivot])){
            i=i+1u;
        }
        else if (goes_before(a[pivot],a[j])){
            j=j-1u;
        }
        else if (goes_before(a[pivot],a[i]) && goes_before(a[j],a[pivot])){
            swap(a,i,j);
            i=i+1u;
            j=j-1u;
        }
    }
    swap(a,pivot,j);
    pivot=j;
    return pivot;
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    /* copiá acá la implementación que hiciste en el ejercicio 3 (quizás quiso decir ejer 2)*/ 
    unsigned int pivot; // variable del pivot
    //printf("izq=%u __  der=%u\n",izq,der);
    //fflush(stdout);
    if (der>izq && der != 0u-1u && der != 0) {
        pivot = partition(a, izq, der);
        quick_sort_rec(a, izq, pivot-1u);
        quick_sort_rec(a, pivot+1u, der);
    }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}

