/* 
 * File:   Utilizador.h
 * Author: joao
 *
 * Created on January 14, 2015, 2:02 PM
 */
#include "DataManagement.h"

#ifndef UTILIZADOR_H
#define	UTILIZADOR_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct {
        unsigned int id_utilizador;
        unsigned int id_tipo_utilizador;
        char nome[MEDIUM_STRING];
        char password[SHORT_STRING];
    } Utilizador;

    enum CamposUtilizador {
        ID_UTILIZADOR,
        ID_TIPO_UTILIZADOR_UTILIZADOR,
        NOME,
        PASSWORD
    };

#ifdef	__cplusplus
}
#endif

#endif	/* UTILIZADOR_H */

