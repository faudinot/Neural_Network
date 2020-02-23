#ifndef INPUT_H
#define INPUT_H

#include <iostream>

struct Input
{
    Input(double val, double wei) : value(val), weight(wei) {}
    void display() {std::cout << "\tValue : " << value << " ; Weight : " << weight << std::endl;}
    double value;
    double weight;
};

#endif // INPUT_H
