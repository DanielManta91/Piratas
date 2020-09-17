/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tempestade.h
 * Author: Pedro
 *
 * Created on 31 de Outubro de 2018, 16:31
 */

#ifndef TEMPESTADE_H
#define TEMPESTADE_H
using namespace std;
#include "Evento.h"

class Tempestade:public Evento {
    int x,y;
    char letra;
    int conta;
    int limconta;
public:
    Tempestade(int x1,int y1);
    virtual ~Tempestade();

    Evento * duplica()const override;
    
    int getx() const;
    int gety() const;
    char getLetra() const;
    void inConta() ;
    void atua(Navio * n,User & u);
    int getConta() const;
    int getLim() const;
};

#endif /* TEMPESTADE_H */

