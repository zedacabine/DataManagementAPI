#include "DataManagement.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>


/**
 * 
 * @param s
 * @return 
 */
char *castString(void *s) {
    char *val = (char *) s;
    return val;
}

/**
 * 
 * @param i
 * @return 
 */
int castInt(void *i) {
    return *(int*) i;
}

/**
 * 
 * @param f
 * @return 
 */
int castFloat(void *f) {
    return *(float*) f;
}

/**
 * 
 * @param i
 * @param storage
 */
void getInt(void *i, void *storage) {
    int *val = (int *) i;
    int *s = (int*) storage;
    *s = *val;

};

/**
 * 
 * @param s
 * @param storage
 */
void getString(void *s, void *storage) {
    char *val = (char *) s;
    char *st = (char*) storage;
    *st = *val;
};

/**
 * 
 * @param f
 * @param storage
 */
void getFloat(void *f, void *storage) {
    float *val = (float *) f;
    float *s = (float*) storage;
    *s = *val;
};

/**
 * 
 * @param type
 * @param reg
 * @param storage
 */
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

/**
 * 
 * @param s
 */
void printString(const void *s) {
    puts(castString(s));
}

/**
 * 
 * @param i
 */
void printInt(const void * i) {
    printf("%d", castInt(i));
    puts("");
}

/**
 * 
 * @param ui
 */
void printUnsignedInt(const void * ui) {
    unsigned int *val = (unsigned int *) ui;
    printf("%ui", *val);
    puts("");
}

/**
 * 
 * @param f
 */
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

int searchSigle();

/**
 * 
 * @param string_one
 * @param string_two
 * @return 
 */
int compareStrings(void *string_one, void *string_two) {
    string_one = castString(string_one);
    string_two = castString(string_two);
    if (strcmp(string_one, string_two) == 0) return true;
    else return false;
}

/**
 * 
 * @param type_one
 * @param value_one
 * @param type_two
 * @param value_two
 * @return 
 */
bool generalCompare(DataType type_one, void *value_one, DataType type_two, void *value_two, char *signal) {
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
    char cmpSignal[2 + 1];
    strcpy(cmpSignal, "==");
    if (compareStrings(signal, cmpSignal) == true) {
        //TODO nao fazer cast aqui
        if (*(int*) value_one == *(int*) value_two) return true;
        else return false;
    }
    strcpy(cmpSignal, ">");
    if (compareStrings(signal, cmpSignal) == true) {
        //TODO nao fazer cast aqui
        if (*(int*) value_one > *(int*) value_two) return true;
        else return false;
    }
    strcpy(cmpSignal, "<");
    if (compareStrings(signal, cmpSignal) == true) {
        //TODO nao fazer cast aqui
        if (*(int*) value_one < *(int*) value_two) return true;
        else return false;
    }
    strcpy(cmpSignal, ">=");
    if (compareStrings(signal, cmpSignal) == true) {
        //TODO nao fazer cast aqui
        if (*(int*) value_one >= *(int*) value_two) return true;
        else return false;
    }
    strcpy(cmpSignal, "<=");
    if (compareStrings(signal, cmpSignal) == true) {
        //TODO nao fazer cast aqui
        if (*(int*) value_one <= *(int*) value_two) return true;
        else return false;
    }
    strcpy(cmpSignal, "!=");
    if (compareStrings(signal, cmpSignal) == true) {
        //TODO nao fazer cast aqui
        if (*(int*) value_one != *(int*) value_two) return true;
        else return false;
    }


}

/**
 * 
 * @param varType
 * @param varValue
 * @param toCompareType
 * @param toCompareValue
 * @return 
 */
bool compare(DataType varType, void* varValue, DataType toCompareType, void * toCompareValue, char *signal) {
    unsigned int toReturn = false;
    if (varType == STRING && toCompareType == STRING) {
        toReturn = compareStrings(varValue, toCompareValue);
    } else {
        if (generalCompare(varType, varValue, toCompareType, toCompareValue, signal) == true) toReturn = true;
        else toReturn = false;
    }
    return toReturn;
}

/**
 * 
 * @param field
 * @param searchValue
 * @param list
 * @param aux
 * @param elementsNumber
 * @param structTypeSize
 * @param searchValueType
 * @return 
 */
int * search(const unsigned int field, void *searchValue, void * list, FieldAux *aux, const unsigned int elementsNumber, const unsigned int structTypeSize, DataType searchValueType, unsigned int *resultCounter, char *signal) {
    unsigned int i = 0, j = 0;
    *resultCounter = 0;
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
        unsigned int result = compare(type, &atributeValue, searchValueType, searchValue, signal);
        if (result == true) {
            resultKeys[*resultCounter] = i;
            (*resultCounter)++;
        }
    }
    for (j = *resultCounter; j < MAX_RESULTS; j++) {
        resultKeys[j] = NO_VALUE;
    }
    return resultKeys;
};

