#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"
#include "palavra.h"


lista * inciaLista(){
    lista * l; 
    l = NULL; 
    return l;
}

lista * empilhaLista(lista *l, char *valor){
    //inserção no fim
    lista * novaLista = (lista *) malloc(sizeof(lista));
    lista * ptrProx = l; 
    strcpy(novaLista->chave.campo, valor);
    novaLista->chave.tam = strlen(valor);
    novaLista->prox = NULL; 
    //se não foi inserido nenhum elemento
    if (l == NULL){
        l = novaLista;
        return l;
    } 

    // se há elementos na lista: 
    while (ptrProx->prox != NULL)
    {
        ptrProx = ptrProx->prox;
    }

    ptrProx->prox = novaLista;
    return l; 
}

lista * desempilhaLista(lista * l){
    //remover o último item da lista
    //se a lista já estiver vazia: 
    if (l == NULL){
        printf("A lista está vazia");
        return l; 
    }

    lista * ptrProx = l;
    lista * ptrAnt = l; 
    
    
    while (ptrProx->prox != NULL)
    {
        ptrAnt = ptrProx; 
        ptrProx = ptrProx->prox; 
    }
    

    //se for um item na lista:
    if(l->prox == NULL){
        free(l);
        l = NULL; 
    } else {
        //libera o nodo da memória
        ptrAnt->prox = NULL;
        free(ptrProx);
        ptrProx = NULL;
    }
    
    return l; 

}

void imprimirLista(lista * l){
    lista * ptrProx =  l;
    if (l == NULL){
        printf("A lista está vazia.\n");
        return;
    }

    while (ptrProx != NULL)
    {
        printf("Elemento: %s\n", ptrProx->chave.campo);
        ptrProx = ptrProx->prox;
    }
}
