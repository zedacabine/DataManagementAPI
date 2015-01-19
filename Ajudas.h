/* 
 * File:   Ajudas.h
 * Author: joao
 *
 * Created on January 14, 2015, 2:05 PM
 */
#include "DataManagement.h"

#ifndef AJUDAS_H
#define	AJUDAS_H

#ifdef	__cplusplus
extern "C" {
#endif

#define MAX_AJUDA 4
    typedef struct {
        unsigned int id_ajuda;
        char ajudas[MEDIUM_STRING];
    } Ajuda;

    enum CamposAjudas {
        ID_AJUDA,
        AJUDA
    };


#ifdef	__cplusplus
}
#endif

#endif	/* AJUDAS_H */

