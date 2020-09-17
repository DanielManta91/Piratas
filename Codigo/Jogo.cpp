/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Jogo.cpp
 * Author: Pedro
 * 
 * Created on 14 de Novembro de 2018, 15:41
 */

#include "Jogo.h"
#include "Mapa.h"
#include "Interface.h"
#include "User.h"
#include "Navio.h"
#include "Escuna.h"
#include "Especial.h"
#include "Veleiro.h"
#include "Fragata.h"
#include "Galeao.h"
#include "Calmaria.h"
#include "Motim.h"
#include "Tempestade.h"
#include "Sereia.h"


Jogo::Jogo() {
}

Jogo::~Jogo() {
}

void Jogo::createMapa(int linhas, int colunas, vector<string> matriz){
    mapa = new Mapa(linhas,colunas,matriz);
}

void Jogo::acrescentaEvento(string t,int x,int y){
    if(t=="C")
        eventoszona.push_back(new Calmaria(x,y));
    if(t=="T")
        eventoszona.push_back(new Tempestade(x,y));

}

void Jogo::acrescentaEvento(string t,Navio * n){
    if(t=="S")
        eventos.push_back(new Sereia(n));
    if(t=="M")
        eventos.push_back(new Motim(n));
}

Evento * Jogo::getEventoZona(int pos) const{
    //cout <<"\naqui";
    if(eventoszona[pos]!=nullptr)
        return eventoszona[pos];
    
    //cout<<"\nali";
    return nullptr;
}

Evento * Jogo::getEvento(int pos) const{
    if(eventos[pos]!= nullptr)
        return eventos[pos];
    
    return nullptr;
}

int Jogo::getnrEventos() const{
    if(eventos.empty())
        return 0;
    else
        return eventos.size();
}



int Jogo::getnrEventosZona() const{
    if(eventoszona.empty())
        return 0;
    else
        return eventoszona.size();
}



void Jogo::acrescentaNavio(string t){
    if(t=="E")
        navios.push_back(new Escuna);
    if(t=="G")
        navios.push_back(new Galeao);
    if(t=="V")
        navios.push_back(new Veleiro);
    if(t=="F")
        navios.push_back(new Fragata);
    if(t=="C")
        navios.push_back(new Especial);
}

Navio* Jogo::getLastNavio() const{
    return navios.back(); 
}

int Jogo::getnrNaviosJogo() const{
    if(navios.empty())
       return 0;
    else
       return navios.size();
}

Navio* Jogo::getNavioJogoPos(int pos){
    if(navios[pos-1]!= nullptr)
            return navios[pos-1];
    
    return nullptr;
}

Navio* Jogo::getNavioJogoID(int id){
    for(int i=0;i<navios.size();i++)
        if(navios[i]->getID()==id)
            return navios[i];
    
    return nullptr;
}

int Jogo::contaNavios(int x, int y) const{
    int conta=0;
    for (int i=0;i<navios.size();i++){
        if(navios[i]->getx() == x && navios[i]->gety()==y)
            conta++;
    }
    return conta;
}

