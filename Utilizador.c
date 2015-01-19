#include "DataManagement.h"
#include "Utilizador.h"
#include <string.h>

void inserirUtilizador(Class utilizadorClass) {

    create(utilizadorClass.StructTypeSize, utilizadorClass.data, utilizadorClass.elements, utilizadorClass.auxStruct, utilizadorClass.fieldsNumber);
     char NomeFicheiro[SHORT_STRING];
    strcpy(NomeFicheiro, "utilizadores.txt");
    writeFile(NomeFicheiro, utilizadorClass);
}

void listarUtilizadors(Class utilizadorClass) {

    fullList(utilizadorClass.data, utilizadorClass.StructTypeSize, (*utilizadorClass.elements), utilizadorClass.auxStruct, utilizadorClass.fieldsNumber);

}

void listarUtilizador(Class utilizadorClass, const unsigned int chave) {

    singleList(utilizadorClass, chave);
}

void filtrarUtilizadors(Class utilizadorClass, int *chaves, int numeroChaves, int *campos, int numeroCampos) {

    parsedList(utilizadorClass.data, utilizadorClass.StructTypeSize, utilizadorClass.auxStruct, chaves, numeroChaves, campos, numeroCampos);
}

void filtrarUtilizador(Class utilizadorClass, int chave, int *campos, int numeroCampos) {

    singleParsedList(utilizadorClass, chave, campos, numeroCampos);
}

void pesquisarUtilizadors(Class utilizadorClass,const unsigned int campo,void *valorPesquisar,unsigned int *numeroResultados,char *sinal){
    FieldAux *aux = utilizadorClass.auxStruct;
    aux[campo].type;
    search(campo, valorPesquisar,utilizadorClass.data,utilizadorClass.auxStruct,(*utilizadorClass.elements),utilizadorClass.StructTypeSize,aux[campo].type,numeroResultados,sinal) ;

    }


