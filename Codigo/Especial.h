/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Especial.h
 * Author: Pedro
 *
 * Created on 31 de Outubro de 2018, 16:30
 */

#ifndef ESPECIAL_H
#define ESPECIAL_H

using namespace std;

#include "Navio.h"

class Especial:public Navio {
public:
    Especial();
    virtual ~Especial();
    string getAsString()const override;
    Navio * duplica()const override;
};

#endif /* ESPECIAL_H */

