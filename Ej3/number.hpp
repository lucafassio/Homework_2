#ifndef NUMBER_H
#define NUMBER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Number{
    protected:
        float num;
    public:
        Number(float n);
        virtual float get_value() const;
        virtual void set_value(float n);
        virtual void print_value() const;
        virtual void plus(const Number& n);
        virtual void minus(const Number& n); 
        virtual void times(const Number& n);
};


class Entero: public Number{
    public:
        Entero(int n);
};

class Real: public Number{
    public:
        Real(float n);
};

class Complejo: public Number{
    private:
        float complex;

    public:
        Complejo(float r, float c);

        float get_complex() const;
        void set_complex(float n);
        void print_value() const override;
        void plus(const Number& n) override; 
        void minus(const Number& n) override; 
        void times(const Number& n) override;
};

void Number_console();

#endif //NUMBER_H