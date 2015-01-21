#include <stdio.h>
#include "Pergunta.h"
#include <string.h>
#include "Utilizador.h"

void voltar() {
    char s[1];
    puts("Prima [ENTER] para voltar");
    readChar(s);
}

void clearscreen() {
    printf("\033[2J");
    printf("\033[H");
}

void menuJogar(void ** arrayClass) {
    int opcao;
    do {
        clearscreen();
        printf("                        Modos de Jogo                            \n");
        printf("                                                                 \n");
        printf("                                                                 \n");
        printf("                        1- Modo Normal                           \n");
        printf("                        2- Modo Por Dificuldade                  \n");
        printf("                        3- Voltar                                \n");

        do {
            scanf("%d", &opcao);
        } while (opcao < 0 || opcao > 3);
      
        switch (opcao) {
            case 1:
                modoNormal(arrayClass);
                break;
            case 2: printf("    Por dificuldade");
                break;
            case 3: menu_admin(arrayClass);
                break;
        }
    } while (opcao != 3);
}

void menuPontuacoes(void **arrayClass) {
    int opcao;
    do {
        clearscreen();
        printf("                        Pontuações                                                  \n");
        printf("                                                                                    \n");
        printf("                                                                                    \n");
        printf("                        1- Recordes Ano/mes                                         \n");
        printf("                        2- Recordes Máximos por Jogador                             \n");
        printf("                        3- Recordes Máximas do Mês                                  \n");
        printf("                        4- Total de Jogos realizados N dia                          \n");
        printf("                        5- Categoria de perguntas com mais respostas correctas      \n");
        printf("                        6- Voltar                                                   \n");
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
            case 6: menu_admin(arrayClass);
                break;

        }
    } while (opcao != 6);
}

void gestaoPerguntas(void **arrayClass) {
    int opcao;
    do {

        clearscreen();
        printf("                        Perguntas                           \n");
        printf("                                                            \n");
        printf("                                                            \n");
        printf("                        1- Adicionar Perguntas              \n");
        printf("                        2- Remover Perguntas                \n");
        printf("                        3- Editar Perguntas                 \n");
        printf("                        4- Visualizar Perguntas             \n");
        printf("                        5- Pesquisar Perguntas              \n");
        printf("                        6- Voltar                           \n");
        do {
            scanf("%d", &opcao);
        } while (opcao < 0 || opcao > 6);
        
        switch (opcao) {
            case 1: inserirPergunta(arrayClass);
                break;
            case 2: printf("    1- Adicionar Perguntas     \n");
                break;
            case 3: listar_editar_perguntas(arrayClass);
                break;
            case 4: listarPerguntas(arrayClass);
                voltar();
                break;
            case 5: printf("    1- Adicionar Perguntas     \n");
                break;
            case 6: menuGestao(arrayClass);
                break;

        }
    } while (opcao != 6);

}

void gestaoCategorias(void **arrayClass) {
    int opcao;
    do {
        clearscreen();
        printf("                        Categorias                          \n");
        printf("                                                            \n");
        printf("                                                            \n");
        printf("                        1- Adicionar categorias             \n");
        printf("                        2- Remover categorias               \n");
        printf("                        3- Editar categorias                \n");
        printf("                        4- Visualizar categorias            \n");
        printf("                        5- Pesquisar categorias             \n");
        printf("                        6- Voltar                           \n");
        do {
            scanf("%d", &opcao);
        } while (opcao < 0 || opcao > 6);
        switch (opcao) {
             case 1: inserirCategoria(arrayClass);
                break;
            case 2: printf("    1- Adicionar Perguntas     \n");
                break;
            case 3: listar_editar_categorias(arrayClass);
                break;
            case 4: listarCategoria(arrayClass);
                voltar();
                break;
            case 5: printf("    1- Adicionar Perguntas     \n");
                break;
            case 6: menuGestao(arrayClass);
                break;

        }
    } while (opcao != 6);

}

