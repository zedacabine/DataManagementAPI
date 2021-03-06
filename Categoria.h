/* 
 * File:   Categoria.h
 * Author: joao
 *
 * Created on January 14, 2015, 1:48 PM
 */
#include "DataManagement.h"

#ifndef CATEGORIA_H
#define	CATEGORIA_H

#ifdef	__cplusplus
extern "C" {
#endif

#define MAX_CATEGORIA 100
    typedef struct {
        unsigned int id_categoria;
        char categoria[SHORT_STRING];
        unsigned int pontuacao_categoria;
    } Categoria;

    enum CamposCategoria {
        ID_CATEGORIA,
        CATEGORIA,
        PONTUACAO_CATEGORIA
    };


#ifdef	__cplusplus
}
#endif

#endif	/* CATEGORIA_H */

