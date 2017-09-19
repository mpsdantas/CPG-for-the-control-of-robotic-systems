#include <iostream>
#include "Cpg.h"
#define PI 3.14159265359
using namespace std;
int main() {
    unsigned oscillators = 4;
    unsigned ti = 0;
    unsigned tf = 40;
    float step = 0.01;
    float RM[] = {0.29132, 0.29132, 0.29132,0.29132};
    float XM[] = {0, 0, 0, 0};
    Cpg cpg(oscillators,ti,tf,step,RM,XM);
    cpg.setWij(0,1,0.5);
    cpg.setWij(1,2,1);
    cpg.setWij(2,3,1.5);
    cpg.setWij(3,0,2);
    cpg.setPhi(0,1,PI/2);
    cpg.setPhi(1,2,PI/2);
    cpg.setPhi(2,3,PI/2);
    cpg.setPhi(3,0,PI/2);
    cpg.setAr(9);
    cpg.setAx(6);
    cpg.processCpg();
    cpg.saveCpg("Osciladores.csv");
    cpg.saveVectorTime("time40");
}
