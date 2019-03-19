#include <stdio.h>
#include <stdlib.h>


#include "qxdsorting.h"
/*
#include "qxdlist.h"
#include "qxdvector.h"
#include "qxqueue.h"
#include "qxdstack.h"
#include "qxdsearching.h"
*/

int main(){

    int tamanho = 0;
    char tipo;
    int *vetor;

    printf("Tamanho do vetor a ser ordenado: ");
    scanf("%d", &tamanho);

    vetor = (int*) malloc (tamanho * sizeof(int));

    printf("Valores do vetor: ");
    for (int i = 0; i < tamanho ;i++){
        scanf("%d", &vetor[i]);
    }

    printf("Escolha o tipo de ordenacao:\n");
    printf("1 - Insertion Sort\n");
    printf("2 - Selection Sort\n");
    printf("3 - Bubble Sort\n");
    printf("4 - Merge Sort\n");
    printf("5 - Quick Sort\n");
    printf("opcao: ");
    scanf(" %c", &tipo);

    switch(tipo){
        case '1':
            qx_insertion_sort(vetor, tamanho);
            break;
        case '2':
            qx_selection_sort(vetor, tamanho);
            break;
        case '3':
            qx_bubble_sort(vetor, tamanho);
            break;
        case '4':
            qx_merge_sort(vetor, tamanho);
            break;
        case '5':
            qx_quick_sort(vetor, tamanho);
            break;
        default:
            printf("Opcao errada flw!\n");
            return 0;

    }

    FILE *arquivo;

    arquivo = fopen("test.txt","w");
    if(arquivo == NULL)
        printf("Erro ao abrir o arquivo\n");

    fprintf(arquivo,"[ ");
    for(int i = 0; i < tamanho ;i++){
        fprintf(arquivo,"%d ", vetor[i]);
    }
    fprintf(arquivo,"]\n");

    printf("O vetor ordenado estar no arquivo 'test.txt'\n");


    return 0;
}