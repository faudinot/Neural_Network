#include "distancecalculation.h"

#include <algorithm>
#include <cmath>

DistanceCalculation::DistanceCalculation()
{

}

struct MathDC
{
    MathDC() : res{0} {}
    void operator()(Input in) {res += pow((in.value - in.weight), 2); }
    double res;
};

double DistanceCalculation::process(std::vector<Input> inputs)
{
    MathDC tmp = std::for_each(inputs.begin(), inputs.end(), MathDC());

    return sqrt(tmp.res);
}
