class Cpg{
private:
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
    float ar;
    float ax;
    float step;
    unsigned osciladores;
    unsigned ti;
    unsigned tf;
    unsigned n;
    void criar(unsigned osciladores, unsigned ti, unsigned tf, float step);
    void copiar();
    void limpar();
    float* generateVectorTime(unsigned ti, unsigned tf, float step);
    float** zeros(float **Matriz);
public:
    Cpg(unsigned osciladores, unsigned ti, unsigned tf, float step);
    Cpg();

};
