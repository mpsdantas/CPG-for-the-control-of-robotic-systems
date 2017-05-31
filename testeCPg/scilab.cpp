#include<iostream>
#include "scilab.h"
#include <cmath>

#define osciladores 3
#define nLinhas 2001
#define h 0.01
using namespace std;
Scilab::Scilab(){}

//==============================Deslocamento usando o metodo de Euler==============================//

void Scilab::setKexe(int parametro)
{
    for(int i =0; i<osciladores; i++){
        kexe[parametro][i] = exe[parametro][i];
    }
}

//Aqui nós iremos setar a inclinação kdexe para cada linhas da matriz
void Scilab::setKdexe(float X[], float ax, int parametro)
{
    for(int i =0; i< osciladores; i++){
        kdexe[parametro][i] = ax*((ax/4)*(X[i] - dexe[parametro][i]) - exe[parametro][i]);
    }
}

void Scilab::eulerDeslocamento(float X[], float exe0[], float dexe0[], float ax, float passo)
{
    for (int k =0; k< osciladores; k++){
        exe[0][k] = exe0[k];
        dexe[0][k] = dexe0[k];
    }
    for(int i =0;i<nLinhas; i++){
        setKexe(i);
        setKdexe(X, ax, i);
        for(int j = 0;j<osciladores; j++){
            exe[i+1][j] = exe[i][j] + kexe[i][j]*passo;
            dexe[i+1][j] = dexe[i][j] + kdexe[i][j]*passo;
        };
    }
}


//==============================Amplitude usando o metodo de Euler==============================//



//Aqui nós iremos setar a inclinação km para cada linhas da matriz
void Scilab::setKm(int parametro)
{
    for(int i =0; i<osciladores; i++){
        km[parametro][i] = m[parametro][i];
    }
}
//Aqui nós iremos setar a inclinação kdm para cada linhas da matriz
void Scilab::setKdm(float R[], float ar, int parametro)
{
    for(int i =0; i< osciladores; i++){
        kdm[parametro][i] = ar*((ar/4)*(R[i] - r[parametro][i]) - m[parametro][i]);
    }
}
void Scilab::eulerAmplitude(float R[], float m0[], float r0[], float ar, float passo)
{
    for (int k =0; k< osciladores; k++){
        m[0][k] = m0[k];
        r[0][k] = r0[k];
    }
    for(int i =0;i<nLinhas; i++){
        setKm(i);
        setKdm(R, ar, i);
        for(int j = 0;j<osciladores; j++){
            m[i+1][j] = m[i][j] + km[i][j]*passo;
            r[i+1][j] = r[i][j] + kdm[i][j]*passo;
        }
    }
}

//==========================Definindo a matriz w osciladora das patas==========================//


void Scilab::setW()
{
    for(int i = 0; i< osciladores; i++){
        for(int j =0; j<osciladores; j++){
            if(i == j){
                w[i][j] = 0;
            }
            else{
                w[i][j] = 0.5;
            }
        }
    }
}


//==============================Phase usando o metodo de Euler==============================//




//Aqui nós iremos setar a inclinação kdphi

void Scilab::setKdphi(int parametro, float wEntrada[], float wij[][osciladores], float phi[][osciladores])
{
    for(int i =0; i<osciladores; i++){
        dphi[parametro][i] = wEntrada[i];
        for(int j =0; j<osciladores;j++){
            dphi[parametro][i] = dphi[parametro][i] + wij[i][j]*r[parametro][j]*sin(FI[parametro][j] - FI[parametro][i] - phi[i][j]);
            kdphi[parametro][i] = dphi[parametro][i];
        }
    }
}
void Scilab::eulerPhase(float wij[][osciladores], float fi0[], float wEntrada[], float phi[][osciladores], float passo)
{
    for(int k =0; k<osciladores;k++){
        FI[0][k] = fi0[k];
    }
    for(int i = 0; i<nLinhas;i++){
        setKdphi(i, wEntrada, wij, phi);
        //int parametro, float wEntrada[], float wij[], float fi0[], float phi[][osciladores]
        for(int j =0; j<osciladores;j++){
            FI[i+1][j] = FI[i][j] + kdphi[i][j]*passo;
        }
        cout<<endl;
    }
}

//==============================Calculo dos angulos==============================//
void Scilab::angulos()
{
    for(int i =0; i<nLinhas; i++){
        for(int j =0; j<osciladores;j++){
            Tetha[i][j] = exe[i][j] + r[i][j]*sin(FI[i][j]);
        }
    }
}
//==============================Impressao das matrizes==============================//

//Esta função serve apenas para imprimir as matrizes
void Scilab::print()

{

    for(int i =0; i<nLinhas; i++){
        for(int j =0; j<osciladores; j++){
            cout<<r[i][j]<<"    ";
        }
        cout<<endl;
    }
    /*
    cout<<"\n\n\n\n";
    for(int i =0; i<3; i++){
        for(int j =0; j<osciladores; j++){
            cout<<dexe[i][j]<<"    ";
        }
        cout<<endl;
    }
    cout<<"\n\n\n\n";

    for(int i =0; i<nLinhas; i++){
        for(int j =0; j<osciladores; j++){
            cout<<FI[i][j]<<"    ";
        }
        cout<<endl;
    }

    cout<<"\n\n\n\n";

    for(int i =0; i<nLinhas; i++){
        for(int j =0; j<osciladores; j++){
            cout<<Tetha[i][j]<<"    ";
        }
        cout<<endl;
    }
    */

}


