#include "system.h"

#include <math.h>

System::System()
{

}

System::System(const int input_number, const int hidden_neurons, const int output_neurons, std::vector<Data> &data, const double learning_rate,
               std::shared_ptr<AggregationFunction> agg_fct, std::shared_ptr<ActivateFunction> act_fct)
{
    m_learning_rate = 0.3;
    m_error_max = 0.005;
    m_max_iteration = 100;

    m_dataset = DataSet(data, learning_rate);

    m_multilayer_perceptron = MultiLayerPerceptron(input_number, hidden_neurons, output_neurons, agg_fct, act_fct);
}

// --------- PUBLIC ----------

void System::launch()
{
    int nbr_ite = 0;
    int nbr_overfiting = 0;
    double total_error = 99999;
    double old_error = 99999;
    double total_generalization_error = 99999;
    double old_generalization_error = 99999;

    std::cout << "========= Launch =========" << std::endl;

    while(nbr_ite < m_max_iteration && total_error > m_error_max && nbr_overfiting < 3)
    {
        old_error = total_error;
        total_error = 0;
        old_generalization_error = total_generalization_error;
        total_generalization_error = 0;

        // Evaluation & learning
        for(const auto data : m_dataset.getLearningSet())
        {
            std::vector<double> outputs = m_multilayer_perceptron.getOutputs(data);

            for(size_t i=0; i < outputs.size(); ++i)
            {
                double error = data.outputs.at(i) - outputs.at(i);
                total_error += (error * error);
            }

            m_multilayer_perceptron.backpropagation(data, m_learning_rate);
        } 


        // Generalization
        for(const auto data : m_dataset.getGeneralizationSet())
        {
            std::vector<double> outputs = m_multilayer_perceptron.getOutputs(data);

            for(size_t i=0; i < outputs.size(); ++i)
            {
                double error = data.outputs.at(i) - outputs.at(i);
                total_generalization_error += (error * error);
            }
        }

        if(total_generalization_error > old_generalization_error)
        {
            ++nbr_overfiting;
        }
        else
        {
            nbr_overfiting = 0;
        }

        // Modify learning rate
        if(total_error > old_error)
        {
            m_learning_rate /= 2.0;
        }

        std::cout << "Iteration : " << nbr_ite << std::endl;
        std::cout << "\tTotal Error : " << total_error << "\tGeneralization error : " << total_generalization_error << std::endl;
        std::cout << "\tLearning Rate : " << m_learning_rate << "\tAverage : " << sqrt(total_error / m_dataset.getLearningSetSize()) << std::endl;

        ++nbr_ite;
    }

    if(nbr_ite >= m_max_iteration)
    {
        std::cout << "Max iteration" << std::endl;
    }
    else if(total_error < m_error_max)
    {
        std::cout << "Max error" << std::endl;
    }
    else if(nbr_overfiting >= 3)
    {
        std::cout << "Overfiting" << std::endl;
    }
    else
    {
        std::cout << "Others reasons" << std::endl;
        std::cout << "Nbr ite : " << nbr_ite << "\tTotal error : " << total_error << "\tOverfiting : " << nbr_overfiting << std::endl;
    }

    m_multilayer_perceptron.displayNetwork();
}

void System::testMazureNetwork()
{
    m_multilayer_perceptron.setMattMazureNetwork();
}


// --------- PRIVATE ----------

void System::setMaxIteration(const int max_iteration)
{
    m_max_iteration = max_iteration;
}

void System::setLearningRate(const double learning_rate)
{
    m_learning_rate = learning_rate;
}

void System::setErrorMax(const double error_max)
{
    m_error_max = error_max;
}