bool Jogo::localizaBatalha(User& u){
    int verx,very,resultado;
    //NAVIOS VS NAVIOS
    
    for(unsigned int i=1;i<=u.getnrNaviosUser();i++){
        for(unsigned int j=0;j<navios.size();j++){
            for(unsigned int k=0;k<8;k++){
                if(k==0){   //norte
                  verx=u.getNavioUserPos(i)->getx()-1;
                  very=u.getNavioUserPos(i)->gety();
                  if(verx<0)
                      return false;
                  if(navios[j]->getx()==verx && navios[j]->gety()==very && navios[j]->getPirate()==true)
                      resultado=Fight(u.getNavioUserPos(i),navios[j]);
                }
                if(k==1){   //nordeste
                  verx=u.getNavioUserPos(i)->getx()-1;
                  very=u.getNavioUserPos(i)->gety()+1;
                  if(verx<0 || very>mapa->getColunas()-1)
                      return false;
                  if(navios[j]->getx()==verx && navios[j]->gety()==very && navios[j]->getPirate()==true)
                      resultado=Fight(u.getNavioUserPos(i),navios[j]);
                }
                if(k==2){   //este
                  verx=u.getNavioUserPos(i)->getx();
                  very=u.getNavioUserPos(i)->gety()+1;  
                  if(very>mapa->getColunas()-1)
                      return false;
                  if(navios[j]->getx()==verx && navios[j]->gety()==very && navios[j]->getPirate()==true)
                      resultado=Fight(u.getNavioUserPos(i),navios[j]);
                }
                if(k==3){   //sudeste
                  verx=u.getNavioUserPos(i)->getx()+1;
                  very=u.getNavioUserPos(i)->gety()+1; 
                  if(verx>mapa->getLinhas()-1 || very>mapa->getColunas()-1)
                      return false;
                  if(navios[j]->getx()==verx && navios[j]->gety()==very && navios[j]->getPirate()==true)
                      resultado=Fight(u.getNavioUserPos(i),navios[j]);
                }
                if(k==4){   //sul
                  verx=u.getNavioUserPos(i)->getx()+1;
                  very=u.getNavioUserPos(i)->gety();    
                  if(verx>mapa->getColunas()-1)
                      return false;
                  if(navios[j]->getx()==verx && navios[j]->gety()==very && navios[j]->getPirate()==true)
                      resultado=Fight(u.getNavioUserPos(i),navios[j]);
                }
                if(k==5){   //sudoeste
                  verx=u.getNavioUserPos(i)->getx()+1;
                  very=u.getNavioUserPos(i)->gety()-1;  
                  if(verx>mapa->getLinhas()-1 || very<0)
                      return false;
                  if(navios[j]->getx()==verx && navios[j]->gety()==very && navios[j]->getPirate()==true)
                      resultado=Fight(u.getNavioUserPos(i),navios[j]);
                }
                if(k==6){   //oeste
                  verx=u.getNavioUserPos(i)->getx();
                  very=u.getNavioUserPos(i)->gety()-1;    
                  if(very<0)
                      return false;
                  if(navios[j]->getx()==verx && navios[j]->gety()==very && navios[j]->getPirate()==true)
                      resultado=Fight(u.getNavioUserPos(i),navios[j]);
                }
                if(k==7){   //noroeste
                  verx=u.getNavioUserPos(i)->getx()-1;
                  very=u.getNavioUserPos(i)->gety()-1;
                  if(verx<0 || very<0)
                      return false;
                  if(navios[j]->getx()==verx && navios[j]->gety()==very && navios[j]->getPirate()==true){
                      resultado=Fight(u.getNavioUserPos(i),navios[j]);
                  }
                }
                if (resultado==1){
                    u.removeNavio(i-1);
                }
                else if(resultado==2){
                    removeNavio(j);
                }
                else{}
            }
        }
    }
        /////////////////////////
        //NAVIOS USER VS PORTOS//
        /////////////////////////
    //cout<<"2\n";
    for(unsigned int i=1;i<=u.getnrNaviosUser();i++){
        for(unsigned int k=0;k<8;k++){
            if(k==0){   //NORTE
                verx=u.getNavioUserPos(i)->getx()-1;
                very=u.getNavioUserPos(i)->gety();
                if(verx<0)
                    return false;
                if(getMapa()->PesquisaPosPortoPirate(verx,very)==true){
                    FightPortoPirate(u.getNavioUserPos(i),verx,very);
                }
            }
            //cout<<"4\n";
            if(k==1){   //NORDESTE
                verx=u.getNavioUserPos(i)->getx()-1;
                very=u.getNavioUserPos(i)->gety()+1;
                if(verx<0 || very>mapa->getColunas())
                    return false;
                if(getMapa()->PesquisaPosPortoPirate(verx,very)==true){
                    FightPortoPirate(u.getNavioUserPos(i),verx,very);
                }
            }
            //cout<<"5\n";
            if(k==2){   //ESTE
                verx=u.getNavioUserPos(i)->getx();
                very=u.getNavioUserPos(i)->gety()+1;
                if(very>mapa->getColunas()-1)
                    return false;
                if(getMapa()->PesquisaPosPortoPirate(verx,very)==true){
                    FightPortoPirate(u.getNavioUserPos(i),verx,very);
                }
            }
            //cout<<"6\n";
            if(k==3){   //SUDESTE
                verx=u.getNavioUserPos(i)->getx()+1;
                very=u.getNavioUserPos(i)->gety()+1;
                if(verx>mapa->getLinhas()-1 || very>mapa->getColunas()-1)
                    return false;
                if(getMapa()->PesquisaPosPortoPirate(verx,very)==true){
                    FightPortoPirate(u.getNavioUserPos(i),verx,very);
                }
            }
            //cout<<"7\n";
            if(k==4){   //SUL
                verx=u.getNavioUserPos(i)->getx()+1;
                very=u.getNavioUserPos(i)->gety();
                if(verx>mapa->getLinhas()-1)
                    return false;
                if(getMapa()->PesquisaPosPortoPirate(verx,very)==true){
                    FightPortoPirate(u.getNavioUserPos(i),verx,very);
                }
            }
            //cout<<"8\n";
            if(k==5){   //SUDOESTE
                verx=u.getNavioUserPos(i)->getx()+1;
                very=u.getNavioUserPos(i)->gety()-1;
                if(verx>mapa->getLinhas()-1 || very<mapa->getColunas()-1)
                    return false;
                if(getMapa()->PesquisaPosPortoPirate(verx,very)==true){
                    FightPortoPirate(u.getNavioUserPos(i),verx,very);
                }
            }
            //cout<<"9\n";
            if(k==6){   //OESTE
                verx=u.getNavioUserPos(i)->getx();
                very=u.getNavioUserPos(i)->gety()-1;
                if(very<0)
                    return false;
                if(getMapa()->PesquisaPosPortoPirate(verx,very)==true){
                    FightPortoPirate(u.getNavioUserPos(i),verx,very);
                }
            }
            //cout<<"0\n";
            if(k==7){   //NORDESTE
                verx=u.getNavioUserPos(i)->getx()-1;
                very=u.getNavioUserPos(i)->gety()-1;
                if(very<0 || verx<0)
                    return false;
                if(getMapa()->PesquisaPosPortoPirate(verx,very)==true){
                    FightPortoPirate(u.getNavioUserPos(i),verx,very);
                }
            }
            //cout<<"15\n";
        }
    }
        //////////////////////////
        //NAVIOS PIRATE VS PORTOS//
        //////////////////////////
    
    //cout<<"3\n";
    for(unsigned int j=1;j<=getnrNaviosJogo();j++){
        for(unsigned int k=0;k<8;k++){

            
            if(k==0){   //NORTE
                verx=getNavioJogoPos(j)->getx()-1;
                very=getNavioJogoPos(j)->gety();
                if(verx<0)
                    return false;
                if(getMapa()->PesquisaPosPorto(verx,very)==true){
                    FightPortoUser(getNavioJogoPos(j),verx,very);
                }
                    
            }
            
            if(k==1){   //NORDESTE
                verx=getNavioJogoPos(j)->getx()-1;
                very=getNavioJogoPos(j)->gety()+1;
                if(verx<0 || very>mapa->getColunas()-1)
                    return false;
                if(getMapa()->PesquisaPosPorto(verx,very)==true){
                    FightPortoUser(getNavioJogoPos(j),verx,very);
                }
            }
            
            if(k==2){   //ESTE
                verx=getNavioJogoPos(j)->getx();
                very=getNavioJogoPos(j)->gety()+1;
                if(very>mapa->getColunas()-1)
                    return false;
                if(getMapa()->PesquisaPosPorto(verx,very)==true){
                    FightPortoUser(getNavioJogoPos(j),verx,very);
                }
            }
            
            if(k==3){   //SUDESTE
                verx=getNavioJogoPos(j)->getx()+1;
                very=getNavioJogoPos(j)->gety()+1;
                if(verx>mapa->getLinhas()-1 || very<mapa->getColunas()-1)
                    return false;
                if(getMapa()->PesquisaPosPorto(verx,very)==true){
                    FightPortoUser(getNavioJogoPos(j),verx,very);
                }
            }
            
            if(k==4){   //SUL
                verx=getNavioJogoPos(j)->getx()+1;
                very=getNavioJogoPos(j)->gety();
                if(verx>mapa->getLinhas()-1)
                    return false;
                if(getMapa()->PesquisaPosPorto(verx,very)==true){
                    FightPortoUser(getNavioJogoPos(j),verx,very);
                }
            }
            
            if(k==5){   //SUDOESTE
                verx=getNavioJogoPos(j)->getx()+1;
                very=getNavioJogoPos(j)->gety()-1;
                if(verx>mapa->getLinhas()-1 || very<0)
                    return false;
                if(getMapa()->PesquisaPosPorto(verx,very)==true){
                    FightPortoUser(getNavioJogoPos(j),verx,very);
                }
            }
            
            if(k==6){   //OESTE
                verx=getNavioJogoPos(j)->getx();
                very=getNavioJogoPos(j)->gety()-1;
                if(very<0)
                    return false;
                if(getMapa()->PesquisaPosPorto(verx,very)==true){
                    FightPortoUser(getNavioJogoPos(j),verx,very);
                }
            }
            
            if(k==7){   //NORDESTE
                verx=getNavioJogoPos(j)->getx()-1;
                very=getNavioJogoPos(j)->gety()-1;
                if(verx<0 || very<0)
                    return false;
                if(getMapa()->PesquisaPosPorto(verx,very)==true){
                    FightPortoUser(getNavioJogoPos(j),verx,very);
                }
            }

        }
    }
}


