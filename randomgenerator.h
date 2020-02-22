#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

#include <random>


// Passer en template
class RandomGeneratorInt
{
public:
    RandomGeneratorInt(int min, int max) : dist{min, max} {}
    int operator()() {return dist(engine);}

private:
    //std::default_random_engine engine;
    std::random_device engine;
    std::uniform_int_distribution<> dist;
};


class RandomGeneratorDouble
{
public:
    RandomGeneratorDouble(double min, double max) : dist{min, max} {}
    double operator()() {return dist(engine);}

private:
    //std::default_random_engine engine;
    std::random_device engine;
    std::uniform_real_distribution<> dist;
};

#endif // RANDOMGENERATORINT_H
