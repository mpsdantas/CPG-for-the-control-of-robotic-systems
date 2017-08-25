#include <iostream>
#include "scilab.h"
#include <cmath>

#define pi  3.1415927


using namespace std;

int main (){
    Scilab aux;
    //Parametros Deslocamento
    float X[] = {0, 0, 0};
    float dexe0[] = {0,0,0};
    float exe0[] = {0,0,0};
    float ax = 2;

    //Parametros Amplitude
    float R[] = {0.20944, 0.698132, 0.698132};
    float r0[] = {0,0,0};
    float m0[] = {0,0,0};
    float ar = 2;

    //Parametros Phase
    float fi0 [] ={0,0,0};
    float wEntrada[] = {10, 10, 10};
    float wij[][osciladores] = {{0,0,0}, {0.5,0,0}, {0.5,0,0}};
    float phi[][osciladores] = {{0,0,0}, {pi/2,0,0}, {-pi/2,0,0}};


    float passo = 0.01;

    //Chamada dos calculos
    aux.eulerAmplitude(R, m0, r0, ar, passo);
    aux.eulerDeslocamento(X, exe0, dexe0, ax, passo);
    aux.eulerPhase(wij,fi0,wEntrada,phi,passo);
    aux.setW();
    aux.angulos();

    //Impressao das matrizes
    aux.print();

    return 0;

}
