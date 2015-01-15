/* 
 * File:   main.c
 * Author: ivo
 *
 * Created on 16 de Outubro de 2014, 10:32
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataManagement.h"
#include "Menu.h"
#include "Pergunta.h"

int main(int argc, char** argv) {

    //menu();

    
    
    FieldAux estructAuxPerguntas[] = {
        {.fieldName = "id_pergunta", .alias = "Numero Pergunta", .sizeBytes = INT_SIZE, .type = INT, .unique = true, .required = true, .autoIncrement = true, .step = 1},
        {.fieldName = "id_categoria", .alias = "Numero Categoria", .sizeBytes = INT_SIZE, .type = INT, .required = true},
        {.fieldName = "id_dificuldade", .alias = "Numero Dificuldade", .sizeBytes = INT_SIZE, .type = INT, .required = true},
        {.fieldName = "id_resposta_certa", .alias = "Numero Resposta Certa", .sizeBytes = INT_SIZE, .type = INT, .required = true},
        {.fieldName = "pergunta", .alias = "Pergunta", .sizeBytes = LONG_STRING, .type = STRING, .required = true}

    };

    Pergunta perguntas[5];
    int contador = 2;


    const unsigned int tamAuxPergunta = (sizeof (estructAuxPerguntas) / sizeof (estructAuxPerguntas[0]));
    printf("%d", tamAuxPergunta);
    const unsigned int tamPerguntas = sizeof (Pergunta);


    //create(tamPerguntas, perguntas, &contador, estructAuxPerguntas, tamAuxPergunta);

    //inserirPergunta(tamPerguntas, perguntas, &contador, estructAuxPerguntas, tamAuxPergunta);
    // fullList(perguntas, sizeof (Pergunta), 2, estructAuxPerguntas, tamAuxPergunta);



    crud CRUD;
    CRUD.create = &create;
    CRUD.update = &update;
    CRUD.delete = &delete;
    CRUD.list.fullList = &fullList;
    CRUD.list.parsedList = &parsedList;
    CRUD.read.fullRead = &fullRead;
    CRUD.read.parsedRead = &parsedRead;


    int x[] = {2, 3, 4};
    int y[] = {PERGUNTA};
    ////////////////                 Ficheiros                      \\\\\\\\\\\\\\

    char nome[20];
    strcpy(nome, "perguntas.txt");
    //writeFile(nome, perguntas, contador);



    FILE *ap_ficheiro;

    Pergunta pergunta[tamAuxPergunta];
    
    ap_ficheiro = fopen(nome, "r+"); // Abre o ficheiro
    if (!ap_ficheiro){ // Se o apontador devolvido for inválido ocorreu um erro na leitura
        printf("\n IMPOSSIVEL ABRIR O FICHEIRO.");
        printf("\n\n ");
    } else {
        contador = fread(perguntas, sizeof (Pergunta), tamAuxPergunta, ap_ficheiro); // Lê a informação do ficheiro e armazena no array
        fclose(ap_ficheiro); // Fecha o ficheiro
        printf("\n O FICHEIRO FOI LIDO COM SUCESSO.\n\n ");
    }



    CRUD.list.fullList(perguntas, sizeof (Pergunta), contador, estructAuxPerguntas, tamAuxPergunta);
    create(sizeof (Pergunta), perguntas, &contador, estructAuxPerguntas, tamAuxPergunta);

    ap_ficheiro = fopen(nome, "a+"); // Abre o ficheiro  em modo de escrita
    if (!ap_ficheiro) {
        printf("\n IMPOSSIVEL ABRIR O FICHEIRO."); // Se o apontador devolvido for inválido ocorreu um erro na leitura
        printf("\n\n ");
    } else {
        fwrite(perguntas, sizeof (Pergunta), contador, ap_ficheiro); // Guarda a informação do array no ficheiro 
        fclose(ap_ficheiro); // Fecha o ficheiro
        printf("\n O FICHEIRO FOI GUARDADO COM SUCESSO.\n\n ");
    }

    

    return 0;
    
    return (EXIT_SUCCESS);
}

  /////////////////////////////////  TESTES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
 //CRUD.list.fullList(perguntas, sizeof (Pergunta), contador, estructAuxPerguntas, tamAuxPergunta);
    
    /* 
    parsedRead(CREATE,sizeof (Pergunta),perguntas,estructAuxPerguntas, x, 3, y, 1);
    fullRead(CREATE, sizeof (Pergunta), perguntas,contador, estructAuxPerguntas, 5);
    parsedList(perguntas, sizeof (Pergunta), estructAuxPerguntas, x, 3, y, 1);
    int * storage;
    getAtributeValue(&perguntas[1],estructAuxPerguntas, 1, &storage);
    create(sizeof(Pergunta), perguntas, &contador, estructAuxPerguntas, 5)
    fullList(perguntas, sizeof (Pergunta), 3, estructAuxPerguntas, 5);
 
    printInt(&contador);
     * 
     *  int *p;
   int i;
   int *j;
   j=1;
   p = search(ID_CATEGORIA, &j, perguntas, estructAuxPerguntas, 2, sizeof (Pergunta));

   for ( i = 0; i < 10; i++ ){
       printf( "%d \n",*(p + i));
   }
     */

