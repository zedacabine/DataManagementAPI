#include "DataManagement.h"
#include "TipoUtilizador.h"
#include <string.h>

void guardarTipoUtilizadors(Class *tipoTipoUtilizadorClass) {
    char NomeFicheiro[SHORT_STRING];
    strcpy(NomeFicheiro, "tipoTipoUtilizadors.txt");
    writeFile(NomeFicheiro, tipoTipoUtilizadorClass);
}

void listarTipoUtilizadores(Class *tipoTipoUtilizadorClass) {
    fullList(tipoTipoUtilizadorClass->data, tipoTipoUtilizadorClass->StructTypeSize, (*tipoTipoUtilizadorClass->elements), tipoTipoUtilizadorClass->auxStruct, tipoTipoUtilizadorClass->fieldsNumber);

}

void listarTipoUtilizador(Class *tipoTipoUtilizadorClass, const unsigned int chave) {
    singleList(tipoTipoUtilizadorClass, chave);
}

void filtrarTipoUtilizadores(Class *tipoTipoUtilizadorClass, int *chaves, int numeroChaves, int *campos, int numeroCampos) {
    parsedList(tipoTipoUtilizadorClass->data, tipoTipoUtilizadorClass->StructTypeSize, tipoTipoUtilizadorClass->auxStruct, chaves, numeroChaves, campos, numeroCampos);
}

void filtrarTipoUtilizador(Class *tipoTipoUtilizadorClass, int chave, int *campos, int numeroCampos) {
    singleParsedList(tipoTipoUtilizadorClass, chave, campos, numeroCampos);
}

void inserirTipoUtilizador(Class *tipoTipoUtilizadorClass) {
    create(tipoTipoUtilizadorClass->StructTypeSize, tipoTipoUtilizadorClass->data, tipoTipoUtilizadorClass->elements, tipoTipoUtilizadorClass->auxStruct, tipoTipoUtilizadorClass->fieldsNumber);
    guardarTipoUtilizadors(tipoTipoUtilizadorClass);

}

void filtrarEditarTipoUtilizador(Class *tipoTipoUtilizadorClass, const unsigned int chave, const unsigned int *campos, const unsigned int numeroCampos) {
    singleParsedRead(UPDATE, tipoTipoUtilizadorClass->StructTypeSize, tipoTipoUtilizadorClass->data, tipoTipoUtilizadorClass->auxStruct, chave, campos, numeroCampos);
    guardarTipoUtilizadors(tipoTipoUtilizadorClass);

}

void editarTipoUtilizador(Class *tipoTipoUtilizadorClass, const unsigned int chave) {
    fullRead(UPDATE, tipoTipoUtilizadorClass->StructTypeSize, tipoTipoUtilizadorClass->data, chave, tipoTipoUtilizadorClass->auxStruct, tipoTipoUtilizadorClass->fieldsNumber);
    guardarTipoUtilizadors(tipoTipoUtilizadorClass);

}

void listar_editar_tipoTipoUtilizadores(Class *tipoTipoUtilizadorClass) {
    listarTipoUtilizadores(tipoTipoUtilizadorClass);
    puts("Escolha a tipoTipoUtilizador que quer editar");
    unsigned int tipoTipoUtilizadorID;
    readInt(&tipoTipoUtilizadorID);
    TipoUtilizador *tipoTipoUtilizador;
    tipoTipoUtilizador = tipoTipoUtilizadorClass->data;
    if (tipoTipoUtilizadorID > tipoTipoUtilizador[0].id_tipo_utilizador && tipoTipoUtilizadorID < tipoTipoUtilizador[*(tipoTipoUtilizadorClass->elements) - 1].id_tipo_utilizador) {
        editarTipoUtilizador(tipoTipoUtilizadorClass, tipoTipoUtilizadorID - 1);
    }
}

void editarTipoUtilizadores(Class *tipoTipoUtilizadorClass, const unsigned int *chaves, const unsigned numeroChaves) {
    unsigned int i;
    for (i = 0; i < numeroChaves; i++) {
        fullRead(UPDATE, tipoTipoUtilizadorClass->StructTypeSize, tipoTipoUtilizadorClass->data, chaves[i], tipoTipoUtilizadorClass->auxStruct, tipoTipoUtilizadorClass->fieldsNumber);
    }
    guardarTipoUtilizadors(tipoTipoUtilizadorClass);

}

void pesquisarTipoUtilizadors(Class *tipoTipoUtilizadorClass, const unsigned int campo, void *valorPesquisar, unsigned int *numeroResultados, char *sinal) {
    FieldAux *aux = tipoTipoUtilizadorClass->auxStruct;
    aux[campo].type;
    search(campo, valorPesquisar, tipoTipoUtilizadorClass->data, tipoTipoUtilizadorClass->auxStruct, (*tipoTipoUtilizadorClass->elements), tipoTipoUtilizadorClass->StructTypeSize, aux[campo].type, numeroResultados, sinal);

}

