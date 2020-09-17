/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Terreno.cpp
 * Author: Pedro
 * 
 * Created on 14 de Novembro de 2018, 15:42
 */

#include "Terreno.h"
#include "Navio.h"
#include <iostream>

using namespace std;

Terreno::Terreno(char car) {
    letra = car;
}

Terreno::~Terreno() {
}

char Terreno::getChar() const{
    return letra;
}

void Terreno::setChar(char barco){
    letra=barco;
}


