/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mapa.cpp
 * Author: Pedro
 * 
 * Created on 31 de Outubro de 2018, 16:27
 */
#include "Navio.h"
#include "Mapa.h"
#include "Jogo.h"
#include "Mar.h"
#include "User.h"
#include "Porto.h"
#include "Evento.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>


Mapa::Mapa(int l,int c,vector<string> s){
    for(unsigned int i=0;i<l;i++){
        cell.push_back(vector<Celula>());
        for(unsigned int j=0;j<c;j++){
            cell[i].push_back(Celula(s[i][j])); 
       }
    }

    linhas = l;
    colunas = c;
}

Mapa::~Mapa() {
}

int Mapa::getColunas() const{
    return colunas;
}

int Mapa::getLinhas() const{
    return linhas;
}

/*void Mapa::associaNavio(Navio* n, int x, int y){
    cell[x][y].getTerreno()->setNavio(n);
    char c = '0' + n->getID();
    cell[x][y].getTerreno()->setChar(c);
}*/

bool Mapa::spawnNavioUser(Navio* n){
    for(unsigned int i=0;i<linhas;i++)
        for(unsigned int j=0;j<colunas;j++){
            if(cell[i][j].getTerreno()->getChar() >= 'A' && cell[i][j].getTerreno()->getChar() <= 'Z'){ //se for porto amigável
                if(cell[i][j].getTerreno()->getPrincipal()){        //se existe algum porto principal
                    cell[i][j].getTerreno()->acrescentaNavio(n);      //o navio recebido é atracado nesse porto
                    n->setx(i);
                    n->sety(j);
                    n->setPirate(false);
                    
                    return true;
                }
            }
        }
    return false;
}

bool Mapa::spawnNavioJogo(Navio* n,int x,int y){
            if(cell[x][y].getTerreno()->getChar() >= 'a' && cell[x][y].getTerreno()->getChar() <= 'z'){ //se for porto amigável
                    cell[x][y].getTerreno()->acrescentaNavio(n);      //o navio recebido é atracado nesse porto
                    n->setx(x);
                    n->sety(y);
                    n->setPirate(true);
                    return true;

            }
            else if(cell[x][y].getTerreno()->getChar()=='.'){
                n->setx(x);
                n->sety(y);
                n->setPirate(true);
                return true;
            }
            else{
                cout <<"Posicao invalida\n"<<endl;
                return false;
            }
}

bool Mapa::nomeiaPortoPrinc(){
    for(unsigned int i=0;i<linhas;i++)
        for(unsigned int j=0;j<colunas;j++){
            if(cell[i][j].getTerreno()->getChar() >= 'A' && cell[i][j].getTerreno()->getChar() <= 'Z'){ //se existir porto amigo
                if(cell[i][j].getTerreno()->getPrincipal()){        //se já existe um porto principal, sai
                    return false;
                }
            }
        }
    
    for(unsigned int i=0;i<linhas;i++)
        for(unsigned int j=0;j<colunas;j++){
            if(cell[i][j].getTerreno()->getChar() >= 'A' && cell[i][j].getTerreno()->getChar() <= 'Z'){ //se existir porto amigo
                cell[i][j].getTerreno()->setPrincipal();    //transforma o primeiro porto que encontra em principal e sai
                return true;
            }
        }
}



