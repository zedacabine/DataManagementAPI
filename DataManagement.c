#include "DataManagement.h"
#include <stdio.h>
#include <time.h>

char *castString(void *s) {
    char *val = (char *) s;
    return val;
}

int castInt(void *i) {
    return *(int*) i;
}

int castFloat(void *f) {
    return *(float*) f;
}

void getInt(void *i, void *storage) {
    int *val = (int *) i;
    int *s = (int*) storage;
    *s = *val;

};

void getString(void *s, void *storage) {
    char *val = (char *) s;
    char *st = (char*) storage;
    *st = *val;
};

void getFloat(void *f, void *storage) {
    float *val = (float *) f;
    float *s = (float*) storage;
    *s = *val;
};

void get(DataType type, void *reg, void *storage) {
    if (type == STRING) {
        getString(reg, storage);
    } else if (type == INT) {
        getInt(reg, storage);
    } else if (type == FLOAT) {
        getFloat(reg, storage);
    }
}

/**
 * This method returns to a given pointer the value of a chosen atribute structure element;
 * @param *structElement-Pointer to the element structure;
 * @param *aux-Pointer to the aux structure;
 * @param atributeNumber-Atribute number inside of the structure;
 * @param *storage-Pointer to the variable where de atribute value is going to;
 * 
 */
void getAtributeValue(void * element, FieldAux *aux, const unsigned int atributeNumber, void * storage) {

    unsigned i;
    for (i = 0; i < atributeNumber; ++i) {
        element = element + aux[i].sizeBytes;
    }
    DataType type = aux[i].type;
    if (type == STRUCT) {
    }
    get(type, element, storage);

};

void printString(const void *s) {
    puts(castString(s));
}

/*
 * Imprime um inteiro
 */
void printInt(const void * i) {
    printf("%d", castInt(i));
    puts("");
}

void printUnsignedInt(const void * ui) {
    unsigned int *val = (unsigned int *) ui;
    printf("%ui", *val);
    puts("");
}

void printFloat(const void * f) {
    printf("%f", castFloat(f));
    puts("");
}

/*
 * @brief Imprime qualquer tipo de dados, recebe um tipo de dados e o valor a imprimir como parametros
 * @param type- tipo de dados do valor dado
 * @param *val- endereço de memoria do valor
 * Exemplo:
 * @code
 * int i = 1;
 * print(INT,&i);
 * @endcode
 */
void print(const DataType type, const void *const val) {

    if (type == STRING) {
        printString(val);
    } else if (type == INT) {
        printInt(val);
    } else if (type == UNSIGNED_INT) {
        printUnsignedInt(val);
    } else if (type == FLOAT) {
        printFloat(val);
    }
}

/*
 * Imprime chave -> valor de um campo de uma dada estrutura  
 */
void listRegistry(void * reg, FieldAux *aux, unsigned field) {
    unsigned i;
    for (i = 0; i < field; ++i) {
        reg = reg + aux[i].sizeBytes;
    }
    DataType type = aux[i].type;
    if (type == STRUCT) {
    }
    printString(aux[i].alias);
    print(type, reg);
    puts("");
}

/**
 * This method does a full (full elements + full atributes) list of a given structure
 * @param *list-Pointer to some struct
 * @param structTypeSize-Size of the struct
 * 
 */
void fullList(void *list, const unsigned short structTypeSize, const unsigned int listSize, FieldAux *aux, const unsigned int fieldsNumber) {
    unsigned int i = 0, j = 0;
    for (i = 0; i < listSize; i++) {
        for (j = 0; j < fieldsNumber; j++) {
            listRegistry(list + (structTypeSize * i), aux, j);
        }
        puts("---------------------------------------------");
    }
}

void parsedList(void *list, const unsigned short structTypeSize, FieldAux *aux, int *elements, unsigned elementsNumber, int *fields, unsigned fieldsNumber) {
    unsigned int i = 0, j = 0;
    for (i = 0; i < elementsNumber; i++) {
        for (j = 0; j < fieldsNumber; j++) {
            listRegistry(list + (structTypeSize * elements[i]), aux, fields[j]);
        }
        puts("---------------------------------------------");
    }
}

void readString(void * field, const unsigned int maxSize) {
    scanf("%[^\n]s", castString(field));
    while (getchar() != '\n');

};

void readInt(void * field) {
    scanf("%d", field);
    while (getchar() != '\n');
};

void readFloat(void * field) {
    scanf("%f", field);
    while (getchar() != '\n');
};

void readChar(void * field) {
    scanf("%c", field);
    while (getchar() != '\n');
}

void read(DataType type, void * field, const unsigned int maxSize) {
    if (type == STRING) {
        readString(field, maxSize);
    } else if (type == INT) {
        readInt(field);
    } else if (type == FLOAT) {
        readFloat(field);
    }
}

