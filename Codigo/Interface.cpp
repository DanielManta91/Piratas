#include "Interface.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include "Jogo.h"
#include "Celula.h"
#include "Mapa.h"
#include "User.h"
#include "Navio.h"
#include "Evento.h"

using namespace std;

Interface::Interface() {
}

Interface::~Interface() {
}

vector<string> Interface::split(const string& s, char separa) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, separa)) {
        tokens.push_back(token);
    }
    return tokens;
}

bool Interface::iniciaConfig(Jogo& j,User& u) {
    string comando, s,buffer;
    vector<string> tokens;
    vector<string> matriz;
    int val,linhas=0,colunas=0,nmap=0;
    
    
    do{
        cout << "Comando:";
        getline(cin, comando);

        tokens = split(comando, ' ');

        if (tokens[0] == "config") {
            ifstream dados(tokens[1]);

            if (!dados.is_open()) {
                return false;
            }

            while (!dados.eof()) {
                // ler string com os dados da pessoa
                getline(dados, s);

                istringstream iss(s);
                
                //ler dados do mapa
                iss >> buffer >> val;  

                if(buffer == "linhas"){
                    linhas = val;
                  //   cout<<val<<endl;
                }

                if(buffer == "colunas"){
                    colunas = val;
                  //   cout<<val<<endl;
                }

                if((linhas > 0 && colunas > 0) && nmap==0){
                    for(int i = 0;i<linhas;i++){
                        getline(dados,s);
                        matriz.push_back(s);
                    }
                    nmap=1;
                }

                if(buffer == "moedas"){
                    u.setMoedas(val);
                  //  cout<< val<<endl;
                }

                if(buffer == "probpirata"){
                    j.setPirata(val);
                   // cout<< val<<endl;
                }

                if(buffer == "preconavio"){
                    j.setPreconavio(val);
                   // cout<< val<<endl;
                }

                if(buffer == "precosoldado"){
                    j.setPrecosoldado(val);
                   // cout<< val<<endl;
                }

                if(buffer == "precovendepeixe"){
                  j.setPrecovendpeixe(val);
                  //  cout<< val<<endl;
                }

                if(buffer == "precovendemercado"){
                  j.setPrecovendmercad(val);
                  //  cout<< val<<endl;
                }

                if(buffer == "precocompramercado"){
                   j.setPrecocompmercad(val);
                   // cout<< val<<endl;
                }

                if(buffer == "soldadosporto"){
                   j.setSoldadosporto(val);
                   // cout<< val<<endl;
                }

                //Incerto pode pertencer aos eventos

                if(buffer == "probevento"){
                   j.setProbevento(val);
                   //  cout<< val<<endl;
                }

                if(buffer == "probtempestade"){
                   j.setProbtempestade(val);
                   //  cout<< val<<endl;
                }

                if(buffer == "probsereias"){
                   j.setProbsereias(val);
                   //  cout<< val<<endl;
                }

                if(buffer == "probcalmaria"){
                   j.setProbcalmaria(val);
                   //  cout<< val<<endl;
                }

                if(buffer == "probmotim"){
                   j.setProbmotim(val);
                   //  cout<< val<<endl;
                }

            }
            dados.close(); 
           // cout<<"\naqui";
            j.createMapa(linhas,colunas,matriz);
            ///cout<<"\naqui";
            j.getMapa()->nomeiaPortoPrinc();
            //cout<<"\naqui";
                       // cout <<"aqui";
            cout<<j.getMapa()->getAsString(u,j)<<"Moedas Jogador: "<<u.getMoedas()<<endl;
cout<<"\naqui";
            return true;
        } 
        else
            if(tokens[0] != "sair")
                cout << "comando incorrecto" << endl;
    }while(comando!="sair");
    
    return false;
}


