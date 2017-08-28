#include <iostream>
using namespace std;
#include "Cpg.h"
void Cpg::criar(unsigned osciladoresM, unsigned tiM, unsigned tfM, float stepM, float **wijP, float **PhiP, float RM[]){
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
    amplitude = zeros(amplitude);
    aux_amplitude = zeros(amplitude);
    offset = zeros(offset);
    aux_offset = zeros(offset);
    Fi = zeros(Fi);
    tetha = zeros(tetha);
}

float* Cpg::createW(float frequencia){
    /*
        Método criado em 25/08/2017.
        Criador: Marcus Paulo
        Função: gerar vetor de frequencias w.
    */
    w = new float(osciladores);
    for(unsigned i=0;i<osciladores;i++) w[i] = 10;
    return w;
}
float** Cpg::zeros(float **Matriz){
    /*
        Método criado em 25/08/2017.
        Criador: Marcus Paulo
        Função: Cria uma matriz a partir de um ponteiro de ponteiros e inicia ela com zeros.
    */
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
    /*
        Método criado em 25/08/2017.
        Criador: Marcus Paulo
        Função: gera o vetor tempos e preenche além de dar o tamanho n.
    */
    n = (tf-ti)/step;
    vectorTime = new float[n];
    vectorTime[0] = 0;
    for(unsigned i=1; i<n;i++) vectorTime[i] += vectorTime[i-1]+step;
    return vectorTime;
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
Cpg::Cpg(unsigned osciladoresM, unsigned tiM, unsigned tfM, float stepM, float **wijP, float **PhiP, float RM[]){
    /*
        Método criado em 25/08/2017.
        Criador: Marcus Paulo
        Função: Construtor padrão da classe a partir de parametros.
    */
    criar(osciladoresM, tiM, tfM, stepM, wijP, PhiP, RM);
}
