#ifndef WEIGHTSUM_H
#define WEIGHTSUM_H

#include "aggregationfunction.h"

class WeightSum : public AggregationFunction
{
public:
    WeightSum();

    double process(std::vector<Input> inputs);
};

#endif // WEIGHTSUM_H
