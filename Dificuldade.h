/* 
 * File:   Dificuldade.h
 * Author: joao
 *
 * Created on January 14, 2015, 2:07 PM
 */
#include "DataManagement.h"

#ifndef DIFICULDADE_H
#define	DIFICULDADE_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct {
        unsigned int id_dificuldade;
        char dificuldade[SHORT_STRING];
        unsigned int pontuacao_dificuldade;
    } Dificuldade;

    enum CamposDificuldade {
        ID_DIFICULDADE,
        DIFICULDADE,
        PONTUACAO_DIFICULDADE
    };


#ifdef	__cplusplus
}
#endif

#endif	/* DIFICULDADE_H */

