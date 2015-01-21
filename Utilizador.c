#include "DataManagement.h"
#include "Utilizador.h"
#include <string.h>

void guardarUtilizadores(Class *utilizadorClass) {
    char NomeFicheiro[SHORT_STRING];
    strcpy(NomeFicheiro, "utilizadors.txt");
    writeFile(NomeFicheiro,utilizadorClass);
}

void listarUtilizadores(Class *utilizadorClass) {
    fullList(utilizadorClass->data, utilizadorClass->StructTypeSize, (*utilizadorClass->elements), utilizadorClass->auxStruct, utilizadorClass->fieldsNumber);

}

void listarUtilizador(Class *utilizadorClass, const unsigned int chave) {
    singleList(utilizadorClass, chave);
}

void filtrarUtilizadores(Class *utilizadorClass, int *chaves, int numeroChaves, int *campos, int numeroCampos) {
    parsedList(utilizadorClass->data, utilizadorClass->StructTypeSize, utilizadorClass->auxStruct, chaves, numeroChaves, campos, numeroCampos);
}

void filtrarUtilizador(Class *utilizadorClass, int chave, int *campos, int numeroCampos) {
    singleParsedList(utilizadorClass, chave, campos, numeroCampos);
}

void inserirUtilizador(Class *utilizadorClass) {
    create(utilizadorClass->StructTypeSize, utilizadorClass->data, utilizadorClass->elements, utilizadorClass->auxStruct, utilizadorClass->fieldsNumber);
    guardarUtilizadores(utilizadorClass);

}

void filtrarEditarUtilizador(Class *utilizadorClass, const unsigned int chave, const unsigned int *campos, const unsigned int numeroCampos) {
    singleParsedRead(UPDATE, utilizadorClass->StructTypeSize, utilizadorClass->data, utilizadorClass->auxStruct, chave, campos, numeroCampos);
    guardarUtilizadores(utilizadorClass);

}

void editarUtilizador(Class *utilizadorClass, const unsigned int chave) {
    fullRead(UPDATE, utilizadorClass->StructTypeSize, utilizadorClass->data, chave, utilizadorClass->auxStruct, utilizadorClass->fieldsNumber);
    guardarUtilizadores(utilizadorClass);
    
}

void listar_editar_utilizadores(Class *utilizadorClass) {
    listarUtilizadores(utilizadorClass);
    puts("Escolha a utilizador que quer editar");
    unsigned int utilizadorID;
    readInt(&utilizadorID);
    Utilizador *utilizador;
    utilizador = utilizadorClass->data;
    if (utilizadorID > utilizador[0].id_utilizador && utilizadorID < utilizador[*(utilizadorClass->elements) - 1].id_utilizador) {
        editarUtilizador(utilizadorClass, utilizadorID - 1);
    }
}

void editarUtilizadores(Class *utilizadorClass, const unsigned int *chaves, const unsigned numeroChaves) {
    unsigned int i;
    for (i = 0; i < numeroChaves; i++) {
        fullRead(UPDATE, utilizadorClass->StructTypeSize, utilizadorClass->data, chaves[i], utilizadorClass->auxStruct, utilizadorClass->fieldsNumber);
    }
    guardarUtilizadores(utilizadorClass);

}

void pesquisarUtilizadors(Class *utilizadorClass, const unsigned int campo, void *valorPesquisar, unsigned int *numeroResultados, char *sinal) {
    FieldAux *aux = utilizadorClass->auxStruct;
    aux[campo].type;
    search(campo, valorPesquisar, utilizadorClass->data, utilizadorClass->auxStruct, (*utilizadorClass->elements), utilizadorClass->StructTypeSize, aux[campo].type, numeroResultados, sinal);

}

