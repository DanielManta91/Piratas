/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Pedro
 *
 * Created on 17 de Outubro de 2018, 12:50
 */

#include <iostream>
#include <string>
#include <vector>
#include "Interface.h"
#include "User.h"
#include "Jogo.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Jogo j;
    Interface i;
    User u;
    if(i.iniciaConfig(j,u)) //Caso não falhe na configuração do jogo através do ficheiro, executa o jogo.
        i.iniciaExec(j,u);
    
    return 0;
}

