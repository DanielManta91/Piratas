/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Motim.h
 * Author: Pedro
 *
 * Created on 31 de Outubro de 2018, 16:33
 */

#ifndef MOTIM_H
#define MOTIM_H

using namespace std;

#include "Evento.h"


class Motim:public Evento {
    Navio * n=nullptr;
    int conta;
    int limconta;
    char tipo;
public:
    Motim(Navio * n);
    virtual ~Motim();

    Evento * duplica()const override;
    
    void inConta() ;
    void atua(User& u);
    int getConta() const;
    int getLim() const;
    char getTipo() const;
    void trocaPirate();

};

#endif /* MOTIM_H */

