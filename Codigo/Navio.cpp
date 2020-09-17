/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Navio.cpp
 * Author: Pedro
 * 
 * Created on 31 de Outubro de 2018, 16:29
 */

#include "Navio.h"
#include "Mapa.h"
#include "User.h"
#include "Jogo.h"
#include "Escuna.h"
#include "Veleiro.h"
#include "Fragata.h"
#include "Especial.h"
#include "Galeao.h"

#include <iostream>
#include <sstream>

int Navio::sequencia = 1;

Navio::Navio(int cagua,int catrip,int mov,int ccarga,char t):id(sequencia++) {
    capagua=cagua;
    captripulacao=catrip;
    tripulacao=captripulacao;
    agua=capagua;
    movimento=mov;
    cruise=false;
    carga=0;
    capcarga=ccarga;
    tipo=t;
    turn=false;
}



Navio::~Navio() {
}





bool Navio::moveNavio(Mapa* mapa,int dir,User u,int mov){
    int verx=-1,very=-1;
  //  cout <<x<<" " <<y<< "\n";
    if(dir==1){ //NORTE
        
        verx=x-mov;
        very=y;
        if(verx < 0){   //se sair do mapa na próxima célula
                if(mapa->PesquisaPosicao(mapa->getLinhas()-1,y,u)!=0)  //Se a próxima célula no outro lado do mapa for do tipo mar
                    verx=mapa->getLinhas()-1;                  //actualiza a variável para ser possível o navio aparacer na nova célula
                else
                    verx=x;                     //Se a próxima célula no outro lado do mapa não for do tipo mar, atribui-se a posição presente do navio à variável.
                                                //Deste modo não há entrada em mais nenhuma condição e o navio mantém-se na sua posição actual.
            }
    }    

    if(dir==2){ //NORDESTE
        verx=x-mov;
        very=y+mov;
        if(verx < 0 && very > mapa->getColunas()-1){
            //cout<<"1\n";
                    if(mapa->PesquisaPosicao(mapa->getLinhas()-1,0,u)!=0){
                        verx=mapa->getLinhas()-1;
                        very=0;
                    }
                    else{
                        verx=x;
                        very=y;
                    }
                }
                else if(verx < 0){
            //cout<<"1\n";
                    if(mapa->PesquisaPosicao(mapa->getLinhas()-1,very,u)!=0)
                        verx=mapa->getLinhas()-1;
                    else{
                        verx=x;
                        very=y;
                    }
                }
                else if(very > mapa->getLinhas()-1){
              //      cout<<"1\n";
                    if(mapa->PesquisaPosicao(verx,mapa->getColunas()-1,u)!=0)
                        very=mapa->getLinhas()-1;
                    else{
                        very=y;
                        verx=x;
                    }
                }
    }

    if(dir==3){ //ESTE
        verx=x;
        very=y+mov;
        if(very > mapa->getColunas()-1){
                    if(mapa->PesquisaPosicao(verx,0,u)!=0){
                        very=0;
                    }
                    else
                        very=y;
                }
    }
        
    if(dir==4){ //SUDESTE
        verx=x+mov;
        very=y+mov;
        if(verx > mapa->getLinhas()-1 && very > mapa->getColunas()-1){
                    if(mapa->PesquisaPosicao(0,0,u)!=0){
                        verx=0;
                        very=0;
                    }
                    else{
                        verx=x;
                        very=y;
                    }
                }
        else if(verx > mapa->getLinhas()-1){
                    if(mapa->PesquisaPosicao(0,very,u)!=0)
                        verx=0;
                    else{
                        verx=x;
                        very=y;
                    }
                }
        else if(very > mapa->getColunas()-1){
                    if(mapa->PesquisaPosicao(verx,mapa->getColunas()-1,u)!=0)
                        very=0;
                    else{
                        very=y;
                        verx=x;
                    }
                }
    }

    if(dir==5){ //SUL
        verx=x+mov;
        very=y;
        if(verx > mapa->getLinhas()-1){
                    if(mapa->PesquisaPosicao(0,very,u)!=0){
                        verx=0;
                    }
                    else{
                        verx=x;
                    }
                }
    }

    if(dir==6){ //SUDOESTE
        verx=x+mov;
        very=y-mov;
        if(verx > mapa->getLinhas()-1 && very < 0){
                    if(mapa->PesquisaPosicao(0,mapa->getColunas()-1,u)!=0){
                        verx=0;
                        very=mapa->getColunas()-1;
                    }
                    else{
                        verx=x;
                        very=y;
                    }
                }
                else if(very < 0){
                    if(mapa->PesquisaPosicao(verx,mapa->getColunas()-1,u)!=0)
                        very=mapa->getColunas()-1;
                    else{
                        very=y;
                        verx=x;
                    }
                }
                else if(verx > mapa->getLinhas()-1){
                    if(mapa->PesquisaPosicao(mapa->getLinhas()-1,0,u)!=0)
                        verx= 0;
                    else{
                        verx=x;
                        very=y;
                    }
                }
    }

    if(dir==7){ //OESTE
        verx=x;
        very=y-mov;
        if(very < 0){     
                    if(mapa->PesquisaPosicao(verx,mapa->getColunas()-1,u)!=0){
                        very=mapa->getColunas()-1;
                    }
                    else
                        very=y;
                }
    }

    if(dir==8){ //NOROESTE
        verx=x-mov;
        very=y-mov;
        if(verx < 0 && very < 0){
                    if(mapa->PesquisaPosicao(mapa->getLinhas()-1,mapa->getColunas()-1,u)!=0){
                        verx=mapa->getLinhas()-1;
                        very=mapa->getColunas()-1;
                    }
                    else{
                        verx=x;
                        very=y;
                    }
                }
                else if(verx < 0 ){
                    if(mapa->PesquisaPosicao(mapa->getLinhas()-1,very,u)!=0)
                        verx=mapa->getLinhas()-1;
                    else{
                        very=y;
                        verx=x;
                    }
                } 
                else if(very < 0){
                    if(mapa->PesquisaPosicao(x,mapa->getColunas()-1,u)!=0)
                        very=mapa->getColunas()-1;
                    else{
                        very=y;
                        verx=x;
                    } 
                }
    }
        
    if(dir==9){return false;} //FICA
     
    if(mapa->PesquisaPosicao(verx,very,u)==1 ){ //saida de porto para mar
        if(mapa->PesquisaPosPorto(x,y)==true){
            mapa->desassociaPorto(id,x,y);
            x=verx;
            y=very;
            agua--;
            if(agua == 0)
                tripulacao--;
            
          //  if(tripulacao==0) //por fazer
            return true;
        }
        else{                                   //saida de mar para mar
            x=verx;
            y=very;
            agua--;
            if(agua == 0)
                tripulacao--;
            
            //if(tripulacao==0) //por fazer
            return true;
        }
    }
    
    else if(mapa->PesquisaPosicao(verx,very,u)==2){ //entra num porto
        if(mapa->associaNavio(this,verx,very)==true){
            agua=capagua;
            x=verx;
            y=very;
            return true;
        }
    }
    return false;
}

