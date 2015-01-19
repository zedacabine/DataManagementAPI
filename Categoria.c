#include "DataManagement.h"
#include "Categoria.h"

void inserirCategoria(Class categoriaClass) {

    create(categoriaClass.StructTypeSize, categoriaClass.data, categoriaClass.elements, categoriaClass.auxStruct, categoriaClass.fieldsNumber);
}

void listarCategorias(Class categoriaClass) {

    fullList(categoriaClass.data, categoriaClass.StructTypeSize, (*categoriaClass.elements), categoriaClass.auxStruct, categoriaClass.fieldsNumber);

}

void listarCategoria(Class categoriaClass, const unsigned int chave) {

    singleList(categoriaClass, chave);
}

void filtrarCategorias(Class categoriaClass, int *chaves, int numeroChaves, int *campos, int numeroCampos) {

    parsedList(categoriaClass.data, categoriaClass.StructTypeSize, categoriaClass.auxStruct, chaves, numeroChaves, campos, numeroCampos);
}

void filtrarCategoria(Class categoriaClass, int chave, int *campos, int numeroCampos) {

    singleParsedList(categoriaClass, chave, campos, numeroCampos);
}

void pesquisarCategorias(Class categoriaClass,const unsigned int campo,void *valorPesquisar,unsigned int *numeroResultados,char *sinal){
    FieldAux *aux = categoriaClass.auxStruct;
    aux[campo].type;
    search(campo, valorPesquisar,categoriaClass.data,categoriaClass.auxStruct,(*categoriaClass.elements),categoriaClass.StructTypeSize,aux[campo].type,numeroResultados,sinal) ;

    }