bool Interface::iniciaExec(Jogo& j,User& u) {
    string comando, s;
    vector <string> tokens;
    vector <string> tokens2;
    vector <string> comandos;
    while(1){
        comandos.clear();
        comando=" ";
        while(comando!="prox"){
                cout << "Comando:";
                getline(cin, comando);
        
                comandos.push_back(comando);
            }
        
        
        for(unsigned int index=0;index<comandos.size();index++){
            
            
        tokens = split(comandos[index],' ');
    
        if (tokens[0] == "exec") {  
            ifstream dados(tokens[1]);

            if (!dados.is_open()) {
                return false;
            }

            while (getline(dados,s)) {
                // ler string com os dados
                
                tokens = split(s,'\n');
                for(unsigned int i=0;i<tokens.size();i++)
                {
                    
                tokens2= split(tokens[i],' ');

        if(tokens2[0] == "remnavuser"){
            if(tokens2.size()==2){
                istringstream iss(tokens[1]);
                int id;
                iss>> id;
                if(u.getNavioUserID(id))
                u.removeNavioID(id);
                else
                    cout <<"Navio Invalido"<<endl;
            }
        }

        if(tokens2[0] == "compranav"){
            if(tokens2.size()==2){
                istringstream iss(tokens2[1]);
                string t;
                iss>> t;
                compranav(j,t,u);
                
               // cout<<mapa->getAsString(u)<<"Moedas Jogador: "<<u.getMoedas()<<endl;
            }
        }
            
        if(tokens2[0] == "vendenav"){
            if(tokens2.size()==2){
                istringstream iss(tokens[1]);
                int nr;
                iss>>nr;
                if(nr > 0 && nr <= u.getnrNaviosUser()){
                    vendenav(j,nr,u);
                    //cout<<mapa->getAsString(u)<<"Moedas Jogador: "<<u.getMoedas()<<endl;
                }
                else
                    cout << "Insira o nr de um navio que exista" << endl;
            }
            else
                cout << "Insira o nr do Navio desejado" << endl;
        }

        if(tokens2[0] == "listanav"){
            for(unsigned int i=1;i<=u.getnrNaviosUser();i++)
                cout<<u.getNavioUserPos(i)->getAsString();
        }
        
        if(tokens2[0] == "listaev"){
            for(unsigned int i=0;i<j.getnrEventosZona();i++)
                cout<<"evento:"<<i<<" Conta:"<<j.getEventoZona(i)->getConta()<<" LimConta:"<<j.getEventoZona(i)->getLim()<<endl;
            for(unsigned int i=0;i<j.getnrEventos();i++)
                cout<<"evento:"<<i<<" Conta:"<<j.getEvento(i)->getConta()<<" LimConta:"<<j.getEvento(i)->getLim()<<endl;
        }
        
        if(tokens2[0] == "lista"){
            cout<<"\nPreco Navios:"<<"\nGaleao:"<<j.getPreconavio()*6<<"\nCaravela:"<<j.getPreconavio()*5<<"\nFragata:"<<j.getPreconavio()*4
                    <<"\nVeleiro:"<<j.getPreconavio()*2<<"\nEscuna:"<<j.getPreconavio()<<"\n-----"
                    <<"\nSoldados:"<<j.getPrecosoldado()<<"\nPeixe:"<<j.getPrecovendpeixe()<<"\nMercadorias:"
                    <<"\nVender:"<<j.getPrecovendmercad()<<"\nComprar:"<<j.getPrecocompmercad()<<endl;
        }
        

        if(tokens2[0] == "compra"){
               if(tokens2.size() == 3){
                istringstream iss(tokens[1]);
                int nr;
                int quant;
                iss>>nr;
                if(u.getNavioUserID(nr)!=nullptr){
                    istringstream iss(tokens2[2]);
                    iss>>quant;
                    if(j.getMapa()->PesquisaPosPorto(u.getNavioUserID(nr)->getx(),u.getNavioUserID(nr)->gety())==true)
                        compra(j,nr,quant,u);
                    //cout<<mapa->getAsString(u)<<"Moedas Jogador: "<<u.getMoedas()<<endl;
                }
                else
                    cout << "Insira o nr de um navio que exista" << endl;
            }
            else
                cout << "Insira o nr do Navio desejado" << endl;
        }

        if(tokens2[0] == "vende"){
            if(tokens2.size()==2){
                istringstream iss(tokens2[1]);
                int nr;
                iss>>nr;
                if(u.getNavioUserID(nr)!=nullptr){
                    if(j.getMapa()->PesquisaPosPorto(u.getNavioUserID(nr)->getx(),u.getNavioUserID(nr)->gety())==true)
                        vende(j,nr,u);
                    //cout<<mapa->getAsString(u)<<"Moedas Jogador: "<<u.getMoedas()<<endl;
                }
                else
                    cout << "Insira o nr de um navio que exista" << endl;
            }
            else
                cout << "Insira o nr do Navio desejado" << endl;
        }
           
        if(tokens2[0] == "move"){
            if(tokens2.size() == 3){
                istringstream iss(tokens2[1]);
                int nr;
                int dir;
                string orienta;
                iss>>nr;
                if(u.getNavioUserID(nr)!=nullptr){
                    istringstream iss(tokens2[2]);
                    iss>>orienta;
                    
                    if(orienta == "C")
                        dir = 1;
                    if(orienta == "CD")
                        dir=2;
                    if(orienta == "D")
                        dir=3;
                    if(orienta == "BD")
                        dir=4;
                    if(orienta == "B")
                        dir=5;
                    if(orienta == "BE")
                        dir=6;
                    if(orienta == "E")
                        dir=7;
                    if(orienta == "CE")
                        dir=8;
                    
                    if(dir>0 && dir<9)
                        if(u.getNavioUserID(nr)->getTurn()==false && u.getNavioUserID(nr)->getPirate()==false && u.getNavioUserID(nr)->getCruise()==false){
                            u.getNavioUserID(nr)->moveNavio(j.getMapa(),dir,u,u.getNavioUserID(nr)->getMov());
                            u.getNavioUserID(nr)->setTurn(true);
                        }
                        else{
                            cout<<"O navio ja efectuou o seu turno\n";
                    }
                    else{
                        cout<<"Direção invalida"<<endl;
                    }
                   // cout<<mapa->getAsString(u)<<"Moedas Jogador: "<<u.getMoedas()<<endl;
                }
                else
                    cout << "Insira o nr de um navio que exista" << endl;
            }
            else
                cout << "Insira o nr do Navio desejado" << endl;
        }

        if(tokens2[0] == "auto"){
            if(tokens2.size() == 2){
                istringstream iss(tokens2[1]);
                int nr;
            
                iss >> nr; 
                if(u.getNavioUserID(nr)!=nullptr){       
                    u.getNavioUserID(nr)->setCruise(true);
                   // cout<<mapa->getAsString(u)<<"Moedas Jogador: "<<u.getMoedas()<<endl;
                }
                else
                    cout << "Insira o nr de um navio que exista" << endl;
            }
            else
                cout << "Insira o nr do Navio desejado" << endl;
        }

        if(tokens2[0] == "stop"){
              if(tokens2.size() == 2){
                istringstream iss(tokens[1]);
                int nr;
            
                iss >> nr; 
                if(u.getNavioUserID(nr)!=nullptr){       
                    u.getNavioUserID(nr)->setCruise(false);
                    //cout<<mapa->getAsString(u)<<"Moedas Jogador: "<<u.getMoedas()<<endl;
                }
                else
                    cout << "Insira o nr de um navio que exista" << endl;
            }
            else
                cout << "Insira o nr do Navio desejado" << endl;
        }

        if(tokens2[0] == "pirata"){
            if(tokens2.size()==4){
                istringstream iss(tokens[1]);
                int x;
                int y;
                string t;
                iss>> x;
                istringstream iss2(tokens[2]);
                iss2>> y;
                istringstream iss3(tokens[3]);
                iss3>> t;
                if(x<j.getMapa()->getLinhas() && x>=0 && y<j.getMapa()->getColunas() && y>=0)
                    pirate(j,x,y,t);
                else
                    cout<<"Coordenadas Invalidas\n";
                
            }
            else 
                cout<<"Insira os dados segundo o formato (x y tipo)\n";
        }

        if(tokens2[0] == "evpos"){
            if(tokens2.size() == 4){
             istringstream iss(tokens2[1]);
             int x;
             int y;
             string t;
             iss>>t;
             istringstream iss2(tokens2[2]);
             iss2>>x;
             istringstream iss3(tokens2[3]);
             iss3>>y;
             if(t=="C" || t=="T")
                 if(x<j.getMapa()->getLinhas() && x>=0 && y<j.getMapa()->getColunas() && y>=0){
                     j.acrescentaEvento(t,x,y);
                 }
                 else
                     cout<<"Coordenadas Invalidas\n";
             else{
                 cout<< "\nTipo de evento inválido(válidos: C || T)";
             }
            }
            else{
                cout <<"\nInsira os dados segundo o formato(E X Y)";
            }
        }

        if(tokens2[0] == "evnav"){
               if(tokens2.size()==3){
                istringstream iss(tokens2[2]);
                int nr;
                iss>>nr;
                if(u.getNavioUserID(nr)!=nullptr){
                    istringstream iss(tokens[1]);
                    string t;
                    iss>>t;
                    
                    if(t=="S" || t=="M") {
                        j.acrescentaEvento(t,u.getNavioUserID(nr));
                    //cout<<"Evento:"<<t<<" criado"<<endl;
                    }
                    else
                        cout << "\nEvento invalido"<<endl;
                }
                else
                    cout << "\nNavio invalido"<<endl;
            }
               else
                   cout << "\nInsira os dados segundo o formato(E N)"<<endl;
        }

        if(tokens2[0] == "moedas"){
            if(tokens2.size() == 2){
                istringstream iss(tokens2[1]);
                int nr;
            
                iss >> nr;
                if(nr > 0)
                    u.setMoedas(u.getMoedas() + nr);
            }
        }

        if(tokens2[0] == "vaipara"){
                //  cout<< val<<endl;
        }

        if(tokens2[0] == "comprasold"){
            if(tokens2.size()==3){
                istringstream iss(tokens2[1]);
                int nr;
                iss>>nr;
                if(u.getNavioUserID(nr)!=nullptr){
                    istringstream iss(tokens2[2]);
                    int sold;
                    iss>>sold;
                    comprasold(j,nr,sold,u);
                }
            }
            }

            if(tokens2[0] == "saveg"){
                    //  cout<< val<<endl;
            }

            if(tokens2[0] == "loadg"){
                  //  cout<< val<<endl;
            }

            if(tokens2[0] == "delg"){
                   //  cout<< val<<endl;
            }

            if(tokens2[0] == "sair"){
                return true;
                   //  cout<< val<<endl;
            }
        }
                
        }
        dados.close(); 
        }
        
       
        
        if(tokens[0] == "remnavuser"){
            if(tokens.size()==2){
                istringstream iss(tokens[1]);
                int id;
                iss>> id;
                if(u.getNavioUserID(id))
                u.removeNavioID(id);
                else
                    cout <<"Navio Invalido"<<endl;
            }
        }

        if(tokens[0] == "compranav"){
            if(tokens.size()==2){
                istringstream iss(tokens[1]);
                string t;
                iss>> t;
                compranav(j,t,u);
                
               // cout<<mapa->getAsString(u)<<"Moedas Jogador: "<<u.getMoedas()<<endl;
            }
        }
            
        if(tokens[0] == "vendenav"){
            if(tokens.size()==2){
                istringstream iss(tokens[1]);
                int nr;
                iss>>nr;
                if(nr > 0 && nr <= u.getnrNaviosUser()){
                    vendenav(j,nr,u);
                    //cout<<mapa->getAsString(u)<<"Moedas Jogador: "<<u.getMoedas()<<endl;
                }
                else
                    cout << "Insira o nr de um navio que exista" << endl;
            }
            else
                cout << "Insira o nr do Navio desejado" << endl;
        }

        if(tokens[0] == "listanav"){
            for(unsigned int i=1;i<=u.getnrNaviosUser();i++)
                cout<<u.getNavioUserPos(i)->getAsString();
        }
        
        if(tokens[0] == "listaev"){
            for(unsigned int i=0;i<j.getnrEventosZona();i++)
                cout<<"evento:"<<i<<" Conta:"<<j.getEventoZona(i)->getConta()<<" LimConta:"<<j.getEventoZona(i)->getLim()<<endl;
            for(unsigned int i=0;i<j.getnrEventos();i++)
                cout<<"evento:"<<i<<" Conta:"<<j.getEvento(i)->getConta()<<" LimConta:"<<j.getEvento(i)->getLim()<<endl;
        }
        
        if(tokens[0] == "lista"){
            cout<<"\nPreco Navios:"<<"\nGaleao:"<<j.getPreconavio()*6<<"\nCaravela:"<<j.getPreconavio()*5<<"\nFragata:"<<j.getPreconavio()*4
                    <<"\nVeleiro:"<<j.getPreconavio()*2<<"\nEscuna:"<<j.getPreconavio()<<"\n-----"
                    <<"\nSoldados:"<<j.getPrecosoldado()<<"\nPeixe:"<<j.getPrecovendpeixe()<<"\nMercadorias:"
                    <<"\nVender:"<<j.getPrecovendmercad()<<"\nComprar:"<<j.getPrecocompmercad()<<endl;
        }
        

        if(tokens[0] == "compra"){
               if(tokens.size() == 3){
                istringstream iss(tokens[1]);
                int nr;
                int quant;
                iss>>nr;
                if(u.getNavioUserID(nr)!=nullptr){
                    istringstream iss(tokens[2]);
                    iss>>quant;
                    if(j.getMapa()->PesquisaPosPorto(u.getNavioUserID(nr)->getx(),u.getNavioUserID(nr)->gety())==true)
                        compra(j,nr,quant,u);
                    //cout<<mapa->getAsString(u)<<"Moedas Jogador: "<<u.getMoedas()<<endl;
                }
                else
                    cout << "Insira o nr de um navio que exista" << endl;
            }
            else
                cout << "Insira o nr do Navio desejado" << endl;
        }

        if(tokens[0] == "vende"){
            if(tokens.size()==2){
                istringstream iss(tokens[1]);
                int nr;
                iss>>nr;
                if(u.getNavioUserID(nr)!=nullptr){
                    if(j.getMapa()->PesquisaPosPorto(u.getNavioUserID(nr)->getx(),u.getNavioUserID(nr)->gety())==true)
                        vende(j,nr,u);
                    //cout<<mapa->getAsString(u)<<"Moedas Jogador: "<<u.getMoedas()<<endl;
                }
                else
                    cout << "Insira o nr de um navio que exista" << endl;
            }
            else
                cout << "Insira o nr do Navio desejado" << endl;
        }

        if(tokens[0] == "move"){
            if(tokens.size() == 3){
                istringstream iss(tokens[1]);
                int nr;
                int dir;
                string orienta;
                iss>>nr;
                if(u.getNavioUserID(nr)!=nullptr){
                    istringstream iss(tokens[2]);
                    iss>>orienta;
                    
                    if(orienta == "C")
                        dir = 1;
                    if(orienta == "CD")
                        dir=2;
                    if(orienta == "D")
                        dir=3;
                    if(orienta == "BD")
                        dir=4;
                    if(orienta == "B")
                        dir=5;
                    if(orienta == "BE")
                        dir=6;
                    if(orienta == "E")
                        dir=7;
                    if(orienta == "CE")
                        dir=8;
                    
                    if(dir>0 && dir<9)
                        if(u.getNavioUserID(nr)->getTurn()==false && u.getNavioUserID(nr)->getPirate()==false && u.getNavioUserID(nr)->getCruise()==false){
                            u.getNavioUserID(nr)->moveNavio(j.getMapa(),dir,u,u.getNavioUserID(nr)->getMov());
                            u.getNavioUserID(nr)->setTurn(true);
                        }
                        else{
                            cout<<"O navio ja efectuou o seu turno\n";
                    }
                    else{
                        cout<<"Direção invalida"<<endl;
                    }
                   // cout<<mapa->getAsString(u)<<"Moedas Jogador: "<<u.getMoedas()<<endl;
                }
                else
                    cout << "Insira o nr de um navio que exista" << endl;
            }
            else
                cout << "Insira o nr do Navio desejado" << endl;
        }

        if(tokens[0] == "auto"){
            if(tokens.size() == 2){
                istringstream iss(tokens[1]);
                int nr;
            
                iss >> nr; 
                if(u.getNavioUserID(nr)!=nullptr){       
                    u.getNavioUserID(nr)->setCruise(true);
                   // cout<<mapa->getAsString(u)<<"Moedas Jogador: "<<u.getMoedas()<<endl;
                }
                else
                    cout << "Insira o nr de um navio que exista" << endl;
            }
            else
                cout << "Insira o nr do Navio desejado" << endl;
        }

        if(tokens[0] == "stop"){
              if(tokens.size() == 2){
                istringstream iss(tokens[1]);
                int nr;
            
                iss >> nr; 
                if(u.getNavioUserID(nr)!=nullptr){       
                    u.getNavioUserID(nr)->setCruise(false);
                    //cout<<mapa->getAsString(u)<<"Moedas Jogador: "<<u.getMoedas()<<endl;
                }
                else
                    cout << "Insira o nr de um navio que exista" << endl;
            }
            else
                cout << "Insira o nr do Navio desejado" << endl;
        }

        if(tokens[0] == "pirata"){
            if(tokens.size()==4){
                istringstream iss(tokens[1]);
                int x;
                int y;
                string t;
                iss>> x;
                istringstream iss2(tokens[2]);
                iss2>> y;
                istringstream iss3(tokens[3]);
                iss3>> t;
                if(x<j.getMapa()->getLinhas() && x>=0 && y<j.getMapa()->getColunas() && y>=0)
                    pirate(j,x,y,t);
                else
                    cout<<"Coordenadas Invalidas\n";
                
            }
            else 
                cout<<"Insira os dados segundo o formato (x y tipo)\n";
        }

        if(tokens[0] == "evpos"){
            if(tokens.size() == 4){
             istringstream iss(tokens[1]);
             int x;
             int y;
             string t;
             iss>>t;
             istringstream iss2(tokens[2]);
             iss2>>x;
             istringstream iss3(tokens[3]);
             iss3>>y;
             if(t=="C" || t=="T")
                 if(x<j.getMapa()->getLinhas() && x>=0 && y<j.getMapa()->getColunas() && y>=0){
                     j.acrescentaEvento(t,x,y);
                 }
                 else
                     cout<<"Coordenadas Invalidas\n";
             else{
                 cout<< "\nTipo de evento inválido(válidos: C || T)";
             }
            }
            else{
                cout <<"\nInsira os dados segundo o formato(E X Y)";
            }
        }

        if(tokens[0] == "evnav"){
               if(tokens.size()==3){
                istringstream iss(tokens[2]);
                int nr;
                iss>>nr;
                if(u.getNavioUserID(nr)!=nullptr){
                    istringstream iss(tokens[1]);
                    string t;
                    iss>>t;
                    
                    if(t=="S" || t=="M") {
                        j.acrescentaEvento(t,u.getNavioUserID(nr));
                    //cout<<"Evento:"<<t<<" criado"<<endl;
                    }
                    else
                        cout << "\nEvento invalido"<<endl;
                }
                else
                    cout << "\nNavio invalido"<<endl;
            }
               else
                   cout << "\nInsira os dados segundo o formato(E N)"<<endl;
        }

        if(tokens[0] == "moedas"){
            if(tokens.size() == 2){
                istringstream iss(tokens[1]);
                int nr;
            
                iss >> nr;
                if(nr > 0)
                    u.setMoedas(u.getMoedas() + nr);
            }
        }

        if(tokens[0] == "vaipara"){
                //  cout<< val<<endl;
        }

        if(tokens[0] == "comprasold"){
            if(tokens.size()==3){
                istringstream iss(tokens[1]);
                int nr;
                iss>>nr;
                if(u.getNavioUserID(nr)!=nullptr){
                    istringstream iss(tokens[2]);
                    int sold;
                    iss>>sold;
                    comprasold(j,nr,sold,u);
                }
            }
            }

            if(tokens[0] == "saveg"){
                    //  cout<< val<<endl;
            }

            if(tokens[0] == "loadg"){
                  //  cout<< val<<endl;
            }

            if(tokens[0] == "delg"){
                   //  cout<< val<<endl;
            }

            if(tokens[0] == "sair"){
                return true;
                   //  cout<< val<<endl;
            }

            if(index==comandos.size()-1){

                for(unsigned int i=1;i<=u.getnrNaviosUser();i++){
                    u.getNavioUserPos(i)->setTurn(false);
                }

                for(unsigned int i=1;i<=u.getnrNaviosUser();i++)
                    if(u.getNavioUserPos(i)->getPirate()==true)
                        u.getNavioUserPos(i)->MoverRandom(j.getMapa(),u);


                for(unsigned int i=1;i<=j.getnrNaviosJogo();i++)
                    j.getNavioJogoPos(i)->MoverRandom(j.getMapa(),j);
                
                for(unsigned int i=1;i<=u.getnrNaviosUser();i++)
                    if(u.getNavioUserPos(i)->getCruise()==true)
                        u.getNavioUserPos(i)->MoverRandom(j.getMapa(),u);
                
                for(unsigned int i=1;i<=u.getnrNaviosUser();i++){
                    cout<<"\n1";
                    if(u.getNavioUserPos(i)->getTipo()=='V' || u.getNavioUserPos(i)->getTipo()=='E'){
                        cout<<"check"<<endl;
                        u.getNavioUserPos(i)->setPeixe(j.getMapa());
                    }
                }


                j.localizaBatalha(u);
                j.EventosArea(u);
                j.EventosNavio(u);
                j.geraPeixe();
                
                

                cout<<j.getMapa()->getAsString(u,j)<<"Moedas Jogador: "<<u.getMoedas()<<endl;             

                for(unsigned int i=0;i<j.getnrEventosZona();i++){
                    //cout<<"aqui3\n";
                    j.getEventoZona(i)->inConta();
                   // cout<<"aqui4\n";
                    if(j.getEventoZona(i)->getConta()==j.getEventoZona(i)->getLim()){
                        j.removeEventoZona(i);
                    }
                }

                for(unsigned int i=0;i<j.getnrEventos();i++){
                    j.getEvento(i)->inConta();
                               // cout<<"ali\n";
                    if(j.getEvento(i)->getConta()==j.getEvento(i)->getLim()){
                        if(j.getEvento(i)->getTipo()=='M')
                            j.getEvento(i)->trocaPirate();
                        j.removeEventoNavio(i);
                    }
                }
                
              /*  int probpirate;
                probpirate=rand()%100;
                
                if(probpirate<10){
                    string t;
                    int escolha=rand()%100;
                    if(escolha<20)
                        t="C";
                    if(escolha >= 20 && escolha<40)
                        t="F";
                    if(escolha >= 40 && escolha<60)
                        t="G";
                    if(escolha >= 60 && escolha<80)
                        t="E";
                    if(escolha >= 80)
                        t="V";
                    
                    int x=rand()%5;
                    int y=rand()%5;
                   // cout <<"\nx: "<<x<<" y: "<<y<<endl;
                    pirate(j,x,y,t);
                }
                */
                int probevento=rand()%100;
                
                if(probevento<j.getProbevento()){
                    int probt=rand()%100;
                    if(probt<j.getProbcalmaria()){
                        //cout<<"1\n";
                        j.acrescentaEvento("C",rand()%j.getMapa()->getLinhas()-1,rand()%j.getMapa()->getColunas()-1);
                    }
                    else if(probt >= j.getProbcalmaria() && probt<(j.getProbcalmaria()+j.getProbmotim())){
                        //cout<<"2\n";
                        if(u.getnrNaviosUser()==0)
                        {}
                        else if (u.getnrNaviosUser()==1)
                            j.acrescentaEvento("M",u.getNavioUserPos(1));
                        else
                        j.acrescentaEvento("M",u.getNavioUserPos(rand()%u.getnrNaviosUser()+1));
                    }
                    else if(probt >=(j.getProbcalmaria()+j.getProbmotim()) && probt<(j.getProbcalmaria()+j.getProbmotim()+j.getProbsereias()))
                    {
                       // cout<<"3\n";
                        if(u.getnrNaviosUser()==0)
                        {}
                        else if (u.getnrNaviosUser()==1)
                            j.acrescentaEvento("S",u.getNavioUserPos(1));
                        else
                        j.acrescentaEvento("S",u.getNavioUserPos(rand()%u.getnrNaviosUser()+1));
                    }
                    else{
                        //cout<<"4\n";
                        j.acrescentaEvento("T",rand()%j.getMapa()->getLinhas()-1,rand()&j.getMapa()->getColunas()-1);
                    }
                    
                }
                
                

            }
        
        }
                  
        
        
    }
}

