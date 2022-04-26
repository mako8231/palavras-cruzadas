#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pilha.h"
#include "palavra.h"

void empilhar(struct Pilha *pilha, char *valor){
    //se a pilha estiver vazia 
    //aloque o seu tamanho 
    //no caso, por padrão ela precisa ser NULL 
    if ((pilha)->palavras == NULL){
        (pilha)->palavras = (struct Palavra*)malloc(sizeof(struct Palavra));
        (pilha)->palavras[0].tam = strlen(valor); 
        strcpy((pilha)->palavras[0].word, valor); 
        (pilha)->tam = 1; 

    } else {
        //há valores já inseridos na pilha 
        struct Palavra *nova_pilha = NULL; 
        //copiar os valores para uma pilha maior
        nova_pilha = (struct Palavra*) malloc(sizeof(struct Palavra) * (pilha->tam + 1));
        for (int i = 0; i<pilha->tam; i++){
            nova_pilha[i].tam = (pilha)->palavras[i].tam;
            strcpy(nova_pilha[i].word, (pilha)->palavras[i].word);
            //printf("Indice: %d\n", i);
        }
        nova_pilha[pilha->tam].tam = strlen(valor);
        strcpy(nova_pilha[pilha->tam].word, valor);
        pilha->tam ++; 
        //apaga a pilha antiga da memória 
        free((pilha)->palavras);
        (pilha)->palavras = (nova_pilha); 
    }
}

void desempilhar(struct Pilha *pilha){
    if (pilha->tam == 0){
        printf("A pilha já está vazia.\n");
        return;
    } 

    struct Palavra *nova_pilha = NULL; 
    //aloca o tamanho da nova pilha com um índice a menos
    nova_pilha = (struct Palavra*)malloc(sizeof(struct Palavra) * (pilha->tam - 1));
    //copia os valores 
    for (int i=0; i<pilha->tam-1; i++){
        nova_pilha[i].tam = (pilha)->palavras[i].tam;
        strcpy(nova_pilha[i].word, (pilha)->palavras[i].word);
    }

    //libera a pilha antiga 
    free(pilha->palavras);
    //e insere a nova
    pilha->palavras = nova_pilha;
    pilha->tam--;  


}

void imprimirString(struct Pilha pilha){
    for (int i=0; i<pilha.tam; i++){
        printf("Indice: %d, Palavra: %s\n", i, pilha.palavras[i].word);
    } 
}