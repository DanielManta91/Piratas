/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Navio.h
 * Author: Pedro
 *
 * Created on 31 de Outubro de 2018, 16:29
 */

#ifndef NAVIO_H
#define NAVIO_H
#include <string>
#include <ctime>
#include <sstream>

using namespace std;

class Mapa;
class User;
class Jogo;
class Navio {
    static int sequencia;
    bool pirate;
    char tipo;
    //real
    int tripulacao,agua,movimento,carga;
    //limites
    int capagua,captripulacao,capcarga,x,y,id;
    bool cruise;
    bool turn;
    
public:
    Navio(int cagua,int captr,int mov,int ccarga,char t);
    virtual ~Navio();
    
    //GETTER
    virtual int getx() const{ return x;}
    virtual int gety() const{ return y;}
    virtual int getID() const{
        return id;
    }
    
    virtual int getPeixe() const{};
    virtual char getTipo() const{ return tipo;}
    virtual bool getCruise() const{return cruise;}
    virtual int getMov() const{return movimento;}
    virtual int getCarga() const{return carga;}
    virtual int getLimCarga() const{return capcarga;}
    virtual int getLimTrip() const {return captripulacao;}
    virtual int getTrip() const {return tripulacao;}
    virtual bool getPirate() const{return pirate;}
    virtual int getAgua() const{return agua;}
    virtual bool getTurn() const{return turn;}
    virtual int getLimAgua() const{return capagua;}
    
    //SETTER
    virtual void setPeixe(Mapa * mapa){};
    virtual void setx(int pos){ x=pos;}
    virtual void sety(int pos){ y=pos;}
    virtual void setTurn(bool t){turn=t;}
    virtual void setCarga(int v){
        carga=v;
        if(carga>capcarga)
            carga = capcarga;
    }
    virtual void setCruise(bool val){cruise=val;}
    virtual void setTrip(int v){
    tripulacao=v;
    if(tripulacao<0)
        tripulacao=0;
    }
    virtual void setAgua(int v){
        agua = v;
        if(agua > capagua)
            agua = capagua;
    }
    virtual void setPirate(bool p){pirate=p;}
    
    //PESQUISA

    
    //MOVIMENTO
    virtual bool MoverRandom(Mapa * mapa,Jogo j);
    virtual bool MoverRandom(Mapa * mapa,User u);
    virtual bool moveNavio(Mapa * mapa,int dir,User u,int mov);
    virtual bool moveNavio(Mapa* mapa,int dir,Jogo j,int mov);
    
    virtual string getAsString()const;

    
    virtual Navio * duplica()const = 0;
    
    static Navio * fabrica(string tipo);
    
    
    Navio & operator=(const Navio& orig);
};
//ostream & operator<<(ostream & saida, const Navio & x);
#endif /* NAVIO_H */

