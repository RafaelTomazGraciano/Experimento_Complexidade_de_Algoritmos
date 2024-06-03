#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct lista
{
    int data;
    struct lista *prox;
};

typedef struct lista lista;

lista *cria_no_lista(){
    return NULL;
}

lista *insere_ordenado_crescente(lista *lst, int val){
    lista *novo;
    lista *ant = NULL;
    lista *p = lst;
    while(p != NULL && p->data < val){
        ant = p;
        p = p->prox;
    }
    novo = (lista *) malloc(sizeof(lista));
    novo->data = val;

    if(ant == NULL){
        novo->prox = lst;
    }
    else{
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return lst;
}

lista *free_lista(lista *lst){
    lista *aux;
    lista *p = lst;
    while (p != NULL){
        aux = p->prox;
        free(p);
        p = aux;
    }
    
}