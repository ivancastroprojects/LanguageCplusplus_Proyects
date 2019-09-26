#ifndef ALU_H
#define ALU_H


class alu
{
public:
    alu();
    void setValoresA(unsigned int s, unsigned int e, unsigned int f);
    void setValoresB(unsigned int s, unsigned int e, unsigned int f);
    void setValoresEnteros(unsigned int valorEnteroA, unsigned int valorEnteroB);
    void suma();
    void producto();
    void division();
    unsigned int getSignoResultado();
    unsigned int getExponenteResultado();
    unsigned int getFraccionariaResultado();
    unsigned int getMantisaResultado();
    bool checkResultadoIndeterminado();
    bool checkResultadoInfinito();
    bool checkResultadoUnderflow();
    bool checkResultadoNaN();

private:
    unsigned int sa, ea, fa;
    unsigned int sb, eb, fb;
    unsigned int aEntero, bEntero;
    unsigned int resultadoS, resultadoE, resultadoM, resultadoF;
    bool resultadoIndeterminadoNaN = false;
    bool resultadoInfinito = false;
    bool resultadoUnderflow = false;
    bool resultadoNaN = false;

    void multiplicacionBinariaSinSigno(unsigned int x, unsigned int  y);
    unsigned int mbs_c, mbs_P, mbs_A;
    unsigned int multiplica(unsigned int a, unsigned int b);
    unsigned int ponerEnIEEE754(unsigned int signo, unsigned int exponente, unsigned int fraccionaria);
    void asignarValoresClaseIEEE(int n, unsigned int signo, unsigned int exponente, unsigned int fraccionaria);
    unsigned int sumaDiv(unsigned int a, unsigned int b);

    struct datoCampos{
        unsigned int frac:23;
        unsigned int exponente:8;
        unsigned int signo:1;
    };

    union unionDato{
        struct datoCampos campos;
        unsigned int valorEntero;
    };

    struct resultadoCampos{
        unsigned int fraccionaria:23;
        unsigned int exponente:8;
        unsigned int signo:1;
    };
    struct resultadoCampos resultado;

    bool esDenormal(unsigned int e);
    bool esInfinito(unsigned int e, unsigned int f);
    bool esNaN(unsigned int e, unsigned int f);
};

#endif // ALU_H
