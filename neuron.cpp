#include "neuron.h"

#include "randomgenerator.h"

#include <iostream>

Neuron::Neuron()
{

}
/*
Neuron::Neuron(std::vector<Input> inputs, double threshold, std::unique_ptr<AggregationFunction> aggFct, std::unique_ptr<ActivateFunction> actFct)
{
    m_inputs = inputs;
    m_threshhold = threshold;
    m_aggregation_fct = std::move(aggFct);
    m_activate_fct = std::move(actFct);
}
*/

Neuron::Neuron(int nbr_inputs, std::shared_ptr<AggregationFunction> aggFct, std::shared_ptr<ActivateFunction> actFct)
{
    m_nbr_inputs = nbr_inputs;
    m_aggregation_fct = std::move(aggFct);
    m_activate_fct = std::move(actFct);
    m_output = 0.0;
    m_is_output_valid = false;

    createNeuron();
}

Neuron::~Neuron()
{

}

void Neuron::createNeuron()
{
    RandomGeneratorDouble generator_double{-1,1};

    for(int i=0; i < m_nbr_inputs; ++i)
    {
        m_inputs.emplace_back(Input(generator_double(), generator_double()));
    }

    m_threshold = generator_double();
}

void Neuron::display()
{
    std::cout << "Neuron Specifications" << std::endl;

    for(auto& input : m_inputs)
    {
        input.display();
    }

    std::cout << "\tThreshold : " << m_threshold << std::endl;

    std::cout << "\tOutput : " << m_output << "\n" << std::endl;
}

void Neuron::setInput(Data data)
{
    if(data.values.size() != m_inputs.size())
    {
        std::cout << "Mismatch data / input : \t" << data.values.size() << "\t" << m_inputs.size() << std::endl;
        return;
    }

    for(size_t i=0; i < m_inputs.size(); ++i)
    {
        m_inputs.at(i).value = data.values.at(i);
    }
}

void Neuron::setInput(std::vector<double> inputs)
{
    if(inputs.size() != m_inputs.size())
    {
        std::cout << "Mismatch inputs / input" << std::endl;
        return;
    }

    for(size_t i=0; i < m_inputs.size(); ++i)
    {
        m_inputs.at(i).value = inputs.at(i);
    }
}

double Neuron::getWeight(const int index)
{    
    return m_inputs.at(index).weight;
}


void Neuron::setWeight(const int index, const double value)
{
    m_inputs.at(index).weight = value;
}

void Neuron::resetOutput()
{
    m_output = 0.0;
    m_is_output_valid = false;
}

double Neuron::getOutput()
{
    aggregateInputs();

    activation();

    m_is_output_valid = true;

    return m_output;
}

double Neuron::getThreshold()
{
    return m_threshold;
}

void Neuron::setThreshold(const double value)
{
    m_threshold = value;
}


// --------- PRIVATE

void Neuron::aggregateInputs()
{
    m_aggregate_value = m_aggregation_fct->process(m_inputs);
    //std::cout << m_aggregate_value << std::endl;
}

void Neuron::activation()
{
    m_output = m_activate_fct->process(m_aggregate_value, m_threshold);
}
