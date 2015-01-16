/* 
 * File:   Pergunta.h
 * Author: joao
 *
 * Created on January 14, 2015, 1:52 PM
 */
#include "DataManagement.h"

#ifndef PERGUNTA_H
#define	PERGUNTA_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct {
        unsigned int id_pergunta;
        unsigned int id_categoria;
        unsigned int id_dificuldade;
        unsigned int id_resposta_certa;
        char pergunta[LONG_STRING];
    } Pergunta;

    enum CamposPergunta {
        ID_PERGUNTA,
        ID_CATEGORIA,
        ID_DIFICULDADE,
        ID_RESPOSTA_CERTA,
        PERGUNTA
    };
    
    void inserirPergunta(Class perguntaClasse);
    
    
    

    

#ifdef	__cplusplus
}
#endif

#endif	/* PERGUNTA_H */
