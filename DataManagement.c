#include "DataManagement.h"
#include <stdio.h>

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


void getAtributeValue(void * structElement, FieldAux *aux, const unsigned int atributeNumber, void * storage) {

    unsigned i;
    for (i = 0; i < atributeNumber; ++i) {
        structElement = structElement + aux[i].sizeBytes;
    }
    DataType type = aux[i].type;
    if (type == STRUCT) {
    }
    printString(aux[i].alias);
//    get(type, structElement, *storage);

};
 


void printString(const void *s) {
    char *val = (char *) s;
    puts(val);
}

/*
 * Imprime um inteiro
 */
void printInt(const void *i) {
    int *val = (int *) i;
    printf("%d", *val);
    puts("");
}

void printUnsignedInt(const void * ui) {
    unsigned int *val = (unsigned int *) ui;
    printf("%ui", *val);
    puts("");
}

void printFloat(const void * f) {
    float *val = (float *) f;
    printf("%f", *val);
    puts("");
}

/*
 * @brief Imprime qualquer tipo de dados, recebe um tipo de dados e uma variável como parametro
 * Exemplo:
 * @code
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
void fullList(void *list, const unsigned short stuctTypeSize, const unsigned int listSize, FieldAux *aux, const unsigned int fieldsNumber) {
    unsigned int i = 0, j = 0;
    for (i = 0; i < listSize; i++) {
        for (j = 0; j < fieldsNumber; j++) {
            listRegistry(list + (stuctTypeSize * i), aux, j);
        }
        puts("---------------------------------------------");
    }
}

void parsedList(void *list, const unsigned short stuctTypeSize, FieldAux *aux, int *elements, unsigned elementsNumber, int *fields, unsigned fieldsNumber) {
    unsigned int i = 0, j = 0;
    for (i = 0; i < elementsNumber; i++) {
        for (j = 0; j < fieldsNumber; j++) {
            listRegistry(list + (stuctTypeSize * elements[i]), aux, fields[j]);
        }
        puts("---------------------------------------------");
    }
}

void readString(void * field, const unsigned int maxSize) {
    scanf("%[^\n]s", field);
    while (getchar() != '\n');

};

void readInt(void * field) {
    scanf("%d", field);
};

void readFloat(void * field) {
    scanf("%f", field);
};

void readChar(void * field) {
    scanf("%c", field);
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

void parsedRead(RequestType rtype, const unsigned short stuctTypeSize, void *list, FieldAux *aux, int *elements, unsigned elementsNumber, int *fields, unsigned fieldsNumber) {

    unsigned int i = 0, j = 0;
    for (i = 0; i < elementsNumber; i++) {
        for (j = 0; j < fieldsNumber; j++) {
            readRegistry(rtype, list + (stuctTypeSize * elements[i]), aux, fields[j]);
        }
        puts("---------------------------------------------");
    }

}

void fullRead(RequestType rType, const unsigned short stuctTypeSize, void * list, const unsigned int element, FieldAux *aux, const unsigned int fieldsNumber) {
    unsigned int j = 0;
    for (j = 0; j < fieldsNumber; j++) {
        readRegistry(rType, list + (stuctTypeSize * element), aux, j);
    }
    puts("---------------------------------------------");
}

void create(const unsigned short stuctTypeSize, void * list, int *contador, FieldAux *aux, const unsigned int fieldsNumber) {
    fullRead(CREATE, stuctTypeSize, list, (*contador), aux, fieldsNumber);
    (*contador)++;

}

void update() {
};

void delete() {
};
