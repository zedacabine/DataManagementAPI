//#include "DataManagement.h"
#include "Jogo.h"
#include "Dificuldade.h"
#include <string.h>

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

    Class *dificuldadeClass;
    dificuldadeClass = arrayClass[3];
    
    Class *jogoClass;
    jogoClass = arrayClass[6];

    int id_local_user = 2;

    //listarJogos(jogoClass);
    Jogo *jogos;
    jogos = jogoClass->data;
    jogos;
    //------------------------------------Criar Jogo------------------------------//
    jogos[*(jogoClass->elements)].id_jogo = *(jogoClass->elements) + 1;
    jogos[*(jogoClass->elements)].id_utilizador = id_local_user;
    *(jogoClass->elements) = *(jogoClass->elements) + 1;

    Dificuldade *dificuldades;
    dificuldades = dificuldadeClass->data;
    dificuldades;
    
    
    
    listarDificuldades();



    printf("Tamanho do array -> %d", *(jogoClass->elements));


    char NomeFicheiro[SHORT_STRING];
    strcpy(NomeFicheiro, "jogos.txt");
    writeFile(NomeFicheiro, jogoClass);

    listarJogos(jogoClass);


    //inserirJogo(jogoClass);


    //char NomeFicheiro[SHORT_STRING];
    //strcpy(NomeFicheiro, "jogos.txt");
    //writeFile(NomeFicheiro, jogoClass);



    puts("                       Modo Normal                               \n");
    puts("                                                                 \n");
    puts("                                                                 \n");

    voltar();


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