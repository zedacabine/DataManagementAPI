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

    typedef struct {
        unsigned int id_tipo_resposta;
        char tipo_resposta[SHORT_STRING];
        unsigned int id_resposta;
    } TipoResposta;

    enum CamposTipoResposta {
        ID_TIPO_RESPOSTA,
        TIPO_RESPOSTA,
        ID_RESPOSTA
    };



#ifdef	__cplusplus
}
#endif

#endif	/* TIPORESPOSTA_H */

