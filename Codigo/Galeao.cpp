/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Galeao.cpp
 * Author: Pedro
 * 
 * Created on 31 de Outubro de 2018, 16:29
 */

#include "Galeao.h"

Galeao::Galeao() : Navio(400,40,1,70,'G') {
}

Galeao::~Galeao() {
}

Navio * Galeao::duplica()const {
    return new Galeao(*this);
}

string Galeao::getAsString() const{
    ostringstream oss;
    oss<<Navio::getAsString()<<endl;
    return oss.str();
}

/*Galeao::moveNavio(Mapa* mapa, int dir, User u){
    
}*/