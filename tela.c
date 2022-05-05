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
    imprimirPalavrasNaTela(*t);
}

void distribuirPalavras(BancoPal banco, Tela *t, char *palavra, bool horizontal){
    //pega a palavra atual inserida
    NoPalavra * palavra_atual = t->palavrasTela;
    ListaPal * listaPalavras = banco.listaPalavras->prox;
    ListaPal * pilhaPalavras = banco.pilhaPalavras;
    //pega a próxima palavra no banco 
    while (listaPalavras->prox != NULL)
    {
        //verifica se há interessecções 
        Intereseccao ocorrencias; 
        bool inter = interssecta(*t, palavra_atual, palavra_atual->palavra.str, listaPalavras->p.str, &ocorrencias);
        if (inter){
            printf("Há interssecção, teste ocorrência:\n");
            for (int i = 0; i<strlen(listaPalavras->p.str); i++){
                printf("Endereço na posição: %d\n", ocorrencias.str_endereco[i]);
                printf("Endereço na Tela: %d\n", ocorrencias.tela_endereco[i]);
                
            }
             
        } else {
            printf("Não há interssecção\n");
        }

        listaPalavras = listaPalavras->prox;
        free(ocorrencias.str_endereco);
        free(ocorrencias.tela_endereco);
    }
    
}

bool interssecta(Tela t, NoPalavra * palavra_atual, char *palavra_alvo, char *interssectando, Intereseccao *ocorrencias){
    int tam_alvo = strlen(palavra_alvo);
    int tam_inter = strlen(interssectando); 

    int pos_grade_linha = palavra_atual->pos_linha;
    int pos_grade_coluna = palavra_atual->pos_coluna;

    bool horizontal = palavra_atual->horizontal;
    int n_inter = 0;
    //int n_ocorren = 0; //numero de ocorrencias por palavra

    int * ocorr_pal = (int *) malloc(sizeof(int) * tam_inter);
    int * ocorr_tela = (int *) malloc(sizeof(int) * tam_inter);

    //inicializa os vetores
    for (int i = 0; i<tam_inter; i++){
        ocorr_pal[i] = -1;
        ocorr_tela[i] = -1;
    }


    for (int j = 0; j<tam_inter; j++){
        for (int i=0; i<tam_alvo; i++){
            if (palavra_alvo[i] == interssectando[j]){
                n_inter++;
                ocorr_pal[j] = i;
                if (!horizontal){
                    ocorr_tela[j] = i + pos_grade_linha;
                } else {
                    ocorr_tela[j] = i + pos_grade_coluna;
                }
            }
            
        }
    }

    ocorrencias->str_endereco = ocorr_pal;
    ocorrencias->tela_endereco = ocorr_tela;
    return (n_inter > 0);
}

void imprimirPalavrasNaTela(Tela t){
    NoPalavra * aux = t.palavrasTela;
    while (aux != NULL)
    {
        printf("Palavra: %s\n", aux->palavra.str);
        printf("Tamanho: %d\n", aux->palavra.tam);
        printf("Endereço linha: %d\n", aux->pos_linha);
        printf("Endereço coluna: %d\n", aux->pos_coluna);
        printf("Horizontal?: %d\n", aux->horizontal);

        
        aux = aux->prox;
    }
    
}

