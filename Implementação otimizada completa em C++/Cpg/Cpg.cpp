//
// Created by marcus on 29/08/17.
//
#include <iostream>
#include <cmath>
using namespace std;
#include "Cpg.h"
void Cpg::criar(unsigned const &osciladoresM, unsigned const &tiM, unsigned const &tfM, float const &stepM, float const RM[], float const XM[]){
    /*
        Método criado em 25/08/2017.
        Criador: Marcus Paulo
        Função: metodo para o construtor padrão da classe a partir de parametros.
    */
    vectorTime = generateVectorTime(tiM,tfM, stepM);
    ti = tiM;
    tf = tfM;
    osciladores = osciladoresM;
    step = stepM;
    w = createW(10);
    amplitude = zeros(n,osciladores,amplitude);
    aux_amplitude = zeros(n,osciladores,amplitude);
    offset = zeros(n,osciladores,offset);
    aux_offset = zeros(n,osciladores,aux_offset);
    Fi = zeros(n,osciladores,Fi);
    tetha = zeros(n,osciladores,tetha);
    wij = zeros(osciladores,osciladores,wij);
    phi = zeros(osciladores,osciladores,phi);
    R = new float[osciladores];
    X = new float[osciladores];
    for(unsigned i=0; i<osciladores;i++){
        R[i] = RM[i];
        X[i] = XM[i];
    }
}
Cpg::Cpg(unsigned const &osciladoresM, unsigned const &tiM, unsigned const &tfM, float const &stepM, float const RM[], float const XM[]){
    /*
        Método criado em 25/08/2017.
        Criador: Marcus Paulo
        Função: Construtor padrão da classe a partir de parametros.
    */
    criar(osciladoresM, tiM, tfM, stepM, RM, XM);
}
Cpg::Cpg(){
    /*
        Método criado em 25/08/2017.
        Criador: Marcus Paulo
        Função: construtor padrão da classe sem nenhum parametro passado.
    */
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
Cpg::~Cpg(){
    ti = 0;
    tf = 0;
    osciladores = 0;
    step = 0;
    wij = zeros(osciladores,osciladores,wij);
    phi = zeros(osciladores,osciladores,phi);
    for(unsigned i=0; i<osciladores;i++){
        delete[] wij[i];
        delete[] phi[i];
    }
    for(unsigned i=0; i<n;i++){
        delete[] amplitude[i];
        delete[] aux_amplitude[i];
        delete[] offset[i];
        delete[] aux_offset[i];
        delete[] Fi[i];
        delete[] tetha[i];
    }
    delete[] amplitude;
    delete[] aux_amplitude;
    delete[] offset;
    delete[] aux_offset;
    delete[] Fi;
    delete[] tetha;
    delete[] vectorTime;
    delete[] w;
    delete[] wij;
    delete[] phi;
    delete[] R;
    delete[] X;
}
float* Cpg::generateVectorTime(unsigned const &ti, unsigned const &tf, float const &step){
    /*
        Método criado em 25/08/2017.
        Criador: Marcus Paulo
        Função: gera o vetor tempos e preenche além de dar o tamanho n.
    */
    n = (tf-ti)/step+2;
    vectorTime = new float[n];
    vectorTime[0] = 0;
    for(unsigned i=1; i<n;i++) vectorTime[i] += vectorTime[i-1]+step;
    return vectorTime;
}
float** Cpg::zeros(unsigned const &l, unsigned const &c, float **Matriz){
    /*
        Método criado em 25/08/2017.
        Criador: Marcus Paulo
        Função: Cria uma matriz a partir de um ponteiro de ponteiros e inicia ela com zeros.
    */
    Matriz = new float*[n];
    for(unsigned i=0;i<l;i++){
        Matriz[i] = new float[osciladores];
        for(unsigned j=0;j<c;j++){
            Matriz[i][j]=0;
        }
    }
    return Matriz;
}
float* Cpg::createW(float const &frequencia){
    /*
        Método criado em 25/08/2017.
        Criador: Marcus Paulo
        Função: gerar vetor de frequencias w.
    */
    w = new float(osciladores);
    for(unsigned i=0;i<osciladores;i++) w[i] = 10;
    return w;
}
void Cpg::getWij() const{
    /*
        Método criado em 25/08/2017.
        Criador: Marcus Paulo
        Função: imprime a matriz wij.
    */
    for(unsigned i =0; i<osciladores;i++){
        for(unsigned j =0; j<osciladores;j++){
            cout << wij[i][j] << " ";
        }
        cout << endl;
    }
}
void Cpg::getPhi() const{
    /*
        Método criado em 25/08/2017.
        Criador: Marcus Paulo
        Função: imprime a matriz phi.
    */
    for(unsigned i =0; i<osciladores;i++){
        for(unsigned j =0; j<osciladores;j++){
            cout << phi[i][j] << " ";
        }
        cout << endl;
    }
}
void Cpg::processCpg() {
    float k;
    for (unsigned i = 0; i <n-1; i++) {
        for (unsigned j = 0; j < osciladores ; j++) {
            k = ar*((ar/4)*(R[j]-amplitude[i][j]) - aux_amplitude[i][j]);
            aux_amplitude[i+1][j] = aux_amplitude[i][j] + k*step;
            k = aux_amplitude[i][j];
            amplitude[i+1][j] = amplitude[i][j] + k*step;
            k = ax*((ax/4)*(X[j]-offset[i][j]) - aux_offset[i][j]);
            aux_offset[i+1][j] = aux_offset[i][j] + k*step;
            k = aux_offset[i][j];
            offset[i+1][j] = offset[i][j] + k*step;
            k = w[j];
            for (unsigned l = 0; l < osciladores ; l++) {
                k = k + wij[j][l]*amplitude[i][l]*sin(Fi[i][l]-Fi[i][j]-phi[j][l]);
            }
            Fi[i+1][j] = Fi[i][j] + k*step;
            tetha[i][j] = offset[i][j] + amplitude[i][j]*sin(Fi[i][j]);
        }
    }
}




