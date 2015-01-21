//#include "DataManagement.h"
#include "Jogo.h"
#include "Dificuldade.h"
#include "Pergunta.h"
#include "Resposta.h"
#include <string.h>
#include <time.h>
#include "Categoria.h"
#include "Jogadas.h"
#include <unistd.h>

void inserirJogo(Class *jogoClass) {

    create(jogoClass->StructTypeSize, jogoClass->data, jogoClass->elements, jogoClass->auxStruct, jogoClass->fieldsNumber);
    char NomeFicheiro[SHORT_STRING];
    strcpy(NomeFicheiro, "jogos.txt");
    writeFile(NomeFicheiro, jogoClass);
}

void listarJogos(Class *jogoClass) {

    fullList(jogoClass->data, jogoClass->StructTypeSize, (*jogoClass->elements), jogoClass->auxStruct, jogoClass->fieldsNumber);

}

void listarJogo(Class jogoClass, const unsigned int chave) {

    singleList(jogoClass, chave);
}

void filtrarJogos(Class jogoClass, int *chaves, int numeroChaves, int *campos, int numeroCampos) {

    parsedList(jogoClass.data, jogoClass.StructTypeSize, jogoClass.auxStruct, chaves, numeroChaves, campos, numeroCampos);
}

void filtrarJogo(Class jogoClass, int chave, int *campos, int numeroCampos) {

    singleParsedList(jogoClass, chave, campos, numeroCampos);
}

void pesquisarJogos(Class jogoClass, const unsigned int campo, void *valorPesquisar, unsigned int *numeroResultados, char *sinal) {
    FieldAux *aux = jogoClass.auxStruct;
    aux[campo].type;
    search(campo, valorPesquisar, jogoClass.data, jogoClass.auxStruct, (*jogoClass.elements), jogoClass.StructTypeSize, aux[campo].type, numeroResultados, sinal);

}

void modoNormal(void **arrayClass) {
    int id_local_user = 2;


    Class *perguntaClass;
    perguntaClass = arrayClass[0];

    Class *categoriaClass;
    categoriaClass = arrayClass[1];

    Class *respostaClass;
    respostaClass = arrayClass[2];

    Class *dificuldadeClass;
    dificuldadeClass = arrayClass[3];

    Class *jogadaClass;
    jogadaClass = arrayClass[5];

    Class *jogoClass;
    jogoClass = arrayClass[6];

    Pergunta *perguntas;
    perguntas = perguntaClass->data;
    perguntas;

    Jogo *jogos;
    jogos = jogoClass->data;
    jogos;

    Dificuldade *dificuldades;
    dificuldades = dificuldadeClass->data;
    dificuldades;

    Resposta *respostas;
    respostas = respostaClass->data;
    respostas;

    Categoria *categorias;
    categorias = categoriaClass->data;
    categorias;

    Jogada *jogadas;
    jogadas = jogadaClass->data;
    jogadas;


    //------------------------------------Criar Jogo------------------------------//
    jogos[*(jogoClass->elements)].id_jogo = *(jogoClass->elements) + 1;
    jogos[*(jogoClass->elements)].id_utilizador = id_local_user;
    *(jogoClass->elements) = *(jogoClass->elements) + 1;

    int camposEditarPergunta[] = {PERGUNTA};
    int valor = 1;
    int numeroResultados;
    char sinal[2 + 1];
    strcpy(sinal, "==");
    int * resultPesquisa;
    resultPesquisa = pesquisarPerguntas(perguntaClass, ID_DIFICULDADE_PERGUNTAS, &valor, &numeroResultados, sinal);
    //filtrarPerguntas(perguntaClass,resultPesquisa,numeroResultados,camposEditarPergunta,2);
    int *res_rand = 0;
    res_rand = randomize(resultPesquisa, 6, numeroResultados);
    unsigned int r = 0;
    clearscreen();

 
    //------------------------------------------------iniciar Perguntas ------------------------------//
    for (r = 0; r < 6 - 1; r++) {
          
        
        
        filtrarPergunta(perguntaClass, *(res_rand + r), camposEditarPergunta, 1);
        int camposEditarRespostas[] = {RESPOSTA};
        int valorResposta = (*(res_rand + r)) + 1;
        int unsigned numeroResultadosRespostas;
        char sinalRespostas[2 + 1];
        strcpy(sinalRespostas, "==");
        int * resultPesquisaResposta;

        resultPesquisaResposta = pesquisarRespostas(respostaClass, ID_PERGUNTA_RESPOSTA, &valorResposta, &numeroResultadosRespostas, sinalRespostas);
        unsigned int u;

//------------------------------------------------iniciar respostas----------------------------//
        for (u = 0; u < numeroResultadosRespostas; u++) {
            printf("%d: ", respostas[(*(resultPesquisaResposta + u))].id_resposta);
            filtrarResposta(respostaClass, (*(resultPesquisaResposta + u)), camposEditarRespostas, 1);
        }

        time_t inicio;
        time(&inicio);
        puts("Insira uma opcao: ");
        int solucao = 0;
        readInt(&solucao);

        time_t fim;
        time(&fim);
        unsigned int diferencaTempo;
        diferencaTempo = difftime(fim, inicio);
        int camposEditarSolucao[] = {ID_RESPOSTA_CERTA_PERGUNTAS};
        int valorSolucao = solucao;
        int unsigned numeroResultadosSolucao;
        char sinalSolucao[2 + 1];
        strcpy(sinalSolucao, "==");
        int * resultPesquisaSolucao;

        jogadas[*(jogadaClass->elements)].id_jogada = *(jogadaClass->elements) + 1;
        jogadas[*(jogadaClass->elements)].id_utilizador = id_local_user;
        jogadas[*(jogadaClass->elements)].id_jogo = *(jogoClass->elements);
        jogadas[*(jogadaClass->elements)].tempo = diferencaTempo;
        jogadas[*(jogadaClass->elements)].id_resposta = solucao;
        jogadas[*(jogadaClass->elements)].id_pergunta = valorResposta;



        pesquisarPerguntas(perguntaClass, ID_RESPOSTA_CERTA_PERGUNTAS, &valorSolucao, &numeroResultadosSolucao, sinalSolucao);

        if (numeroResultadosSolucao == 0) {
            jogadas[*(jogadaClass->elements)].pontuacao = 0;
            *(jogadaClass->elements) = *(jogadaClass->elements) + 1;
            puts("Resposta Errada Perdeste");
            usleep(1000000);
            menu_admin(arrayClass);
        }
        if (numeroResultadosSolucao == 1) {
            jogadas[*(jogadaClass->elements)].pontuacao = (dificuldades[valor].pontuacao_dificuldade + categorias[perguntas[(*(res_rand + r))].id_categoria].pontuacao_categoria)-(diferencaTempo);
            puts("Resposta Correcta");
            printf("%d", (*(res_rand + r)));
            printf("Ganhou: %d pontos", jogadas[(*(jogadaClass->elements))].pontuacao);
            *(jogadaClass->elements) = *(jogadaClass->elements) + 1;

            usleep(1000000);
        }


        char NomeFicheiro[SHORT_STRING];
        strcpy(NomeFicheiro, "jogadas.txt");
        writeFile(NomeFicheiro, jogadaClass);
        getchar();

        //listarPergunta(perguntaClass, *(res_rand+r));
    }
    char NomeFicheiro[SHORT_STRING];
    strcpy(NomeFicheiro, "jogos.txt");
    writeFile(NomeFicheiro, jogoClass);

    //printf("Tamanho do array -> %d", *(jogoClass->elements));
    //char NomeFicheiro[SHORT_STRING];
    //strcpy(NomeFicheiro, "jogos.txt");
    //writeFile(NomeFicheiro, jogoClass);

    //inserirJogo(jogoClass);
}

