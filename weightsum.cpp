#include "weightsum.h"

#include <algorithm>
#include <iostream>

WeightSum::WeightSum()
{

}

struct MathWS
{
    MathWS() : res{0.0} {}
    void operator()(Input in)
    {
        res += (in.value * in.weight);
    }
    double res;
};

double WeightSum::process(std::vector<Input> inputs)
{
    //std::cout << "\tWeight Sum :" << std::endl;

    MathWS tmp = std::for_each(inputs.begin(), inputs.end(), MathWS());

    return tmp.res;

    /*
    double res = inputs.at(0).value * inputs.at(0).weight;
    res += inputs.at(1).value * inputs.at(1).weight;
    std::cout << res << std::endl;
    return res;
    */
}