int Jogo::FightPortoUser(Navio * n,int x,int y){
    int prob1,prob2,flag;
    char letra='a';
    prob1=rand()%n->getTrip();
    prob2=rand()%100;
    if(prob1>prob2){
        n->setTrip(n->getTrip()-(n->getTrip()*0.1));
        while(flag!=2){
            flag=0;
        for(unsigned int k=0;k<mapa->getColunas();k++){
            for(unsigned int l=0;l<mapa->getLinhas();l++){
                if(mapa->getPos(l,k)==letra){
                    letra=letra+1;
                    flag=1;
                }
            }
        }
        if(flag==0)
            flag=2;
        }
        mapa->setPos(letra,x,y);
    }
    else if(prob2>prob1){
        n->setTrip(n->getTrip()-(n->getTrip()*0.1));
    }
    else{
        n->setTrip(n->getTrip()-(n->getTrip()*0.1));
        while(flag!=2){
            flag=0;
        for(unsigned int k=0;k<mapa->getColunas();k++){
            for(unsigned int l=0;mapa->getLinhas();l++){
                if(mapa->getPos(x,y)==letra){
                    letra=letra+1;
                    flag=1;
                }
            }
        }
        if(flag==0)
            flag=2;
        }
    }
    mapa->nomeiaPortoPrinc();
}


