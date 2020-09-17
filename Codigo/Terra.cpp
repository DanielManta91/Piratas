/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Terra.cpp
 * Author: Pedro
 * 
 * Created on 13 de Novembro de 2018, 11:44
 */

#include "Terra.h"

Terra::Terra(char car):Terreno(car) {
}

char Terra::getChar() const{
    return Terreno::getChar();
}