/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   User.h
 * Author: Pedro
 *
 * Created on 31 de Outubro de 2018, 16:52
 */



#ifndef USER_H
#define USER_H
#include <vector>
#include <string>

using namespace std;

class Navio;

class User {
    int moedas;
    vector<Navio*> navios;
public:
    User();
    virtual ~User();
    
    Navio* getNavioUserID(int id);
    Navio* getNavioUserPos(int pos);
    int getMoedas() const;
    Navio* getLastNavio() const;    //último navio adicionado no vector
    int getnrNaviosUser() const;      //retorna o número de navios que o jogador possui
    
    void setMoedas(int m);
    void acrescentaNavio(string t);         //cria um novo navio e adiciona ao vector
    void vendeNavio(int id);
    int contaNavios(int x,int y) const; //conta o numero de navios numa posição
    bool removeNavio(int pos);
    bool removeNavioID(int id);
};

#endif /* USER_H */

