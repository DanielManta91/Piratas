/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Interface.h
 * Author: Pedro
 *
 * Created on 31 de Outubro de 2018, 16:34
 */

#ifndef INTERFACE_H
#define INTERFACE_H

#include <vector>
#include <string>

using namespace std;

class Jogo;
class Mapa;
class Celula;
class User;
class Evento;
class Interface {
    Mapa* mapa=nullptr;
public:
    Interface();
    ~Interface();
    bool iniciaConfig(Jogo& j,User &u);   //Configuração do jogo através do ficheiro de texto
    bool iniciaExec(Jogo& j,User &u);       //Execução do jogo
    vector<string> split(const string& s, char separa);     //Vector auxiliar para leitura de comandos
    
    
    //COMANDOS
    void pirate(Jogo& j,int x,int y,string t);
    void compranav(Jogo& j,string t,User& u);   
    bool vendenav(Jogo& j,int id,User& u);
    bool compra(Jogo& j,int id,int quant,User& u);
    bool vende(Jogo& j,int id,User& u);
    bool comprasold(Jogo& j,int id,int quant,User& u);
};

#endif /* INTERFACE_H */

