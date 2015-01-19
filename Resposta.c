#include "DataManagement.h"
#include "Resposta.h"

void inserirResposta(Class perguntaClasse) {

    create(perguntaClasse.StructTypeSize, perguntaClasse.data, perguntaClasse.elements, perguntaClasse.auxStruct, perguntaClasse.fieldsNumber);
}

void listarRespostas(Class perguntaClass) {

    fullList(perguntaClass.data, perguntaClass.StructTypeSize, (*perguntaClass.elements), perguntaClass.auxStruct, perguntaClass.fieldsNumber);

}

void listarResposta(Class perguntaClass, const unsigned int chave) {

    singleList(perguntaClass, chave);
}

void filtrarRespostas(Class perguntaClass, int *chaves, int numeroChaves, int *campos, int numeroCampos) {

    parsedList(perguntaClass.data, perguntaClass.StructTypeSize, perguntaClass.auxStruct, chaves, numeroChaves, campos, numeroCampos);
}

void filtrarResposta(Class perguntaClass, int chave, int *campos, int numeroCampos) {

    singleParsedList(perguntaClass, chave, campos, numeroCampos);
}

void pesquisarRespostas(Class perguntaClass,const unsigned int campo,void *valorPesquisar,unsigned int *numeroResultados,char *sinal){
    FieldAux *aux = perguntaClass.auxStruct;
    aux[campo].type;
    search(campo, valorPesquisar,perguntaClass.data,perguntaClass.auxStruct,(*perguntaClass.elements),perguntaClass.StructTypeSize,aux[campo].type,numeroResultados,sinal) ;

    }

