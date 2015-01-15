/* 
 * File:   Resposta.h
 * Author: joao
 *
 * Created on January 14, 2015, 1:54 PM
 */
#include "DataManagement.h"

#ifndef RESPOSTA_H
#define	RESPOSTA_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct {
        unsigned int id_resposta;
        unsigned int id_pergunta;
        char resposta[LONG_STRING];
    } Resposta;

    enum CamposResposta {
        ID_RESPOSTA,
        ID_PERGUNTA,
        RESPOSTA
    };


#ifdef	__cplusplus
}
#endif

#endif	/* RESPOSTA_H */

