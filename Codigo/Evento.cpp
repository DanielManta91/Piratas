/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Eventos.cpp
 * Author: Pedro
 * 
 * Created on 31 de Outubro de 2018, 16:30
 */

#include "Evento.h"
#include "Calmaria.h"
#include "Sereia.h"
#include "Tempestade.h"
#include "Motim.h"
#include "User.h"
#include "Jogo.h"
#include "Mapa.h"

Evento::Evento(){}


Evento* Evento::fabrica(string tipo,Navio * n) {
        if (tipo == "S"){
            return new Sereia(n);
        }
        else if (tipo == "M"){
            return new Motim(n);
        }         
        else{
            return nullptr;
        }
}




Evento * Evento::fabrica(string tipo,int x,int y){
	if (tipo == "C") {
            return new Calmaria(x,y);
	}
        else if (tipo == "T"){
            return new Tempestade(x,y);
        }
        else{
        return nullptr;
        }
}

Evento::~Evento() {
}