bool Navio::moveNavio(Mapa* mapa,int dir,Jogo j,int mov){
    int verx=-1,very=-1;
  //  cout <<x<<" " <<y<< "\n";
    if(dir==1){ //NORTE
        verx=x-mov;
        very=y;
        if(verx < 0){   //se sair do mapa na próxima célula
                if(mapa->PesquisaPosicaoPirate(mapa->getLinhas()-1,y,j)==1)  //Se a próxima célula no outro lado do mapa for do tipo mar
                    verx=mapa->getLinhas()-1;                  //actualiza a variável para ser possível o navio aparacer na nova célula
                else
                    verx=x;                     //Se a próxima célula no outro lado do mapa não for do tipo mar, atribui-se a posição presente do navio à variável.
                                                //Deste modo não há entrada em mais nenhuma condição e o navio mantém-se na sua posição actual.
            }
    }    

    if(dir==2){ //NORDESTE
        verx=x-mov;
        very=y+mov;
        if(verx < 0 && very > mapa->getColunas()-1){
                    if(mapa->PesquisaPosicaoPirate(mapa->getLinhas()-1,0,j)==1){
                        verx=mapa->getLinhas()-1;
                        very=0;
                    }
                    else{
                        verx=x;
                        very=y;
                    }
                }
                else if(verx < 0){
                    if(mapa->PesquisaPosicaoPirate(mapa->getLinhas()-1,y,j)==1)
                        verx=mapa->getLinhas()-1;
                    else{
                        verx=x;
                        very=y;
                    }
                }
                else if(very > mapa->getLinhas()-1){
                    if(mapa->PesquisaPosicaoPirate(x,mapa->getColunas()-1,j)==1)
                        very=mapa->getLinhas()-1;
                    else{
                        very=y;
                        verx=x;
                    }
                }
    }

    if(dir==3){ //ESTE
        verx=x;
        very=y+mov;
        if(very > mapa->getColunas()-1){
                    if(mapa->PesquisaPosicaoPirate(x,0,j)==1){
                        very=0;
                    }
                    else
                        very=y;
                }
    }
        
    if(dir==4){ //SUDESTE
        verx=x+mov;
        very=y+mov;
        if(verx > mapa->getLinhas()-1 && very > mapa->getColunas()-1){
                    if(mapa->PesquisaPosicaoPirate(0,0,j)==1){
                        verx=0;
                        very=0;
                    }
                    else{
                        verx=x;
                        very=y;
                    }
                }
        else if(verx > mapa->getLinhas()-1){
                    if(mapa->PesquisaPosicaoPirate(0,very,j)==1)
                        verx=0;
                    else{
                        verx=x;
                        very=y;
                    }
                }
        else if(very > mapa->getColunas()-1){
                    if(mapa->PesquisaPosicaoPirate(x,mapa->getColunas()-1,j)==1)
                        very=0;
                    else{
                        very=y;
                        verx=x;
                    }
                }
    }

    if(dir==5){ //SUL
        verx=x+mov;
        very=y;
        if(verx > mapa->getLinhas()-1){
                    if(mapa->PesquisaPosicaoPirate(0,y,j)==1){
                        verx=0;
                    }
                    else{
                        verx=x;
                    }
                }
    }

    if(dir==6){ //SUDOESTE
        verx=x-mov;
        very=y-mov;
        if(verx > mapa->getLinhas()-1 && very < 0){
                    if(mapa->PesquisaPosicaoPirate(0,mapa->getColunas()-1,j)==1){
                        verx=0;
                        very=mapa->getColunas()-1;
                    }
                    else{
                        verx=x;
                        very=y;
                    }
                }
                else if(very < 0){
                    if(mapa->PesquisaPosicaoPirate(x,mapa->getColunas()-1,j)==1)
                        very=mapa->getColunas()-1;
                    else{
                        very=y;
                        verx=x;
                    }
                }
                else if(verx > mapa->getLinhas()-1){
                    if(mapa->PesquisaPosicaoPirate(mapa->getLinhas()-1,0,j)==1)
                        verx= 0;
                    else{
                        verx=x;
                        very=y;
                    }
                }
    }

    if(dir==7){ //OESTE
        verx=x;
        very=y-mov;
        if(very < 0){     
                    if(mapa->PesquisaPosicaoPirate(x,mapa->getColunas()-1,j)==1){
                        very=mapa->getColunas()-1;
                    }
                    else
                        very=y;
                }
    }

    if(dir==8){ //NOROESTE
        verx=x-mov;
        very=y-mov;
        if(verx < 0 && very < 0){
                    if(mapa->PesquisaPosicaoPirate(mapa->getLinhas()-1,mapa->getColunas()-1,j)==1){
                        verx=mapa->getLinhas()-1;
                        very=mapa->getColunas()-1;
                    }
                    else{
                        verx=x;
                        very=y;
                    }
                }
                else if(verx < 0 ){
                    if(mapa->PesquisaPosicaoPirate(mapa->getLinhas()-1,y,j)==1)
                        verx=mapa->getLinhas()-1;
                    else{
                        very=y;
                        verx=x;
                    }
                } 
                else if(very < 0){
                    if(mapa->PesquisaPosicaoPirate(x,mapa->getColunas()-1,j)==1)
                        very=mapa->getColunas()-1;
                    else{
                        very=y;
                        verx=x;
                    } 
                }
    }
        
    if(dir==9){return false;} //FICA
     
    if(mapa->PesquisaPosicaoPirate(verx,very,j)==1 ){ //saida de porto para mar
        if(mapa->PesquisaPosPorto(x,y)==true){
            mapa->desassociaPorto(id,x,y);
            x=verx;
            y=very;
            if(agua == 0)
                tripulacao--;
            
          //  if(tripulacao==0) //por fazer
            return true;
        }
        else{                                   //saida de mar para mar
            x=verx;
            y=very;
            if(agua == 0)
                tripulacao--;
            
            //if(tripulacao==0) //por fazer
            return true;
        }
    }
    
    else if(mapa->PesquisaPosicaoPirate(verx,very,j)==2){ //entra num porto
        if(mapa->associaNavio(this,verx,very)==true){
            agua=capagua;
            x=verx;
            y=very;
            return true;
        }
    }
    return false;
}

