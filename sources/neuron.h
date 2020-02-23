#ifndef NEURON_H
#define NEURON_H

#include <vector>
#include <memory>

#include "data.h"
#include "input.h"
#include "aggregationfunction.h"
#include "activatefunction.h"


// Voir les 3, 5 grands
// Créer les entrées et le seuil en interne, avec des valeurs aléatoires
class Neuron
{
public:
    Neuron();
    //Neuron(std::vector<Input> inputs, double threshold, std::unique_ptr<AggregationFunction> aggFct, std::unique_ptr<ActivateFunction> actFct);
    Neuron(int nbr_inputs, std::shared_ptr<AggregationFunction> aggFct, std::shared_ptr<ActivateFunction> actFct);
    ~Neuron();

    void createNeuron();

    void display();

    void setInput(Data data);
    void setInput(std::vector<double> inputs);

    double getWeight(const int index);
    void setWeight(const int index, const double value);

    double getOutput();
    void resetOutput();

    double getThreshold();
    void setThreshold(const double value);

private:
    bool m_is_output_valid;
    int m_nbr_inputs;
    double m_output;
    double m_threshold;
    double m_aggregate_value;
    std::vector<Input> m_inputs;
    std::shared_ptr<AggregationFunction> m_aggregation_fct;
    std::shared_ptr<ActivateFunction> m_activate_fct;

    void aggregateInputs();
    void activation();
};

#endif // NEURON_H
