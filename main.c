#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

void limpaTela(char **scrn, int linha, int col);
//np = numero de palavras
void distribuiPal(char **scrn, char **palavras, int linha, int col, int np);
void inserePalavra(char *palavra, char **tela, int dir, int x, int y);
void desenhaNaTela(char item, int x, int y, char **scrn);
void atualizarTela(char **scrn, int tamx, int tamy);

char lista[15][20] = {
    "Uzbequistão",
    "Malásia",
    "Europa",
    "Canadá",
    "Brasil",
    "Japão",
    "China"
};


int main (){
    char **tela = (char **)malloc(TAM * sizeof(char *));
    for (int i = 0; i<TAM; i++){
        tela[i] = (char *) malloc(TAM * sizeof(char));
    }
    limpaTela(tela, TAM, TAM);    
    inserePalavra("Teste", tela, 1, 0, 0);
    atualizarTela(tela, TAM, TAM);
}



void limpaTela(char **scrn, int linha, int col){
    for (int i=0; i<linha; i++){
        for (int j=0; j<col; j++){
            //printf("inseriu linha: %d, coluna: %d\n", i, j);
            scrn[i][j] = '#'; 
        }
    }
}

void desenhaNaTela(char item, int x, int y, char **scrn){
    scrn[x][y] = item; 
}

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

void inserePalavra(char *palavra, char **tela, int dir, int x, int y){
    //dir > 0 = horizontal
    //dir < 0 = vertical 
    int palTam = strlen(palavra);
    for (int i = 0; i<palTam; i++){
        if (dir > 0){
            tela[i][y] = palavra[i];
        } else {
            tela[x][i] = palavra[i];
        }
    }
}

void distribuiPal(char **scrn, char **palavras, int linha, int col, int np){
    
}


