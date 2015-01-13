/* 
 * File:   main.c
 * Author: ivo
 *
 * Created on 16 de Outubro de 2014, 10:32
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataManagement.h"

/*
 * 
 */
#define SHORT_STRING 28
#define MEDIUM_STRING 80
#define LONG_STRING 260 

/*------------------------------------------------------------*/
typedef struct {
    unsigned int id_categoria;
    char categoria[SHORT_STRING];
    unsigned int pontuacao_categoria;

} Categoria;

typedef struct {
    unsigned int id_pergunta;
    unsigned int id_categoria;
    unsigned int id_dificuldade;
    unsigned int id_resposta_certa;
    char pergunta[LONG_STRING];
} Pergunta;

enum CamposPergunta {
    ID_PERGUNTA,
    ID_CATEGORIA,
    ID_DIFICULDADE,
    ID_RESPOSTA_CERTA,
    PERGUNTA
};

typedef struct {
    unsigned int id_resposta;
    unsigned int id_pergunta;
    char resposta[LONG_STRING];
} Resposta;

typedef struct {
    unsigned int id_jogo;
    unsigned int id_utilizador;
} Jogo;

typedef struct {
    unsigned int id_jogada;
    unsigned int id_utilizador;
    unsigned int id_jogo;
    unsigned int tempo;
    unsigned int id_pergunta;
    unsigned int id_resposta;
    unsigned int pontuacao;
} Jogadas;

/*---------------------------------------------------------------------*/
typedef struct {
    unsigned int id_tipo_resposta;
    char tipo_resposta[SHORT_STRING];
    unsigned int id_resposta;
} TipoResposta;

/*---------------------------------------------------------------------*/
typedef struct {
    unsigned int id_utilizador;
    unsigned int id_tipo_utilizador;
    char nome[MEDIUM_STRING];
    char password[SHORT_STRING];
} Utilizador;

typedef struct {
    unsigned int id_utilizador;
    char tipo_utilizador;
} TipoUtilizador;

typedef struct {
    unsigned int id_ajuda;
    char ajuda[MEDIUM_STRING];
} Ajudas;

typedef struct {
    unsigned int id_dificuldade;
    char dificuldade[SHORT_STRING];
    unsigned int pontuacao;
} Dificuldade;

/*------------------------------------------------------------*/


int main(int argc, char** argv) {

 
    
   

    
    int contador = 2;


    FieldAux estructAuxPerguntas[] = {
        {.fieldName = "id_pergunta", .alias = "Numero Pergunta", .sizeBytes = INT_SIZE, .type = INT, .unique = true, .required = true, .autoIncrement = true, .step = 1},
        {.fieldName = "id_categoria", .alias = "Numero Categoria", .sizeBytes = INT_SIZE, .type = INT, .required = true},
        {.fieldName = "id_dificuldade", .alias = "Numero Dificuldade", .sizeBytes = INT_SIZE, .type = INT, .required = true},
        {.fieldName = "id_resposta_certa", .alias = "Numero Resposta Certa", .sizeBytes = INT_SIZE, .type = INT, .required = true},
        {.fieldName = "pergunta", .alias = "Pergunta", .sizeBytes = LONG_STRING, .type = STRING, .required = true}

    };

    Pergunta perguntas[5] = {
        {.id_pergunta = 1, .id_categoria = 1, .id_dificuldade = 1, .id_resposta_certa = 1, .pergunta = "Qual é o resultado de 1+1?"},
        {.id_pergunta = 2, .id_categoria = 1, .id_dificuldade = 1, .id_resposta_certa = 1, .pergunta = "Como se chama a musa do Fabão?"}
    };

    ////////////////////////


    crud CRUD;
    CRUD.create = &create;
    CRUD.update = &update;
    CRUD.delete = &delete;
    CRUD.list.fullList = &fullList;
    CRUD.list.parsedList = &parsedList;
    CRUD.read.fullRead = &fullRead;
    CRUD.read.parsedRead = &parsedRead;


    int x[] = {2, 3, 4};
    int y[] = {PERGUNTA};
    /////////////////////////////////  TESTES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

    /* 
    parsedRead(CREATE,sizeof (Pergunta),perguntas,estructAuxPerguntas, x, 3, y, 1);
    fullRead(CREATE, sizeof (Pergunta), perguntas,contador, estructAuxPerguntas, 5);
    parsedList(perguntas, sizeof (Pergunta), estructAuxPerguntas, x, 3, y, 1);
    
    int * storage;
    getAtributeValue(&perguntas[1],estructAuxPerguntas, 1, &storage);
     * 
    CRUD.create(sizeof(Pergunta),perguntas, &contador,estructAuxPerguntas,5);

    fullList(perguntas, sizeof (Pergunta), 3, estructAuxPerguntas, 5);
 
    printInt(&contador);
     * 
     *  int *p;
   int i;
   int *j;
   j=1;

   p = search(ID_CATEGORIA, &j, perguntas, estructAuxPerguntas, 2, sizeof (Pergunta));

   for ( i = 0; i < 10; i++ )
   {
       printf( "%d \n",*(p + i));
   }
     */

   
    char ola[10];
    strcpy(ola,"ola");
    char ole[10];
    strcpy(ole,"ole");
    
    //printf("%d",strcmp(ola,ole));
    ////////////////////////
    printf("%d",compare(STRING,ola,STRING,ole));
    //printf("%d",compare(STRING,ola,STRING,ole));

   return 0;
   



    return (EXIT_SUCCESS);
}


