/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   User.cpp
 * Author: Pedro
 * 
 * Created on 31 de Outubro de 2018, 16:52
 */

#include "User.h"
#include "Navio.h"
#include "Escuna.h"
#include "Galeao.h"
#include "Veleiro.h"
#include "Fragata.h"
#include "Especial.h"
#include <iostream>

User::User() {
}

User::~User() {
}

int User::contaNavios(int x, int y) const{
    int conta=0;
    for (int i=0;i<navios.size();i++){
        if(navios[i]->getx() == x && navios[i]->gety()==y)
            conta++;
    }
    return conta;
}

Navio* User::getNavioUserPos(int pos){
    if(navios[pos-1]!= nullptr)
            return navios[pos-1];
    
    return nullptr;
}

Navio* User::getNavioUserID(int id){
    for(int i=0;i<navios.size();i++)
        if(navios[i]->getID()==id)
            return navios[i];
    
    return nullptr;
}

void User::setMoedas(int m){
    moedas=m;
}

int User::getMoedas() const{
    return moedas;
}

int User::getnrNaviosUser() const{
    if(navios.empty())
       return 0;
    else
       return navios.size();
}

Navio* User::getLastNavio() const{
    return navios.back(); 
}

void User::acrescentaNavio(string t){
    if(t=="E")
        navios.push_back(new Escuna);
    if(t=="G")
        navios.push_back(new Galeao);
    if(t=="V")
        navios.push_back(new Veleiro);
    if(t=="F")
        navios.push_back(new Fragata);
    if(t=="C")
        navios.push_back(new Especial);
}

void User::vendeNavio(int id) {
    for(unsigned int i=0;i<=navios.size();i++){
        if(navios[i]->getID()==id){
            removeNavio(i);
        }
    }
}

bool User::removeNavio(int pos){
    if(navios[pos]!=nullptr){
        delete navios[pos];
        navios.erase(navios.begin()+pos);
        return true;
    }
    return false;
}

bool User::removeNavioID(int id){
        for(unsigned int i=0;i<navios.size();i++){
            if(navios[i]->getID()==id){
                delete navios[i];
                navios.erase(navios.begin()+i);
                 return true;
            }
        }
    return false;
}