int Jogo::FightPortoPirate(Navio * n,int x,int y){
    int prob1,prob2,flag;
    char letra='A';
    prob1=rand()%n->getTrip();
    prob2=rand()%100;
    cout<<"\nprob n:"<<prob1<<"\nprob p:"<<prob2<<endl;
    if(prob1>prob2){
        n->setTrip(n->getTrip()-(n->getTrip()*0.1));
        while(flag!=2){
            flag=0;
        for(unsigned int k=0;k<mapa->getColunas();k++){
            for(unsigned int l=0;l<mapa->getLinhas();l++){
                if(mapa->getPos(l,k)==letra){
                    letra=letra+1;
                    flag=1;
                }
            }
        }
        if(flag==0)
            flag=2;
        }
        mapa->setPos(letra,x,y);
    }
    else if(prob2>prob1){
        n->setTrip(n->getTrip()-(n->getTrip()*0.1));
    }
    else{
        n->setTrip(n->getTrip()-(n->getTrip()*0.1));
        while(flag!=2){
            flag=0;
        for(unsigned int k=0;k<mapa->getColunas();k++){
            for(unsigned int l=0;mapa->getLinhas();l++){
                if(mapa->getPos(x,y)==letra){
                    letra=letra+1;
                    flag=1;
                }
            }
        }
        if(flag==0)
            flag=2;
        }
    }
}

