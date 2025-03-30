#ifndef NUMBER_H
#define NUMBER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class Number{
    public:
        virtual void toString() const = 0;
        virtual void plus(const Number& n) = 0;
        virtual void minus(const Number& n) = 0;
        virtual void times(const Number& n) = 0;
};

#endif //NUMBER_H