#ifndef SCILAB_H
#define SCILAB_H


#define nLinhas 2001 //Aqui é o numero de linhas com o passo de 0.01==> n = (b-a)/passo; n = (20 - 0)/0.01
#define osciladores 3
class Scilab{
private:

    //Aqui é a nossa matriz m que recebe a derivada primeira da EDO com n linhas e 3 osciladores
    float m[nLinhas][osciladores];
    //Aqui é a nossa matriz r que recebe a derivada segunda da EDO com n linhas e 3 osciladores
    float r[nLinhas][osciladores];
    //Vetor de inclinações para a estimativa de m
    float km[nLinhas][osciladores];
    //Vetor de inclinações para a estimativa de r
    float kdm[nLinhas][osciladores];


    //Aqui é a nossa matriz exe que recebe a derivada segunda da EDO com n linhas e 3 osciladores
    float exe[nLinhas][osciladores];
    //Aqui é a nossa matriz x que recebe a derivada segunda da EDO com n linhas e 3 osciladores
    float dexe[nLinhas][osciladores];
    //Vetor de inclinações para a estimativa de exe
    float kexe[nLinhas][osciladores];
    //Vetor de inclinações para a estimativa de dexe
    float kdexe[nLinhas][osciladores];


    //Definindo matriz w
    float w[osciladores][osciladores];


    //variaveis para o calculo da phase
    float dphi[osciladores][osciladores];
    float FI[nLinhas][osciladores];
    float kdphi[nLinhas][osciladores];

    //Calculos dos angulos
    float Tetha[nLinhas][osciladores];


public:

    Scilab();
    //Metodos para o calculo do deslocamento
    void setKexe(int parametro);
    void setKdexe(float X[], float ax, int parametro);
    void eulerDeslocamento(float X[], float exe0[], float dexe0[], float ax, float passo);


    //Metodos para o calculo da amplitude
    void setKm(int parametro);
    void setKdm(float R[], float ar, int parametro);
    void eulerAmplitude(float R[], float m0[], float r0[], float ar, float passo);


    //Matriz w osciladora das patas
    void setW();


    //Metodos para o calulo da Phase
    void setKdphi(int parametro, float wEntrada[], float wij[][osciladores], float phi[][osciladores]);
    void eulerPhase(float wij[][osciladores], float fi0[], float wEntrada[],
                    float phi[][osciladores], float passo);



    //Calculo do angulo Tetha
    void angulos();




    void print();
};

#endif // SCILAB_H
