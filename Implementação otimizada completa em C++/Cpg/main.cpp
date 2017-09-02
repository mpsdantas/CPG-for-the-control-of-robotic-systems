#include <iostream>
#include "Cpg.h"
#define PI 3.14159265359
using namespace std;
int main() {
    unsigned oscillators = 4;
    unsigned ti = 0;
    unsigned tf = 25;
    float step = 0.01;
    float RM[] = {0.29132, 0.5434, 0.29132,0.29132};
    float XM[] = {0, 0, 0, 0};
    Cpg cpg(oscillators,ti,tf,step,RM,XM);
    cpg.setWij(3,0,0.5);
    cpg.setWij(1,0,0.5);
    cpg.setWij(2,0,0.5);
    cpg.setPhi(3,0,-PI/4);
    cpg.setPhi(1,0,PI/4);
    cpg.setPhi(2,0,-PI/8);
    cpg.setAr(2);
    cpg.setAx(2);
    cpg.processCpg();
    cpg.saveCpg("Arquivo6.csv");
}
