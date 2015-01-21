#include "DataManagement.h"
#include "Resposta.h"
#include <string.h>

void inserirResposta(Class *respostaClass) {

    create(respostaClass->StructTypeSize, respostaClass->data, respostaClass->elements, respostaClass->auxStruct, respostaClass->fieldsNumber);
     char NomeFicheiro[SHORT_STRING];
    strcpy(NomeFicheiro, "respostas.txt");
    writeFile(NomeFicheiro, respostaClass);
}

void listarRespostas(Class *respostaClass) {

    fullList(respostaClass->data, respostaClass->StructTypeSize, (*respostaClass->elements), respostaClass->auxStruct, respostaClass->fieldsNumber);

}

void listarResposta(Class *respostaClass, const unsigned int chave) {

    singleList(respostaClass, chave);
}

void filtrarRespostas(Class *respostaClass, int *chaves, int numeroChaves, int *campos, int numeroCampos) {

    parsedList(respostaClass->data, respostaClass->StructTypeSize, respostaClass->auxStruct, chaves, numeroChaves, campos, numeroCampos);
}

void filtrarResposta(Class *respostaClass, int chave, int *campos, int numeroCampos) {

    singleParsedList(respostaClass, chave, campos, numeroCampos);
}

void pesquisarRespostas(Class *respostaClass,const unsigned int campo,void *valorPesquisar,unsigned int *numeroResultados,char *sinal){
    FieldAux *aux = respostaClass->auxStruct;
    aux[campo].type;
    search(campo, valorPesquisar,respostaClass->data,respostaClass->auxStruct,(*respostaClass->elements),respostaClass->StructTypeSize,aux[campo].type,numeroResultados,sinal) ;

    }

