#include "cpg.h"
#include <iostream>
#include <cmath>
using namespace std;
float Cpg::primeiraDerivadaR(float dr[]){

}
int main(){
	int tInicio = 0;
	int tFim = 25;
	float passo = 0.01;
	int t = (tFim - tInicio)/passo;
	int osciladores = 3;
	float R[1][osciladores] = {0.40944,0.29132,0.29132};
	float r[t][osciladores];
	float m[t][osciladores];
	float x[t][osciladores];
	float exe[t][osciladores];
	float FI[t][osciladores];
	float tetha[t][osciladores];
	float X[1][osciladores] = {0,0,0};
	int w[1][osciladores] = {10, 10, 10};
	float wij[osciladores][osciladores] = {0, 0, 0, 0.5, 0, 0,0.5,0,0};
	float phi[osciladores][osciladores] = {0, 0, 0, M_PI_2, 0, 0, -M_PI_2, 0, 0};
	int ar = 2;
	int ax = 2;
	for(int j = 0; j < osciladores; j++){
        for(int i = 0; i < t; i++){
            r[j][i] = 0;
            m[j][i] = 0;
            x[j][i] = 0;
            exe[j][i] = 0;
            FI[j][i] = 0;
            tetha[j][i] = 0;
        }
	}
}
