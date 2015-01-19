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
#include "Resposta.h"
#include "Categoria.h"
#include "Ajudas.h"
#include "Dificuldade.h"
#include "Jogadas.h"
#include "Jogo.h"
#include "Pergunta.h"
#include "TipoResposta.h"
#include "TipoUtilizador.h"
#include "Utilizador.h"

int main(int argc, char** argv) {

    //---------------------------------------------------------------------------------------------------------------//

    crud CRUD;
    CRUD.create = &create;
    CRUD.update = &update;
    CRUD.delete = &delete;
    CRUD.list.fullList = &fullList;
    CRUD.list.parsedList = &parsedList;
    CRUD.read.fullRead = &fullRead;
    CRUD.read.parsedRead = &parsedRead;

    //---------------------------------------------------------------------------------------------------------------//

    //menu();
    char NomeFicheiro[SHORT_STRING];

    unsigned int contador, contadorPerguntas, contadorCategorias;

    //---------------------------------------------------------------------------------------------------------------//

    FieldAux estructAuxCategorias[] = {
        {.fieldName = "id_categoria", .alias = "Numero Categoria", .sizeBytes = INT_SIZE, .type = INT, .unique = true, .required = true, .autoIncrement = true},
        {.fieldName = "categoria", .alias = "Categoria", .sizeBytes = LONG_STRING, .type = STRING, .required = true},
        {.fieldName = "pontuacao_categoria", .alias = "Pontuacao", .sizeBytes = INT_SIZE, .type = INT, .required = true}
    };

    Categoria categorias[20];
    const unsigned int tamAuxCategoria = (sizeof (estructAuxCategorias) / sizeof (estructAuxCategorias[0]));
    const unsigned int tamTipoCategoria = sizeof (Categoria);
    const unsigned int tamArrayCategoria = (sizeof (categorias) / sizeof (categorias[0]));

    strcpy(NomeFicheiro, "categorias.txt");
    readFile(NomeFicheiro, tamArrayCategoria, categorias, &contadorCategorias);

    Class categoriaClass = {.name = "Categoria", .StructTypeSize = tamTipoCategoria, .data = categorias, .auxStruct = estructAuxCategorias, .elements = &contadorCategorias, .fieldsNumber = tamAuxCategoria, .aliasField = CATEGORIA};

    //---------------------------------------------------------------------------------------------------------------//

    FieldAux estructAuxPerguntas[] = {
        {.fieldName = "id_pergunta", .alias = "Numero Pergunta", .sizeBytes = INT_SIZE, .type = INT, .unique = true, .required = true, .autoIncrement = true, .step = 1},
        {.fieldName = "id_categoria_pergunta", .alias = "Numero Categoria", .sizeBytes = INT_SIZE, .type = INT, .required = true, .foreignKey = true, .parentPrimaryKey = ID_CATEGORIA, .parentClass = &categoriaClass},
        {.fieldName = "id_dificuldade_pergunta", .alias = "Numero Dificuldade", .sizeBytes = INT_SIZE, .type = INT, .required = true},
        {.fieldName = "id_resposta_certa_pergunta", .alias = "Numero Resposta Certa", .sizeBytes = INT_SIZE, .type = INT, .required = true},
        {.fieldName = "pergunta", .alias = "Pergunta", .sizeBytes = LONG_STRING, .type = STRING, .required = true}

    };

    Pergunta perguntas[100];
    const unsigned int tamAuxPergunta = (sizeof (estructAuxPerguntas) / sizeof (estructAuxPerguntas[0]));
    const unsigned int tamTipoPergunta = sizeof (Pergunta);
    const unsigned int tamArrayPergunta = (sizeof (perguntas) / sizeof (perguntas[0]));

    strcpy(NomeFicheiro, "perguntas.txt");
    readFile(NomeFicheiro, tamArrayPergunta, perguntas, &contadorPerguntas);

    //---------------------------------------------------------------------------------------------------------------//

    FieldAux estructAuxAjudas[] = {
        {.fieldName = "id_ajuda", .alias = "Numero Ajuda", . sizeBytes = INT_SIZE, .type = INT, .unique = true},
        {.fieldName = "ajuda", .alias = "Ajuda", .sizeBytes = LONG_STRING, .type = STRING}
    };

    Ajuda ajudas[3];
    const unsigned int tamAuxAjuda = (sizeof (estructAuxAjudas) / sizeof (estructAuxAjudas[0]));
    const unsigned int tamTipoAjuda = sizeof (Ajuda);
    const unsigned int tamArrayAjuda = (sizeof (ajudas) / sizeof (estructAuxAjudas[0]));

    strcpy(NomeFicheiro, "ajudas.txt");
    readFile(NomeFicheiro, tamArrayAjuda, ajudas, &contador);

    //---------------------------------------------------------------------------------------------------------------//

    FieldAux estructAuxDificuldades[] = {
        {.fieldName = "id_dificuldade", .alias = "Numero Dificuldade", .sizeBytes = INT_SIZE, . type = INT, . unique = true},
        {.fieldName = "dificuldade", .alias = "Dificuldade", .sizeBytes = INT_SIZE, .type = STRING, . required = true},
        {.fieldName = "pontuacao_dificuldade", .alias = "Pontuacao", .sizeBytes = INT_SIZE, .type = INT, .required = true}
    };

    Dificuldade dificuldades[3];
    const unsigned int tamAuxDificuldade = (sizeof (estructAuxDificuldades) / sizeof (estructAuxDificuldades[0]));
    const unsigned int tamTipoDificuldade = sizeof (Dificuldade);
    const unsigned int tamArrayDificuldade = (sizeof (dificuldades) / sizeof (estructAuxDificuldades[0]));

    strcpy(NomeFicheiro, "dificuldades.txt");
    readFile(NomeFicheiro, tamArrayDificuldade, dificuldades, &contador);

    //---------------------------------------------------------------------------------------------------------------//

    FieldAux estructAuxJogadas[] = {
        {.fieldName = "id_jogada", .alias = "Numero Jogada", .sizeBytes = INT_SIZE, .type = INT, .unique = true},
        {.fieldName = "id_utilizador_jogadas", .alias = "Numero Utilizador Jogadas", .sizeBytes = INT_SIZE, .type = INT, .unique = true},
        {.fieldName = "id_jogo_jogadas", .alias = "Numero Jogo Jogadas", .sizeBytes = INT_SIZE, .type = INT, .unique = true},
        {.fieldName = "tempo", .alias = "Tempo", .sizeBytes = INT_SIZE, .type = INT, .unique = true},
        {.fieldName = "id_pergunta_jogadas", .alias = "Numero Pergunta Jogadas", .sizeBytes = INT_SIZE, .type = INT, .unique = true},
        {.fieldName = "id_resposta_jogadas", .alias = "Numero Resposta Jogadas", .sizeBytes = INT_SIZE, .type = INT, .unique = true},
        {.fieldName = "pontuacao", .alias = "Pontuacao", .sizeBytes = INT_SIZE, .type = INT, .unique = true},
    };

    Jogada jogadas[100];
    const unsigned int tamAuxJogada = (sizeof (estructAuxJogadas) / sizeof (estructAuxJogadas[0]));
    const unsigned int tamTipoJogada = sizeof (Jogada);
    const unsigned int tamArrayJogada = (sizeof (jogadas) / sizeof (estructAuxJogadas[0]));

    strcpy(NomeFicheiro, "jogadas.txt");
    readFile(NomeFicheiro, tamArrayJogada, jogadas, &contador);

    //---------------------------------------------------------------------------------------------------------------//


    FieldAux estructAuxJogos[] = {
        {.fieldName = "id_jogo", .alias = "Numero Jogo", .sizeBytes = INT_SIZE, .type = INT, .unique = true},
        {.fieldName = "id_utilizador_jogo", .alias = "Numero Utilizador Jogo", .sizeBytes = INT_SIZE, .type = INT, .unique = true}
    };

    Jogo jogos[100];
    const unsigned int tamAuxJogo = (sizeof (estructAuxJogos) / sizeof (estructAuxJogos[0]));
    const unsigned int tamTipoJogo = sizeof (Jogo);
    const unsigned int tamArrayJogo = (sizeof (jogos) / sizeof (estructAuxJogos[0]));

    strcpy(NomeFicheiro, "jogos.txt");
    readFile(NomeFicheiro, tamArrayJogo, jogos, &contador);

    //---------------------------------------------------------------------------------------------------------------//

    FieldAux estructAuxRespostas[] = {
        {.fieldName = "id_resposta", .alias = "Numero Resposta", .sizeBytes = INT_SIZE, .type = INT, .unique = true},
        {.fieldName = "id_pergunta_resposta", .alias = "Numero Pergunta Resposta", .sizeBytes = INT_SIZE, .type = INT, .unique = true},
        {.fieldName = "resposta", .alias = "Resposta", . sizeBytes = LONG_STRING, .type = STRING}
    };

    Resposta respostas[100];
    const unsigned int tamAuxResposta = (sizeof (estructAuxRespostas) / sizeof (estructAuxRespostas[0]));
    const unsigned int tamTipoResposta = sizeof (Resposta);
    const unsigned int tamArrayResposta = (sizeof (respostas) / sizeof (estructAuxRespostas[0]));

    strcpy(NomeFicheiro, "respostas.txt");
    readFile(NomeFicheiro, tamArrayResposta, respostas, &contador);

    //---------------------------------------------------------------------------------------------------------------//

    FieldAux estructAuxTipoRespostas[] = {
        {.fieldName = "id_tipo_resposta", .alias = "Numero Tipo Resposta", .sizeBytes = INT_SIZE, .type = INT, .unique = true},
        {.fieldName = "Tipo Resposta", .alias = "Tipo Resposta", .sizeBytes = LONG_STRING, .type = STRING},
        {.fieldName = "id_resposta_tipo_resposta", .alias = "Numero resposta", .sizeBytes = BOOL_SIZE, .type = BOOL, .unique = true}
    };

    TipoResposta tipoRespostas[100];
    const unsigned int tamAuxTipoResposta = (sizeof (estructAuxTipoRespostas) / sizeof (estructAuxTipoRespostas[0]));
    const unsigned int tamTipoTipoResposta = sizeof (TipoResposta);
    const unsigned int tamArrayTipoResposta = (sizeof (tipoRespostas) / sizeof (estructAuxTipoRespostas[0]));

    strcpy(NomeFicheiro, "tiporespostas.txt");
    readFile(NomeFicheiro, tamArrayTipoResposta, tipoRespostas, &contador);

    //---------------------------------------------------------------------------------------------------------------//

    FieldAux estructAuxTipoUtilizadores[] = {
        {.fieldName = "id_tipo_utilizador", .alias = "Numero Tipo Utilizador", .sizeBytes = INT_SIZE, .type = INT, .unique = true},
        {.fieldName = "tipo_utilizador", .alias = "Tipo Utilizador", .sizeBytes = BOOL_SIZE, .type = BOOL}
    };

    TipoUtilizador tipoUtilizadores[2];
    const unsigned int tamAuxTipoUtilizador = (sizeof (estructAuxTipoUtilizadores) / sizeof (estructAuxTipoUtilizadores[0]));
    const unsigned int tamTipoTipoUtilizador = sizeof (TipoUtilizador);
    const unsigned int tamArrayTipoUtilizador = (sizeof (tipoUtilizadores) / sizeof (estructAuxTipoUtilizadores[0]));

    strcpy(NomeFicheiro, "tipoutilizadores.txt");
    readFile(NomeFicheiro, tamArrayTipoUtilizador, tipoUtilizadores, &contador);

    //---------------------------------------------------------------------------------------------------------------//

    FieldAux estructAuxUtilizadores[] = {
        {.fieldName = "id_utilizador", .alias = "Numero Utilizador", .sizeBytes = INT_SIZE, .type = INT, .unique = true},
        {.fieldName = "id_tipo_utilizador_utilizador", .alias = "Numero tipo utilizador", .sizeBytes = INT_SIZE, .type = INT, .unique = true},
        {.fieldName = "nome", .alias = "Nome", . sizeBytes = LONG_STRING, .type = CHAR},
        {.fieldName = "password", .alias = "Password", . sizeBytes = LONG_STRING, .type = CHAR}
    };

    Utilizador utilizadores[20];
    const unsigned int tamAuxUtilizador = (sizeof (estructAuxUtilizadores) / sizeof (estructAuxUtilizadores[0]));
    const unsigned int tamTipoUtilizador = sizeof (Utilizador);
    const unsigned int tamArrayUtilizador = (sizeof (utilizadores) / sizeof (estructAuxUtilizadores[0]));

    strcpy(NomeFicheiro, "utilizador.txt");
    readFile(NomeFicheiro, tamArrayUtilizador, utilizadores, &contador);

    //---------------------------------------------------------------------------------------------------------------//

    int x[] = {0, 1};
    int y[] = {ID_CATEGORIA_PERGUNTAS};

    Class perguntaClass = {.name = "Pergunta", .StructTypeSize = tamTipoPergunta, .data = perguntas, .auxStruct = estructAuxPerguntas, .elements = &contadorPerguntas, .fieldsNumber = tamAuxPergunta, .aliasField = PERGUNTA};


    //---------------------------------------------------------------------------------------------------------------//

    //inserirPergunta(perguntaClass);
    //listarPerguntas(perguntaClass);
    //listarPergunta(perguntaClass,contadorPerguntas-1);
    //filtrarPergunta(perguntaClass,contador-1,y,1);
    //pesquisarPerguntas(perguntaClass,ID_PERGUNTA,1);
    int i = 1;
    int *teste;
    int counter;
    char sinal[2 + 1];
    strcpy(sinal, "==");
    //teste = pesquisarPerguntas(perguntaClass, ID_CATEGORIA_PERGUNTAS, &i, &counter, sinal);
   // teste = pesquisarCategorias(categoriaClass, ID_CATEGORIA, &i, &counter, sinal);
    //filtrarCategorias(categoriaClass,teste, counter, y, 1);
    filtrarPerguntas(perguntaClass, x, 1, y, 1);
    
    //funcao search a perder o valor do sinall

    //for (i = 0; i < counter; i++) printf("%d\n", *(teste + i));
    //listarCategorias(categoriaClass);


    return 0;


    return (EXIT_SUCCESS);
}



