/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sereias.h
 * Author: Pedro
 *
 * Created on 31 de Outubro de 2018, 16:31
 */

#ifndef SEREIA_H
#define SEREIA_H

using namespace std;

#include "Evento.h"
#include <iostream>

class Sereia:public Evento {
    Navio * n=nullptr;
    int conta;
    int limconta;
    char tipo;
public:
    Sereia(Navio * n1);
    virtual ~Sereia();
    Evento * duplica()const override;
    
    char getTipo() const;
    void inConta() ;
    void atua();
    int getConta() const;
    int getLim() const;
};

#endif /* SEREIA_H */

