#include <stdio.h>
#include "palavra.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

void carregarPalavras(struct Palavra palavras[]){
        //carrega o arquivo
    FILE *stream; 
    int character;  
    int linhas = 0; 
    int i = 0;

    stream = fopen("banco_pal.txt", "rt");
    if (!stream){
        printf("Não foi possível abrir o arquivo");
        return; 
    }

    while((character = getc(stream)) != EOF){
        if (character == '\n' || character == ' ' || character == '\t'){ 
            printf("quebra de linha\n");
            palavras[linhas].tam = strlen(palavras[linhas].word);
            printf("Palavra: %s, Indice: %d, Linha: %d, Tamanho: %d\n", palavras[linhas].word, i, linhas, palavras[linhas].tam);
            linhas ++;
            i = 0;
        } else {
            palavras[linhas].word[i] = character;
            i++;
        }
        
    }
    fclose(stream);

}

bool interseccao(int **corresp, char *pal1, char *pal2){
    //pegar o tamanho das duas palavras
    int pal1Tam = strlen(pal1);
    int pal2Tam = strlen(pal2);
    //tá funcionando a leitura dos tamanhos 
    //printf("Tamanho das palavras: %d, %d", pal1Tam, pal2Tam);
    (*corresp) = malloc(sizeof(int) * pal1Tam);
    bool tem = false; 

    //fazer o comparador de correpondência:
    for (int i = 0; i<pal1Tam; i++){
        (*corresp)[i] = 0; 
        for (int j = 0; j<pal2Tam; j++){
            if (pal1[i] == pal2[j]){
                tem = true; 
                (*corresp)[i]++; 
            }
        }

    }

    // for (int j = 0; j<pal1Tam; j++){
    //     printf("%d\n", (*corresp)[j]);
    // }

    return tem;
}
