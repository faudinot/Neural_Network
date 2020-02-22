#ifndef SIGMOID_H
#define SIGMOID_H

#include "activatefunction.h"

class Sigmoid : public ActivateFunction
{
public:
    Sigmoid();

    double process(double value, double threshold);
};

#endif // SIGMOID_H
