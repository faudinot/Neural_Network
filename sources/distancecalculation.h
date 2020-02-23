#ifndef DISTANCECALCULATION_H
#define DISTANCECALCULATION_H

#include "aggregationfunction.h"

class DistanceCalculation : public AggregationFunction
{
public:
    DistanceCalculation();

    double process(std::vector<Input> inputs);
};

#endif // DISTANCECALCULATION_H
