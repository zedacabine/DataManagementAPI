#include "DataManagement.h"
#include "Resposta.h"
#include <string.h>

void guardarRespostas(Class *respostaClass) {
    char NomeFicheiro[SHORT_STRING];
    strcpy(NomeFicheiro, "respostas.txt");
    writeFile(NomeFicheiro,respostaClass);
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

void inserirResposta(Class *respostaClass) {
    create(respostaClass->StructTypeSize, respostaClass->data, respostaClass->elements, respostaClass->auxStruct, respostaClass->fieldsNumber);
    guardarRespostas(respostaClass);

}

void filtrarEditarResposta(Class *respostaClass, const unsigned int chave, const unsigned int *campos, const unsigned int numeroCampos) {
    singleParsedRead(UPDATE, respostaClass->StructTypeSize, respostaClass->data, respostaClass->auxStruct, chave, campos, numeroCampos);
    guardarRespostas(respostaClass);

}

void editarResposta(Class *respostaClass, const unsigned int chave) {
    fullRead(UPDATE, respostaClass->StructTypeSize, respostaClass->data, chave, respostaClass->auxStruct, respostaClass->fieldsNumber);
    guardarRespostas(respostaClass);
    
}

void listar_editar_respostas(Class *respostaClass) {
    listarRespostas(respostaClass);
    puts("Escolha a resposta que quer editar");
    unsigned int respostaID;
    readInt(&respostaID);
    Resposta *resposta;
    resposta = respostaClass->data;
    if (respostaID > resposta[0].id_resposta && respostaID < resposta[*(respostaClass->elements) - 1].id_resposta) {
        editarResposta(respostaClass, respostaID - 1);
    }
}

void editarRespostas(Class *respostaClass, const unsigned int *chaves, const unsigned numeroChaves) {
    unsigned int i;
    for (i = 0; i < numeroChaves; i++) {
        fullRead(UPDATE, respostaClass->StructTypeSize, respostaClass->data, chaves[i], respostaClass->auxStruct, respostaClass->fieldsNumber);
    }
    guardarRespostas(respostaClass);

}

void pesquisarRespostas(Class *respostaClass, const unsigned int campo, void *valorPesquisar, unsigned int *numeroResultados, char *sinal) {
    FieldAux *aux = respostaClass->auxStruct;
    aux[campo].type;
    search(campo, valorPesquisar, respostaClass->data, respostaClass->auxStruct, (*respostaClass->elements), respostaClass->StructTypeSize, aux[campo].type, numeroResultados, sinal);

}

