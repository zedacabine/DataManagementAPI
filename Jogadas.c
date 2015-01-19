#include "DataManagement.h"
#include "Jogadas.h"
#include <string.h>

void inserirJogada(Class jogadaClass) {

    create(jogadaClass.StructTypeSize, jogadaClass.data, jogadaClass.elements, jogadaClass.auxStruct, jogadaClass.fieldsNumber);
     char NomeFicheiro[SHORT_STRING];
    strcpy(NomeFicheiro, "jogadas.txt");
    writeFile(NomeFicheiro, jogadaClass);
}

void listarJogadas(Class jogadaClass) {

    fullList(jogadaClass.data, jogadaClass.StructTypeSize, (*jogadaClass.elements), jogadaClass.auxStruct, jogadaClass.fieldsNumber);

}

void listarJogada(Class jogadaClass, const unsigned int chave) {

    singleList(jogadaClass, chave);
}

void filtrarJogadas(Class jogadaClass, int *chaves, int numeroChaves, int *campos, int numeroCampos) {

    parsedList(jogadaClass.data, jogadaClass.StructTypeSize, jogadaClass.auxStruct, chaves, numeroChaves, campos, numeroCampos);
}

void filtrarJogada(Class jogadaClass, int chave, int *campos, int numeroCampos) {

    singleParsedList(jogadaClass, chave, campos, numeroCampos);
}

void pesquisarJogadas(Class jogadaClass,const unsigned int campo,void *valorPesquisar,unsigned int *numeroResultados,char *sinal){
    FieldAux *aux = jogadaClass.auxStruct;
    aux[campo].type;
    search(campo, valorPesquisar,jogadaClass.data,jogadaClass.auxStruct,(*jogadaClass.elements),jogadaClass.StructTypeSize,aux[campo].type,numeroResultados,sinal) ;

    }


