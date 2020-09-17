/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Porto.h
 * Author: Pedro
 *
 * Created on 31 de Outubro de 2018, 16:34
 */

#ifndef PORTO_H
#define PORTO_H

#include "Terreno.h"
#include <iostream>
#include <vector>

using namespace std;

class Navio;

class Porto : public Terreno {
    vector<Navio*> navios;
    bool principal = false;
    int x,y;
public:
    Porto(char car);
    
    char getChar() const override;
    bool getPrincipal() const override; 
   // int getNaviosPorto() const override;     //retorna quanto navios estão atracados no porto
    
    void setChar(char p) override;
    void setPrincipal() override;
    
    bool acrescentaNavio(Navio *n) override;     //acrescenta um ponteiro para um navio existente ao vector de navios do porto
    Navio* PesquisaNavio(int id) const override; //procura por um navio que tenha um determinado id
    bool removeNavio(int id) override;           //retira o ponteiro para um navio do vector de navios do porto
   
};

#endif /* PORTO_H */

