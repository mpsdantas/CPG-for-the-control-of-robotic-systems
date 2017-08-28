#include <iostream>
#include "Cpg.h"
#define PI 3.14159265359
using namespace std;
int main()
{
    unsigned osciladores = 3;
    unsigned ti = 0;
    unsigned tf = 30;
    float step = 0.001;

    // GAMBIARRA //
    float wij[osciladores][osciladores] = {{0, 0, 0}, {0.5, 0, 0}, {0.5, 0, 0}};
    float phiM[3][3] = {{0, 0, 0}, {PI/2, 0, 0}, {-PI/2, 0, 0}};

    float **wijP = new float*[osciladores];
    for(int i=0; i < osciladores; i++){
        wijP[i] = new float[osciladores];
        for(int j=0;j<osciladores;j++) wijP[i][j] = wij[i][j];
    }
    float **phiP = new float*[osciladores];
    for(int i=0; i < osciladores; i++){
        phiP[i] = new float[osciladores];
        for(int j=0;j<osciladores;j++) phiP[i][j] = phiM[i][j];
    }
    // GAMBIARRA //

    float RM[] = {0.40944, 0.29132, 0.29132};
    Cpg cpg(osciladores,ti,tf,step,wijP,phiP,RM);
}
