#include "DataManagement.h"
#include "Ajudas.h"
#include <string.h>

void guardarAjudas(Class *ajudaClass) {
    char NomeFicheiro[SHORT_STRING];
    strcpy(NomeFicheiro, "ajudas.txt");
    writeFile(NomeFicheiro,ajudaClass);
}

void listarAjudas(Class *ajudaClass) {
    fullList(ajudaClass->data, ajudaClass->StructTypeSize, (*ajudaClass->elements), ajudaClass->auxStruct, ajudaClass->fieldsNumber);

}

void listarAjuda(Class *ajudaClass, const unsigned int chave) {
    singleList(ajudaClass, chave);
}

void filtrarAjudas(Class *ajudaClass, int *chaves, int numeroChaves, int *campos, int numeroCampos) {
    parsedList(ajudaClass->data, ajudaClass->StructTypeSize, ajudaClass->auxStruct, chaves, numeroChaves, campos, numeroCampos);
}

void filtrarAjuda(Class *ajudaClass, int chave, int *campos, int numeroCampos) {
    singleParsedList(ajudaClass, chave, campos, numeroCampos);
}

void inserirAjuda(Class *ajudaClass) {
    create(ajudaClass->StructTypeSize, ajudaClass->data, ajudaClass->elements, ajudaClass->auxStruct, ajudaClass->fieldsNumber);
    guardarAjudas(ajudaClass);

}

void filtrarEditarAjuda(Class *ajudaClass, const unsigned int chave, const unsigned int *campos, const unsigned int numeroCampos) {
    singleParsedRead(UPDATE, ajudaClass->StructTypeSize, ajudaClass->data, ajudaClass->auxStruct, chave, campos, numeroCampos);
    guardarAjudas(ajudaClass);

}

void editarAjuda(Class *ajudaClass, const unsigned int chave) {
    fullRead(UPDATE, ajudaClass->StructTypeSize, ajudaClass->data, chave, ajudaClass->auxStruct, ajudaClass->fieldsNumber);
    guardarAjudas(ajudaClass);
    
}

void listar_editar_ajudas(Class *ajudaClass) {
    listarAjudas(ajudaClass);
    puts("Escolha a ajuda que quer editar");
    unsigned int ajudaID;
    readInt(&ajudaID);
    Ajuda *ajuda;
    ajuda = ajudaClass->data;
    if (ajudaID > ajuda[0].id_ajuda && ajudaID < ajuda[*(ajudaClass->elements) - 1].id_ajuda) {
        editarAjuda(ajudaClass, ajudaID - 1);
    }
}

void editarAjudas(Class *ajudaClass, const unsigned int *chaves, const unsigned numeroChaves) {
    unsigned int i;
    for (i = 0; i < numeroChaves; i++) {
        fullRead(UPDATE, ajudaClass->StructTypeSize, ajudaClass->data, chaves[i], ajudaClass->auxStruct, ajudaClass->fieldsNumber);
    }
    guardarAjudas(ajudaClass);

}

void pesquisarAjudas(Class *ajudaClass, const unsigned int campo, void *valorPesquisar, unsigned int *numeroResultados, char *sinal) {
    FieldAux *aux = ajudaClass->auxStruct;
    aux[campo].type;
    search(campo, valorPesquisar, ajudaClass->data, ajudaClass->auxStruct, (*ajudaClass->elements), ajudaClass->StructTypeSize, aux[campo].type, numeroResultados, sinal);

}

