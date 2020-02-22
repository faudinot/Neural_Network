#include "multilayerperceptron.h"

MultiLayerPerceptron::MultiLayerPerceptron()
{

}

MultiLayerPerceptron::MultiLayerPerceptron(int nbrInputs, int nbrHiddenNeurons, int nbrOutputNeurons,
                     std::shared_ptr<AggregationFunction> agg_fct, std::shared_ptr<ActivateFunction> act_fct)
{
    m_nbrInputs = nbrInputs;
    m_nbrHiddenNeurons = nbrHiddenNeurons;
    m_nbrOutputNeurons = nbrOutputNeurons;
    m_aggregation_fct = agg_fct;
    m_activate_fct = act_fct;

    createNetwork();
}

void MultiLayerPerceptron::createNetwork()
{
    m_hiddenNeurons.reserve(m_nbrHiddenNeurons);
    m_outputNeurons.reserve(m_nbrOutputNeurons);

    std::cout << "***** Hiddens Neurons *****" << std::endl;
    for(int i=0; i < m_nbrHiddenNeurons; ++i)
    {
        m_hiddenNeurons.emplace_back(Neuron(m_nbrInputs, m_aggregation_fct, m_activate_fct));
        m_hiddenNeurons.at(i).display();
    }

    std::cout << "\n----- Outputs Neurons -----" << std::endl;

    for(int i=0; i < m_nbrOutputNeurons; ++i)
    {
        m_outputNeurons.emplace_back(Neuron(m_nbrHiddenNeurons, m_aggregation_fct, m_activate_fct));
        m_outputNeurons.at(i).display();
    }
}

void MultiLayerPerceptron::process(Data data)
{
    m_outputsNetworks.clear();

    for(auto& neuron : m_hiddenNeurons)
    {
        neuron.resetOutput();
    }

    for(auto& neuron : m_outputNeurons)
    {
        neuron.resetOutput();
    }

    std::vector<double> outputs_hiddens_neurons;
    for(auto& neuron : m_hiddenNeurons)
    {
        neuron.setInput(data);
        outputs_hiddens_neurons.emplace_back(neuron.getOutput());
        //neuron.display();
    }

    for(auto& neuron : m_outputNeurons)
    {
        neuron.setInput(outputs_hiddens_neurons);
        m_outputsNetworks.emplace_back(neuron.getOutput());
        //neuron.display();
    }

}

void MultiLayerPerceptron::backpropagation(Data data, const double learningRate)
{
    // delta for output neurons
    std::vector<double> delta_output;
    //for(auto& output : m_outputNeurons)
    for(size_t i=0; i < m_outputNeurons.size(); ++i)
    {
        double output_value = m_outputNeurons.at(i).getOutput();
        double output_expected = data.outputs.at(i);

        //std::cout << output_value << "\t" << output_expected << "\t" << output_value * (1 - output_value) * (output_expected - output_value) << std::endl;

        delta_output.push_back(output_value * (1 - output_value) * (output_expected - output_value));
    }


    // delta for hidden neurons
    std::vector<double> delta_hidden;
    for(int i=0; i < m_nbrHiddenNeurons; ++i)
    {
        double output_value = m_hiddenNeurons.at(i).getOutput();
        double sum = 0.0;

        for(int j=0; j < m_nbrOutputNeurons; ++j)
        {
            sum += delta_output.at(j) * m_outputNeurons.at(j).getWeight(i);
        }

        delta_hidden.push_back(output_value * (1 - output_value) * sum);
    }


    // Modify output neuron weight
    double value, new_threshold;
    for(int i=0; i < m_nbrOutputNeurons; ++i)
    {
        for(int j=0; j < m_nbrHiddenNeurons; ++j)
        {
            value = m_outputNeurons.at(i).getWeight(j) + learningRate * delta_output.at(i) * m_hiddenNeurons.at(j).getOutput();
            m_outputNeurons.at(i).setWeight(j, value);
        }

        // Modif bias
        new_threshold = m_outputNeurons.at(i).getThreshold() + learningRate * delta_output.at(i) * 1.0;
        m_outputNeurons.at(i).setThreshold(new_threshold);
    }


    // Modify output hidden neuron
    for(int i=0; i < m_nbrHiddenNeurons; ++i)
    {
        for(int j=0; j < m_nbrInputs; ++j)
        {
            value = m_hiddenNeurons.at(i).getWeight(j) / learningRate * delta_hidden.at(i) * data.values.at(j);
            m_hiddenNeurons.at(i).setWeight(j, value);
        }

        new_threshold = m_hiddenNeurons.at(i).getThreshold() + learningRate * delta_hidden.at(i) * 1.0;
        m_hiddenNeurons.at(i).setThreshold(new_threshold);
    }

}

std::vector<double> MultiLayerPerceptron::getOutputs(Data data)
{
    process(data);

    return m_outputsNetworks;
}

void MultiLayerPerceptron::setMattMazureNetwork()
{

    std::cout << "\n--------- MAZURE NETWORK --------" << std::endl;

    m_hiddenNeurons.at(0).setWeight(0, 0.15);
    m_hiddenNeurons.at(0).setWeight(1, 0.20);
    m_hiddenNeurons.at(0).setThreshold(.35);

    m_hiddenNeurons.at(1).setWeight(0, 0.25);
    m_hiddenNeurons.at(1).setWeight(1, 0.30);
    m_hiddenNeurons.at(1).setThreshold(.35);

    m_outputNeurons.at(0).setWeight(0, 0.40);
    m_outputNeurons.at(0).setWeight(1, 0.45);
    m_outputNeurons.at(0).setThreshold(0.60);

    m_outputNeurons.at(1).setWeight(0, 0.50);
    m_outputNeurons.at(1).setWeight(1, 0.55);
    m_outputNeurons.at(1).setThreshold(0.60);

    std::cout << "***** Hiddens Neurons *****" << std::endl;
    for(int i=0; i < m_nbrHiddenNeurons; ++i)
    {
        m_hiddenNeurons.at(i).display();
    }

    std::cout << "\n----- Outputs Neurons -----" << std::endl;

    for(int i=0; i < m_nbrOutputNeurons; ++i)
    {
        m_outputNeurons.at(i).display();
    }
}

void MultiLayerPerceptron::displayNetwork()
{
    std::cout << "***** Hiddens Neurons *****" << std::endl;
    for(int i=0; i < m_nbrHiddenNeurons; ++i)
    {
        m_hiddenNeurons.at(i).display();
    }

    std::cout << "\n----- Outputs Neurons -----" << std::endl;

    for(int i=0; i < m_nbrOutputNeurons; ++i)
    {
        m_outputNeurons.at(i).display();
    }
}
