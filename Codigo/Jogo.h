/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Jogo.h
 * Author: Pedro
 *
 * Created on 14 de Novembro de 2018, 15:41
 */

#ifndef JOGO_H
#define JOGO_H
#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Mapa;
class User;
class Navio;
class Evento;
class Jogo {
    vector <Navio *> navios;
    vector <Evento *> eventos;
    vector <Evento *> eventoszona;
    Mapa * mapa=nullptr;
    //Estas variáveis podem ir para outro lado se assim entendermos no futuro.
    int probpirata,preconavio,precosoldado,precovendpeixe;
    int precocompmercad,precovendmercad,soldadosporto;
    int probevento,probtempestade,probsereias,probcalmaria;
    int probmotim;
    
public:
    Jogo();
    virtual ~Jogo();
    
    void createMapa(int linhas,int colunas,vector<string> matriz);
    void geraPeixe();
    
    
    void acrescentaEvento(string t,int x,int y);
    void acrescentaEvento(string t,Navio * n);
    int getnrEventosZona() const;
    int getnrEventos() const;
    Evento * getEvento(int pos) const;
    Evento * getEventoZona(int pos) const;
    bool removeEventoZona(int pos);
    bool removeEventoNavio(int pos);
    void EventosArea(User & u);
    void EventosNavio(User& u);
    
    
    void acrescentaNavio(string t);         //cria um novo navio e adiciona ao vector
    int getnrNaviosJogo() const;      //retorna o número de navios que o jogador possui
    Navio* getLastNavio() const;    //último navio adicionado no vector
    Navio* getNavioJogoID(int id);
    Navio* getNavioJogoPos(int pos);
    int contaNavios(int x, int y) const;
        
    
    
    Mapa * getMapa(){
        return mapa;
    }
    
    //COMBATE
    
    bool localizaBatalha(User & u);
    int Fight(Navio * n,Navio * n2);
    bool removeNavio(int id);
    int FightPortoPirate(Navio * n,int x,int y);
    int FightPortoUser(Navio * n,int x,int y);
    ///////////
    //SETTERS//
    ///////////
    void setPirata(int p){
        probpirata = p;
    }
    
    void setPreconavio(int p){
        preconavio = p;
    }
    
    void setSoldadosporto(int p){
        soldadosporto = p;
    }
    
    //Talvez pertença aos eventos
    
    void setProbmotim(int p){
        probmotim = p;
    }
    
    void setProbcalmaria(int p){
        probcalmaria = p;
    }
    
    void setProbsereias(int p){
        probsereias = p;
    }
    
    void setProbevento(int p){
        probevento = p;
    }
    
    void setProbtempestade(int p){
        probtempestade = p;
    }
    
    //para cima
    
    void setPrecosoldado(int p){
        precosoldado = p;
    }
    
    void setPrecovendpeixe(int p){
        precovendpeixe = p;
    }
    
    void setPrecocompmercad(int p){
        precocompmercad = p;
    }
    
    void setPrecovendmercad(int p){
        precovendmercad = p;
    }
    
    
    ///////////
    //GETTERS//
    ///////////
    int getPirata() const{
        return probpirata;
    }
    
    int getPreconavio() const{
        return preconavio;
    }
    
    int getSoldadosporto() const{
        return soldadosporto;
    }
    
    int getProbmotim() const{
        return probmotim;
    }
    
    int getProbcalmaria() const{
        return probcalmaria;
    }
    
    int getProbsereias() const{
        return probsereias;
    }
    
    int getProbevento() const{
        return probevento;
    }
    
    int getProbtempestade() const{
        return probtempestade;
    }
    
    int getPrecosoldado() const{
        return precosoldado;
    }
    
    int getPrecovendpeixe() const{
        return precovendpeixe;
    }
    
    int getPrecocompmercad() const{
        return precocompmercad;
    }
    
    int getPrecovendmercad() const{
        return precovendmercad;
    }
};

#endif /* JOGO_H */

