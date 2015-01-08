/* 
 * File:   Genero.h
 * Author: ivo
 *
 * Created on 13 de Novembro de 2014, 11:52
 */

#ifndef GENERO_H
#define	GENERO_H


#ifdef	__cplusplus
extern "C" {
#endif

    const char *generoDescritivo[] = {
        "Feminino",
        "Masculino"
    };

    typedef enum {
        FEMININO,
        MASCULINO
    } Genero;
    
    //Aqui so pode estar o prototipo
    void readGenero(Genero *const genero);
    void escreverGenero(Genero const genero);
    void converterGeneroEmTexto(const Genero genero);    

#ifdef	__cplusplus
}
#endif

#endif	/* GENERO_H */

