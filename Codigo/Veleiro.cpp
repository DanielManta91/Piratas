/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Veleiro.cpp
 * Author: Pedro
 * 
 * Created on 31 de Outubro de 2018, 16:29
 */

#include "Veleiro.h"
#include "Mapa.h"
#include <iostream>
#include <sstream>

Veleiro::Veleiro():Navio(200,20,2,40,'V') {
    peixe=0;
    limpeixe=40;
}

Veleiro::~Veleiro() {
}

Navio * Veleiro::duplica()const {
    return new Veleiro(*this);
}

int Veleiro::getPeixe() const{
    return peixe;
}

void Veleiro::setPeixe(Mapa * mapa){

    if(mapa->pesqPeixe(getx(),gety())==true){
        peixe++;
        if(peixe>limpeixe)
            peixe=limpeixe;
        mapa->setPeixe(getx(),gety());
    }
}

string Veleiro::getAsString() const{
    ostringstream oss;
    oss<<Navio::getAsString()<<"\n"<<peixe<<endl;
    return oss.str();
}