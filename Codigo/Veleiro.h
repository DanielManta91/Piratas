/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Veleiro.h
 * Author: Pedro
 *
 * Created on 31 de Outubro de 2018, 16:29
 */

#ifndef VELEIRO_H
#define VELEIRO_H

using namespace std;

#include "Navio.h"

class Veleiro:public Navio {
    int peixe;
    int limpeixe;
public:
    Veleiro();
    virtual ~Veleiro();
    
    void setPeixe(Mapa * mapa) override;
    int getPeixe() const override;
    
    string getAsString()const override;
    
    Navio * duplica()const override;
};

#endif /* VELEIRO_H */

