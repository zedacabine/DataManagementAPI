#include <stdio.h>
#include "Pergunta.h"

void clearscreen() {
    printf("\033[2J");
    printf("\033[H");
}

void menuJogar(Class * arrayClass) {
    int opcao;
    do {
        clearscreen();
        printf("   1- Modo Normal       \n");
        printf("   2- Modo Por Dificuldade      \n");
        printf("   3- Voltar      \n");

        do {
            scanf("%d", &opcao);
        } while (opcao < 0 || opcao > 3);
        switch (opcao) {
            case 1: printf("    Este modo é o normal");
                break;
            case 2: printf("    Por dificuldade");
                break;
            case 3: menu(arrayClass);
                break;

        }
    } while (opcao != 3);
}

void records(Class arrayClass) {
    int opcao;
    do {
        clearscreen();
        printf("    1- Recordes Ano/mes     \n");
        printf("    2- Recordes Máximos por Jogador     \n");
        printf("    3- Recordes Máximas do Mês     \n");
        printf("    4- Total de Jogos realizados N dia    \n");
        printf("    5- Categoria de perguntas com mais respostas correctas    \n");
        printf("    6- Voltar  \n");
        do {
            scanf("%d", &opcao);
        } while (opcao < 0 || opcao > 6);
        switch (opcao) {
            case 1: printf("Adicionar Perguntas");
                break;
            case 2: printf("Remover Perguntas");
                break;
            case 3: printf("Editar Perguntas");
                break;
            case 4: printf("Visualizars Perguntas");
                break;
            case 5: printf("Pesquisar Perguntas");
                break;
            case 6: menu(arrayClass);
                break;

        }
    } while (opcao != 6);
}

void gestaoPerguntas(Class arrayClass) {
    int opcao;
    do {
        clearscreen();
        printf("    1- Adicionar Perguntas     \n");
        printf("    2- Remover Perguntas     \n");
        printf("    3- Editar Perguntas     \n");
        printf("    4- Visualizar Perguntas     \n");
        printf("    5- Pesquisar Perguntas     \n");
        printf("    6- Voltar  \n");
        do {
            scanf("%d", &opcao);
        } while (opcao < 0 || opcao > 6);
        switch (opcao) {
            case 1: inserirPergunta(arrayClass);
                break;
            case 2: printf("    1- Adicionar Perguntas     \n");
                break;
            case 3: printf("    1- Adicionar Perguntas     \n");
                break;
            case 4: listarPerguntas(arrayClass);
                break;
            case 5: printf("    1- Adicionar Perguntas     \n");
                break;
            case 6: menuGestao(arrayClass);
                break;

        }
    } while (opcao != 6);

}
void gestaoCategorias(Class arrayClass) {
    int opcao;
    do {
        clearscreen();
        printf("    1- Adicionar categorias     \n");
        printf("    2- Remover categorias    \n");
        printf("    3- Editar categorias    \n");
        printf("    4- Visualizar categorias     \n");
        printf("    5- Pesquisar categorias    \n");
        printf("    6- Voltar  \n");
        do {
            scanf("%d", &opcao);
        } while (opcao < 0 || opcao > 6);
        switch (opcao) {
            case 1: inserirCategoria(arrayClass);
                break;
            case 2: printf("    1- Adicionar Perguntas     \n");
                break;
            case 3: printf("    1- Adicionar Perguntas     \n");
                break;
            case 4: listarCategorias(arrayClass);
                break;
            case 5: printf("    1- Adicionar Perguntas     \n");
                break;
            case 6: menuGestao(arrayClass);
                break;

        }
    } while (opcao != 6);

}

void menuGestao(Class * arrayClass) {
    int opcao;
    do {
        clearscreen();
        printf("   1- Perguntas   \n");
        printf("   2- Categorias    \n");
        printf("   3- Voltar    \n");
       

        do {
            scanf("%d", &opcao);
        } while (opcao < 0 || opcao > 3);
        switch (opcao) {
            case 1: gestaoPerguntas(arrayClass[0]);
                break;
            case 2: gestaoCategorias(arrayClass[1]);
                break;
            case 3: menu(arrayClass);
                break;
            
        }
    } while (opcao != 3);
}

void ficheiros() {
    int opcao;
    do {
        clearscreen();
        printf("   1- Carregar Ficheiros       \n");
        printf("   2- Gravar Ficheiros      \n");
        printf("   3- Voltar       \n");

        do {
            scanf("%d", &opcao);
        } while (opcao < 0 || opcao > 3);
        switch (opcao) {
            case 1: printf("    Este modo é o normal");
                break;
            case 2: printf("    Por dificuldade");
                break;
            case 3: menu();
                break;

        }
    } while (opcao != 3);
}

void menu(Class * arrayClass) {
    int opcao;
    do {
        clearscreen();
        printf("   1- Jogar    \n");
        printf("   2- Gestão de jogo    \n");
        printf("   3- Pontuações    \n");
        printf("   4- Ficheiros     \n");

        do {
            scanf("%d", &opcao);
        } while (opcao < 0 || opcao > 4);
        switch (opcao) {
            case 1: menuJogar(arrayClass);
                break;
            case 2: menuGestao(arrayClass);
                break;
            case 3: puts("Ola");
                break;
            case 4: ficheiros();
                break;
        }
    } while (opcao != 4);
}