#ifndef NUMBER_H
#define NUMBER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Real;
class Complejo;

class Entero{
    private:
        int num;

    public:
        Entero(int n);

        int get_value() const;
        void set_value(int n);
        void print_value() const;
        void plus(Entero n);
        void plus(Real n);
        void minus(Entero n);
        void minus(Real n);
        void times(Entero n);
        void times(Real n);
};

class Real{
    private:
        float num;

    public:
        Real(float n);

        float get_value() const;
        void set_value(int n);
        void print_value() const;
        void plus(Real n);
        void plus(Entero n);
        void minus(Real n);
        void minus(Entero n);
        void times(Real n);
        void times(Entero n);
};

class Complejo{
    private:
        Real real;
        Real complex;

    public:
        Complejo(Real r, Real c);

        float get_real() const;
        float get_complex() const;
        void set_real(float n);
        void set_complex(float n);
        void print_value() const;
        void plus(Complejo n);
        void minus(Complejo n);
        void times(Complejo n);
};

#endif