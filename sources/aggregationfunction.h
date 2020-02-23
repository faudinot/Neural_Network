#ifndef AGGREGATIONFUNCTION_H
#define AGGREGATIONFUNCTION_H

#include <vector>

#include "input.h"


class AggregationFunction
{
public :

    virtual double process(std::vector<Input> inputs) = 0;

};

#endif // AGGREGATIONFUNCTION_H
