#include "DataManagement.h"
#include "Ajudas.h"
#include <string.h>

void inserirAjuda(Class *ajudaClass) {

    create(ajudaClass->StructTypeSize, ajudaClass->data, ajudaClass->elements, ajudaClass->auxStruct, ajudaClass->fieldsNumber);
    char NomeFicheiro[SHORT_STRING];
    strcpy(NomeFicheiro, "ajudas.txt");
    writeFile(NomeFicheiro, ajudaClass);
}

void listarAjudas(Class *ajudaClass) {
    fullList(ajudaClass->data, ajudaClass->StructTypeSize, (*ajudaClass->elements), ajudaClass->auxStruct, ajudaClass->fieldsNumber);
}

void listarAjuda(Class ajudaClass, const unsigned int chave) {

    singleList(ajudaClass, chave);
}

void filtrarAjudas(Class ajudaClass, int *chaves, int numeroChaves, int *campos, int numeroCampos) {

    parsedList(ajudaClass.data, ajudaClass.StructTypeSize, ajudaClass.auxStruct, chaves, numeroChaves, campos, numeroCampos);
}

void filtrarAjuda(Class ajudaClass, int chave, int *campos, int numeroCampos) {

    singleParsedList(ajudaClass, chave, campos, numeroCampos);
}

void pesquisarAjudas(Class ajudaClass,const unsigned int campo,void *valorPesquisar,unsigned int *numeroResultados,char *sinal){
    FieldAux *aux = ajudaClass.auxStruct;
    aux[campo].type;
    search(campo, valorPesquisar,ajudaClass.data,ajudaClass.auxStruct,(*ajudaClass.elements),ajudaClass.StructTypeSize,aux[campo].type,numeroResultados,sinal) ;

    }

