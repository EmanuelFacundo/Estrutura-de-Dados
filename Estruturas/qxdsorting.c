//
// Created by emanuel on 12/1/2018.
//
#include <stdio.h>
#include <stdint.h>
#include <math.h>

#include "qxdsorting.h"

void qx_insertion_sort(int *array, size_t num_elems){

	int i = 0, j = 0;
	int value = 0;

	for(i = 0; i < num_elems - 1 ;i++){
		value = array[i+1];
		j = i;

		while(j >= 0 && array[j] > value){
			array[j+1] = array[j];
			j--;
		}

		array[j+1] = value;

	}
}

void qx_selection_sort(int array[], size_t num_elems){

	int i = 0, j = 0, m = 0, aux = 0;

	for(i = 0; i < num_elems ;i++){

		m = i;

		for(j = i; j < num_elems ;j++){
			if(array[j] < array[m]){
				m = j;
			}
		}

		aux = array[i];
		array[i] = array[m];
		array[m] = aux;
	}
}

void qx_bubble_sort(int *array, size_t num_elems) {

	int j = 0, i = 0, aux = 0;

	for(j = 2; j < num_elems ;j++){
		for(i = 0; i < num_elems - j ;i++){
			if(array[i] > array[i+1]){
				aux = array[i];
				array[i] = array[i+1];
				array[i+1] = aux;
			}
		}
	}

}

void entrelaca(int v[], int p, int m, int q){

	int z[q-p];
	int i = p;
	int j = m+1;
	int k = 0;

	for(k = 0; k < q-p ;k++){
		if(j > q || (i <= m && v[i] <= v[j])){
			z[k] = v[i];
			i++;
		}else{
			z[k] = v[j];
			j++;
		}
	}

	for(k = 0; k < q-p ;k++){
		v[p+k] = z[k];
	}

}
void merge(int v[], int p, int q){
	if(p >= q) return;

	int m = (p+q)/2;

	merge(v, p, m);
	merge(v, m+1, q);
	entrelaca(v, p, m, q);

}

void qx_merge_sort(int array[], size_t num_elems){

	merge(array, 0, num_elems);

}
int particionamento(int array[], int p, int q){

	int i = p - 1;
	int j = 0, aux = 0;

	for(j = p; j < q ;j++){
		if(array[j] <= array[q]){
			i++;

			aux = array[i];
			array[i] = array[j];
			array[j] = aux;
		}
	}
	aux = array[i+1];
	array[i+1] = array[q];
	array[q] = aux;

	return i + 1;
}

void quick_sort(int array[], int p, int q){

	if(p >= q) return;

	int pivo = particionamento(array, p, q);
	quick_sort(array, p, pivo-1);
	quick_sort(array, pivo+1, q);
}
void qx_quick_sort(int array[], size_t num_elems){

	quick_sort(array, 0, num_elems);

}

void qx_counting_sort(int array[], size_t num_elems, int min_val, int max_val){

    int i = 0, j = 0;
    int aux[num_elems];
    int C[max_val+1];

    for(i = 0; i <= max_val ;i++){
        C[i] = 0;
    }

    for (j = 0; j <= num_elems ;j++){
        C[array[j]] = C[array[j]] +1;
    }

    for(i = 1; i <= max_val ;i++){
        C[i] = C[i] + C[i - 1];
    }

    for(j = num_elems - 1;  j >= 0 ;j--){
        aux[C[array[j]]-1] = array[j];
        C[array[j]] = C[array[j]] - 1;
    }

    for(i = 0; i <= num_elems ;i++){
        array[i] = aux[i];
    }

}