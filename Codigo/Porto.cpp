/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Porto.cpp
 * Author: Pedro
 * 
 * Created on 31 de Outubro de 2018, 16:34
 */

#include "Porto.h"
#include "Navio.h"


Porto::Porto(char car):Terreno(car) {
}

char Porto::getChar() const{
    return Terreno::getChar();
}

bool Porto::getPrincipal() const{
    return principal;
}


void Porto::setChar(char p){
    Terreno::setChar(p);
}

void Porto::setPrincipal(){
    if(principal)
        principal = false;
    else
        principal = true;
}

bool Porto::acrescentaNavio(Navio *n){
    if(n == nullptr)    //se este navio não existir
        return false;
    
    for(unsigned int i=0;i<navios.size();i++)   //verifica se este navio já se encontra no porto
        if(n == navios[i])
            return false;
    
    navios.push_back(n);    
    return true;
}

Navio* Porto::PesquisaNavio(int id) const{   
    for(unsigned int i=0;i<navios.size();i++)
        if(navios[i]->getID() == id)
            return navios[i];
    
    return nullptr;
}

bool Porto::removeNavio(int id){
    for(unsigned int i=0;i<navios.size();i++)
        if(navios[i]->getID() == id){
            navios.erase(navios.begin() + i);
            return true;
        }
    return false;
}
