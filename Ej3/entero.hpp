#ifndef ENTERO_HPP
#define ENTERO_HPP

#include "number.hpp"

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class Entero: public Number{
    private:
        int num;

    public:
        Entero(int n);

        int get_value() const;
        void set_value(int n);
        
        void toString() const override;
        void plus(const Number& n) override;
        void minus(const Number& n) override;
        void times(const Number& n) override;
};



#endif //ENTERO_HPP