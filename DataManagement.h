/* 
 * File:   DataManagement.h
 * Author: ivo
 *
 * Created on 24 de Novembro de 2014, 18:15
 */

#ifndef DATAMANAGEMENT_H
#define	DATAMANAGEMENT_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef int bool;
#define true 1
#define false 0

    typedef unsigned short TypeSize;
#define CHAR_SIZE sizeof(char)
#define FLOAT_SIZE sizeof(float)
#define INT_SIZE sizeof(int)
#define SHORT_SIZE sizeof(short)
#define UNSIGNED_SHORT_SIZE sizeof(unsigned short)
#define UNSIGNED_INT_SIZE sizeof(unsigned int)

    typedef enum {
        INT,
        SHORT,
        UNSIGNED,
        STRING,
        CHAR,
        VOID,
        FLOAT,
        UNSIGNED_SHORT,
        UNSIGNED_INT,
        STRUCT
    } DataType;

    typedef enum {
        CREATE,
        UPDATE,
        LIST,
        DELETE
    } RequestType;

    typedef struct {
        char fieldName[20];
        char alias[25+1];
        DataType type;
        bool required;
        bool unique;
        bool autoIncrement;
        unsigned int step;
        TypeSize sizeBytes;
        unsigned int maxSize;
        void *substruct;
    } FieldAux;

    typedef struct {
        void (*listRegistry)(void *, FieldAux *, unsigned);
        void (*fullList)(void *, const unsigned short, const unsigned int, FieldAux *, const unsigned int);
        void (*parsedList)(void *, const unsigned short, FieldAux *, int *, unsigned, int *, unsigned);
    } List;

    typedef struct {
        void(*fullRead)(RequestType, const unsigned short, void *, const unsigned int, FieldAux *, const unsigned int);
        void(*parsedRead)(RequestType, void *, FieldAux *, int *, unsigned, int *, unsigned);
        void(*readRegistry)(RequestType, void *, FieldAux *, unsigned);

    } Read;

    typedef struct {
        void (*create)(void *, int *, FieldAux *, const unsigned int);
        Read read;
        void (*update)();
        void (*delete)();
        List list;
    } crud;
    
    //Print interface
    void printString(const void *s);
    void printInt(const void *i);
    void printUnsignedInt(const void * ui);
    void printFloat(const void * f);
    void print(const DataType type, const void *const val);
    
    //List interface
    void listRegistry(void * reg, FieldAux *aux, unsigned field);
    void fullList(void *list, const unsigned short stuctTypeSize, const unsigned int listSize, FieldAux *aux, const unsigned int fieldsNumber);
    void parsedList(void *list, const unsigned short stuctTypeSize, FieldAux *aux, int *elements, unsigned elementsNumber, int *fields, unsigned fieldsNumber);
    
    //Create interface
    void create(const unsigned short stuctTypeSize, void * list, int *contador, FieldAux *aux, const unsigned int fieldsNumber);
    
    //Read interface
    //void read();
    void parsedRead(RequestType rtype, const unsigned short stuctTypeSize, void *list, FieldAux *aux, int *elements, unsigned elementsNumber, int *fields, unsigned fieldsNumber);
    void fullRead(RequestType rType, const unsigned short stuctTypeSize, void * list, const unsigned int element, FieldAux *aux, const unsigned int fieldsNumber);
    
    //Update interface
    void update();
    
    //Delete interface
    void delete();
    





#ifdef	__cplusplus
}
#endif

#endif	/* DATAMANAGEMENT_H */

