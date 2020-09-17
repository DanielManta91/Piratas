/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mar.h
 * Author: Pedro
 *
 * Created on 13 de Novembro de 2018, 11:44
 */

#ifndef MAR_H
#define MAR_H

#include "Terreno.h"

class Navio;
class Mar : public Terreno {  
    Navio* n;
    bool peixe;
public:
    Mar(char car='.');
    char getChar() const override;
    
    bool getPeixe() const override;
    
    void setPeixe(bool p) override;
    void setChar(char barco) override;
    void setNavio(Navio* nav) override;      //associa o ponteiro de navio a um determinado navio recebido
    Navio* getNavio() const override;        //retorna o ponteiro para o navio associado
    
    void resetChar() override;           //repõe o caracter da célula para '.'
    void resetNavio() override;          //repõe o ponteiro de navio para nullptr
};

#endif /* MAR_H */

