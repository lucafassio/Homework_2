#ifndef REAL_HPP
#define REAL_HPP

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

class Real: public Number{
    private:
        float num;

    public:
        Real(float n);

        float get_value() const;
        void set_value(float n);
        
        string toString() const override;
        void plus(const Number& n) override;
        void minus(const Number& n) override;
        void times(const Number& n) override;
};

#endif //REAL_HPP