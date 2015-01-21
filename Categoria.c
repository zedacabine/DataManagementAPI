#include "DataManagement.h"
#include "Categoria.h"
#include <string.h>

void guardarCategorias(Class *categoriaClass) {
    char NomeFicheiro[SHORT_STRING];
    strcpy(NomeFicheiro, "categorias.txt");
    writeFile(NomeFicheiro,categoriaClass);
}

void listarCategorias(Class *categoriaClass) {
    fullList(categoriaClass->data, categoriaClass->StructTypeSize, (*categoriaClass->elements), categoriaClass->auxStruct, categoriaClass->fieldsNumber);

}

void listarCategoria(Class *categoriaClass, const unsigned int chave) {
    singleList(categoriaClass, chave);
}

void filtrarCategorias(Class *categoriaClass, int *chaves, int numeroChaves, int *campos, int numeroCampos) {
    parsedList(categoriaClass->data, categoriaClass->StructTypeSize, categoriaClass->auxStruct, chaves, numeroChaves, campos, numeroCampos);
}

void filtrarCategoria(Class *categoriaClass, int chave, int *campos, int numeroCampos) {
    singleParsedList(categoriaClass, chave, campos, numeroCampos);
}

void inserirCategoria(Class *categoriaClass) {
    create(categoriaClass->StructTypeSize, categoriaClass->data, categoriaClass->elements, categoriaClass->auxStruct, categoriaClass->fieldsNumber);
    guardarCategorias(categoriaClass);

}

void filtrarEditarCategoria(Class *categoriaClass, const unsigned int chave, const unsigned int *campos, const unsigned int numeroCampos) {
    singleParsedRead(UPDATE, categoriaClass->StructTypeSize, categoriaClass->data, categoriaClass->auxStruct, chave, campos, numeroCampos);
    guardarCategorias(categoriaClass);

}

void editarCategoria(Class *categoriaClass, const unsigned int chave) {
    fullRead(UPDATE, categoriaClass->StructTypeSize, categoriaClass->data, chave, categoriaClass->auxStruct, categoriaClass->fieldsNumber);
    guardarCategorias(categoriaClass);
    
}

void listar_editar_categorias(Class *categoriaClass) {
    listarCategorias(categoriaClass);
    puts("Escolha a categoria que quer editar");
    unsigned int categoriaID;
    readInt(&categoriaID);
    Categoria *categoria;
    categoria = categoriaClass->data;
    if (categoriaID > categoria[0].id_categoria && categoriaID < categoria[*(categoriaClass->elements) - 1].id_categoria) {
        editarCategoria(categoriaClass, categoriaID - 1);
    }
}

void editarCategorias(Class *categoriaClass, const unsigned int *chaves, const unsigned numeroChaves) {
    unsigned int i;
    for (i = 0; i < numeroChaves; i++) {
        fullRead(UPDATE, categoriaClass->StructTypeSize, categoriaClass->data, chaves[i], categoriaClass->auxStruct, categoriaClass->fieldsNumber);
    }
    guardarCategorias(categoriaClass);

}

void pesquisarCategorias(Class *categoriaClass, const unsigned int campo, void *valorPesquisar, unsigned int *numeroResultados, char *sinal) {
    FieldAux *aux = categoriaClass->auxStruct;
    aux[campo].type;
    search(campo, valorPesquisar, categoriaClass->data, categoriaClass->auxStruct, (*categoriaClass->elements), categoriaClass->StructTypeSize, aux[campo].type, numeroResultados, sinal);

}

