/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Celula.h
 * Author: Pedro
 *
 * Created on 14 de Novembro de 2018, 15:42
 */

#ifndef CELULA_H
#define CELULA_H

class Terreno;

class Celula {
    Terreno *t;
public:
    Celula(char c);
//    Celula(const Celula& orig);
    virtual ~Celula();
    Terreno* getTerreno() const;    //Retorna o ponteiro para o Terreno

};

#endif /* CELULA_H */

