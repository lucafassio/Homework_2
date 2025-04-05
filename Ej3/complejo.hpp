#ifndef COMPLEJO_HPP
#define COMPLEJO_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class Complejo: public Number{
    private:
        float real;
        float complex;

    public:
        Complejo(float r, float c);

        float get_real() const;
        float get_complex() const;
        void set_real(float n);
        void set_complex(float n);

        string toString() const override;
        void plus(const Number& n) override;
        void minus(const Number& n) override;
        void times(const Number& n) override;
};

#endif //COMPLEJO_HPP