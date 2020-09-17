/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mapa.h
 * Author: Pedro
 *
 * Created on 31 de Outubro de 2018, 16:27
 */
#ifndef MAPA_H
#define MAPA_H
#include <string>
#include <vector>
#include "Celula.h"

using namespace std;

class Navio;
class Mar;
class Porto;
class User;
class Jogo;

class Mapa {
    vector<vector<Celula>> cell;
    int linhas,colunas;
public:
    
    //ENG:CIVIL//
    
    Mapa(int l, int c,vector<string> s);
    virtual ~Mapa();
    

    //SETTERS//
    void setPeixe(int x,int y);
    void setLinhas(int l){ linhas=l; }
    void setColunas(int c){ colunas=c; }
    void setPos(char letra,int x,int y);
    
    bool spawnNavioUser(Navio* n);                //associa um navio do jogador com o porto principal
    bool spawnNavioJogo(Navio* n,int x,int y);                //associa um navio do jogador com o porto principal
    
    bool geraPeixe();
    
    //GETTERS//
    
    int getLinhas() const;
    int getColunas() const;
    string getAsString(User u,Jogo jogo) const;
    char getPos(int x,int y) const;
    
    //MOVE//
    bool MoverRandom(int id);       //movimento aleatório dos navios
    
    //PESQUISA//
    bool pesqPeixe(int x, int y) const;
    bool PesquisaPosPorto(int x,int y);
    int PesquisaPosicao(int x,int y,User u);
    
    bool PesquisaPosPortoPirate(int x,int y);
    int PesquisaPosicaoPirate(int x,int y,Jogo j);
    
    //ESCOLHE PORTO PRINCIPAL//
    bool nomeiaPortoPrinc();        //escolhe o porto principal do jogador
    
    //PORTOS
    
    bool desassociaPorto(int id,int x,int y);
    bool associaNavio(Navio* n, int x, int y);
    
};

#endif /* MAPA_H */