bool Navio::MoverRandom(Mapa * mapa,User u){
    int dir;
    int mov=rand()%movimento+1;
    dir = rand()%9+1;
    moveNavio(mapa,dir,u,mov);
    //cout <<dir<<endl;
}

bool Navio::MoverRandom(Mapa * mapa,Jogo j){
    int dir;
    int mov=rand()%movimento+1;
    dir = rand()%9+1;
    moveNavio(mapa,dir,j,mov);
    //cout <<dir<<endl;
}

Navio * Navio::fabrica(string tipo){
	if (tipo == "E") {
            return new Escuna;
	}
        if (tipo == "V"){
            return new Veleiro;
        }
        if (tipo == "G"){
            return new Galeao;
        }            
        if (tipo == "F"){
            return new Fragata;
        }
        if (tipo == "Esp"){
            return new Especial;
        }
	return nullptr;
}

Navio & Navio::operator=(const Navio& orig) {
    // prevencao da auto-atribuicao
    if(this == &orig){
        return *this;
    }
    agua=orig.agua;
    tripulacao=orig.tripulacao;
    capagua=orig.capagua;
    captripulacao=orig.captripulacao;
    x=orig.x;
    y=orig.y;
    
    
    return *this;
}

/*ostream & operator<<(ostream & saida, const Navio & x) {
    saida << x.getAsString();
    return saida;
}         POR FUNCIONAR          */ 

string Navio::getAsString()const{
    ostringstream oss;
    oss << "\nNavio: " << id << "\nagua: " << agua
         <<"\nTripulacao: " << tripulacao << "\ncruise: " << cruise
         <<pirate<<"\nturn:"<<turn<<endl;
    return oss.str();
}