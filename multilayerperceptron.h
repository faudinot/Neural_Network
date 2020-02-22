#ifndef MULTILAYERPERCEPTRON_H
#define MULTILAYERPERCEPTRON_H

#include "neuron.h"

//  https://mattmazur.com/2015/03/17/a-step-by-step-backpropagation-example/

class MultiLayerPerceptron
{
public:
    MultiLayerPerceptron();
    MultiLayerPerceptron(int nbrInputs, int nbrHiddenNeurons, int nbrOutputNeurons,
                         std::shared_ptr<AggregationFunction> agg_fct, std::shared_ptr<ActivateFunction> act_fct);

    void createNetwork();

    void process(Data data);

    void backpropagation(Data data, const double learningRate);

    std::vector<double> getOutputs(Data data);

    void setMattMazureNetwork();

    void displayNetwork();

private:
    int m_nbrInputs;
    int m_nbrHiddenNeurons;
    int m_nbrOutputNeurons;

    // Cast to shared_ptr if necessary
    std::shared_ptr<AggregationFunction> m_aggregation_fct;
    std::shared_ptr<ActivateFunction> m_activate_fct;

    std::vector<Neuron> m_hiddenNeurons;
    std::vector<Neuron> m_outputNeurons;
    std::vector<double> m_outputsNetworks;

};

#endif // MULTILAYERPERCEPTRON_H
