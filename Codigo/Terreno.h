/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Terreno.h
 * Author: Pedro
 *
 * Created on 14 de Novembro de 2018, 15:42
 */

#ifndef TERRENO_H
#define TERRENO_H

class Navio;

class Terreno {
    char letra;
public:
    Terreno(char car);
    virtual ~Terreno();
    
    
    virtual bool getPeixe() const{};              //class Mar
    virtual char getChar() const;
    virtual bool getPrincipal() const{};      //class Porto
    virtual Navio* getNavio() const{};        //class Mar
    virtual int getNaviosPorto() const{};
    
    
    virtual void setPeixe(bool p){};  //class Mar
    virtual void setChar(char barco);
    virtual void setPrincipal(){};          //class Porto
    virtual void setNavio(Navio* nav){};   //class Mar
    
    virtual void resetChar(){};         //class Mar
    virtual void resetNavio(){};        //class Mar
    
    virtual Navio* PesquisaNavio(int id) const{};   //class Porto
    virtual bool acrescentaNavio(Navio *n){};       //class Porto
    virtual bool removeNavio(int id){};             //class Porto
    
    
};

#endif /* TERRENO_H */

