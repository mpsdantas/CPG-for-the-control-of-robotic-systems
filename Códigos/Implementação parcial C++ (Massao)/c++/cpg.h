#include <iostream>
#define osci 3
using namespace std;
class Cpg{
public:
	float primeiraDerivadaR(float dr[]);
	float segundaDerivadaR(float ar, float R[], float r[], float m[], int n);
	float primeiraDerivadaX(float dx[]);
	float segundaDerivadaX(float ax, float X[], float x[], float exe[], int n);
	float dphi(int n, float w[],float wij[][osci],float r[], float fi[], float phi[][osci]);
	float deslocamento(float ax, float X[], float x[], float exe[], int n, int i);
	float amplitude(float ar, float R[], float r[], float m[], int n, int i);
	float phase(int n, float w[], float wij[][osci], float r[], float fi[], float phi[][osci],int i);
	float angulos(int osciladores, float FI[][osci], float r[][osci], float x[][osci]);
};
