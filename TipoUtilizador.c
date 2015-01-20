#include "DataManagement.h"
#include "TipoUtilizador.h"
#include <string.h>

void inserirTipoUtilizador(Class tipoUtilizadorClass) {
    create(tipoUtilizadorClass.StructTypeSize, tipoUtilizadorClass.data, tipoUtilizadorClass.elements, tipoUtilizadorClass.auxStruct, tipoUtilizadorClass.fieldsNumber);
    char NomeFicheiro[SHORT_STRING];
    strcpy(NomeFicheiro, "tipoUtilizadores.txt");
    writeFile(NomeFicheiro, tipoUtilizadorClass);
}

void listarTipoUtilizadores(Class tipoUtilizadorClass) {

    fullList(tipoUtilizadorClass.data, tipoUtilizadorClass.StructTypeSize, (*tipoUtilizadorClass.elements), tipoUtilizadorClass.auxStruct, tipoUtilizadorClass.fieldsNumber);

}

void listartipoUtilizador(Class tipoUtilizadorClass, const unsigned int chave) {

    singleList(tipoUtilizadorClass, chave);
}

void filtrartipoUtilizadors(Class tipoUtilizadorClass, int *chaves, int numeroChaves, int *campos, int numeroCampos) {

    parsedList(tipoUtilizadorClass.data, tipoUtilizadorClass.StructTypeSize, tipoUtilizadorClass.auxStruct, chaves, numeroChaves, campos, numeroCampos);
}

void filtrartipoUtilizador(Class tipoUtilizadorClass, int chave, int *campos, int numeroCampos) {

    singleParsedList(tipoUtilizadorClass, chave, campos, numeroCampos);
}

void pesquisartipoUtilizadors(Class tipoUtilizadorClass,const unsigned int campo,void *valorPesquisar,unsigned int *numeroResultados,char *sinal){
    FieldAux *aux = tipoUtilizadorClass.auxStruct;
    aux[campo].type;
    search(campo, valorPesquisar,tipoUtilizadorClass.data,tipoUtilizadorClass.auxStruct,(*tipoUtilizadorClass.elements),tipoUtilizadorClass.StructTypeSize,aux[campo].type,numeroResultados,sinal) ;

    }

