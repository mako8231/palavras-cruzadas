#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "palavra.h"


void carregarBancoPal(char * caminho, BancoPal * banco){
    banco->listaPalavras = iniciaLista();
    banco->pilhaPalavras = iniciaLista();
    
    FILE * stream;
    int caractere;
    int linhas = 0;
    int i = 0;
    char aux[PAL_TAM];

    stream = fopen(caminho, "rt");
    if (!stream){
        printf("Não foi possível abrir o arquivo\n");
        return;
    } 

    for (int j = 0; j<PAL_TAM; j++){
        aux[j] = 0;
    }

    while((caractere = getc(stream)) != EOF){
        //inserção caractere por caractere 
        if (caractere == '\n' || caractere == ' ' || caractere == '\t'){
            //empilha a palavra
            banco->listaPalavras = empilhaLista(banco->listaPalavras, aux);
            for (int j = 0; j<PAL_TAM; j++){
                aux[j] = 0;
            }
            i = 0;
        } else {
            aux[i] = caractere;
            i++;
        }
    }


}

ListaPal * iniciaLista(){
    return NULL; 
}

ListaPal * empilhaLista(ListaPal * l, char * str){
    //inserção no fim
    ListaPal * nova_lista = iniciaLista();
    ListaPal * aux = l; 

    nova_lista = (ListaPal *)malloc(sizeof(ListaPal));
    strcpy(nova_lista->p.str, str);
    nova_lista->p.tam = strlen(str);
    nova_lista->prox = NULL;

    if (l == NULL){
        l = nova_lista;
        return l; 
    }

    while(aux->prox != NULL){
        aux = aux->prox;
    }

    aux->prox = nova_lista;
    return l;
}

ListaPal * desempilhaLista(ListaPal * l){
    //remoção no fim
    if (l == NULL){
        printf("A lista já está vazia\n");
        return NULL; 
    }

    ListaPal * aux = l; 
    ListaPal * anterior = NULL; 
    while (aux->prox != NULL){
        anterior = aux;
        aux = aux->prox;
    }

    free(aux);
    aux = NULL; 
    anterior->prox = NULL; 
    return l; 
    
}

void imprimirLista(ListaPal * l){
    ListaPal * aux = l; 
    while(aux != NULL){
        printf("%s\n", aux->p.str);
        aux = aux->prox;
    }
}

