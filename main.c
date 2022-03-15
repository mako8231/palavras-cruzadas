#include <stdio.h>
#include <stdlib.h>

#define TAM 40 

void clearScrn(char **scrn, int linha, int col);
//np = numero de palavras
void distribuiPal(char **scrn, char **palavras, int linha, int col, int np);


char lista[15][20] = {
    "Ubequistão",
    "Malásia",
    "Europa",
    "Canadá",
    "Brasil",
    "Japão",
    "China"
};

char tela[TAM][TAM]; 


int main (){
    clearScrn(tela, 40, 40);
    printf("aaaa");
}

void clearScrn(char **scrn, int linha, int col){
    for (int i=0; i<linha; i++){
        for (int j=0; j<col; j++){
            scrn[i][j] = ' '; 
        }
    }
}

void distribuiPal(char **scrn, char **palavras, int linha, int col, int np){
    
}


