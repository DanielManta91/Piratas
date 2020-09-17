/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Galeao.h
 * Author: Pedro
 *
 * Created on 31 de Outubro de 2018, 16:29
 */

#ifndef GALEAO_H
#define GALEAO_H

using namespace std;

#include "Navio.h"
class Mapa;
class User;
class Galeao:public Navio {

public:
    Galeao();
    virtual ~Galeao();
//    virtual bool moveNavio(Mapa * mapa,int dir,User u);
    
    Navio * duplica()const override;
    string getAsString()const override;

};

#endif /* GALEAO_H */

