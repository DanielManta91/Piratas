/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Escuna.cpp
 * Author: Pedro
 * 
 * Created on 31 de Outubro de 2018, 16:29
 */

#include "Escuna.h"
#include "Mapa.h"
#include <iostream>

Escuna::Escuna() : Navio(100,10,1,20,'E') {
    peixe = 0;
    limpeixe = 20;
}

Escuna::~Escuna(){}

Navio * Escuna::duplica()const {
    return new Escuna(*this);
}

int Escuna::getPeixe() const{
    return peixe;
}

void Escuna::setPeixe(Mapa * mapa){
      //  cout <<getx()<<gety()<<endl;
    if(mapa->pesqPeixe(getx(),gety())==true){
        peixe++;
        if(peixe>limpeixe)
            peixe=limpeixe;
        mapa->setPeixe(getx(),gety());
    }
}

string Escuna::getAsString() const{
    ostringstream oss;
    oss<<Navio::getAsString()<<endl;
    return oss.str();
}