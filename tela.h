#ifndef TELA_H
#define TELA_H
#include "palavra.h"

#define LINHAS 41
#define COLUNAS 41

#include <stdbool.h>

typedef struct NoPalavra{
    Palavra palavra;
    int pos_linha;
    int pos_coluna;
    bool horizontal; 
    struct NoPalavra * prox; 
} NoPalavra;

typedef struct Tela {
    char grade[LINHAS][COLUNAS];
    NoPalavra * palavrasTela;
} Tela; 

typedef struct Intereseccao {
    int * str_endereco; //endereço na posição da string
    int * tela_endereco_linha; //endereço na posição da palavra na tela
    int * tela_endereco_coluna;
} Intereseccao;

Tela inicializarTela();
void desenharTela(Tela t);
void inserirCaractere(Tela * t, char valor, int linha, int coluna);
void inserirPalavra(Tela *t, char * palavra, int linha, int coluna, bool horizontal);
void distribuirPalavras(BancoPal banco, Tela *t, char *palavra, bool horizontal);
NoPalavra * inserirLista(Tela *t, char * palavra, int linha, int coluna, bool horizontal);
int listaTam(Tela *t);
void inserirPrimeiraPalavra(BancoPal banco, Tela * t, bool horizontal);
void imprimirPalavrasNaTela(Tela t);
bool interssecta(Tela t, NoPalavra * palavra_atual, char *palavra_alvo, char *interssectando, Intereseccao *ocorrencias);

#endif