void Interface::compranav(Jogo& j,string t,User& u){
    int custo;
    if(t=="C")
        custo=j.getPreconavio()*5;
    else if(t=="F")
        custo=j.getPreconavio()*4;
    else if(t=="G")
        custo=j.getPreconavio()*6;
    else if(t=="E")
        custo=j.getPreconavio();
    else if(t=="V")
        custo=j.getPreconavio()*2;
    else{}
    
            if(u.getMoedas()-custo>=0){     //se tiver moedas suficientes para comprar um navio
                u.acrescentaNavio(t);                    //cria um navio jogador
                
                if(j.getMapa()->spawnNavioUser(u.getLastNavio())){      //se houver porto principal, navio fica atracado nesse porto
                    u.setMoedas(u.getMoedas()-custo);       //actualiza a quantidade de moedas
                }
                else
                    cout << endl << "Nao foi possivel comprar navio" << endl;
            }
            else
                cout << endl << "Fundos insuficientes para compra de navio" << endl;
}

void Interface::pirate(Jogo& j, int x, int y, string t){
    j.acrescentaNavio(t);
    if(j.getMapa()->spawnNavioJogo(j.getLastNavio(),x,y)){
        j.getLastNavio()->setPirate(true);
    }
    else
        cout << "spawn invalido\n";
}




