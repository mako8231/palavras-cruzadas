#ifndef PALAVRA_H_
#define PALAVRA_H_
#include <stdbool.h>

struct Palavra
{
    int tam;  
    char word[100];
};


void carregarPalavras(struct Palavra palavras[]);
bool interseccao(int **corresp, char *pal1, char *pal2);




#endif