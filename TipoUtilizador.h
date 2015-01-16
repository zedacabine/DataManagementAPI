/* 
 * File:   TipoUtilizador.h
 * Author: joao
 *
 * Created on January 14, 2015, 2:04 PM
 */
#include "DataManagement.h"

#ifndef TIPOUTILIZADOR_H
#define	TIPOUTILIZADOR_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct {
        unsigned int id_utilizador;
        char tipo_utilizador;
    } TipoUtilizador;

    enum CamposTipoUtilizador {
        ID_UTILIZADOR,
        TIPO_UTILIZADOR
    };


#ifdef	__cplusplus
}
#endif

#endif	/* TIPOUTILIZADOR_H */