/**
 * 
 * @param class
 * @param key
 * @param fields
 * @param fieldsNumber
 */
void singleParsedList(Class class, const unsigned int key, int *fields, unsigned fieldsNumber) {

    int keys[] = {key};
    parsedList(class.data, class.StructTypeSize, class.auxStruct, keys, 1, fields, fieldsNumber);
}

/**
 * 
 * @param reg
 * @param aux
 * @param field
 */
void listRegistry(void * reg, FieldAux *aux, unsigned field) {
    unsigned i, j;
    for (i = 0; i < field; ++i) {
        reg = reg + aux[i].sizeBytes;
    }
    DataType type = aux[i].type;
    if (type != STRUCT) {
        if (aux[i].foreignKey == true) {
            unsigned int resultNumber;
            char signal[2 + 1];
            strcpy(signal, "==");
            int *result;
            result = search(aux[i].parentPrimaryKey, reg, aux[i].parentClass->data, aux[i].parentClass->auxStruct, *(aux[i].parentClass->elements), aux[i].parentClass->StructTypeSize, aux[i].type, &resultNumber, signal);
            //listRegistry(reg,aux[i].parentClass->auxStruct,aux[i].parentClass->aliasField);
            if (*(result + 0) != NO_VALUE) {
                int field[1];
                field[0] = aux[i].parentClass->aliasField;
                parsedList(aux[i].parentClass->data, aux[i].parentClass->StructTypeSize, aux[i].parentClass->auxStruct, result, resultNumber, field, 1);
                //?? nao da nao sei porque
                //singleParsedList(aux[i].parentClass,*(result + 0),field,1);
            } else {
                FieldAux *parentAux;
                parentAux = aux[i].parentClass->auxStruct;
                printf("No value found on Parent class %s primary key field %s \n", aux[i].parentClass->name, parentAux[aux[i].parentPrimaryKey]);
            }
        } else if (aux[i].foreignKey != true) {
            if (reg != NULL) {
                print(type, reg);
            } else puts("No Value");
        }
        puts("");

    }
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
        puts("---------------------------------------------");
        for (j = 0; j < fieldsNumber; j++) {

            if (aux[j].foreignKey != true) {
                printString(aux[j].alias);
            }
            listRegistry(list + (structTypeSize * i), aux, j);
        }
        puts("---------------------------------------------");
    }
}

/**
 * 
 * @param list
 * @param structTypeSize
 * @param aux
 * @param elements
 * @param elementsNumber
 * @param fields
 * @param fieldsNumber
 */
void parsedList(void *list, const unsigned short structTypeSize, FieldAux *aux, int *elements, unsigned elementsNumber, int *fields, unsigned fieldsNumber) {
    unsigned int i = 0, j = 0;
    for (i = 0; i < elementsNumber; i++) {
        for (j = 0; j < fieldsNumber; j++) {
            if (aux[j].foreignKey != true) {
                printString(aux[j].alias);
            }
            listRegistry(list + (structTypeSize * elements[i]), aux, fields[j]);
        }
        //puts("---------------------------------------------");
    }
}

/**
 * 
 * @param perguntaClass
 * @param key
 */
void singleList(Class *class, const unsigned int key) {

    int keys[] = {key};
    int fields[class->fieldsNumber];
    unsigned int i;
    for (i = 0; i < class->fieldsNumber; i++) {
        fields[i] = i;
    }
    parsedList(class->data, class->StructTypeSize, class->auxStruct, keys, 1, fields, class->fieldsNumber);
}

/**
 * 
 * @param field
 * @param maxSize
 */
void readString(void * field, const unsigned int maxSize) {
    scanf("%[^\n]s", castString(field));
    while (getchar() != '\n');

};

/**
 * 
 * @param field
 */
void readInt(void * field) {
    scanf("%d", field);
    while (getchar() != '\n');
};

/**
 * 
 * @param field
 */
void readFloat(void * field) {
    scanf("%f", field);
    while (getchar() != '\n');
};

/**
 * 
 * @param field
 */
void readChar(void * field) {
    scanf("%c", field);
    while (getchar() != '\n');
}

/**
 * 
 * @param type
 * @param field
 * @param maxSize
 */
void read(DataType type, void * field, const unsigned int maxSize) {
    if (type == STRING) {
        readString(field, maxSize);
    } else if (type == INT) {
        readInt(field);
    } else if (type == FLOAT) {
        readFloat(field);
    }
}

bool checkUniqueField(const unsigned int field, void *searchValue, void * list, FieldAux *aux, const unsigned int elementsNumber, const unsigned int structTypeSize, DataType searchValueType) {
    if (aux[field].unique) {
        unsigned int resultCounter;
        char signal[2 + 1];
        strcpy(signal, "==");
        search(field, searchValue, list, aux, elementsNumber, structTypeSize, searchValueType, &resultCounter, signal);
        if (resultCounter == 0) return false;
        else return true;

    } else {
        puts("Field isn't unique");
    }
}

