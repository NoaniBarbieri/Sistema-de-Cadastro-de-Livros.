/*
-Daniel Lisboa Alves
-Deyvet Walef dos Santos Martins
-Gabriel Mattos Rocha
-Lucas Correia Peçanha
-Manoella dos Reis Leite
-Noani Zinger Barbieri
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

typedef struct{
    char titulo[51];
    char autor[51];
    char categoria[51];
    char ISBN[20];
    int qtd_paginas;
}Livros;

int validaISBN(Livros liv[], int *contadorLivros){ //passando por parametro a struct e um ponteiro que vai apontar para o endereço da variavel do argumento
    int teste=0, i; //este teste servira para analisar quantas vezes se repetiu o mesmo ISBN no la�o abaixo
    char ISBN[20];
    int aux = *contadorLivros; //determinando um auxiliar para evitar problemas caso o contador seja alterado

    printf("Entre com o ISBN: ");
    fflush(stdin);
    gets(ISBN);

    for(i=0; i<(*contadorLivros); i++){ //o laço ira analisar se o mesmo ISBN inserido ja foi inserido
        if(strcmp(ISBN, liv[i].ISBN)==0){
            teste++; //caso encontrar repetição essa variável irá ser alterada
        }
    }
    if(teste==0){ //Portanto, se ela for igual a zero significa que não houve repetição
        strcpy(liv[aux].ISBN, ISBN); //função para copiar a string inserida pela usuário e colar na struct
        return 0;
    }
    else{
        return 1; //caso a variável for diferente de zero o ISBN já existe, portanto o programa retorna 1
    }
}

void main(){
    setlocale(LC_ALL, "Portuguese");

    Livros livros[100];
    int op=0; //começando em zero para sempre entrar no while de inicio e evitar problemas de valores aleatorios na variavel
    int contadorLivros=-1; //conta a quantidade de livros

    int teste=0; //variavel para testar se existe algum livro com a ISBN inserida
    int i; //contador para os laços
    int validar; //variavel para receber o valor de retorno da função que valida o ISBN

    //VARIAVEIS PARA SERVIREM COMO BUSCA PELO USUARIO:
    char ISBN[20]; //ISBN para ser comparado com todos os livros presentes na biblioteca
    char categoria[51]; //categoria para ser comparado com todos os livros presentes na biblioteca
    char autor[51]; //Autor para ser comparado com todos os livros presentes na biblioteca



    while(op!=6){
        system("color F4");
        printf("\n*************** MENU **************\n");
        printf("\n1 - CADASTRAR LIVRO\n2 - BUSCAR ISBN\n3 - BUSCAR AUTOR\n4 - LISTAR POR CATEGORIA\n5 - IMPRIMIR LIVROS\n6 - SAIR DO PROGRAMA\n");
        printf("\n***********************************");
        printf("\nEscolha uma op��o: ");
        scanf("%d",&op);

        switch(op){
        case 1:
            contadorLivros++;
            validar = validaISBN(livros, &contadorLivros); //esta variavel ira receber o retorno da função
                if(validar==0){ //caso o retorno for zero, os dados poderão ser preenchidos
                    printf("Entre com o titulo do livro: ");
                    fflush(stdin);
                    gets(livros[contadorLivros].titulo);
                    printf("Entre com o autor: ");
                    fflush(stdin);
                    gets(livros[contadorLivros].autor);
                    printf("Entre com a categoria: ");
                    fflush(stdin);
                    gets(livros[contadorLivros].categoria);
                    printf("Entre com a quantidade de paginas: ");
                    fflush(stdin);
                    scanf("%d",&livros[contadorLivros].qtd_paginas);
                    system("cls");
                    printf("\nLivro Cadastrado com sucesso!!\n");

                }
            else{ //caso contrario o usuario nao podera preencher os dados, pois esse ISBN ja existe
                system("cls");
                printf("\nImpossivel cadastrar esse livro, ja existe um livro com esse ISBN no acervo\n");
                contadorLivros--;
            }
        break;

        case 2:
            printf("Entre com o ISBN do livro: ");
            fflush(stdin);
            gets(ISBN);

            for(i=0; i<contadorLivros+1; i++){
                if(strcmp(ISBN, livros[i].ISBN)==0){ //função para comparar strings e caso sejam iguais entra na condição
                    system("cls");
                    printf("\nTitulo: %s", livros[i].titulo);
                    printf("\nAutor: %s", livros[i].autor);
                    printf("\nCategoria: %s", livros[i].categoria);
                    printf("\nISBN: %s", livros[i].ISBN);
                    printf("\nQuantidade de paginas: %d\n\n", livros[i].qtd_paginas);
                    teste++; //acrescentando 1 a variavel para verificar se existe o ISBN  na lista
                }
            }
            if(teste==0){ //caso nao houver o usuario sera informado, pois o teste termina nulo
                system("cls");
                printf("\nISBN nao encontrada no acervo\n");
            }
            teste=0; //voltando para o valor original para novas pesquisas
        break;

        case 3:
            printf("Entre com o nome do autor do Livro: ");
            fflush(stdin);
            gets(autor);

            system("cls");
            printf("\nEstes sao os livros escritos por %s:\n ", autor);
            for(i=0; i<contadorLivros+1; i++){
                if(strcmp(autor, livros[i].autor)==0){ //funçao para comparar strings e caso sejam iguais entra na condiçao
                    printf("\nTitulo: %s", livros[i].titulo);
                    printf("\nCategoria: %s", livros[i].categoria);
                    printf("\nISBN: %s", livros[i].ISBN);
                    printf("\nQuantidade de paginas: %d\n\n", livros[i].qtd_paginas);
                    teste++; //acrescentando 1 a variavel para verificar se existe livros do autor  na lista
                }
            }
            if(teste==0){ //caso nao houver o usuario sera informado, pois o teste termina nulo
                printf("\nNenhum livro escrito por esse autor foi encontrado no acervo\n");
            }
            teste=0; //voltando para o valor original para novas pesquisas
        break;

        case 4:
            printf("Entre com o nome da categoria: ");
            fflush(stdin);
            gets(categoria);

            system("cls");
            printf("\nEstes sao os livros da categoria %s:\n ", categoria);
            for(i=0; i<contadorLivros+1; i++){
                if(strcmp(categoria, livros[i].categoria)==0){ //funcao para comparar strings e caso sejam iguais entra na condicao
                    printf("\nTitulo: %s", livros[i].titulo);
                    printf("\nAutor: %s", livros[i].autor);
                    printf("\nCategoria: %s", livros[i].categoria);
                    printf("\nISBN: %s", livros[i].ISBN);
                    printf("\nQuantidade de paginas: %d\n\n", livros[i].qtd_paginas);
                    teste++; //acrescentando 1 a variavel para verificar se existe livros da categoria  na lista
                }
            }
            if(teste==0){ //caso nao houver o usuario sera informado, pois o teste termina nulo
                system("cls");
                printf("\nNao existe nenhum livro dessa categoria no acervo\n");
            }
            teste=0; //voltando para o valor original para novas pesquisas
        break;

        case 5:
            system("cls");
            printf("Estes sao todos os livros presentes no acervo: \n");
            for(i=0; i<contadorLivros+1; i++){
                printf("\nTitulo: %s", livros[i].titulo);
                printf("\nAutor: %s", livros[i].autor);
                printf("\nCategoria: %s", livros[i].categoria);
                printf("\nISBN: %s", livros[i].ISBN);
                printf("\nQuantidade de paginas: %d\n\n", livros[i].qtd_paginas);
            }
        break;

        case 6:
            system("cls");
            printf("\nVoce optou por encerrar o programa\n");
            exit(0);
        break;
        default:
            system("cls");
            printf("Error\n");
            printf("Tente novamente.\n");
            main();
            break;
        }
    }
}
