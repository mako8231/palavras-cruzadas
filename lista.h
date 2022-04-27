#ifndef PILHA_H_
#define PILHA_H_
#include "palavra.h"

struct Lista
{
    struct Palavra chave;
    struct Lista *prox; 
    
};

#define lista struct Lista


lista * inciaLista();
lista * empilhaLista(lista *l, char *valor);
lista * desempilhaLista(lista *l);
void apagaLista(lista *l);
void imprimirLista(lista *l);


#endif 