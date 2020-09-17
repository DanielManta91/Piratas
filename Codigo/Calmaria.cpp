/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Calmaria.cpp
 * Author: Pedro
 * 
 * Created on 31 de Outubro de 2018, 16:31
 */

#include "Calmaria.h"
#include "User.h"
#include "Navio.h"

Calmaria::Calmaria(int xi,int yi):Evento() {
    x=xi;
    y=yi;
    letra='/';
    conta=0;
    limconta=4;
}

Calmaria::~Calmaria() {
}

Evento * Calmaria::duplica() const{
    return new Calmaria(*this);
}

int Calmaria::getx() const{
    return x;
}


int Calmaria::gety() const{
    return y;
}

char Calmaria::getLetra() const{
    return letra;
}

void Calmaria::inConta(){
    conta++;
}

void Calmaria::atua(Navio * n,User & u){
    if(n->getTipo()!='C')
        n->setTurn(true);
    
    if(conta==limconta-1)
        u.setMoedas(u.getMoedas()+100);
}

int Calmaria::getConta() const{
    return conta;
}

int Calmaria::getLim() const{
    return limconta;
}