/* 
 * File:   Jogo.h
 * Author: joao
 *
 * Created on January 14, 2015, 1:56 PM
 */
#include "DataManagement.h"

#ifndef JOGO_H
#define	JOGO_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct {
        unsigned int id_jogo;
        unsigned int id_utilizador;
    } Jogo;

    enum CamposJogo {
        ID_JOGO,
        ID_UTILIZADOR_JOGO
    };


#ifdef	__cplusplus
}
#endif

#endif	/* JOGO_H */

