#ifndef SYSTEM_H
#define SYSTEM_H

#include <memory>

#include "aggregationfunction.h"
#include "activatefunction.h"

#include "dataset.h"
#include "multilayerperceptron.h"

class System
{
public:
    System();
    System(const int input_number, const int hidden_neurons, const int output_neurons, std::vector<Data>& data
           , const double learning_rate, std::shared_ptr<AggregationFunction> agg_fct, std::shared_ptr<ActivateFunction> act_fct );

    void launch();

    void setLearningRate(const double learning_rate);
    void setErrorMax(const double error_max);
    void setMaxIteration(const int max_iteration);

    void testMazureNetwork();

private:
    int m_max_iteration;

    double m_learning_rate;
    double m_error_max;

    DataSet m_dataset;
    MultiLayerPerceptron m_multilayer_perceptron;

};

#endif // SYSTEM_H