string Mapa::getAsString(User u,Jogo jogo) const{
    ostringstream oss;
    string s;
    vector<string> mat;
    
    //PREENCHIMENTO DA PRIMEIRA LINHA DA MATRIZ DE APRESENTAÇÃO DO MAPA
    for(unsigned int i=0;i<linhas;i++){
        for(unsigned int j=0;j<colunas;j++){
            s+=cell[i][j].getTerreno()->getChar();
            if(cell[i][j].getTerreno()->getChar() >= 'A' && cell[i][j].getTerreno()->getChar() <= 'Z')  //Caso seja Porto amigo, apresentar o nr de navios atracados.
                s+='0' + u.contaNavios(i,j);
            else if(cell[i][j].getTerreno()->getChar() >= 'a' && cell[i][j].getTerreno()->getChar() <='z')   //Caso seja Porto pirata, apresentar o nr de navios atracados.
                s+='0' + jogo.contaNavios(i,j);
            else
                s+=cell[i][j].getTerreno()->getChar();
            

            
        }
        mat.push_back(s);   //Acrescentar primeira linha à matriz
        s.clear();
        //PREENCHIMENTO DA SEGUNDA LINHA DA MATRIZ DE APRESENTAÇÃO DO MAPA
        for(unsigned int y=0;y<colunas;y++){
                s+=cell[i][y].getTerreno()->getChar();
                s+=cell[i][y].getTerreno()->getChar();
        }
        mat.push_back(s);   //Acrescentar segunda linha à matriz
        s.clear();  
    }
    
    //INSERE PEIXE
    
    for (int i=0;i<linhas*2;i++){
        for(int j=0;j<colunas*2;j++){
            if(cell[i/2][j/2].getTerreno()->getChar()=='.'){
                if(cell[i/2][j/2].getTerreno()->getPeixe()==true){
                    mat[i][j]='*';
                }
            }
        }
    }
    
    
    
    
    
    //INSERE EVENTOS
    for (int i=0;i<linhas*2;i++){
        for(int j=0;j<colunas*2;j++){
            for(unsigned int y=0;y<jogo.getnrEventosZona();y++){
                for(unsigned int l=jogo.getEventoZona(y)->getx()*2;l<(jogo.getEventoZona(y)->getx()+2)*2;l++){
                    for(unsigned int m=jogo.getEventoZona(y)->gety()*2;m<(jogo.getEventoZona(y)->gety()+2)*2;m++){
                            mat[l][m]=jogo.getEventoZona(y)->getLetra();

                    }
                }
            }
        }
    }

    cout<<"hmm\n";
    //INSERE BARCOS
    //cout<<u.getnrNaviosUser()<<endl;
    for (int i=0;i<linhas*2;i++){
        for(int j=0;j<colunas*2;j++){
            for(int y=1;y<=u.getnrNaviosUser();y++){
                if(u.getNavioUserPos(y)->getx()*2 == i && u.getNavioUserPos(y)->gety()*2 == j && mat[i][j]=='.'){
                    mat[i][j]=u.getNavioUserPos(y)->getTipo();
                    mat[i+1][j]='0' + u.getNavioUserPos(y)->getID()/10;
                    mat[i][j+1]=u.getNavioUserPos(y)->getTipo();
                    mat[i+1][j+1]='0' + u.getNavioUserPos(y)->getID()%10;
                }
            }
        }
    }
    cout<<"hmm2\n";
    //INSERE BARCOS PIRATA
    for (int i=0;i<linhas*2;i++){
        for(int j=0;j<colunas*2;j++){
            for(int y=1;y<=jogo.getnrNaviosJogo();y++){
                if(jogo.getNavioJogoPos(y)->getx()*2 == i && jogo.getNavioJogoPos(y)->gety()*2 == j && mat[i][j]=='.'){
                    mat[i][j]=jogo.getNavioJogoPos(y)->getTipo();
                    mat[i+1][j]=jogo.getNavioJogoPos(y)->getID()/10;
                    mat[i][j+1]=jogo.getNavioJogoPos(y)->getTipo();
                    mat[i+1][j+1]='0' + jogo.getNavioJogoPos(y)->getID()%10;
                }
            }
        }
    }
    
    //cout<<"hmm3\n";

      //  cout<< "crash\n";
    //APRESENTAÇÃO DO MAPA EM CÉLULAS 2X2
    for(unsigned int i=0 ; i<linhas*2;i++){
        for(unsigned int j=0; j<colunas*2;j++){
            oss << mat[i][j];
        }
        oss<<endl;
    }
    return oss.str();
/*
    for(unsigned int i=0 ; i<linhas;i++){
        for(unsigned int j=0; j<colunas;j++){
            oss << cell[i][j].getTerreno()->getChar();
        }
        oss<<endl;
    }
    return oss.str();
 */
}

