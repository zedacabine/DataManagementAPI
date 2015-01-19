#include "DataManagement.h"
#include "Dificuldade.h"
#include <string.h>

void inserirDificuldade(Class dificuldadeClass) {
    create(dificuldadeClass.StructTypeSize, dificuldadeClass.data, dificuldadeClass.elements, dificuldadeClass.auxStruct, dificuldadeClass.fieldsNumber);
    char NomeFicheiro[SHORT_STRING];
    strcpy(NomeFicheiro, "dificuldades.txt");
    writeFile(NomeFicheiro, dificuldadeClass);
}

void listarDificuldades(Class dificuldadeClass) {

    fullList(dificuldadeClass.data, dificuldadeClass.StructTypeSize, (*dificuldadeClass.elements), dificuldadeClass.auxStruct, dificuldadeClass.fieldsNumber);

}

void listarDificuldade(Class dificuldadeClass, const unsigned int chave) {

    singleList(dificuldadeClass, chave);
}

void filtrarDificuldades(Class dificuldadeClass, int *chaves, int numeroChaves, int *campos, int numeroCampos) {

    parsedList(dificuldadeClass.data, dificuldadeClass.StructTypeSize, dificuldadeClass.auxStruct, chaves, numeroChaves, campos, numeroCampos);
}

void filtrarDificuldade(Class dificuldadeClass, int chave, int *campos, int numeroCampos) {

    singleParsedList(dificuldadeClass, chave, campos, numeroCampos);
}

void pesquisarDificuldades(Class dificuldadeClass,const unsigned int campo,void *valorPesquisar,unsigned int *numeroResultados,char *sinal){
    FieldAux *aux = dificuldadeClass.auxStruct;
    aux[campo].type;
    search(campo, valorPesquisar,dificuldadeClass.data,dificuldadeClass.auxStruct,(*dificuldadeClass.elements),dificuldadeClass.StructTypeSize,aux[campo].type,numeroResultados,sinal) ;

    }

