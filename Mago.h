/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mago.h
 * Author: FACOMP
 *
 * Created on 20 de Janeiro de 2016, 17:17
 */

#ifndef MAGO_H
#define MAGO_H
#include <iostream.h>

class Mago{
	
private:
    int fogo;
    int raio;
    int agua;
    int ar;
    int gelo;
    int terra;
    int trevas;
};
	
public:
    void atacar();
    void defender();
    void invocar();
};