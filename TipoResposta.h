/* 
 * File:   TipoResposta.h
 * Author: joao
 *
 * Created on January 14, 2015, 2:00 PM
 */
#include "DataManagement.h"
#ifndef TIPORESPOSTA_H
#define	TIPORESPOSTA_H

#ifdef	__cplusplus
extern "C" {
#endif

#define MAX_TIPO_RESPOSTA 100
    typedef struct {
        unsigned int id_tipo_resposta;
        char tipo_resposta[SHORT_STRING];
        unsigned int id_resposta;
    } TipoResposta;

    enum CamposTipoResposta {
        ID_TIPO_RESPOSTA,
        TIPO_RESPOSTA,
        ID_RESPOSTA_TIPO_REPOSTA
    };



#ifdef	__cplusplus
}
#endif

#endif	/* TIPORESPOSTA_H */

