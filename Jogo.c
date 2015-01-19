#include "DataManagement.h"
#include "Jogo.h"
#include <string.h>

void inserirJogo(Class jogoClass) {

    create(jogoClass.StructTypeSize, jogoClass.data, jogoClass.elements, jogoClass.auxStruct, jogoClass.fieldsNumber);
     char NomeFicheiro[SHORT_STRING];
    strcpy(NomeFicheiro, "jogos.txt");
    writeFile(NomeFicheiro, jogoClass);
}

void listarJogos(Class jogoClass) {

    fullList(jogoClass.data, jogoClass.StructTypeSize, (*jogoClass.elements), jogoClass.auxStruct, jogoClass.fieldsNumber);

}

void listarJogo(Class jogoClass, const unsigned int chave) {

    singleList(jogoClass, chave);
}

void filtrarJogos(Class jogoClass, int *chaves, int numeroChaves, int *campos, int numeroCampos) {

    parsedList(jogoClass.data, jogoClass.StructTypeSize, jogoClass.auxStruct, chaves, numeroChaves, campos, numeroCampos);
}

void filtrarJogo(Class jogoClass, int chave, int *campos, int numeroCampos) {

    singleParsedList(jogoClass, chave, campos, numeroCampos);
}

void pesquisarJogos(Class jogoClass,const unsigned int campo,void *valorPesquisar,unsigned int *numeroResultados,char *sinal){
    FieldAux *aux = jogoClass.auxStruct;
    aux[campo].type;
    search(campo, valorPesquisar,jogoClass.data,jogoClass.auxStruct,(*jogoClass.elements),jogoClass.StructTypeSize,aux[campo].type,numeroResultados,sinal) ;

    }


