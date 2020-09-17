/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fragata.h
 * Author: Pedro
 *
 * Created on 31 de Outubro de 2018, 16:30
 */

#ifndef FRAGATA_H
#define FRAGATA_H

using namespace std;

#include "Navio.h"

class Fragata:public Navio {
public:
    Fragata();

    virtual ~Fragata();
    
    Navio * duplica()const override;

    string getAsString()const override;
};

#endif /* FRAGATA_H */