void gestaoRespostas(void **arrayClass) {
    int opcao;
    do {
        clearscreen();
        printf("                        Respostas                           \n");
        printf("                                                            \n");
        printf("                                                            \n");
        printf("                        1- Adicionar respostas              \n");
        printf("                        2- Remover respostas                \n");
        printf("                        3- Editar respostas                 \n");
        printf("                        4- Visualizar respostas             \n");
        printf("                        5- Pesquisar respostas              \n");
        printf("                        6- Voltar                           \n");
        do {
            scanf("%d", &opcao);
        } while (opcao < 0 || opcao > 6);
        switch (opcao) {
             case 1: inserirResposta(arrayClass);
                break;
            case 2: printf("    1- Adicionar Perguntas     \n");
                break;
            case 3: listar_editar_respostas(arrayClass);
                break;
            case 4: listarResposta(arrayClass);
                voltar();
                break;
            case 5: printf("    1- Adicionar Perguntas     \n");
                break;
            case 6: menuGestao(arrayClass);
                break;

        }
    } while (opcao != 6);

}

void gestaoTipoRespostas(void **arrayClass) {
    int opcao;
    do {
        clearscreen();
        printf("                        Tipo Utilizadores                   \n");
        printf("                                                            \n");
        printf("                                                            \n");
        printf("                        1- Adicionar Tipo Resposta          \n");
        printf("                        2- Remover Resposta                 \n");
        printf("                        3- Editar Resposta                  \n");
        printf("                        4- Visualizar Resposta             \n");
        printf("                        5- Pesquisar Resposta              \n");
        printf("                        6- Voltar                           \n");
        do {
            scanf("%d", &opcao);
        } while (opcao < 0 || opcao > 6);
        switch (opcao) {
             case 1: inserirTipoResposta(arrayClass);
                break;
            case 2: printf("    1- Adicionar Perguntas     \n");
                break;
            case 3: listar_editar_tipoTipoRespostas(arrayClass);
                break;
            case 4: listarTipoResposta(arrayClass);
                break;
            case 5: printf("    1- Adicionar Perguntas     \n");
                break;
            case 6: menuGestao(arrayClass);
                break;

        }
    } while (opcao != 6);

}

void gestaoUtilizadores(void **arrayClass) {
    int opcao;
    do {
        clearscreen();
        printf("                        Utilizadores                        \n");
        printf("                                                            \n");
        printf("                                                            \n");
        printf("                        1- Adicionar utilizador    \n");
        printf("                        2- Remover utilizador    \n");
        printf("                        3- Editar utilizador    \n");
        printf("                        4- Visualizar utilizador     \n");
        printf("                        5- Pesquisar utilizador    \n");
        printf("                        6- Voltar  \n");
        do {
            scanf("%d", &opcao);
        } while (opcao < 0 || opcao > 6);
        switch (opcao) {
            case 1: inserirUtilizador(arrayClass);
                break;
            case 2: printf("    1- Adicionar Perguntas     \n");
                break;
            case 3: listar_editar_utilizadores(arrayClass);
                break;
            case 4: listarUtilizadores(arrayClass);
                voltar();
                break;
            case 5: printf("    1- Adicionar Perguntas     \n");
                break;
            case 6: menuGestao(arrayClass);
                break;
        }
    } while (opcao != 6);

}

void gestaoTipoUtilizadores(void **arrayClass) {
    int opcao;
    do {
        clearscreen();
        printf("                        Tipo Utilizadores                        \n");
        printf("                                                            \n");
        printf("                                                            \n");
        printf("                        1- Adicionar Tipo Utilizador    \n");
        printf("                        2- Remover  Tipo Utilizador    \n");
        printf("                        3- Editar Tipo Utilizador    \n");
        printf("                        4- Visualizar Tipo Utilizador     \n");
        printf("                        5- Pesquisar Tipo Utilizador    \n");
        printf("                        6- Voltar  \n");
        do {
            scanf("%d", &opcao);
        } while (opcao < 0 || opcao > 6);
        switch (opcao) {
             case 1: inserirTipoUtilizador(arrayClass);
                break;
            case 2: printf("    1- Adicionar Perguntas     \n");
                break;
            case 3: listar_editar_tipoTipoUtilizadores(arrayClass);
                break;
            case 4: listarTipoUtilizadores(arrayClass);
                voltar();
                break;
            case 5: printf("    1- Adicionar Perguntas     \n");
                break;
            case 6: menuGestao(arrayClass);
                break;
        }
    } while (opcao != 6);
}

