/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fragata.cpp
 * Author: Pedro
 * 
 * Created on 31 de Outubro de 2018, 16:30
 */

#include "Fragata.h"

Fragata::Fragata():Navio(500,50,2,0,'B') {
}

Fragata::~Fragata() {
}

Navio * Fragata::duplica()const {
    return new Fragata(*this);
}

string Fragata::getAsString() const{
    ostringstream oss;
    oss<<Navio::getAsString()<<endl;
    return oss.str();
}