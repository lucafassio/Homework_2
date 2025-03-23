#include "class.hpp"

estudiante::estudiante(string name, int legajo, float avg):
    name(name), legajo(legajo), avg(avg)
{}

Curso::Curso(string name):
    students(), name(name)
{}