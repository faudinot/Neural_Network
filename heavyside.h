#ifndef HEAVYSIDE_H
#define HEAVYSIDE_H

#include "activatefunction.h"

class Heavyside : public ActivateFunction
{
public:
    Heavyside();

    double process(double value, double threshold);

    void display();

};

#endif // HEAVYSIDE_H
