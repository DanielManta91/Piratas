/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Escuna.h
 * Author: Pedro
 *
 * Created on 31 de Outubro de 2018, 16:29
 */

#ifndef ESCUNA_H
#define ESCUNA_H

using namespace std;

#include "Navio.h"

class Escuna: public Navio{
    int peixe;
    int limpeixe;
    public: 
         Escuna();
         virtual ~Escuna();
         
        void setPeixe(Mapa * mapa) override;
        int getPeixe() const override;
    
        Navio * duplica()const override;
       string getAsString()const override;

};

#endif /* ESCUNA_H */

