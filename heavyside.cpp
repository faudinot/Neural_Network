#include "heavyside.h"

Heavyside::Heavyside()
{

}

double Heavyside::process(double value, double threshold)
{
    double res = 0.0;

    if(value > threshold)
    {
        res = 1.0;
    }

    return res;
}