void modoDificuldade() {
    clearscreen();

    puts("                       Modo Por Dificuldade                      \n");
    puts("                                                                 \n");
    puts("                                                                 \n");

    voltar();
}

/*
void get_random_difficulty_questions(Questions *question, const unsigned short int *OP) {
    const unsigned short int TAM_QUESTION_ADD = 30;
    unsigned short int QUESTION_NUMBER_LIMIT = 10;
    unsigned short int i, j = 0, count_questions = 0, random, temp, count, count_correct = 0;
    read_file_questions(question, &count_questions, TAM_QUESTION_ADD);
    unsigned short int easy_questions[count_questions],
            medium_questions[count_questions],
            hard_questions[count_questions];

    for (i = 0; i < count_questions; i++) {
        if (question[i].difficulty == 0 && *OP == 1) {
            easy_questions[j] = question[i].id;
            j++;
        }
        if (question[i].difficulty == 1 && *OP == 2) {
            medium_questions[j] = question[i].id;
            j++;
        }
        if (question[i].difficulty == 2 && *OP == 3) {
            hard_questions[j] = question[i].id;
            j++;
        }
    }

    //srand(time(0));
    for (i = 0; i < j; i++) {
        if (*OP == 1) {
            // printf("ID Easy: %u\n", easy_questions[i]);
            random = rand() % j;
            temp = easy_questions[i];
            easy_questions[i] = easy_questions[random];
            easy_questions[random] = temp;
        }
        if (*OP == 2) {
            // printf("ID Medium: %u\n", medium_questions[i]);
            random = rand() % j;
            temp = medium_questions[i];
            medium_questions[i] = medium_questions[random];
            medium_questions[random] = temp;
        }
        if (*OP == 3) {
            // printf("ID Hard: %u\n", hard_questions[i]);
            random = rand() % j;
            temp = hard_questions[i];
            hard_questions[i] = hard_questions[random];
            hard_questions[random] = temp;
        }
    }
    if (*OP == 1) {
        next_question_game(question, easy_questions, &count, OP, &count_correct, &QUESTION_NUMBER_LIMIT);
    }
    if (*OP == 2) {
        next_question_game(question, medium_questions, &count, OP, &count_correct, &QUESTION_NUMBER_LIMIT);
    }
    if (*OP == 3) {
        next_question_game(question, hard_questions, &count, OP, &count_correct, &QUESTION_NUMBER_LIMIT);
    }
}
 * */