//
// Created by marcus on 29/08/17.
//
#ifndef CPG_CPG_H
#define CPG_CPG_H
using namespace std;
class Cpg {
    //----------- Matrizes e vetores --------------//
    float **amplitude;
    float **aux_amplitude;
    float **offset;
    float **aux_offset;
    float **Fi;
    float **tetha;
    float **wij;
    float **phi;
    float *w;
    float *R;
    float *X;
    float *vectorTime;
    //----------- Matrizes e vetores --------------//
    //----------- Variaveis e constantes --------------//
    float ar;
    float ax;
    float step;
    unsigned osciladores;
    unsigned ti;
    unsigned tf;
    unsigned n;
    //----------- Variaveis e constantes --------------//
    //----------- Métodos para os construtores e destrutores da classe --------------//
    void criar(unsigned const &osciladoresM, unsigned const &tiM, unsigned const &tfM, float const &stepM, float const RM[], float const XM[]);
    void copiar();
    void limpar();
    //----------- Métodos para os construtores e destrutores da classe --------------//
    float** zeros(unsigned const &l, unsigned const &c, float **Matriz); // Inicializa e preenche com zeros uma matriz.
    float* createW(float const &frequencia); // Gera o vetor de frequencias w.
    float* generateVectorTime(unsigned const &ti, unsigned const &tf, float const &step); // Gera vetor de tempo e n.
public:
    //Construtor padrão com parametros.
    Cpg(unsigned const &osciladoresM, unsigned const &tiM, unsigned const &tfM, float const &stepM, float const RM[], float const XM[]);
    Cpg(); // Construtor padrão sem parametros.
    ~Cpg();
    void getWij() const;
    void getPhi() const;
    inline float getAr() const{return ar;}
    inline float getAx() const{return ax;}
    inline float getStep() const{return step;}
    inline unsigned getOsciladores() const{return osciladores;}
    inline unsigned getTi() const{return ti;}
    inline unsigned getTf() const{return tf;}
    inline unsigned getN() const{return n;}
    inline void setPhi(unsigned const &l, unsigned const &c, float const &value){phi[l][c] = value;}
    inline void setWij(unsigned const &l, unsigned const &c, float const &value){wij[l][c] = value;}
    inline void setAr(float const &value){ar = value;}
    inline void setAx(float const &value){ax = value;}
    void processCpg();
    friend ostream &operator<<(ostream &O, const Cpg &cpg);
    void saveCpg(string const &name,const Cpg &cpg);
};
#endif //CPG_CPG_H
