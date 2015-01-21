#include "DataManagement.h"
#include "Jogadas.h"
#include <string.h>

void guardarJogadas(Class *jogadaClass) {
    char NomeFicheiro[SHORT_STRING];
    strcpy(NomeFicheiro, "jogadas.txt");
    writeFile(NomeFicheiro,jogadaClass);
}

void listarJogadas(Class *jogadaClass) {
    fullList(jogadaClass->data, jogadaClass->StructTypeSize, (*jogadaClass->elements), jogadaClass->auxStruct, jogadaClass->fieldsNumber);

}

void listarJogada(Class *jogadaClass, const unsigned int chave) {
    singleList(jogadaClass, chave);
}

void filtrarJogadas(Class *jogadaClass, int *chaves, int numeroChaves, int *campos, int numeroCampos) {
    parsedList(jogadaClass->data, jogadaClass->StructTypeSize, jogadaClass->auxStruct, chaves, numeroChaves, campos, numeroCampos);
}

void filtrarJogada(Class *jogadaClass, int chave, int *campos, int numeroCampos) {
    singleParsedList(jogadaClass, chave, campos, numeroCampos);
}

void inserirJogada(Class *jogadaClass) {
    create(jogadaClass->StructTypeSize, jogadaClass->data, jogadaClass->elements, jogadaClass->auxStruct, jogadaClass->fieldsNumber);
    guardarJogadas(jogadaClass);

}

void filtrarEditarJogada(Class *jogadaClass, const unsigned int chave, const unsigned int *campos, const unsigned int numeroCampos) {
    singleParsedRead(UPDATE, jogadaClass->StructTypeSize, jogadaClass->data, jogadaClass->auxStruct, chave, campos, numeroCampos);
    guardarJogadas(jogadaClass);

}

void editarJogada(Class *jogadaClass, const unsigned int chave) {
    fullRead(UPDATE, jogadaClass->StructTypeSize, jogadaClass->data, chave, jogadaClass->auxStruct, jogadaClass->fieldsNumber);
    guardarJogadas(jogadaClass);
    
}

void listar_editar_jogadas(Class *jogadaClass) {
    listarJogadas(jogadaClass);
    puts("Escolha a jogada que quer editar");
    unsigned int jogadaID;
    readInt(&jogadaID);
    Jogada *jogada;
    jogada = jogadaClass->data;
    if (jogadaID > jogada[0].id_jogada && jogadaID < jogada[*(jogadaClass->elements) - 1].id_jogada) {
        editarJogada(jogadaClass, jogadaID - 1);
    }
}

void editarJogadas(Class *jogadaClass, const unsigned int *chaves, const unsigned numeroChaves) {
    unsigned int i;
    for (i = 0; i < numeroChaves; i++) {
        fullRead(UPDATE, jogadaClass->StructTypeSize, jogadaClass->data, chaves[i], jogadaClass->auxStruct, jogadaClass->fieldsNumber);
    }
    guardarJogadas(jogadaClass);

}

void pesquisarJogadas(Class *jogadaClass, const unsigned int campo, void *valorPesquisar, unsigned int *numeroResultados, char *sinal) {
    FieldAux *aux = jogadaClass->auxStruct;
    aux[campo].type;
    search(campo, valorPesquisar, jogadaClass->data, jogadaClass->auxStruct, (*jogadaClass->elements), jogadaClass->StructTypeSize, aux[campo].type, numeroResultados, sinal);

}

