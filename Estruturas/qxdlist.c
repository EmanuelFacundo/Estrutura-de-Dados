//
// Created by emanuel on 12/1/2018.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
#include <stdbool.h>

#include "qxdlist.h"


typedef struct qx_list_node *QXLNode;

struct qx_list_node{

    int value;
    QXLNode next;

};



struct __qxd_list{

    QXLNode first;

};

QxList qx_list_new(){ 

    QxList list_new = malloc(sizeof(struct __qxd_list)); 

    list_new->first = NULL;

    return list_new;
}

QXLNode qx_list_node_new(int value){

    QXLNode node = malloc(sizeof(struct qx_list_node));

    node->value = value;
    node->next = NULL;

    return node;
}

void qx_list_delete_nodes(QXLNode node){
    
    if(node != NULL){

        qx_list_delete_nodes(node->next);
        free(node);
    
    }

}

void qx_list_delete_node(QXLNode node){
    free(node);
}

void qx_list_delete(QxList list){ 

    qx_list_delete_nodes(list->first);
    free(list);

}

size_t qx_list_size(QxList list){ 

    QXLNode node = list->first;
    size_t size = 0;

    while(node != NULL){
        
        size++;
        node = node->next;

    }

    return size;

}

bool qx_list_empty(QxList list){ 

    if(list->first == NULL)
        return true;
    else
        return false;

}

bool qx_list_contains(QxList list, int element){ 

    //if(list->first == NULL) return false; 

    QXLNode node = list->first;

    while(node->next != NULL){
        if(node->value == element){
            return true; 
        }

        node = node->next;
    }

    return false; 
}

qxIndex qx_list_find(QxList list, int element, qxIndex fromIndex){

    QXLNode node = list->first;

    qxIndex i = 0;

    for(i = 0; i < fromIndex ;i++){
        node = node->next;
    }

    i = 0;

    while(node->next != NULL){
        
        if(node->value == element){
            return i;
        }

        i++;
        node = node->next;
    }

    return QX_LAMBDA_INDEX;
}

qxIndex qx_list_find_last(QxList list, int element, qxIndex upToIndex){

    QXLNode node = list->first;

    int find_last = -1;
    int i;

    for(i = 0; i <= upToIndex; i++){
        if(node != NULL){
            
            if(node->value == element){
                find_last = i;
            }
            
            node = node->next;
        }
    }

    if(find_last == -1)
        return (size_t )QX_LAMBDA_ELEMENT;
    
    return (size_t )find_last;
}

int qx_list_at(QxList list, qxIndex index){

    QXLNode node = list->first;

    int i;
    bool flag = false;
    
    for(i = 0; i < index ;i++){
        if(node->next != NULL){
            node = node->next;
            flag = true;
        }
    }

    if(flag == true){
        return node->value;
    }

    return QX_LAMBDA_ELEMENT;
}

int qx_list_font(QxList list){

    QXLNode node = list->first;

    if(node == NULL) return QX_LAMBDA_ELEMENT;

    return node->value;
}

int qx_list_back(QxList list){

    QXLNode node = list->first;

    int last = 0;
    bool flag = false;

    while(node != NULL){
        last = node->value;
        node = node->next;
        flag = true;
    }

    if(flag == true){
        return last;
    }


    return QX_LAMBDA_ELEMENT;
}

bool qx_list_insert_at(QxList list, int element, qxIndex index){

    QXLNode node = NULL;

    if(index == 0){

        node = qx_list_node_new(element);
        node->next = list->first;
        list->first = node;

        return true;
    }else if(index > 0){

        QXLNode antnode = list->first;
        int antindex = 0;

        while(antindex < index - 1 && antnode != NULL){
            antindex++;
            antnode = antnode->next;
        }

        if(antnode != NULL){
            node = qx_list_node_new(element);

            node->next = antnode->next;
            antnode->next = node;

            return true;
        }
    }

    return false;
}

void qx_list_push_front(QxList list, int element){

    QXLNode node = qx_list_node_new(element);

    node->next = list->first;
    list->first = node;

}

void qx_list_push_back(QxList list, int element){



    QXLNode antnode = list->first;

    if(antnode == NULL){
        QXLNode node = qx_list_node_new(element);
        list->first = node;
    }

    while(antnode->next != NULL){
        antnode = antnode->next;
    }

    QXLNode node = qx_list_node_new(element);
    antnode->next = node;

}

qxIndex qx_list_remove_element_first(QxList list, int element){

    QXLNode antnode = list->first;

    if(antnode->value == element){
        list->first = antnode->next;

        qx_list_delete_node(antnode);

        return 0;
    }else{

        size_t i = 0;

        while(antnode->next->value != element){
            antnode = antnode->next;
            i++;
        }

        if(antnode->next == NULL) return QX_LAMBDA_INDEX;

        QXLNode node = antnode->next;
        antnode->next = antnode->next->next;
        free(node);

        return i + 1;


    }

}

qxIndex qx_list_remove_element_last(QxList list, int element) {

    QXLNode node = list->first;
    QXLNode rip_node = NULL;
    QXLNode antnode = NULL;

    bool flag = false;
    size_t i = 0, rip = 0;


    while (node->next != NULL){
        if (node->next->value == element) {
            antnode = node;
            rip_node = node->next;
            rip = i;
            flag = true;
        }

        i++;
        node = node->next->next;
    }

    if (flag == false){
        return (size_t) QX_LAMBDA_INDEX;
    }else{
        antnode->next = rip_node->next;
        qx_list_delete_node(rip_node);

        return rip;
    }


}

unsigned int qx_list_remove_element_all(QxList list, int element) {

    QXLNode antnode = list->first;

    unsigned int i = 0;

    if (antnode->value == element) {
        list->first = antnode->next;

        qx_list_delete_node(antnode);

        i++;
    }

    while (antnode->next != NULL) {

        if (antnode->value == element) {
            QXLNode node = antnode->next;
            antnode->next = antnode->next->next;
            free(node);
            i++;
        }
        antnode = antnode->next;
    }

        return i;
}

bool qx_list_remove_at(QxList list, qxIndex index){

    QXLNode node = list->first;
    QXLNode antnode = NULL;

    if(index == 0){
        list->first = node->next;
        qx_list_delete_node(node);

        return true;
    }

    int i = 0;

    while(i < index && node->next != NULL){
        antnode = node;
        node = node->next;
    }

    if(node->next == NULL){
        return false;
    }

    antnode->next = node->next;
    qx_list_delete_node(node);

    return true;
}

void qx_list_pop_front(QxList list){
    QXLNode node = list->first;
    list->first = node->next;
    qx_list_delete_node(node);
}

void qx_list_pop_back(QxList list){
    QXLNode node = list->first;
    QXLNode antnode = NULL;

    while(node->next != NULL){
        antnode = node;
        node = node->next;
    }

    antnode->next = node->next;
    qx_list_delete_node(node);
}

void qx_list_clear(QxList list){

    qx_list_delete_nodes(list->first);
    list->first = NULL;

}

void qx_list_print_to(QxList list, FILE *fp){

    QXLNode node = list->first;

    fprintf(fp,"[ ");
    while(node != NULL){
        fprintf(fp,"%d ", node->value);
        node = node->next;
    }
    fprintf(fp,"]\n");
}