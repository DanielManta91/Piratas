/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Celula.cpp
 * Author: Pedro
 * 
 * Created on 14 de Novembro de 2018, 15:42
 */

#include "Celula.h"
#include "Mar.h"
#include "Terra.h"
#include "Porto.h"
#include <iostream>

using namespace std;

Celula::Celula(char c) {
    if(c == '.')
        t = new Mar;
    else if(c == '+')    
        t = new Terra;
    else
        t = new Porto(c);
}

//Celula::Celula(const Celula& orig) {
//}

Celula::~Celula() {
}

Terreno* Celula::getTerreno() const{
    return t;    
}