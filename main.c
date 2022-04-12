#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TAM 20

#define PAL_TAM 15
#define PAL_LIST 20

//registro da palavra inserida na grade
//indica a posição dela, também há uma cópia de seus caracteres.
struct Palavra
{
    int pal_x; 
    int pal_y; 
    int dir; 
    int tam;  
};


void limpaTela(char **scrn, int linha, int col);
//np = numero de palavras
void distribuiPal(char **scrn, char palavras[PAL_TAM][PAL_LIST], int linha, int col, int np);
void inserePalavra(char *palavra, char **tela, int dir, int x, int y);
void atualizarTela(char **scrn, int tamx, int tamy);
bool correpondentes(int *corresp, char *pal1, char *pal2);

char lista[PAL_TAM][PAL_LIST] = {
    "Uzbequistão",
    "Malásia",
    "Europa",
    "Canadá",
    "Brasil",
    "Japão",
    "China"
};


int main (){
    //Aloca dinamicamente a tela 
    int *c = NULL; 
    bool teste = correpondentes(c, "Teste", "Teste");
    printf("%d",c[0]); 

    char **tela = (char **)malloc(TAM * sizeof(char *));
    for (int i = 0; i<TAM; i++){
        tela[i] = (char *) malloc(TAM * sizeof(char));
    }
    
    limpaTela(tela, TAM, TAM);    
    //inserePalavra("Teste", tela, 1, 0, 0);
    //atualizarTela(tela, TAM, TAM);
    distribuiPal(tela, lista, TAM, TAM, 0);
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
    inserePalavra(palavras[0], scrn, -1, telaX, telaY - metadePal);

    //distribui as demais palavras 

}

bool correpondentes(int *corresp, char *pal1, char *pal2){
    //pegar o tamanho das duas palavras
    int pal1Tam = strlen(pal1);
    int pal2Tam = strlen(pal2);
    //tá funcionando a leitura dos tamanhos 
    //printf("Tamanho das palavras: %d, %d", pal1Tam, pal2Tam);
    corresp = malloc(sizeof(int) * pal1Tam);
    bool tem = false; 

    //fazer o comparador de correpondência:
    for (int i = 0; i<pal1Tam; i++){
        corresp[i] = 0; 
        for (int j = 0; j<pal2Tam; j++){
            if (pal1[i] == pal2[j]){
                tem = true; 
                corresp[i]++; 
            }
        }

    }

    for (int j = 0; j<pal1Tam; j++){
        printf("%d\n", corresp[j]);
    }

    return tem;
}

