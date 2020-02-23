#include "testneuron.h"
/*
#include <iostream>
#include <vector>
#include <memory>

#include "neuron.h"
#include "input.h"

// Aggregation Function
#include "distancecalculation.h"
#include "weightsum.h"

// Activation Function
#include "heavyside.h"
#include "sigmoid.h"

TestNeuron::TestNeuron()
{

}

int TestNeuron::runAllTest()
{
    int res {0};

    std::cout << "Run all test" << std::endl;

    if(test01() == false)
    {
        ++res;
    }

    if(test02() == false)
    {
        ++res;
    }

    if(test03() == false)
    {
        ++res;
    }

    if(test04() == false)
    {
        ++res;
    }

    return res;
}

bool TestNeuron::test01()
{
    bool res {false};

    std::unique_ptr<WeightSum> weight_sum(new WeightSum());
    std::unique_ptr<Heavyside> heavyside(new Heavyside());

    std::vector<Input> inp;
    inp.push_back(Input(5.0, 2.0));
    inp.push_back(Input(4.2, 1.8));

    Neuron n1(inp, 1.0, std::move(weight_sum), std::move(heavyside));

    if(n1.getOutput() == 1)
    {
        res = true;
    }

    return res;
}

bool TestNeuron::test02()
{
    bool res {false};

    std::shared_ptr<WeightSum> weight_sum(new WeightSum());
    std::shared_ptr<Sigmoid> sigmoid(new Sigmoid());

    std::vector<Input> inp;
    inp.push_back(Input(5.0, 2.0));
    inp.push_back(Input(4.2, 1.8));

    Neuron n1(inp, 1.0, std::move(weight_sum), std::move(sigmoid));

    if(n1.getOutput() == 0.9999)
    {
        res = true;
    }

    return res;
}

bool TestNeuron::test03()
{
    bool res {false};

    std::shared_ptr<DistanceCalculation> dist_calc(new DistanceCalculation());
    std::shared_ptr<Heavyside> heavyside(new Heavyside());

    std::vector<Input> inp;
    inp.push_back(Input(5.0, 2.0));
    inp.push_back(Input(4.2, 1.8));

    Neuron n1(inp, 1.0, std::move(dist_calc), std::move(heavyside));

    if(n1.getOutput() == 1)
    {
        res = true;
    }

    return res;

}

bool TestNeuron::test04()
{
    bool res {false};

    std::shared_ptr<DistanceCalculation> dist_calc(new DistanceCalculation());
    std::shared_ptr<Sigmoid> sigmoid(new Sigmoid());

    std::vector<Input> inp;
    inp.push_back(Input(5.0, 2.0));
    inp.push_back(Input(4.2, 1.8));

    Neuron n1(inp, 1.0, std::move(dist_calc), std::move(sigmoid));

    if(n1.getOutput() == 0.945)
    {
        res = true;
    }

    return res;
}
*/