bool Interface::vendenav(Jogo& j,int id,User& u){
    if(j.getMapa()->PesquisaPosPorto(u.getNavioUserID(id)->getx(),u.getNavioUserID(id)->gety())==true){
        j.getMapa()->desassociaPorto(id,u.getNavioUserID(id)->getx(),u.getNavioUserID(id)->gety());
        u.vendeNavio(id);
        u.setMoedas(u.getMoedas()+50);
        return true;
    }
    cout<<"Navio nao se encontra num porto"<<endl;
    return false;
}

bool Interface::compra(Jogo& j, int id, int quant,User& u){
    int custo;
    if(u.getNavioUserID(id)->getCarga()+quant > u.getNavioUserID(id)->getLimCarga()){
        quant=u.getNavioUserID(id)->getLimCarga()-quant;
        custo=j.getPrecocompmercad()*quant;
    }
    else
        custo=j.getPrecocompmercad()*quant;
    
    if(j.getMapa()->PesquisaPosPorto(u.getNavioUserID(id)->getx(),u.getNavioUserID(id)->gety())==true){
        if(u.getMoedas()-custo >= 0){
            u.setMoedas(u.getMoedas()-custo);
            u.getNavioUserID(id)->setCarga(quant);
            return true;
        }
        cout<<"Fundos insuficientes para efectuar compra"<<endl;
        return false;
    }
    cout<<"Navio nao se encontra atracado num porto"<<endl;
    return false;
}

