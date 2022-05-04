#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tela.h"

Tela inicializarTela(){
    Tela nova_tela; 
    for (int i = 1; i<LINHAS; i++){
        for (int j = 1; j<COLUNAS; j++){
            nova_tela.grade[i][j] = '#';
        }
    }
    nova_tela.palavrasTela = NULL;  
    return nova_tela; 
}

void desenharTela(Tela t){
    for (int i = 1; i<LINHAS; i++){
        for (int j=1; j<COLUNAS; j++){
            if ((j%COLUNAS-1)==0){
                printf("\n");
            }
            printf("%c", t.grade[i][j]);
        }
    }
}

void inserirCaractere(Tela * t, char valor, int linha, int coluna){
    if ((linha == 0 || linha > LINHAS-1) || (coluna == 0 || coluna > COLUNAS-1)){
        printf("Endereço fora de alcance da tela\n");
        return;
    }
    t->grade[linha][coluna] = valor;
    return;
}

void inserirPalavra(Tela *t, char * palavra, int linha, int coluna, bool horizontal){
    int tam = strlen(palavra);
    for (int i = 0; i<tam; i++){
        if (!horizontal){
            inserirCaractere(t, palavra[i], linha + i, coluna);
        } else {
            inserirCaractere(t, palavra[i], linha, coluna + i);
        }
    }

    t->palavrasTela = inserirLista(t, palavra, linha, coluna, horizontal);
}

NoPalavra * inserirLista(Tela *t, char * palavra, int linha, int coluna, bool horizontal){
    //inserção no fim
    NoPalavra * nova_lista;
    NoPalavra * aux = t->palavrasTela;

    //insere os valores 
    nova_lista = (NoPalavra *)malloc(sizeof(NoPalavra));
    nova_lista->horizontal = horizontal;
    strcpy(nova_lista->palavra.str, palavra);
    nova_lista->palavra.tam = strlen(palavra);
    nova_lista->pos_linha = linha; 
    nova_lista->pos_coluna = coluna; 
    nova_lista->prox = NULL; 

    if (t->palavrasTela == NULL){
        t->palavrasTela = nova_lista;
        return t->palavrasTela;
    }

    while (aux->prox != NULL){
        aux = aux->prox;   
    }

    aux->prox = nova_lista;
    return t->palavrasTela;

}

int listaTam(Tela * t){
    NoPalavra * aux = t->palavrasTela; 
    int tamanho = 0;
    while(aux != NULL){
        aux = aux->prox;
        tamanho++;
    }
    return tamanho;
}

void inserirPrimeiraPalavra(BancoPal banco, Tela * t, bool horizontal){
    //calcular a metade da tela:
    int m_linha = (LINHAS-1)/2;
    int m_col = (COLUNAS-1)/2;

    //calcular a metade da palavra
    int m_tamanho = (banco.listaPalavras->p.tam)/2;
    inserirPalavra(t, banco.listaPalavras->p.str, m_linha - (m_tamanho * !horizontal), m_col - (m_tamanho * horizontal), horizontal);
}