/**
 * 
 * @param rtype
 * @param reg
 * @param aux
 * @param field
 */
void readRegistry(RequestType rtype, void * reg, FieldAux *aux, unsigned field) {
    unsigned i, j;
    for (i = 0; i < field; ++i) {
        reg = reg + aux[i].sizeBytes;
    }
    DataType type = aux[i].type;
    if (aux[i].type != STRUCT) {
        if (aux[i].foreignKey == true) {
            printString(aux[i].parentClass->name);
            puts("1-List / 2-New");
            unsigned int op;
            readInt(&op);
            if (op == 1) {
                puts("");
                puts("__________________________________________________________________________");
                puts("__________________________________________________________________________");
                // search(i,reg,aux[i].parentClass->data,aux[i].parentClass->auxStruct)
                // parsedList(aux[i].parentClass->data,aux[1].parentClass->StructTypeSize,aux[i].parentClass->auxStruct,,aux[i].parentClass->elements,aux[1].parentClass->fieldsNumber)
                fullList(aux[i].parentClass->data, aux[i].parentClass->StructTypeSize, *(aux[i].parentClass->elements), aux[i].parentClass->auxStruct, aux[i].parentClass->fieldsNumber);
                puts("__________________________________________________________________________");
                puts("__________________________________________________________________________");
                puts("");
            } else if (op == 2) {

                fullRead(CREATE, aux[i].parentClass->StructTypeSize, aux[i].parentClass->data, *(aux[i].parentClass->elements), aux[i].parentClass->auxStruct, aux[i].parentClass->fieldsNumber);
            }

        }
        if (aux[i].required == true) {
            do {
                printString(aux[i].alias);
                read(type, reg, aux[i].maxSize);
                puts("");
            } while (reg == NULL);

        } else {
            printString(aux[i].alias);
            read(type, reg, aux[i].maxSize);
            puts("");
        }
    }
}

/**
 * 
 * @param rtype
 * @param structTypeSize
 * @param list
 * @param aux
 * @param elements
 * @param elementsNumber
 * @param fields
 * @param fieldsNumber
 */


void parsedRead(RequestType rtype, const unsigned short structTypeSize, void *list, FieldAux *aux, int *elements, unsigned elementsNumber, int *fields, unsigned fieldsNumber) {

    unsigned int i = 0, j = 0;
    for (i = 0; i < elementsNumber; i++) {
        for (j = 0; j < fieldsNumber; j++) {
            readRegistry(rtype, list + (structTypeSize * elements[i]), aux, fields[j]);
        }
        puts("---------------------------------------------");
    }

}

void singleParsedRead(RequestType rtype, const unsigned short structTypeSize, void *list, FieldAux *aux, const unsigned int element, int *fields, unsigned fieldsNumber) {
    int elements[] = {element};
    parsedList(list, structTypeSize, aux, elements, 1, fields, fieldsNumber);
}

/**
 * 
 * @param rType
 * @param structTypeSize
 * @param list
 * @param element
 * @param aux
 * @param fieldsNumber
 */
void fullRead(RequestType rType, const unsigned short structTypeSize, void * list, const unsigned int element, FieldAux *aux, const unsigned int fieldsNumber) {
    unsigned int j = 0;
    for (j = 0; j < fieldsNumber; j++) {
        readRegistry(rType, list + (structTypeSize * element), aux, j);
    }
    puts("---------------------------------------------");
}

/**
 * 
 * @param structTypeSize
 * @param list
 * @param contador
 * @param aux
 * @param fieldsNumber
 */
void create(const unsigned short structTypeSize, void * list, int *contador, FieldAux *aux, const unsigned int fieldsNumber) {
    fullRead(CREATE, structTypeSize, list, (*contador), aux, fieldsNumber);
    (*contador)++;

}

void update() {
};

void delete() {
};

/**
 * 
 * @param list
 * @param structTypeSize
 * @param elementNumber
 * @param storage
 */
void elementMemoryAdress(void * list, const unsigned int structTypeSize, const unsigned int elementNumber, void *storage) {
    storage = list + (structTypeSize * elementNumber);
}




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

/**
 * 
 * @param vet
 * @param chave
 * @param Tam
 * @return 
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

int * dele(int *counter, int *array, const unsigned int element) {
    int j;
    for (j = element; j<*counter - 1; j++) {
        array[j] = array[j + 1];
        //printf("%d", array[j]);
    }
    (*counter)--;
    return array;
}

int * randomize(int *array, size_t n, int limit) {
    if (n > 1) {
        size_t i;
        for (i = 0; i < n; i++) {
            srand(time(0));
            size_t j = i + rand() / (RAND_MAX / (limit - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
    return array;
}