bool Interface::vende(Jogo& j, int id,User& u){
    int ganho=0;
    ganho=j.getPrecovendmercad()*u.getNavioUserID(id)->getCarga();
    if(u.getNavioUserID(id)->getTipo()=='V' || u.getNavioUserID(id)->getTipo()=='E')
        ganho= ganho + j.getPrecovendpeixe()*u.getNavioUserID(id)->getPeixe();
    
    if(j.getMapa()->PesquisaPosPorto(u.getNavioUserID(id)->getx(),u.getNavioUserID(id)->gety())==true){
        u.setMoedas(u.getMoedas()+ganho);
        u.getNavioUserID(id)->setCarga(0);
        return true;
    }
    cout<<"Navio nao se encontra atracado num porto"<<endl;
    return false;
}

bool Interface::comprasold(Jogo& j, int id,int quant,User& u){
    int custo;
    if(u.getNavioUserID(id)->getTrip()+quant > u.getNavioUserID(id)->getLimCarga()){
        quant=u.getNavioUserID(id)->getLimTrip()-quant;
        custo=j.getPrecosoldado()*quant;
    }
    else
        custo=j.getPrecosoldado()*quant;
    
    if(j.getMapa()->PesquisaPosPorto(u.getNavioUserID(id)->getx(),u.getNavioUserID(id)->gety())==true){
        if(u.getMoedas()-custo >= 0){
            u.setMoedas(u.getMoedas()-custo);
            u.getNavioUserID(id)->setTrip(quant);
            return true;
        }
        else 
            return false;
    }
    return false;
}

