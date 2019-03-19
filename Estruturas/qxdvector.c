//
// Created by emanuel on 12/1/2018.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#include "qxdvector.h"

struct __qxd_vector{

	int *v; 
	int size; 
	int last; 

};

QxVector qx_vector_new(size_t initCapacity){ 
	QxVector vector_new = malloc (sizeof(struct __qxd_vector));

	vector_new->v = malloc (initCapacity * sizeof(int));
	vector_new->size = initCapacity;
	vector_new->last = -1;

	return vector_new;
}

void qx_vector_delete(QxVector vector){ 

	if(vector->size > 0)
		free(vector->v);
	
	free(vector);
}

size_t qx_vector_size(QxVector vector){ 

	return (size_t )vector->size;

}

size_t qx_vector_capacity(QxVector vector){
	return (size_t)vector->size - (vector->last + 1);
}

bool qx_vector_empty(QxVector vector){ 

	if(vector->last > -1)
		return true;
	
	else
		return false;

}

bool qx_vector_full(QxVector vector){ 

	if(vector->last + 1 == vector->size)
		return true;
	
	else
		return false;
}

bool qx_vector_contains(QxVector vector, int element){

	int i;

	for(i = 0; i <= vector->last ;i++)
		if(vector->v[i] == element)
			return true;
		
	return false;
}

qxIndex qx_vector_find(QxVector vector, int element, qxIndex fromIndex) {

	int i;

	for (i = fromIndex; i <= vector->last; i++) {
		if (vector->v[i] == element) {
			return (size_t) i;
		}
	}

	return QX_LAMBDA_INDEX;
}

qxIndex qx_vector_find_last(QxVector vector, int element, qxIndex upToIndex){

	
	if(upToIndex <= vector->last){

		int i, id = -1;

		for(i = 0; i < upToIndex ;i++)
			if(vector->v[i] == element)
				id = i;

		if(id > -1)
			return (size_t )id;
		
		else
			return QX_LAMBDA_INDEX;
	}

	return QX_LAMBDA_INDEX;
}

int qx_vector_at(QxVector vector, qxIndex index){

	if(index <= vector->last && index > -1)
		return vector->v[index];
	
	return QX_LAMBDA_ELEMENT;
}

int qx_vector_font(QxVector vector){

	if(vector->last > -1)
		return vector->v[0];
	
	return QX_LAMBDA_ELEMENT;
}

int qx_vector_back(QxVector vector){

	if(vector->last > -1)
		return vector->v[vector->last];

	return QX_LAMBDA_ELEMENT;
}

bool qx_vector_insert_at(QxVector vector, int element, qxIndex index){

	if(index >= vector->size) return false;

	int i = 0;

	for(i = vector->last ; index < i ;i--){

		vector->v[i] = vector->v[i-1];

	}

	vector->v[index] = element;
	vector->last++;

	return true;
}

void qx_vector_push_front(QxVector vector, int element){

	if(vector->last == vector->size){

		vector->v = realloc (vector->v,17 * sizeof(int));
		vector->size +=17;

	}
	int i = 0;

	for(i = vector->last + 1; 0 < i ;i--){
		vector->v[i] = vector->v[i-1];
	}

	vector->v[0] = element;
	vector->last++;
}

void qx_vector_push_back(QxVector vector, int element){

	if(vector->last == vector->size){

		vector->v = realloc (vector->v,17 * sizeof(int));
		vector->size +=17;

	}

	vector->v[vector->last+1] = element;
	vector->last++;

}

qxIndex qx_vector_remove_element_first(QxVector vector, int element){

    int i = 0;

    while(i <= vector->last && vector->v[i] != element){
        i++;
    }

    if(vector->v[i] == element){
        int id = i;
        while(i < vector->last){
            vector->v[i] = vector->v[i+1];
            i++;
        }

        vector->last--;

        return (size_t)id;
    }

    vector->last--;

    return (size_t)i;
}

qxIndex qx_vector_remove_element_last(QxVector vector, int element){

    int i = 0;
    int id = 0;

    for(i = 0; i <= vector->last ;i++){
        if(vector->v[i] == element) {
            id = i;
        }
    }

    if(id == vector->last){
        vector->last--;
        return (size_t)id;
    }

    for (i = vector->last; id < i ;i--){

        vector->v[i] = vector->v[i-1];

    }

    vector->last--;
    return (size_t)id;
}

size_t qx_vector_remove_element_all(QxVector vector, int element){

    int qtd = 0;
    int i =0;

    for(i = 0; i <= vector->last ;i++){
        if(vector->v[i] == element){
            for (int j = i; j < vector->last;j++){
                vector->v[j] = vector->v[j+1];
            }
            qtd++;
            vector->last--;
        }
    }

    return (size_t )qtd;
}

bool qx_vector_remove_at(QxVector vector, qxIndex index){

    if(index > vector->last) return false;

    int i = 0;

    if(index == vector->last){
        vector->last--;
        return true;
    }

    for(i = index; i < vector->last;i++){
        vector->v[i] = vector->v[i+1];
    }

    vector->last--;

    return true;
}

void qx_vector_pop_front(QxVector vector){

    int i = 0;

    if(vector->last == 0){
        vector->last--;
        return;
    }
    for(i = 0; i < vector->last ;i++){
        vector->v[i] = vector->v[i+1];
    }

    vector->last--;
}

void qx_vector_pop_back(QxVector vector){
    if(vector->last > -1)
        vector->last--;

}

void qx_vector_clear(QxVector vector){
    vector->last = -1;
}

void qx_vector_print_to(QxVector vector, FILE *fp){

    fprintf(fp,"[ ");
    int i = 0;
    for (i = 0; i <= vector->last;i++)
        fprintf(fp,"%d ", vector->v[i]);

    fprintf(fp,"]\n");

}





