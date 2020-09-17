/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Especial.cpp
 * Author: Pedro
 * 
 * Created on 31 de Outubro de 2018, 16:30
 */

#include "Especial.h"

Especial::Especial():Navio(100,10,5,20,'C') {           //CRIA CARAVELA

}

Especial::~Especial() {
}

Navio * Especial::duplica()const {
    return new Especial(*this);
}

string Especial::getAsString() const{
    ostringstream oss;
    oss<<Navio::getAsString()<<endl;
    return oss.str();
}