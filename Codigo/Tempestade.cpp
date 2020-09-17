/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tempestade.cpp
 * Author: Pedro
 * 
 * Created on 31 de Outubro de 2018, 16:31
 */

#include "Tempestade.h"
#include "Navio.h"
#include "User.h"

Tempestade::Tempestade(int x1,int y1):Evento() {
    x=x1;
    y=y1;
    letra='@';
    conta=0;
    limconta=1;
}

Tempestade::~Tempestade() {
}

Evento* Tempestade::duplica() const{
    return new Tempestade(*this);
}

int Tempestade::getx() const{
    return x;
}

int Tempestade::gety() const{
    return y;
}

char Tempestade::getLetra() const{
    return letra;
}

void Tempestade::inConta(){
    conta++;
}

int Tempestade::getConta() const{
    return conta;
}

void Tempestade::atua(Navio * n,User & u){
    n->setAgua(n->getLimAgua());
    int escolhe;
    escolhe=rand()%100;
    if(escolhe < 50){
        n->setCarga(n->getCarga()/2);
    }
    else if(escolhe >=50 && escolhe <90){
        n->setTrip((n->getTrip()/4)*3);
    }
    else
    {
        u.removeNavioID(n->getID());
    }
}

int Tempestade::getLim() const{
    return limconta;
}