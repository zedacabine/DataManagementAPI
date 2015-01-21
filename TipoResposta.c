#include "DataManagement.h"
#include "TipoResposta.h"
#include <string.h>

void guardarTipoRespostas(Class *tipoTipoRespostaClass) {
    char NomeFicheiro[SHORT_STRING];
    strcpy(NomeFicheiro, "tipoTipoRespostas.txt");
    writeFile(NomeFicheiro, tipoTipoRespostaClass);
}

void listarTipoRespostas(Class *tipoTipoRespostaClass) {
    fullList(tipoTipoRespostaClass->data, tipoTipoRespostaClass->StructTypeSize, (*tipoTipoRespostaClass->elements), tipoTipoRespostaClass->auxStruct, tipoTipoRespostaClass->fieldsNumber);

}

void listarTipoResposta(Class *tipoTipoRespostaClass, const unsigned int chave) {
    singleList(tipoTipoRespostaClass, chave);
}

void filtrarTipoRespostas(Class *tipoTipoRespostaClass, int *chaves, int numeroChaves, int *campos, int numeroCampos) {
    parsedList(tipoTipoRespostaClass->data, tipoTipoRespostaClass->StructTypeSize, tipoTipoRespostaClass->auxStruct, chaves, numeroChaves, campos, numeroCampos);
}

void filtrarTipoResposta(Class *tipoTipoRespostaClass, int chave, int *campos, int numeroCampos) {
    singleParsedList(tipoTipoRespostaClass, chave, campos, numeroCampos);
}

void inserirTipoResposta(Class *tipoTipoRespostaClass) {
    create(tipoTipoRespostaClass->StructTypeSize, tipoTipoRespostaClass->data, tipoTipoRespostaClass->elements, tipoTipoRespostaClass->auxStruct, tipoTipoRespostaClass->fieldsNumber);
    guardarTipoRespostas(tipoTipoRespostaClass);

}

void filtrarEditarTipoResposta(Class *tipoTipoRespostaClass, const unsigned int chave, const unsigned int *campos, const unsigned int numeroCampos) {
    singleParsedRead(UPDATE, tipoTipoRespostaClass->StructTypeSize, tipoTipoRespostaClass->data, tipoTipoRespostaClass->auxStruct, chave, campos, numeroCampos);
    guardarTipoRespostas(tipoTipoRespostaClass);

}

void editarTipoResposta(Class *tipoTipoRespostaClass, const unsigned int chave) {
    fullRead(UPDATE, tipoTipoRespostaClass->StructTypeSize, tipoTipoRespostaClass->data, chave, tipoTipoRespostaClass->auxStruct, tipoTipoRespostaClass->fieldsNumber);
    guardarTipoRespostas(tipoTipoRespostaClass);

}

void listar_editar_tipoTipoRespostas(Class *tipoTipoRespostaClass) {
    listarTipoRespostas(tipoTipoRespostaClass);
    puts("Escolha a tipoTipoResposta que quer editar");
    unsigned int tipoTipoRespostaID;
    readInt(&tipoTipoRespostaID);
    TipoResposta *tipoTipoResposta;
    tipoTipoResposta = tipoTipoRespostaClass->data;
    if (tipoTipoRespostaID > tipoTipoResposta[0].id_tipo_resposta && tipoTipoRespostaID < tipoTipoResposta[*(tipoTipoRespostaClass->elements) - 1].id_tipo_resposta) {
        editarTipoResposta(tipoTipoRespostaClass, tipoTipoRespostaID - 1);
    }
}

void editarTipoRespostas(Class *tipoTipoRespostaClass, const unsigned int *chaves, const unsigned numeroChaves) {
    unsigned int i;
    for (i = 0; i < numeroChaves; i++) {
        fullRead(UPDATE, tipoTipoRespostaClass->StructTypeSize, tipoTipoRespostaClass->data, chaves[i], tipoTipoRespostaClass->auxStruct, tipoTipoRespostaClass->fieldsNumber);
    }
    guardarTipoRespostas(tipoTipoRespostaClass);

}

void pesquisarTipoRespostas(Class *tipoTipoRespostaClass, const unsigned int campo, void *valorPesquisar, unsigned int *numeroResultados, char *sinal) {
    FieldAux *aux = tipoTipoRespostaClass->auxStruct;
    aux[campo].type;
    search(campo, valorPesquisar, tipoTipoRespostaClass->data, tipoTipoRespostaClass->auxStruct, (*tipoTipoRespostaClass->elements), tipoTipoRespostaClass->StructTypeSize, aux[campo].type, numeroResultados, sinal);

}