int Jogo::Fight(Navio* n, Navio* n2){
    int prob1,prob2;
    //cout<<"1\n";
    prob1=rand()%n->getTrip();
    //cout<< "3\n";
    prob2=rand()%n2->getTrip();
      //  cout<<"2\n";
    if(prob1>prob2){
        n->setTrip(n->getTrip()-(n->getTrip()*0.2));
        n2->setTrip(n2->getTrip()-(n->getTrip()*0.4));
        //    cout<<"3\n";
    }
    else if(prob1<prob2){
        n->setTrip(n->getTrip()-(n2->getTrip()*0.4));
        n2->setTrip(n2->getTrip()-(n2->getTrip()*0.2));
          //  cout<<"4\n";
    }
    else{           //em caso de empate o barco com menos tripulação ganha
        if(n->getTrip()>n2->getTrip()){
            n->setTrip(n->getTrip()-(n->getTrip()*0.2));
            n2->setTrip(n2->getTrip()-(n->getTrip()*0.4));
            //    cout<<"5\n";
        }
        else{
            n->setTrip(n->getTrip()-(n2->getTrip()*0.4));
            n2->setTrip(n2->getTrip()-(n2->getTrip()*0.2));
              //  cout<<"6\n";
        }
    }
//    cout << "\nProb U:"<<prob1<<"\nProb P:"<<prob2<<endl;
//    cout << "\nTrip U:"<<n->getTrip()<<"\nTrip P:"<<n2->getTrip()<<endl;
    if(n->getTrip()==0){
        n2->setCarga(n2->getCarga()+n->getCarga()*0.5);
        return 1;
    }
    else if(n2->getTrip()==0){
        n->setCarga(n->getCarga()+n2->getCarga()*0.5);
        n->setAgua(n->getAgua()+n2->getAgua()*0.5);
        return 2;
    }
    return 0;
}


bool Jogo::removeNavio(int pos){
    if(navios[pos]!=nullptr){
        delete navios[pos];
        navios.erase(navios.begin()+pos);
        return true;
    }
    return false;
}


bool Jogo::removeEventoNavio(int pos){
    if(eventos[pos]!=nullptr){
        delete eventos[pos];
        eventos.erase(eventos.begin()+pos);
        return true;
    }
    return false;
}

bool Jogo::removeEventoZona(int pos){
    if(eventoszona[pos]!=nullptr){
        delete eventoszona[pos];
        eventoszona.erase(eventoszona.begin()+pos);
        return true;
    }
    return false;
}

void Jogo::EventosNavio(User& u){
    for(unsigned int i=0;i<getnrEventos();i++){
        if(getEvento(i)->getTipo()=='M')
        getEvento(i)->atua(u);
        if(getEvento(i)->getTipo()=='S')
        getEvento(i)->atua();
    }
}

void Jogo::EventosArea(User& u){
    for(unsigned int i=0;i<getnrEventosZona();i++){
        for(unsigned int j=1;j<=u.getnrNaviosUser();j++){
            if(u.getNavioUserPos(j)->getx()>= getEventoZona(i)->getx() && u.getNavioUserPos(j)->getx()<= (getEventoZona(i)->getx()+2) && u.getNavioUserPos(j)->gety()>=getEventoZona(i)->gety() && u.getNavioUserPos(j)->gety() <=  getEventoZona(i)->gety()+2){
                getEventoZona(i)->atua(u.getNavioUserPos(j),u);
                
            }
                
        }
    }
}

void Jogo::geraPeixe(){    
    mapa->geraPeixe();
}