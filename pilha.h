#ifndef PILHA_H_
#define PILHA_H_
#include "palavra.h"

struct Pilha
{
    struct Palavra* palavras;
    int tam;  
};


//pilha de caracteres 
//que deverá funcionar com alocação de memória dinâmica 
//debug

//empilha a struct de palavra na pilha, última que entra é a primeira que sai 
void empilhar(struct Pilha *pilha, char *valor);
//remove a última palavra inserida e redimensiona o vetor 
void desempilhar(struct Pilha *pilha);
//apagar a pilha da memória 
void apagar(struct Pilha *pilha);
//imprimir os valores da pilha
void imprimirString(struct Pilha pilha);

#endif 