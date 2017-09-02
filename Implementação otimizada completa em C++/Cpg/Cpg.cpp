#include <iostream>
#include <cmath>
#include <fstream>
#include "Cpg.h"
using namespace std;
void Cpg::criar(unsigned const &oscillatorsM, unsigned const &tiM, unsigned const &tfM, float const &stepM, float const RM[], float const XM[]){
    /*
        Método criado em 25/08/2017.
        Criador: Marcus Paulo
        Função: metodo para o construtor padrão da classe a partir de parametros.
    */
    vectorTime = generateVectorTime(tiM,tfM, stepM);
    ti = tiM;
    tf = tfM;
    oscillators = oscillatorsM;
    step = stepM;
    w = createW(10);
    amplitude = zeros(n,oscillators,amplitude);
    aux_amplitude = zeros(n,oscillators,amplitude);
    offset = zeros(n,oscillators,offset);
    aux_offset = zeros(n,oscillators,aux_offset);
    Fi = zeros(n,oscillators,Fi);
    tetha = zeros(n,oscillators,tetha);
    wij = zeros(oscillators,oscillators,wij);
    phi = zeros(oscillators,oscillators,phi);
    R = new float[oscillators];
    X = new float[oscillators];
    for(unsigned i=0; i<oscillators;i++){
        R[i] = RM[i];
        X[i] = XM[i];
    }
}
Cpg::Cpg(unsigned const &oscillatorsM, unsigned const &tiM, unsigned const &tfM, float const &stepM, float const RM[], float const XM[]){
    /*
        Método criado em 25/08/2017.
        Criador: Marcus Paulo
        Função: Construtor padrão da classe a partir de parametros.
    */
    criar(oscillatorsM, tiM, tfM, stepM, RM, XM);
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
    oscillators = 0;
    ti = 0;
    tf = 0;
    n = 0;
}
Cpg::~Cpg(){
    ti = 0;
    tf = 0;
    oscillators = 0;
    step = 0;
    wij = zeros(oscillators,oscillators,wij);
    phi = zeros(oscillators,oscillators,phi);
    for(unsigned i=0; i<oscillators;i++){
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
    n = (tf-ti)/step+1;
    vectorTime = new float[n];
    vectorTime[0] = 0;
    for(unsigned i=1; i<n;i++) vectorTime[i] += vectorTime[i-1]+step;
    return vectorTime;
}
float** Cpg::zeros(unsigned const &l, unsigned const &c, float **Matriz){
    Matriz = new float*[n];
    for(unsigned i=0;i<l;i++){
        Matriz[i] = new float[oscillators];
        for(unsigned j=0;j<c;j++){
            Matriz[i][j]=0;
        }
    }
    return Matriz;
}
float* Cpg::createW(float const &frequencia){
    w = new float(oscillators);
    for(unsigned i=0;i<oscillators;i++) w[i] = 10;
    return w;
}
void Cpg::getWij() const{
    for(unsigned i =0; i<oscillators;i++){
        for(unsigned j =0; j<oscillators;j++){
            cout << wij[i][j] << " ";
        }
        cout << endl;
    }
}
void Cpg::getPhi() const{
    for(unsigned i =0; i<oscillators;i++){
        for(unsigned j =0; j<oscillators;j++){
            cout << phi[i][j] << " ";
        }
        cout << endl;
    }
}
void Cpg::processCpg() {
    float k;
    for (unsigned i = 0; i <n-1; i++) {
        for (unsigned j = 0; j < oscillators ; j++) {
            k = ar*((ar/4)*(R[j]-amplitude[i][j]) - aux_amplitude[i][j]);
            aux_amplitude[i+1][j] = aux_amplitude[i][j] + k*step;
            k = aux_amplitude[i][j];
            amplitude[i+1][j] = amplitude[i][j] + k*step;
            k = ax*((ax/4)*(X[j]-offset[i][j]) - aux_offset[i][j]);
            aux_offset[i+1][j] = aux_offset[i][j] + k*step;
            k = aux_offset[i][j];
            offset[i+1][j] = offset[i][j] + k*step;
            k = w[j];
            for (unsigned l = 0; l < oscillators ; l++) {
                k = k + wij[j][l]*amplitude[i][l]*sin(Fi[i][l]-Fi[i][j]-phi[j][l]);
            }
            Fi[i+1][j] = Fi[i][j] + k*step;
            tetha[i][j] = offset[i][j] + amplitude[i][j]*sin(Fi[i][j]);
        }
    }
    for (unsigned m = 0; m < oscillators; m++) tetha[n-1][m] = offset[n-1][m] + amplitude[n-1][m]*sin(Fi[n-1][m]);
}
ostream &operator<<(ostream &O, const Cpg &cpg) {
    for (unsigned i = 0; i < cpg.n; i++) {
        for (unsigned j = 0; j < cpg.oscillators ; j++) {
            O << cpg.tetha[i][j];
            if(j!=cpg.oscillators-1) O<<',';
        }
        O << endl;
    }
}
void Cpg::saveCpg(string const &name){
    ofstream arq(name.c_str());
    if(arq.is_open()){
        for(unsigned i = 0; i<n;i++) {
            for (unsigned j = 0; j < oscillators; j++) {
                arq << tetha[i][j];
                if (j != oscillators - 1) arq << ',';
            }
            arq << endl;
        }
    }
    arq.close();
}
void Cpg::saveVectorTime(string const &name) {
    ofstream arq(name.c_str());
    if(arq.is_open()){
        for(unsigned i =0; i <n;i++){
            arq << vectorTime[i] << endl;
        }
    }
    arq.close();
}
void Cpg::saveAmplitude(string const &name) {
    ofstream arq(name.c_str());
    if(arq.is_open()){
        for(unsigned i = 0; i<n;i++) {
            for (unsigned j = 0; j < oscillators; j++) {
                arq << amplitude[i][j];
                if (j != oscillators - 1) arq << ',';
            }
            arq << endl;
        }
    }
}
void Cpg::saveOffset(string const &name) {
    ofstream arq(name.c_str());
    if(arq.is_open()){
        for(unsigned i = 0; i<n;i++) {
            for (unsigned j = 0; j < oscillators; j++) {
                arq << offset[i][j];
                if (j != oscillators - 1) arq << ',';
            }
            arq << endl;
        }
    }
}
void Cpg::saveFI(string const &name) {
    ofstream arq(name.c_str());
    if(arq.is_open()){
        for(unsigned i = 0; i<n;i++) {
            for (unsigned j = 0; j < oscillators; j++) {
                arq << Fi[i][j];
                if (j != oscillators - 1) arq << ',';
            }
            arq << endl;
        }
    }
}




