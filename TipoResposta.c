#include "DataManagement.h"
#include "TipoResposta.h"
#include <string.h>

void inserirTipoResposta(Class tipoRespostaClass) {

    create(tipoRespostaClass.StructTypeSize, tipoRespostaClass.data, tipoRespostaClass.elements, tipoRespostaClass.auxStruct, tipoRespostaClass.fieldsNumber);
     char NomeFicheiro[SHORT_STRING];
    strcpy(NomeFicheiro, "tipoRespostas.txt");
    writeFile(NomeFicheiro, tipoRespostaClass);
}

void listarTipoRespostas(Class tipoRespostaClass) {

    fullList(tipoRespostaClass.data, tipoRespostaClass.StructTypeSize, (*tipoRespostaClass.elements), tipoRespostaClass.auxStruct, tipoRespostaClass.fieldsNumber);

}

void listarTipoResposta(Class tipoRespostaClass, const unsigned int chave) {

    singleList(tipoRespostaClass, chave);
}

void filtrarTipoRespostas(Class tipoRespostaClass, int *chaves, int numeroChaves, int *campos, int numeroCampos) {

    parsedList(tipoRespostaClass.data, tipoRespostaClass.StructTypeSize, tipoRespostaClass.auxStruct, chaves, numeroChaves, campos, numeroCampos);
}

void filtrarTipoResposta(Class tipoRespostaClass, int chave, int *campos, int numeroCampos) {

    singleParsedList(tipoRespostaClass, chave, campos, numeroCampos);
}

void pesquisarTipoRespostas(Class tipoRespostaClass,const unsigned int campo,void *valorPesquisar,unsigned int *numeroResultados,char *sinal){
    FieldAux *aux = tipoRespostaClass.auxStruct;
    aux[campo].type;
    search(campo, valorPesquisar,tipoRespostaClass.data,tipoRespostaClass.auxStruct,(*tipoRespostaClass.elements),tipoRespostaClass.StructTypeSize,aux[campo].type,numeroResultados,sinal) ;

    }


