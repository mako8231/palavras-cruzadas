#ifndef PALAVRA_H
#define PALAVRA_H
#define PAL_TAM 30
    typedef struct Palavra{
        int tam; //tamanho da palavra
        char str[PAL_TAM]; //a palavra em si
    } Palavra;

    typedef struct ListaPal
    {
        Palavra p;
        struct ListaPal * prox; 
    }ListaPal;
    

    typedef struct BancoPal
    {
        ListaPal * listaPalavras; 
        ListaPal * pilhaPalavras;
    }BancoPal;
    
    void carregarBancoPal(char * caminho, BancoPal * banco);
    ListaPal * iniciaLista();
    ListaPal * empilhaLista(ListaPal * l, char * str);
    ListaPal * desempilhaLista(ListaPal * l);
    void imprimirLista(ListaPal * l);


#endif 