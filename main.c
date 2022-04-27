
/**
 * todo: criar a função: criaBancoDePalavras()
 * essa função lerá o conjunto de palavras do arquivo.dat 
 * gera uma lista ordenada decrescente
 * antes de mandar para o ordenar, ter valores como palavra e seu tamanho
 * para facilitar, usar uma struct que tenha os campos: palavra, tamanho da palavra
 * 
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "palavra.h"
#include "lista.h"


#define TAM 20

#define PAL_TAM 15
#define PAL_LIST 20

struct Palavra banco_pal[100];

//registro da palavra inserida na grade
//indica a posição dela, também há uma cópia de seus caracteres.


void limpaTela(char **scrn, int linha, int col);
//np = numero de palavras
void distribuiPal(char **scrn, char palavras[PAL_TAM][PAL_LIST], int linha, int col, int np);
void inserePalavra(char *palavra, char **tela, int dir, int x, int y);
void atualizarTela(char **scrn, int tamx, int tamy);

char lista_pal[PAL_TAM][PAL_LIST] = {
    "Uzbequistão",
    "Malásia",
    "Europa",
    "Canadá",
    "Brasil",
    "Japão",
    "China"
};


int main (){
    carregarPalavras(banco_pal);
    
    lista * l = inciaLista();
    l = empilhaLista(l, "Teste");
    imprimirLista(l);
    l = desempilhaLista(l);
    imprimirLista(l);

    //Aloca dinamicamente a tela 
    int *c = NULL; 
    bool teste = interseccao(&c, "Teste", "JOAO");

    char **tela = (char **)malloc(TAM * sizeof(char *));
    for (int i = 0; i<TAM; i++){
        tela[i] = (char *) malloc(TAM * sizeof(char));
    }
    
    limpaTela(tela, TAM, TAM);    
    //inserePalavra("Teste", tela, 1, 0, 0);
    //atualizarTela(tela, TAM, TAM);
    distribuiPal(tela, lista_pal, TAM, TAM, 0);
    atualizarTela(tela, TAM, TAM);
    
}



//limpa cada posição da matriz na array
void limpaTela(char **scrn, int linha, int col){
    for (int i=0; i<linha; i++){
        for (int j=0; j<col; j++){
            //printf("inseriu linha: %d, coluna: %d\n", i, j);
            scrn[i][j] = '#'; 
        }
    }
}


//Atualiza os itens na tela
void atualizarTela(char **scrn, int tamx, int tamy) {
    for (int i = 0; i<tamx; i++){
        for (int j=0; j<tamy; j++){
            printf("%c", scrn[i][j]);
            if (j == tamy - 1){
                printf("\n");
            }
            
        }
    }
}

//Insere um char dentro da garde da tela 
void inserePalavra(char *palavra, char **tela, int dir, int x, int y){
    //dir > 0 = horizontal
    //dir < 0 = vertical 
    int palTam = strlen(palavra);
    for (int i = 0; i<palTam; i++){
        if (dir > 0){
            tela[i + x][y] = palavra[i];
        } else {
            tela[x][i + y] = palavra[i];
        }
    }
}


void distribuiPal(char **scrn, char palavras[PAL_TAM][PAL_LIST], int linha, int col, int np){
    //distribui a primeira palavra
    //pega as coordenadas do centro da tela
    int telaX = linha/2;
    int telaY = col/2;

    //pega a metade da palavra 
    int metadePal = strlen(palavras[0])/2;
    inserePalavra(banco_pal[0].campo, scrn, -1, telaX, telaY - metadePal);

    //distribui as demais palavras 

}


