#include "DataManagement.h"
#include "Pergunta.h"

void inserirPergunta(Class perguntaClasse) {
    create(perguntaClasse.StructTypeSize, perguntaClasse.data, perguntaClasse.elements, perguntaClasse.auxStruct, perguntaClasse.fieldsNumber);
}

void listarTodasPerguntas(Class perguntaClass) {
    fullList(perguntaClass.data, perguntaClass.StructTypeSize, (*perguntaClass.elements), perguntaClass.auxStruct, perguntaClass.fieldsNumber);

}

void filtrarPerguntas(Class perguntaClass, int *keys, int keysNumber,int *fields,int fieldsNumber) {
    parsedList(perguntaClass.data, perguntaClass.StructTypeSize, perguntaClass.auxStruct, keys, keysNumber, fields, fieldsNumber);
}

void listarPergunta(Class perguntaClass,const unsigned int key){
    
    //int keys[]=key;
    //unsigned int i;
    //for(i=0;){}
    //parsedList(perguntaClass.data, perguntaClass.StructTypeSize, perguntaClass.auxStruct, keys,1,fields,perguntaClass.fieldsNumber);

    
}