void gestaoAjudas(void **arrayClass) {
    int opcao;
    do {
        clearscreen();
        printf("                        Ajudas                       \n");
        printf("                                                            \n");
        printf("                                                            \n");
        printf("                        1- Adicionar Ajuda   \n");
        printf("                        2- Remover  Ajuda    \n");
        printf("                        3- Editar Ajuda    \n");
        printf("                        4- Visualizar Ajuda     \n");
        printf("                        5- Pesquisar Ajuda    \n");
        printf("                        6- Voltar  \n");
        do {
            scanf("%d", &opcao);
        } while (opcao < 0 || opcao > 6);
        switch (opcao) {
             case 1: inserirAjuda(arrayClass);
                break;
            case 2: printf("    1- Adicionar Perguntas     \n");
                break;
            case 3: listar_editar_ajudas(arrayClass);
                break;
            case 4: listarAjuda(arrayClass);
                voltar();
                break;
            case 5: printf("    1- Adicionar Perguntas     \n");
                break;
            case 6: menuGestao(arrayClass);
                break;
        }
    } while (opcao != 6);
}

void gestaoDificuldades(void **arrayClass) {
    int opcao;
    do {
        clearscreen();
        printf("                        Dificuldades                      \n");
        printf("                                                            \n");
        printf("                                                            \n");
        printf("                        1- Adicionar Dificuldade   \n");
        printf("                        2- Remover  Dificuldade    \n");
        printf("                        3- Editar Dificuldade    \n");
        printf("                        4- Visualizar Dificuldade   \n");
        printf("                        5- Pesquisar Dificuldade    \n");
        printf("                        6- Voltar  \n");
        do {
            scanf("%d", &opcao);
        } while (opcao < 0 || opcao > 6);
        switch (opcao) {
             case 1: inserirDificuldade(arrayClass);
                break;
            case 2: printf("    1- Adicionar Perguntas     \n");
                break;
            case 3: listar_editar_dificuldades(arrayClass);
                break;
            case 4: listarDificuldades(arrayClass);
                voltar();
                break;
            case 5: printf("    1- Adicionar Perguntas     \n");
                break;
            case 6: menuGestao(arrayClass);
                break;
        }
    } while (opcao != 6);
}

void gestaoJogadas(void **arrayClass) {
    int opcao;
    do {
        clearscreen();
        printf("                        Jogadas                      \n");
        printf("                                                            \n");
        printf("                                                            \n");
        printf("                        1- Adicionar Jogada   \n");
        printf("                        2- Remover jogada    \n");
        printf("                        3- Editar Jogada    \n");
        printf("                        4- Visualizar Jogada  \n");
        printf("                        5- Pesquisar jogada    \n");
        printf("                        6- Voltar  \n");
        do {
            scanf("%d", &opcao);
        } while (opcao < 0 || opcao > 6);
        switch (opcao) {
             case 1: inserirJogada(arrayClass);
                break;
            case 2: printf("    1- Adicionar Perguntas     \n");
                break;
            case 3: listar_editar_jogadas(arrayClass);
                break;
            case 4: listarJogadas(arrayClass);
                break;
            case 5: printf("    1- Adicionar Perguntas     \n");
                break;
            case 6: menuGestao(arrayClass);
                break;
        }
    } while (opcao != 6);
}

