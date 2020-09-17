/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Eventos.h
 * Author: Pedro
 *
 * Created on 31 de Outubro de 2018, 16:30
 */

#ifndef EVENTO_H
#define EVENTO_H
#include <string>

using namespace std;

class Mapa;
class User;
class Jogo;
class Navio;
class User;
class Evento {
public:
    Evento();
    virtual ~Evento();
    static Evento * fabrica(string tipo,Navio * n);
    static Evento * fabrica(string tipo,int x,int y);
    virtual Evento * duplica()const = 0;
    
    virtual int getx() const{};
    virtual int gety() const{};
    virtual char getLetra() const{};        //Eventos de area
    virtual void inConta() {};         //Eventos
    virtual int getConta() const{};         //Eventos
    virtual int getLim() const{};           //Eventos
    
    virtual char getTipo() const{};      //Eventos Navios
    virtual void trocaPirate(){};    //Evento Motim
    
    virtual void atua(Navio * n,User & u){};//Evento faz o seu efeito
    virtual void atua(User &u){};
    virtual void atua(){};
};

#endif /* EVENTO_H */

