#include <stdio.h>

void clearscreen() {
    printf("\033[2J");
    printf("\033[H");
}

void menu_jogar() {
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
            case 3: menu();
                break;

        }
    } while (opcao != 3);
}

void records() {
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
            case 6: menu();
                break;

        }
    } while (opcao != 6);
}

void gestaodejogo() {
    int opcao;
    do {
        clearscreen();
        printf("    1- Adicionar Perguntas     \n");
        printf("    2- Remover Perguntas     \n");
        printf("    3- Editar Perguntas     \n");
        printf("    4- Visualizars Perguntas     \n");
        printf("    5- Pesquisar Perguntas     \n");
        printf("    6- Voltar  \n");
        do {
            scanf("%d", &opcao);
        } while (opcao < 0 || opcao > 6);
        switch (opcao) {
            case 1: printf("    1- Adicionar Perguntas     \n");;
                break;
            case 2: printf("    1- Adicionar Perguntas     \n");;
                break;
            case 3: printf("    1- Adicionar Perguntas     \n");;
                break;
            case 4: printf("    1- Adicionar Perguntas     \n");;
                break;
            case 5: printf("    1- Adicionar Perguntas     \n");;
                break;
            case 6: menu();
                break;

        }
    } while (opcao != 6);

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

void menu() {
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
            case 1: menu_jogar();
                break;
            case 2: gestaodejogo();
                break;
            case 3: puts("Ola");
                break;
            case 4: ficheiros();
                break;

        }
    } while (opcao != 4);
}
