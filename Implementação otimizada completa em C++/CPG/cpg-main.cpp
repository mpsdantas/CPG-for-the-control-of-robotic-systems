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
    float wij[3][3] = {{0, 0, 0}, {0.5, 0, 0}, {0.5, 0, 0}};
    float phi[3][3] = {{0, 0, 0}, {PI/2, 0, 0}, {-PI/2, 0, 0}};
    float R[] = {0.40944, 0.29132, 0.29132};
    Cpg cpg(osciladores,ti,tf,step);
}
