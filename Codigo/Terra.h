/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Terra.h
 * Author: Pedro
 *
 * Created on 13 de Novembro de 2018, 11:44
 */

#ifndef TERRA_H
#define TERRA_H
#include "Terreno.h"

class Terra : public Terreno {
public:
    Terra(char car='+');
    char getChar() const override;

};

#endif /* TERRA_H */

