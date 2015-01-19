/* 
 * File:   Jogadas.h
 * Author: joao
 *
 * Created on January 14, 2015, 1:57 PM
 */
#include "DataManagement.h"

#ifndef JOGADAS_H
#define	JOGADAS_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#define MAX_JOGADA 100
    typedef struct {
        unsigned int id_jogada;
        unsigned int id_utilizador;
        unsigned int id_jogo;
        unsigned int tempo;
        unsigned int id_pergunta;
        unsigned int id_resposta;
        unsigned int pontuacao;
    } Jogada;

    enum CamposJogadas {
        ID_JOGADA,
        ID_UTILIZADOR_JOGADAS,
        ID_JOGO_JOGADAS,
        TEMPO,
        ID_PERGUNTA_JOGADAS,
        ID_RESPOSTA_JOGADAS,
        PONTUACAO
    };


#ifdef	__cplusplus
}
#endif

#endif	/* JOGADAS_H */

