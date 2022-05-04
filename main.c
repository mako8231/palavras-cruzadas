
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "palavra.h"
#include "tela.h"


int main(){
    Tela t = inicializarTela();
    //desenharTela(t);
    inserirCaractere(&t, 'a', 20, 20);
    //carregar o banco de palavras do arquivo
    BancoPal banco; 
    carregarBancoPal("banco_pal.txt", &banco);
    imprimirLista(banco.listaPalavras);
    inserirPrimeiraPalavra(banco, &t, true);
    desenharTela(t);
    

    return 0; 
}