int Mapa::PesquisaPosicao(int x, int y,User u){
    if(cell[x][y].getTerreno()->getChar()=='+' || (cell[x][y].getTerreno()->getChar()>'a' && cell[x][y].getTerreno()->getChar() <'z'))
        return 0;
    if(cell[x][y].getTerreno()->getChar()=='.'){
        for(int i=1;i<=u.getnrNaviosUser();i++){       //verifica navios
            if(u.getNavioUserPos(i)->getx()==x && u.getNavioUserPos(i)->gety()==y)
                return 0;
        }
        
        
        
        return 1;

    }
    else if(cell[x][y].getTerreno()->getChar() >= 'A' && cell[x][y].getTerreno()->getChar() <= 'Z')
        return 2;
}

int Mapa::PesquisaPosicaoPirate(int x, int y,Jogo j){
    if(cell[x][y].getTerreno()->getChar()=='+')
        return 0;
    if(cell[x][y].getTerreno()->getChar()=='.'){
        for(int i=1;i<=j.getnrNaviosJogo();i++){       //verifica navios
            if(j.getNavioJogoPos(i)->getx()==x && j.getNavioJogoPos(i)->gety()==y)
                return 0;
        }
        return 1;

    }
    else if(cell[x][y].getTerreno()->getChar() >= 'a' && cell[x][y].getTerreno()->getChar() <= 'z')
        return 2;
}

bool Mapa::PesquisaPosPorto(int x, int y){
    if(cell[x][y].getTerreno()->getChar()>='A' && cell[x][y].getTerreno()->getChar()<='Z'){
        return true;
    }
    return false;
}

bool Mapa::PesquisaPosPortoPirate(int x,int y){
    if(cell[x][y].getTerreno()->getChar()>='a' && cell[x][y].getTerreno()->getChar()<='z'){
        return true;
    }
    return false;
}

bool Mapa::desassociaPorto(int id,int x,int y){
    if(cell[x][y].getTerreno()->getChar()>='A' && cell[x][y].getTerreno()->getChar()<='Z'){
        cell[x][y].getTerreno()->removeNavio(id);
        return true;
    }
    else
        return false;
}

bool Mapa::associaNavio(Navio* n, int x, int y){
    if(cell[x][y].getTerreno()->getChar()>='A' && cell[x][y].getTerreno()->getChar()<='Z'){
        cell[x][y].getTerreno()->acrescentaNavio(n);
        return true;
    }
    else
        return false;
}

char Mapa::getPos(int x,int y) const{
    return cell[x][y].getTerreno()->getChar();
}

void Mapa::setPos(char letra,int x,int y){
    cell[x][y].getTerreno()->setChar(letra);
}

bool Mapa::geraPeixe(){
    int flag=0;
    for(unsigned int i=0;i<linhas;i++){
        for(unsigned int j=0;j<colunas;j++){
            if(cell[i][j].getTerreno()->getChar()=='.'){
                int pesca=rand()%10000;
                if(pesca>9987 && flag==0){  //0.0013 de probabilidade
                    cout <<"PEIXE:"<<i<<" "<<j<<endl;
                    cell[i][j].getTerreno()->setPeixe(true);
                    flag=1;
                }
            }
        }
    }
    
    
}

bool Mapa::pesqPeixe(int x,int y) const{
    if(cell[x][y].getTerreno()->getChar()=='.'){
        if(cell[x][y].getTerreno()->getPeixe()==true){
            return true;
        }
        return false;
    }
    return false;
}

void Mapa::setPeixe(int x, int y){
    if(cell[x][y].getTerreno()->getChar()=='.'){
        if(cell[x][y].getTerreno()->getPeixe()==true){
            cell[x][y].getTerreno()->setPeixe(false);
        }
    }
}