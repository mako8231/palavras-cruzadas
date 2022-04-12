#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

void incializarPilha(char val, char *pilha){
    //criando o ponteiro 
    pilha = (char *)malloc(sizeof(char) * 1);

}

void empilhar(char valor, char *pilha){
    //cria um novo vetor com incremento de +1 
    char *nova_pilha;
    nova_pilha = (char *)malloc(sizeof(char) * (tamPilha(pilha) + 1));
    //agora, inserir os o novo valor na pilha
    nova_pilha[0] = valor; 
    for (int i=1; i<tamPilha(pilha); i++){
        nova_pilha[i] = pilha[i - 1];
    }
    free(pilha);
    pilha = nova_pilha;
}

int tamPilha(char *pilha){    
    size_t n = sizeof(pilha)/sizeof(pilha[0]);
    return n; 
}

