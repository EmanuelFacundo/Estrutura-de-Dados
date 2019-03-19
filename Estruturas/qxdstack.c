//
// Created by emanuel on 12/3/2018.
//
#include "qxdstack.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>

typedef struct qx_stack_node *QXSNode;

struct qx_stack_node{

    int value;
    QXSNode next;

};

struct __qxd_stack{

    QXSNode top;

};

QxStack qx_stack_new(size_t initCapacity){

    QxStack new_stack = malloc(sizeof(struct __qxd_stack));

    new_stack->top = NULL;

    return new_stack;
}

QXSNode qx_stack_node_new(int value){

    QXSNode node = malloc(sizeof(struct qx_stack_node));

    node->value = value;
    node->next = NULL;

    return node;
}

void qx_stack_delete_nodes(QXSNode node){

    if(node != NULL){

        qx_stack_delete_nodes(node->next);
        free(node);

    }

}

void qx_stack_delete_node(QXSNode node){
    free(node);
}

void qx_stack_delete(QxStack stack){

    qx_stack_delete_nodes(stack->top);
    stack->top = NULL;

}

size_t qx_stack_size(QxStack stack){

    QXSNode node = stack->top;

    size_t size = 0;

    while(node->next != NULL){
        size++;
        node = node->next;
    }

    return size;
}

size_t qx_stack_capacity(QxStack stack){

    return (size_t)QX_INFINITY_SIZE;

}

bool qx_stack_empty(QxStack stack){

    if(stack->top == NULL) return true;

    return false;
}

bool qx_stack_full(QxStack stack){

    return false;

}

int qx_stack_top(QxStack stack){

    return stack->top->value;
}

bool qx_stack_contains(QxStack stack, int element){

    QXSNode node = stack->top;

    while(node->next != NULL){
        if(node->value == element) return true;

        node = node->next;
    }

    return false;
}

size_t qx_stack_find(QxStack stack, int element){

    QXSNode node = stack->top;

    size_t i = 0;

    while(node->next != NULL){
        if(node->value == element) return i;

        i++;
        node = node->next;
    }

    return QX_INFINITY_SIZE;
}

void qx_stack_push(QxStack stack, int elem){

    QXSNode node_new = qx_stack_node_new(elem);

    node_new->next = stack->top;
    stack->top = node_new;

}

void qx_stack_pop(QxStack stack){

    QXSNode rip_node = stack->top;
    stack->top = rip_node->next;

    qx_stack_delete_node(rip_node);

}

void qx_stack_clear(QxStack stack){

    qx_stack_delete_nodes(stack->top);

}

void qx_stack_print_to(QxStack stack, FILE *fp){

    QXSNode node = stack->top;

    fprintf(fp,"[(top) ");
    while(node != NULL){
        fprintf(fp,"%d ", node->value);
        node = node->next;
    }
    fprintf(fp,"(base)]\n");
}