#ifndef PILHA_H_
#define PILHA_H_

//pilha de caracteres 
//debug
void imprimePilha(char *pilha);
//tamanho da pilha 
int tamPilha(char *pilha);
//criar um ponteiro de caracteres do tipo vetor
void incializarPilha(char val, char *pilha);
//copiar valores de um vetor para uma pilha
void copiarPilha(int tam, char *copia, char *pilha);
//inserir o valor no final da pilha
void empilhar(char valor, char *pilha);
//remover o ultimo valor no topo da pilha
void desempilhar(char *pilha);

#endif 