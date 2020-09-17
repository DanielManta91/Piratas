/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sereias.cpp
 * Author: Pedro
 * 
 * Created on 31 de Outubro de 2018, 16:31
 */

#include "Sereia.h"
#include "Navio.h"


    Sereia::Sereia(Navio * n1):Evento() {
        n=n1;
        conta=0;
        limconta=1;
        tipo = 'S';
    }

    Sereia::~Sereia() {
    }

    Evento* Sereia::duplica() const{
        return new Sereia(*this);
    }

    void Sereia::inConta(){
        conta++;
    }
    void Sereia::atua(){
        n->setTrip(n->getTrip()*0.9);
    }
    int Sereia::getConta() const{
        return conta;
    }
    int Sereia::getLim() const{
        return limconta;
    }
    
    char Sereia::getTipo() const{
        return tipo;
    }

