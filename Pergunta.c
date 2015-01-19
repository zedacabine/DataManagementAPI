#include "DataManagement.h"
#include "Pergunta.h"
#include <string.h>

void inserirPergunta(Class perguntaClass) {

    create(perguntaClass.StructTypeSize, perguntaClass.data, perguntaClass.elements, perguntaClass.auxStruct, perguntaClass.fieldsNumber);
    char NomeFicheiro[SHORT_STRING];
    strcpy(NomeFicheiro, "perguntas.txt");
    writeFile(NomeFicheiro, perguntaClass);
}

void listarPerguntas(Class perguntaClass) {
    fullList(perguntaClass.data, perguntaClass.StructTypeSize, (*perguntaClass.elements), perguntaClass.auxStruct, perguntaClass.fieldsNumber);
}

void listarPergunta(Class perguntaClass, const unsigned int chave) {

    singleList(perguntaClass, chave);
}

void filtrarPerguntas(Class perguntaClass, int *chaves, int numeroChaves, int *campos, int numeroCampos) {

    parsedList(perguntaClass.data, perguntaClass.StructTypeSize, perguntaClass.auxStruct, chaves, numeroChaves, campos, numeroCampos);
}

void filtrarPergunta(Class perguntaClass, int chave, int *campos, int numeroCampos) {

    singleParsedList(perguntaClass, chave, campos, numeroCampos);
}

void pesquisarPerguntas(Class perguntaClass,const unsigned int campo,void *valorPesquisar,unsigned int *numeroResultados,char *sinal){
    FieldAux *aux = perguntaClass.auxStruct;
    aux[campo].type;
    search(campo, valorPesquisar,perguntaClass.data,perguntaClass.auxStruct,(*perguntaClass.elements),perguntaClass.StructTypeSize,aux[campo].type,numeroResultados,sinal) ;

    }

