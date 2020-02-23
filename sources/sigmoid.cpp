#include "sigmoid.h"

#include <cmath>

#include <iostream>

Sigmoid::Sigmoid()
{

}

double Sigmoid::process(double value, double threshold)
{
    double res = (1 / (1 + exp(-(value + threshold))));
    return res;
}