void readRegistry(RequestType rtype, void * reg, FieldAux *aux, unsigned field) {
    unsigned i;
    for (i = 0; i < field; ++i) {
        reg = reg + aux[i].sizeBytes;
    }
    DataType type = aux[i].type;

    printString(aux[i].alias);
    read(type, reg, aux[i].maxSize);
    puts("");
}

void parsedRead(RequestType rtype, const unsigned short structTypeSize, void *list, FieldAux *aux, int *elements, unsigned elementsNumber, int *fields, unsigned fieldsNumber) {

    unsigned int i = 0, j = 0;
    for (i = 0; i < elementsNumber; i++) {
        for (j = 0; j < fieldsNumber; j++) {
            readRegistry(rtype, list + (structTypeSize * elements[i]), aux, fields[j]);
        }
        puts("---------------------------------------------");
    }

}

void fullRead(RequestType rType, const unsigned short structTypeSize, void * list, const unsigned int element, FieldAux *aux, const unsigned int fieldsNumber) {
    unsigned int j = 0;
    for (j = 0; j < fieldsNumber; j++) {
        readRegistry(rType, list + (structTypeSize * element), aux, j);
    }
    puts("---------------------------------------------");
}

void create(const unsigned short structTypeSize, void * list, int *contador, FieldAux *aux, const unsigned int fieldsNumber) {
    fullRead(CREATE, structTypeSize, list, (*contador), aux, fieldsNumber);
    (*contador)++;

}

void update() {
};

void delete() {
};

void elementMemoryAdress(void * list, const unsigned int structTypeSize, const unsigned int elementNumber, void *storage) {
    storage = list + (structTypeSize * elementNumber);
}

int searchSigle();

int compareStrings(void *string_one, void *string_two) {
    string_one = castString(string_one);
    string_two = castString(string_two);
    if (strcmp(string_one, string_two) == 0) return true;
    else return false;
}

bool generalCompare(DataType type_one, void *value_one, DataType type_two, void *value_two) {
    //TODO nao esta a fazer cast
    if (type_one == INT) {
        *(int*) value_one = castInt(value_one);
        //printf("%d", value_one);
    } else if (type_one == FLOAT) {
        *(float*) value_one = castFloat(&value_one);
    }
    if (type_two == INT) {
        *(int*) value_two = castInt(value_two);
    } else if (type_two == FLOAT) {
        *(float*) value_two = castFloat(value_two);
    }

    //TODO nao fazer cast aqui
    if (*(int*) value_one == *(int*) value_two) return true;
    else return false;

}

bool compare(DataType varType, void* varValue, DataType toCompareType, void * toCompareValue) {
    unsigned int toReturn = false;
    if (varType == STRING && toCompareType == STRING) {
        toReturn = compareStrings(varValue, toCompareValue);
    } else {
        if (generalCompare(varType,varValue, toCompareType, toCompareValue) == true) toReturn = true;
        else toReturn = false;
    }
    return toReturn;
}

int * search(const unsigned int field, void *searchValue, void * list, FieldAux *aux, const unsigned int elementsNumber, const unsigned int structTypeSize, DataType searchValueType) {
    #define MAX_RESULTS 10
    unsigned int i = 0, j = 0, counter = 0;
    void *reg;
    int atributeValue = NULL;
    static int resultKeys[MAX_RESULTS];
    for (i = 0; i < elementsNumber; i++) {
        reg = list + (structTypeSize * i);
        //TODO implementar a função elementMemoryAdress
        getAtributeValue(reg, aux, field, &atributeValue);
        DataType type = aux[field].type;
        //fazer cast para search value
        //TODO cast interface
        unsigned int result = compare(type, &atributeValue, searchValueType, &searchValue);
        if (result == true) {
            resultKeys[counter] = i;
            counter++;
        }
    }
    for (j = counter; j < MAX_RESULTS; j++) {
        resultKeys[j] = NO_VALUE;
    }
    return resultKeys;
};

/*
int ordenar(int inf, int sup){
     int i, j;
     Pergunta temp;

     while(sup > inf)
     {
           i=inf;
           j=sup;
           temp = alunos[inf];

           while(i < j){
                 while(alunos[j].cod_alunos > temp.cod_alunos){
                       j--;
                 }
                 alunos[i] = alunos[j];
                 while(i < j && alunos[i].cod_alunos <= temp.cod_alunos){
                       i++;
                 }
                 alunos[j] = alunos[i];
           }
           alunos[i] = temp;
           ordenar(inf, i - 1);
           inf = i + 1;
     }
}
 */

int PesquisaBinaria(int vet[], int chave, int Tam) {
    int inf = 0; //Limite inferior      (o primeiro elemento do vetor em C é zero          )
    int sup = Tam - 1; //Limite superior    (termina em um número a menos 0 à 9 são 10 numeros )
    int meio;
    while (inf <= sup) {
        meio = (inf + sup) / 2;
        if (chave == vet[meio])
            return meio;
        else if (chave < vet[meio])
            sup = meio - 1;
        else
            inf = meio + 1;
    }
    return -1; // não encontrado
}




