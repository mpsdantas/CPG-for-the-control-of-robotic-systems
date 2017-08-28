class Cpg{
private:

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
    void criar(unsigned osciladoresM, unsigned tiM, unsigned tfM, float stepM, float **wijP, float **PhiP, float RM[]);
    void copiar();
    void limpar();
    //----------- Métodos para os construtores e destrutores da classe --------------//

    float* generateVectorTime(unsigned ti, unsigned tf, float step); // Gera vetor de tempo e n.
    float** zeros(float **Matriz); // Inicializa e preenche com zeros uma matriz.
    float* createW(float frequencia); // Gera o vetor de frequencias w.
public:
    //Construtor padrão com parametros.
    Cpg(unsigned osciladoresM, unsigned tiM, unsigned tfM, float stepM, float **wijP, float **PhiP, float RM[]);
    Cpg(); // Construtor padrão sem parametros.

};
