//
// Created by emanuel on 12/3/2018.
//

#include "qxqueue.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct qx_queue_node *QXQNode;

struct qx_queue_node{

    int value;
    QXQNode next;

};


QXQNode qx_queue_node_new(int value){

    QXQNode node = malloc(sizeof(struct qx_queue_node));

    node->value = value;
    node->next = NULL;

    return node;
}

void qx_queue_delete_nodes(QXQNode node){

    if(node != NULL){

        qx_queue_delete_nodes(node->next);
        free(node);

    }

}

void qx_queue_delete_node(QXQNode node){
    free(node);
}

struct __qxd_queue{

    QXQNode start;

};

QxQueue qx_queue_new(){

    QxQueue queue_new = malloc(sizeof(struct __qxd_queue));

    queue_new->start = NULL;

    return queue_new;
}

void qx_queue_delete(QxQueue queue){

    qx_queue_delete_nodes(queue->start);
    free(queue);

}

size_t qx_queue_size(QxQueue queue){

    QXQNode node = queue->start;
    size_t size = 0;

    while(node != NULL){

        size++;
        node = node->next;

    }

    return size;

}

bool qx_queue_empty(QxQueue queue){
    if(queue->start == NULL) return true;

    return false;
}

bool qx_queue_contains(QxQueue queue, int element){

    if(queue->start == NULL)
        return false;

    QXQNode node = queue->start;

    while(node->next != NULL){
        if(node->value == element) return true;

        node = node->next;
    }

    return false;

}

size_t qx_queue_find(QxQueue queue, int element){

    QXQNode node = queue->start;

    size_t i = 0;
    bool flag = false;

    while(node->next != NULL){

        if(node->value == element) {
            flag = true;
            break;
        }

        i++;
        node = node->next;
    }

    if(flag == true) return i;

    return QX_INFINITY_SIZE;

}

int qx_queue_font(QxQueue queue){

    if(queue->start == NULL) return QX_LAMBDA_ELEMENT;

    return queue->start->value;

}

int qx_queue_back(QxQueue queue){

    if(queue->start == NULL) return QX_LAMBDA_ELEMENT;

    QXQNode node = queue->start;

    while(node->next != NULL){
        node = node->next;
    }

    return node->value;
}

void qx_queue_enqueue(QxQueue queue, int elem){

    QXQNode node = queue->start;

    if(node == NULL){
        QXQNode node_new = qx_queue_node_new(elem);
        
        queue->start = node_new;
        return;
    }

    while(node->next != NULL){
        node = node->next;
    }

    QXQNode node_new = qx_queue_node_new(elem);

    node->next = node_new;

}

void qx_queue_dequeue(QxQueue queue){

    if(queue->start == NULL) return;

    QXQNode rip_node = queue->start;

    queue->start = rip_node->next;

    qx_queue_delete_node(rip_node);
}

void qx_queue_clear(QxQueue queue){

    qx_queue_delete_nodes(queue->start);

}

void qx_queue_print_to(QxQueue queue, FILE *fp){

    QXQNode node = queue->start;

    fprintf(fp,"[(start) ");
    while(node != NULL){
        fprintf(fp,"%d ", node->value);
        node = node->next;
    }
    fprintf(fp,"(end)]\n");
}