/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Calmaria.h
 * Author: Pedro
 *
 * Created on 31 de Outubro de 2018, 16:31
 */

#ifndef CALMARIA_H
#define CALMARIA_H

using namespace std;

#include "Evento.h"

class Calmaria:public Evento {
    int x,y;
    char letra;
    int conta;
    int limconta;
public:
    Calmaria(int x,int y);
    virtual ~Calmaria();
    
    int getx() const;
    int gety() const;
    char getLetra() const;
    void inConta() ;
    void atua(Navio * n,User & u);
    int getConta() const;
    int getLim() const;

    Evento * duplica()const override;
    //string getAsString()const override;
};

#endif /* CALMARIA_H */

