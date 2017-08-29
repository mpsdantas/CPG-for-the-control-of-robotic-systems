#include <iostream>
#include "Cpg.h"
#define PI 3.14159265359
using namespace std;
int main() {
    unsigned osciladores = 3;
    unsigned ti = 0;
    unsigned tf = 25;
    float step = 0.0001;
    float RM[] = {0.40944, 0.29132, 0.29132};
    float XM[] = {0, 0, 0};
    Cpg cpg(osciladores,ti,tf,step,RM,XM);
    // ---------------- Setando defasagem e outros parametros------------
    cpg.setWij(1,0,0.5);
    cpg.setWij(2,0,0.5);
    cpg.setPhi(1,0,PI/2);
    cpg.setPhi(2,0,-PI/2);
    cpg.setAr(2);
    cpg.setAx(2);
    // ---------------- Setando defasagem e outros parametros------------
    cpg.processCpg();
}
