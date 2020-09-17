/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Motim.cpp
 * Author: Pedro
 * 
 * Created on 31 de Outubro de 2018, 16:33
 */

#include "Motim.h"
#include "Navio.h"
#include "User.h"

    Motim::Motim(Navio * n1):Evento(){
        n=n1;
        conta=0;
        limconta=4;
        tipo='M';
    }
    
    Motim::~Motim(){}
    
    Evento * Motim::duplica()const{
        return new Motim(*this);
    }
 
    void Motim::inConta(){
        conta++;
    }
    
    void Motim::atua(User& u){
        if(n->getTipo()=='V' || n->getTipo()=='F')
            n->setPirate(true);
        else{
            u.removeNavioID(n->getID());
        }
    }
    
    int Motim::getConta() const{
        return conta;
    }
    
    int Motim::getLim() const{
        return limconta;
    }
    
    char Motim::getTipo() const{
        return tipo;
    }
    
    void Motim::trocaPirate(){
        n->setPirate(false);
    }