/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mar.cpp
 * Author: Pedro
 * 
 * Created on 13 de Novembro de 2018, 11:44
 */

#include "Mar.h"
#include "Navio.h"

Mar::Mar(char car):Terreno(car) {
    n=nullptr;
    peixe=false;
}

char Mar::getChar() const{
    return Terreno::getChar(); 
}

void Mar::setChar(char barco){
    Terreno::setChar(barco);
}

void Mar::setNavio(Navio* nav){
    n=nav;
}

Navio* Mar::getNavio() const{
    return n;
}

void Mar::resetChar(){
    Terreno::setChar('.');
}

void Mar::resetNavio(){
    n=nullptr;
}

bool Mar::getPeixe() const{
    return peixe;
}

void Mar::setPeixe(bool p){
    peixe=p;
}