void gestaoJogo(void **arrayClass) {
    int opcao;
    do {
        clearscreen();
        printf("                        Jogo                     \n");
        printf("                                                            \n");
        printf("                                                            \n");
        printf("                        1- Adicionar Jogo   \n");
        printf("                        2- Remover Jogo    \n");
        printf("                        3- Editar Jogo   \n");
        printf("                        4- Visualizar Jogo  \n");
        printf("                        5- Pesquisar Jogo   \n");
        printf("                        6- Voltar  \n");
        do {
            scanf("%d", &opcao);
        } while (opcao < 0 || opcao > 6);
        switch (opcao) {
            case 1: inserirJogo(arrayClass);
                break;
            case 2: printf("    1- Adicionar Perguntas     \n");
                break;
            case 3:;
                break;
            case 4: listarJogo(arrayClass);
                break;
                break;
            case 5: printf("    1- Adicionar Perguntas     \n");
                break;
            case 6: menuGestao(arrayClass);
                break;
        }
    } while (opcao != 6);
}

void menuGestao(void **arrayClass) {
    int opcao;
    do {
        clearscreen();
        printf("                        Gestão                              \n");
        printf("                                                            \n");
        printf("                                                            \n");
        printf("                        1- Perguntas                        \n");
        printf("                        2- Categorias                       \n");
        printf("                        3- Respostas                        \n");
        printf("                        4- Tipo Respostas                   \n");
        printf("                        5- Utilizadores                     \n");
        printf("                        6- Tipos Utilizador                 \n");
        printf("                        7- Ajudas                           \n");
        printf("                        8- Dificuldades                     \n");
        printf("                        9- Jogadas                          \n");
        printf("                        10- Jogo                            \n");
        printf("                        11- Voltar                          \n");
        printf("                                                            \n");
        printf("                                                            \n");
        do {
            scanf("%d", &opcao);
        } while (opcao < 0 || opcao > 11);
        
        Class *perguntaClass;
        perguntaClass = arrayClass[0];
        Class *categoriaClass;
        categoriaClass = arrayClass[1];
        Class *respostaClass;
        respostaClass = arrayClass[2];
        Class *dificuldadeClass;
        dificuldadeClass = arrayClass[3];
        Class *ajudaClass;
        ajudaClass = arrayClass[4];
        Class *jogadaClass;
        jogadaClass = arrayClass[5];
        Class *jogoClass;
        jogoClass = arrayClass[6];
        Class *tipoUtilizadorClass;
        tipoUtilizadorClass = arrayClass[7];
        Class *tipoRespostaClass;
        tipoRespostaClass = arrayClass[8];
        Class *utilizadorClass;
        utilizadorClass = arrayClass[9];
        
        
        switch (opcao) {
            case 1: gestaoPerguntas(perguntaClass);
                break;
            case 2: gestaoCategorias(categoriaClass);
                break;
            case 3: gestaoRespostas(respostaClass);
                break;
            case 4: gestaoTipoRespostas(tipoRespostaClass);
                break;
            case 5: gestaoUtilizadores(utilizadorClass);
                break;
            case 6: gestaoTipoUtilizadores(tipoUtilizadorClass);
                break;
            case 7: gestaoAjudas(ajudaClass);
                break;
            case 8: gestaoDificuldades(dificuldadeClass);
                break;
           case 9: gestaoJogadas(jogadaClass);
                break;
            case 10: gestaoJogo(jogoClass);
                break;
            case 11: menu_admin(arrayClass);
                break;
        }
    } while (opcao != 11);
}


void menu_admin(void **arrayClass) {
    int opcao;
    do {
        clearscreen();
        printf("                   QUEM QUER SER MILIONARIO                 \n");
        printf("                                                            \n");
        printf("                                                            \n");
        printf("                        1- Jogar                            \n");
        printf("                        2- Gestão de jogo                   \n");
        printf("                        3- Pontuações                       \n");
        printf("                        4- Sair                             \n");
        do {
            scanf("%d", &opcao);
        } while (opcao < 0 || opcao > 4);
        switch (opcao) {
            case 1: menuJogar(arrayClass);
                break;
            case 2: menuGestao(arrayClass);
                break;
            case 3: menuPontuacoes(arrayClass);
                break;
            case 4: return 0;
                break;
        }
    } while (opcao != 4);
}

/*
void login(Class *arrayClass, Class utilizadorClass) {
    char nome[20], password[20];

    puts("Login:");
    readString(nome, 20);
    puts("Password:");
    readString(password, 20);
}
 * */