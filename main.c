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

    unsigned int contador, contadorPerguntas, contadorCategorias, contadorRespostas, contadorTipoUtilizadores, contadorAjudas, contadorDificuldades, contadorTipoResposta, contadorJogadas, contadorJogos, contadorUtilizadores;

    //---------------------------------------------------------------------------------------------------------------//

    FieldAux estructAuxCategorias[] = {
        {.fieldName = "id_categoria", .alias = "Numero Categoria", .sizeBytes = INT_SIZE, .type = INT, .unique = true, .required = true, .autoIncrement = true},
        {.fieldName = "categoria", .alias = "Categoria", .sizeBytes = SHORT_STRING, .type = STRING, .required = true},
        {.fieldName = "pontuacao_categoria", .alias = "Pontuacao", .sizeBytes = INT_SIZE, .type = INT, .required = true}
    };

    Categoria categorias[MAX_CATEGORIA];
    const unsigned int tamAuxCategoria = (sizeof (estructAuxCategorias) / sizeof (estructAuxCategorias[0]));
    const unsigned int tamTipoCategoria = sizeof (Categoria);
    const unsigned int tamArrayCategoria = (sizeof (categorias) / sizeof (categorias[0]));

    Class categoriaClass = {.name = "Categoria", .StructTypeSize = tamTipoCategoria, .data = categorias, .auxStruct = estructAuxCategorias, .elements = &contadorCategorias, .fieldsNumber = tamAuxCategoria, .aliasField = CATEGORIA};

    strcpy(NomeFicheiro, "categorias.txt");
    //readFile(NomeFicheiro, categoriaClass, MAX_CATEGORIA);
    readFile(NomeFicheiro, &categoriaClass, MAX_CATEGORIA);

    //---------------------------------------------------------------------------------------------------------------//

    FieldAux estructAuxRespostas[] = {
        {.fieldName = "id_resposta", .alias = "Numero Resposta", .sizeBytes = INT_SIZE, .type = INT, .unique = true},
        {.fieldName = "id_pergunta_resposta", .alias = "Numero Pergunta Resposta", .sizeBytes = INT_SIZE, .type = INT, .unique = true},
        {.fieldName = "resposta", .alias = "Resposta", . sizeBytes = LONG_STRING, .type = STRING}
    };

    Resposta respostas[MAX_RESPOSTA];
    const unsigned int tamAuxResposta = (sizeof (estructAuxRespostas) / sizeof (estructAuxRespostas[0]));
    const unsigned int tamTipoResposta = sizeof (Resposta);
    const unsigned int tamArrayResposta = (sizeof (respostas) / sizeof (estructAuxRespostas[0]));

    Class respostaClass = {.name = "Resposta", .StructTypeSize = tamTipoResposta, .data = respostas, .auxStruct = estructAuxRespostas, .elements = &contadorRespostas, .fieldsNumber = tamAuxResposta, .aliasField = RESPOSTA};

    strcpy(NomeFicheiro, "respostas.txt");
    readFile(NomeFicheiro, &respostaClass, MAX_RESPOSTA);

    //---------------------------------------------------------------------------------------------------------------//

    FieldAux estructAuxDificuldades[] = {
        {.fieldName = "id_dificuldade", .alias = "Numero Dificuldade", .sizeBytes = INT_SIZE, . type = INT, . unique = true},
        {.fieldName = "dificuldade", .alias = "Dificuldade", .sizeBytes = SHORT_STRING, .type = STRING, . required = true},
        {.fieldName = "pontuacao_dificuldade", .alias = "Pontuacao", .sizeBytes = INT_SIZE, .type = INT, .required = true}

    };

    Dificuldade dificuldades[MAX_DIFICULDADE];
    const unsigned int tamAuxDificuldade = (sizeof (estructAuxDificuldades) / sizeof (estructAuxDificuldades[0]));
    const unsigned int tamTipoDificuldade = sizeof (Dificuldade);
    const unsigned int tamArrayDificuldade = (sizeof (dificuldades) / sizeof (estructAuxDificuldades[0]));

    Class dificuldadeClass = {.name = "Dificuldade", .StructTypeSize = tamTipoDificuldade, .data = dificuldades, .auxStruct = estructAuxDificuldades, .elements = &contadorDificuldades, .fieldsNumber = tamAuxDificuldade, .aliasField = DIFICULDADE};

    strcpy(NomeFicheiro, "dificuldades.txt");
    readFile(NomeFicheiro, &dificuldadeClass, MAX_DIFICULDADE);


    //---------------------------------------------------------------------------------------------------------------//


    FieldAux estructAuxPerguntas[] = {
        {.fieldName = "id_pergunta", .alias = "Numero Pergunta", .sizeBytes = INT_SIZE, .type = INT, .unique = true, .required = true, .autoIncrement = true, .step = 1},
        {.fieldName = "id_categoria_pergunta", .alias = "Numero Categoria", .sizeBytes = INT_SIZE, .type = INT, .required = true, .foreignKey = true, .parentPrimaryKey = ID_CATEGORIA, .parentClass = &categoriaClass},
        {.fieldName = "id_dificuldade_pergunta", .alias = "Numero Dificuldade", .sizeBytes = INT_SIZE, .type = INT, .required = true, .foreignKey = true, .parentPrimaryKey = ID_DIFICULDADE, .parentClass = &dificuldadeClass},
        {.fieldName = "id_resposta_certa_pergunta", .alias = "Numero Resposta Certa", .sizeBytes = INT_SIZE, .type = INT, .required = true, .foreignKey = true, .parentPrimaryKey = ID_RESPOSTA, .parentClass = &respostaClass},
        {.fieldName = "pergunta", .alias = "Pergunta", .sizeBytes = LONG_STRING, .type = STRING, .required = true}

    };

    Pergunta perguntas[MAX_PERGUNTA];
    const unsigned int tamAuxPergunta = (sizeof (estructAuxPerguntas) / sizeof (estructAuxPerguntas[0]));
    const unsigned int tamTipoPergunta = sizeof (Pergunta);
    const unsigned int tamArrayPergunta = (sizeof (perguntas) / sizeof (perguntas[0]));

    Class perguntaClass = {.name = "Pergunta", .StructTypeSize = tamTipoPergunta, .data = perguntas, .auxStruct = estructAuxPerguntas, .elements = &contadorPerguntas, .fieldsNumber = tamAuxPergunta, .aliasField = PERGUNTA};

    strcpy(NomeFicheiro, "perguntas.txt");
    readFile(NomeFicheiro, &perguntaClass, MAX_PERGUNTA);



    //---------------------------------------------------------------------------------------------------------------//

    FieldAux estructAuxAjudas[] = {
        {.fieldName = "id_ajuda", .alias = "Numero Ajuda", . sizeBytes = INT_SIZE, .type = INT, .unique = true},
        {.fieldName = "ajuda", .alias = "Ajuda", .sizeBytes = LONG_STRING, .type = STRING}
    };

    Ajuda ajudas[MAX_AJUDA];
    const unsigned int tamAuxAjuda = (sizeof (estructAuxAjudas) / sizeof (estructAuxAjudas[0]));
    const unsigned int tamTipoAjuda = sizeof (Ajuda);
    const unsigned int tamArrayAjuda = (sizeof (ajudas) / sizeof (estructAuxAjudas[0]));

    Class ajudaClass = {.name = "Ajuda", .StructTypeSize = tamTipoAjuda, .data = ajudas, .auxStruct = estructAuxAjudas, .elements = &contadorAjudas, .fieldsNumber = tamAuxAjuda, .aliasField = AJUDA};

    strcpy(NomeFicheiro, "ajudas.txt");
    readFile(NomeFicheiro, &ajudaClass, MAX_AJUDA);


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

    Jogada jogadas[MAX_JOGADA];
    const unsigned int tamAuxJogada = (sizeof (estructAuxJogadas) / sizeof (estructAuxJogadas[0]));
    const unsigned int tamTipoJogada = sizeof (Jogada);
    const unsigned int tamArrayJogada = (sizeof (jogadas) / sizeof (estructAuxJogadas[0]));

    Class jogadaClass = {.name = "Jogada", .StructTypeSize = tamTipoJogada, .data = jogadas, .auxStruct = estructAuxJogadas, .elements = &contadorJogadas, .fieldsNumber = tamAuxJogada, .aliasField = PONTUACAO};

    strcpy(NomeFicheiro, "jogadas.txt");
    readFile(NomeFicheiro, &jogadaClass, MAX_JOGADA);


    //---------------------------------------------------------------------------------------------------------------//
    FieldAux estructAuxJogos[] = {
        {.fieldName = "id_jogo", .alias = "Numero Jogo", .sizeBytes = INT_SIZE, .type = INT, .unique = true},
        {.fieldName = "id_utilizador_jogo", .alias = "Numero Utilizador Jogo", .sizeBytes = INT_SIZE, .type = INT, .unique = true}
    };

    Jogo jogos[MAX_JOGO];
    const unsigned int tamAuxJogo = (sizeof (estructAuxJogos) / sizeof (estructAuxJogos[0]));
    const unsigned int tamTipoJogo = sizeof (Jogo);
    const unsigned int tamArrayJogo = (sizeof (jogos) / sizeof (estructAuxJogos[0]));

    Class jogoClass = {.name = "Jogo", .StructTypeSize = tamTipoJogo, .data = jogos, .auxStruct = estructAuxJogos, .elements = &contadorJogos, .fieldsNumber = tamAuxJogo};

    strcpy(NomeFicheiro, "jogos.txt");
    readFile(NomeFicheiro, &jogoClass, MAX_JOGO);
    //---------------------------------------------------------------------------------------------------------------//

    FieldAux estructAuxTipoRespostas[] = {
        {.fieldName = "id_tipo_resposta", .alias = "Numero Tipo Resposta", .sizeBytes = INT_SIZE, .type = INT, .unique = true},
        {.fieldName = "tipo_resposta", .alias = "Tipo Resposta", .sizeBytes = SHORT_STRING, .type = STRING},
        {.fieldName = "id_resposta_tipo_resposta", .alias = "Numero resposta", .sizeBytes = INT_SIZE, .type = INT, .unique = true}
    };

    TipoResposta tipoRespostas[MAX_TIPO_RESPOSTA];
    const unsigned int tamAuxTipoResposta = (sizeof (estructAuxTipoRespostas) / sizeof (estructAuxTipoRespostas[0]));
    const unsigned int tamTipoTipoResposta = sizeof (TipoResposta);
    const unsigned int tamArrayTipoResposta = (sizeof (tipoRespostas) / sizeof (estructAuxTipoRespostas[0]));

    Class tipoRespostaClass = {.name = "Tipo Resposta", .StructTypeSize = tamTipoTipoResposta, .data = tipoRespostas, .auxStruct = estructAuxTipoRespostas, .elements = &contadorTipoResposta, .fieldsNumber = tamAuxTipoResposta, .aliasField = TIPO_RESPOSTA};

    strcpy(NomeFicheiro, "tiporespostas.txt");
    readFile(NomeFicheiro, &tipoRespostaClass, MAX_TIPO_RESPOSTA);


    //---------------------------------------------------------------------------------------------------------------//

    FieldAux estructAuxTipoUtilizadores[] = {
        {.fieldName = "id_tipo_utilizador", .alias = "Numero Tipo Utilizador", .sizeBytes = INT_SIZE, .type = INT, .unique = true},
        {.fieldName = "tipo_utilizador", .alias = "Tipo Utilizador", .sizeBytes = MEDIUM_STRING, .type = STRING}
    };

    TipoUtilizador tipoUtilizadores[MAX_TIPO_UTILIZADOR];
    const unsigned int tamAuxTipoUtilizador = (sizeof (estructAuxTipoUtilizadores) / sizeof (estructAuxTipoUtilizadores[0]));
    const unsigned int tamTipoTipoUtilizador = sizeof (TipoUtilizador);
    const unsigned int tamArrayTipoUtilizador = (sizeof (tipoUtilizadores) / sizeof (estructAuxTipoUtilizadores[0]));

    Class tipoUtilizadorClass = {.name = "Tipo Utilizador", .StructTypeSize = tamTipoTipoUtilizador, .data = tipoUtilizadores, .auxStruct = estructAuxTipoUtilizadores, .elements = &contadorTipoUtilizadores, .fieldsNumber = tamAuxTipoUtilizador, .aliasField = DIFICULDADE};

    strcpy(NomeFicheiro, "tipoUtilizadores.txt");
    readFile(NomeFicheiro, &tipoUtilizadorClass, MAX_TIPO_UTILIZADOR);

    //---------------------------------------------------------------------------------------------------------------//

    FieldAux estructAuxUtilizadores[] = {
        {.fieldName = "id_utilizador", .alias = "Numero Utilizador", .sizeBytes = INT_SIZE, .type = INT, .unique = true, .required = true},
        {.fieldName = "id_tipo_utilizador_utilizador", .alias = "Numero tipo utilizador", .sizeBytes = INT_SIZE, .type = INT, .required = true, .unique = true},
        {.fieldName = "nome", .alias = "Nome", . sizeBytes = MEDIUM_STRING, .type = STRING, .required = true},
        {.fieldName = "password", .alias = "Password", . sizeBytes = MEDIUM_STRING, .type = STRING, .required = true}
    };

    Utilizador utilizadores[MAX_UTILIZADOR];
    const unsigned int tamAuxUtilizador = (sizeof (estructAuxUtilizadores) / sizeof (estructAuxUtilizadores[0]));
    const unsigned int tamTipoUtilizador = sizeof (Utilizador);
    const unsigned int tamArrayUtilizador = (sizeof (utilizadores) / sizeof (estructAuxUtilizadores[0]));

    Class utilizadorClass = {.name = "Utilizador", .StructTypeSize = tamTipoUtilizador, .data = utilizadores, .auxStruct = estructAuxUtilizadores, .elements = &contadorUtilizadores, .fieldsNumber = tamAuxUtilizador, .aliasField = NOME};

    strcpy(NomeFicheiro, "utilizadores.txt");
    readFile(NomeFicheiro, &utilizadorClass, MAX_UTILIZADOR);


    //---------------------------------------------------------------------------------------------------------------//

    int x[] = {0, 1};
    int y[] = {ID_CATEGORIA_PERGUNTAS};

    void *lista[] = {};

    void *arrayClass[10];
    arrayClass[0] = &perguntaClass;
    arrayClass[1] = &categoriaClass;
    arrayClass[2] = &respostaClass;
    arrayClass[3] = &dificuldadeClass;
    arrayClass[4] = &ajudaClass;
    arrayClass[5] = &jogadaClass;
    arrayClass[6] = &jogoClass;
    arrayClass[7] = &tipoUtilizadorClass;
    arrayClass[8] = &tipoRespostaClass;
    arrayClass[9] = &utilizadorClass;

    //login(arrayClass, utilizadorClass);

    menu_admin(arrayClass);



    //---------------------------------------------------------------------------------------------------------------//
    //listarUtilizadores(utilizadorClass);
    //inserirUtilizador(utilizadorClass);
    //listarTipoUtilizadores(tipoUtilizadorClass);
    // inserirTipoUtilizador(tipoUtilizadorClass);
    //inserirCategoria(categoriaClass);
    //listarCategorias(categoriaClass);

    ///////////////////Perguntas\\\\\\\\\\\\\/
    int camposEditarPergunta[2] = {ID_PERGUNTA,PERGUNTA};
    int chaves[] = {0, 1, 2};
    int valor = 1;
    int numeroResultados;
    char sinal[2 + 1];
    strcpy(sinal, "==");
    int * resultPesquisa;
    resultPesquisa=pesquisarPerguntas(&perguntaClass, ID_DIFICULDADE, &valor, &numeroResultados, sinal);
    //inserirPergunta(&perguntaClass);
    //listarPerguntas(&perguntaClass);
    //listarPergunta(&perguntaClass,0);
    //filtrarPergunta(&perguntaClass,0,camposEditarPergunta,2);
     //filtrarPerguntas(&perguntaClass,resultPesquisa,numeroResultados,camposEditarPergunta,2);
    //filtrarEditarPergunta(&perguntaClass, 0, camposEditarPergunta, 2);
    //editarPergunta(&perguntaClass,1);
    //editarPerguntas(&perguntaClass, chaves, 3);
    //listar_editar_perguntas(&perguntaClass);
    ///////////////////////////////////////////

    //inserirDificuldade(dificuldadeClass);
    //listarDificuldades(dificuldadeClass);
    //inserirResposta(respostaClass);
    //listarRespostas(respostaClass);
    //listarUtilizador(utilizadorClass,0);
    //filtrarPergunta(perguntaClass,contador-1,y,1);
    //squisarPerguntas(perguntaClass, ID_CATEGORIA_PERGUNTAS, &i, &counter, sinal);
    //teste = ppesquisarPerguntas(perguntaClass,ID_PERGUNTA,1);
    // char pes[20];
    //strcpy(pes, "")
    //int *teste;
    //int counter;
    //char sinal[2 + 1];
    //strcpy(sinal, "==");
    //teste = pesquisarCategorias(categoriaClass, CATEGORIA, &i, &counter, sinal);
    //printInt(&counter);

    //teste = pesquisarPerguntas(perguntaClass, ID_CATEGORIA_PERGUNTAS, &i, &counter, sinal);

    //filtrarCategorias(categoriaClass,teste, counter, y, 1);
    //filtrarPerguntas(perguntaClass, x, 1, y, 1);

    //funcao search a perder o valor do sinall

    //for (i = 0; i < counter; i++) printf("%d\n", *(teste + i));
    //listarCategorias(categoriaClass);
    return 0;

    return (EXIT_SUCCESS);
}



