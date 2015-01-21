#include "DataManagement.h"
#include "Dificuldade.h"
#include <string.h>

void guardarDificuldades(Class *dificuldadeClass) {
    char NomeFicheiro[SHORT_STRING];
    strcpy(NomeFicheiro, "dificuldades.txt");
    writeFile(NomeFicheiro,dificuldadeClass);
}

void listarDificuldades(Class *dificuldadeClass) {
    fullList(dificuldadeClass->data, dificuldadeClass->StructTypeSize, (*dificuldadeClass->elements), dificuldadeClass->auxStruct, dificuldadeClass->fieldsNumber);
    
}

void listarDificuldade(Class *dificuldadeClass, const unsigned int chave) {
    singleList(dificuldadeClass, chave);
}

void filtrarDificuldades(Class *dificuldadeClass, int *chaves, int numeroChaves, int *campos, int numeroCampos) {
    parsedList(dificuldadeClass->data, dificuldadeClass->StructTypeSize, dificuldadeClass->auxStruct, chaves, numeroChaves, campos, numeroCampos);
}

void filtrarDificuldade(Class *dificuldadeClass, int chave, int *campos, int numeroCampos) {
    singleParsedList(dificuldadeClass, chave, campos, numeroCampos);
}

void inserirDificuldade(Class *dificuldadeClass) {
    create(dificuldadeClass->StructTypeSize, dificuldadeClass->data, dificuldadeClass->elements, dificuldadeClass->auxStruct, dificuldadeClass->fieldsNumber);
    guardarDificuldades(dificuldadeClass);

}

void filtrarEditarDificuldade(Class *dificuldadeClass, const unsigned int chave, const unsigned int *campos, const unsigned int numeroCampos) {
    singleParsedRead(UPDATE, dificuldadeClass->StructTypeSize, dificuldadeClass->data, dificuldadeClass->auxStruct, chave, campos, numeroCampos);
    guardarDificuldades(dificuldadeClass);

}

void editarDificuldade(Class *dificuldadeClass, const unsigned int chave) {
    fullRead(UPDATE, dificuldadeClass->StructTypeSize, dificuldadeClass->data, chave, dificuldadeClass->auxStruct, dificuldadeClass->fieldsNumber);
    guardarDificuldades(dificuldadeClass);
    
}

void listar_editar_dificuldades(Class *dificuldadeClass) {
    listarDificuldades(dificuldadeClass);
    puts("Escolha a dificuldade que quer editar");
    unsigned int dificuldadeID;
    readInt(&dificuldadeID);
    Dificuldade *dificuldade;
    dificuldade = dificuldadeClass->data;
    if (dificuldadeID > dificuldade[0].id_dificuldade && dificuldadeID < dificuldade[*(dificuldadeClass->elements) - 1].id_dificuldade) {
        editarDificuldade(dificuldadeClass, dificuldadeID - 1);
    }
}

void editarDificuldades(Class *dificuldadeClass, const unsigned int *chaves, const unsigned numeroChaves) {
    unsigned int i;
    for (i = 0; i < numeroChaves; i++) {
        fullRead(UPDATE, dificuldadeClass->StructTypeSize, dificuldadeClass->data, chaves[i], dificuldadeClass->auxStruct, dificuldadeClass->fieldsNumber);
    }
    guardarDificuldades(dificuldadeClass);

}

void pesquisarDificuldades(Class *dificuldadeClass, const unsigned int campo, void *valorPesquisar, unsigned int *numeroResultados, char *sinal) {
    FieldAux *aux = dificuldadeClass->auxStruct;
    aux[campo].type;
    search(campo, valorPesquisar, dificuldadeClass->data, dificuldadeClass->auxStruct, (*dificuldadeClass->elements), dificuldadeClass->StructTypeSize, aux[campo].type, numeroResultados, sinal);

}

