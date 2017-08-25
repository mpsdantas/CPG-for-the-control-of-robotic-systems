#include <iostream>
using namespace std;
#include "Cpg.h"
void Cpg::criar(unsigned osciladoresM, unsigned tiM, unsigned tfM, float stepM){
    vectorTime = generateVectorTime(tiM,tfM, stepM);
}
float** Cpg::zeros(float **Matriz){
    Matriz = new float*[n];
    for(unsigned i=0;i<n;i++){
        Matriz[i] = new float[osciladores];
        for(unsigned j=0;j<osciladores;j++){
            Matriz[i][j]=0;
        }
    }
    return Matriz;
}
float* Cpg::generateVectorTime(unsigned ti, unsigned tf, float step){
    n = (tf-ti)/step;
    vectorTime = new float[n];
    vectorTime[0] = 0;
    for(unsigned i=1; i<n;i++) vectorTime[i] += vectorTime[i-1]+step;
    return vectorTime;
}
Cpg::Cpg(){
    amplitude = NULL;
    aux_amplitude = NULL;
    offset = NULL;
    aux_offset = NULL;
    Fi = NULL;
    tetha = NULL;
    wij = NULL;
    phi = NULL;
    w = NULL;
    R = NULL;
    X = NULL;
    vectorTime = NULL;
    ar = 0;
    ax = 0;
    step = 0;
    osciladores = 0;
    ti = 0;
    tf = 0;
    n = 0;
}
Cpg::Cpg(unsigned osciladoresM, unsigned tiM, unsigned tfM, float stepM){
    criar(osciladoresM, tiM, tfM, stepM);
}
