#ifndef CPG_CPG_H
#define CPG_CPG_H
using namespace std;
class Cpg {
private:
    /// Pointer to the array width, from that pointer will be created an array nxoscillators.
    float **amplitude;
    ///Pointer to the auxiliary array amplitude, pointer used in the modeling of the second order EDO.
    float **aux_amplitude;
    ///Pointer to the array offset, from that pointer will be created an array nxoscillators.
    float **offset;
    ///Pointer to the array offset, from that pointer will be created an array nxoscildaores.
    float **aux_offset;
    /// Pointer to the array Fi, from that pointer will be created an array nxoscildaores.
    float **Fi;
    /// Pointer to the tetha array, from that pointer an array will be created nxoscildaores.
    float **tetha;
    /// Pointer to matrix wij, lag matrix oscildaoresxoscildaores.
    float **wij;
    /// Pointer to the phi matrix, lag matrix oscildaoresxoscildaores.
    float **phi;
    /// Pointer to vector w, vector corresponding to frequency of each oscillator.
    float *w;
    /// Pointer to the vector R, vector corresponds to the maximum amplitude of each oscillator.
    float *R;
    /// Pointer to vector X, vector corresponds to the maximum offset of each oscillator.
    float *X;
    /// Pointer to the vector of times, vector generated from the initial and final time.
    float *vectorTime;
    /// Constant amplitude.
    float ar;
    /// Offset constant.
    float ax;
    /// Step used for processing the euler method.
    float step;
    /// Number of oscillators used.
    unsigned oscillators;
    /// Initial time.
    unsigned ti;
    /// Final time.
    unsigned tf;
    /// Time vector size.
    unsigned n;
    /**
     * Method used by the default constructor (with parameters) of the class to start the parameters and pointers.
     * @param oscillatorsM Number of oscillators desired.
     * @param tiM Initial time.
     * @param tfM Final time.
     * @param stepM Accuracy required.
     * @param RM Vector of maximum aplitudes.
     * @param XM Vector of maximum offset.
     */
    void criar(unsigned const &oscillatorsM, unsigned const &tiM, unsigned const &tfM, float const &stepM, float const RM[], float const XM[]);
    /**
     * Method for creating arrays from pointers passed as parameters.
     * @param l Number of rows of array to be processed.
     * @param c Number of columns of the array to be processed.
     * @param Matriz Pointer to be processed.
     * @return Point of Pointer to array filled with zeros from the initial pointer passed as a parameter.
     */
    float** zeros(unsigned const &l, unsigned const &c, float **Matriz);
    /**
     *
     * @param frequencia Frequency set for oscillators.
     * @return Pointer to array of frequency matrix.
     */
    float* createW(float const &frequencia);
    /**
     *
     * @param ti Initial time.
     * @param tf Final time.
     * @param step Accuracy required.
     * @return Point to array of time.
     */
    float* generateVectorTime(unsigned const &ti, unsigned const &tf, float const &step);
public:
    /**
     * Standard constructor of the class from parameters.
     * @param oscillatorsM Number of oscillators desired.
     * @param tiM Initial time.
     * @param tfM Final time.
     * @param stepM Accuracy required.
     * @param RM Vector of maximum aplitudes.
     * @param XM Vector of maximum offset.
     */
    Cpg(unsigned const &oscillatorsM, unsigned const &tiM, unsigned const &tfM, float const &stepM, float const RM[], float const XM[]);
    /**
     * Standard constructor of the class without parameters.
     */
    Cpg();
    /**
     * Standard class destructor.
     */
    ~Cpg();
    /**
     * Method for printing the matrix wij.
     */
    void getWij() const;
    /**
     * Method for printing the matrix phi.
     */
    void getPhi() const;
    /**
     * Method to obtain the air amplitude constant.
     * @return Returns the air amplitude constant.
     */
    inline float getAr() const{return ar;}
    /**
     * Method to obtain the air offset constant.
     * @return Returns the air offset constant.
     */
    inline float getAx() const{return ax;}
    /**
     * Method to obtain the Acuracy.
     * @return Acuracy.
     */
    inline float getStep() const{return step;}
    /**
     * Method to obtain the oscillators.
     * @return This method return the numbers of oscillators.
     */
    inline unsigned getoscillators() const{return oscillators;}
    /**
     * Method to obtain the time initial.
     * @return Initial time.
     */
    inline unsigned getTi() const{return ti;}
    /**
     * Method to obtain the final time.
     * @return Final time.
     */
    inline unsigned getTf() const{return tf;}
    /**
     * Method to obtain the size of vector time.
     * @return Size of vector time.
     */
    inline unsigned getN() const{return n;}
    /**
     * Method for setting parameters of the Phi matrix.
     * @param l Phi array line.
     * @param c phi matrix column.
     * @param value Value to be set in phi array.
     */
    inline void setPhi(unsigned const &l, unsigned const &c, float const &value){phi[l][c] = value;}
    /**
     *
     * Method for setting parameters of the Wij matrix.
     * @param l Wij array line.
     * @param c Wij matrix column.
     * @param value Value to be set in Wij array.
     */
    inline void setWij(unsigned const &l, unsigned const &c, float const &value){wij[l][c] = value;}
    /**
     * Method for setting the value of the ar amplitude constant
     * @param value Value to be set in Ar amplitude constant
     */
    inline void setAr(float const &value){ar = value;}
    /**
     * Method for setting the value of the ax offset constant
     * @param value Value to be set in Ax offset constant
     */
    inline void setAx(float const &value){ax = value;}
    /**
     * Method for performing the cpg processing.
     */
    void processCpg();
    /**
     * Method to overload the "<<" operator.
     * @param O Parameter of ostream
     * @param cpg Cpg object.
     * @return Parameter of ostream
     */
    friend ostream &operator<<(ostream &O, const Cpg &cpg);
    /**
     * Method to save the angles of the processing of the cpg.
     * @param name Name of the file that will be saved in the directory.
     */
    void saveCpg(string const &name);
    /**
     * Method to save the vector of times.
     * @param name Name of the file that will be saved in the directory.
     */
    void saveVectorTime(string const &name);
    /**
     * Method to save the matrix of Amplitudes.
     * @param name Name of the file that will be saved in the directory.
     */
    void saveAmplitude(string const &name);
    /**
     * Method to save the matrix of offsets.
     * @param name Name of the file that will be saved in the directory.
     */
    void saveOffset(string const &name);
    /**
     * Method to save the matrix of FI..
     * @param name Name of the file that will be saved in the directory.
     */
    void saveFI(string const &name);
};
#endif
