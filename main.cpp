#include <iostream>
#include <vector>
#include <memory>

#include "neuron.h"
#include "input.h"
#include "data.h"
#include "dataset.h"

#include "testneuron.h"

// Aggregation Function
#include "distancecalculation.h"
#include "weightsum.h"

// Activation Function
#include "heavyside.h"
#include "sigmoid.h"

#include "multilayerperceptron.h"
#include "system.h"

#include "TextParser.h"


using namespace std;

int main()
{
    // Aggregation function
    std::shared_ptr<DistanceCalculation> distance_calculation(new DistanceCalculation());
    std::shared_ptr<WeightSum> weight_sum(new WeightSum());

    // Activation function
    std::shared_ptr<Sigmoid> sigmoid(new Sigmoid());
    std::shared_ptr<Heavyside> heavyside(new Heavyside());

/*
    // XOR Problem
    TextParser txt("../ressources/xor.txt");
    std::vector<Data> tmp = txt.get_all_data();
    System my_system(2, 2, 1, tmp, 1.0, weight_sum, sigmoid);
*/
/*
    std::cout << "azerty" << std::endl;
    std::cout << tmp.size() << std::endl;
    for(const auto& item : tmp)
    {
        for(const auto& val : item.outputs)
        {
            //std::cout << item.values.size() << std::endl;
            std::cout << val << "\t";
        }
        std::cout << "\n";
    }
*/

/*
    // Matt Mazure
    TextParser txt("../ressources/matt_mazure.txt");
    std::vector<Data> tmp = txt.get_all_data();
    System my_system(2, 2, 2, tmp, 1.0, weight_sum, sigmoid);
    my_system.testMazureNetwork();
*/

/*
    // Abalone Problem
    TextParser txt("../ressources/abalone_norm.txt");
    std::vector<Data> tmp = txt.get_all_data();
    System my_system(10, 5, 1, tmp, 0.8, weight_sum, sigmoid);
    my_system.setLearningRate(0.6);
    my_system.setMaxIteration(50000);
*/

    // Abs/Ord Problem
    TextParser txt("../ressources/abs_ord.txt");
    std::vector<Data> tmp = txt.get_all_data();
    System my_system(2, 4, 1, tmp, 0.8, weight_sum, sigmoid);

    try{
        my_system.launch();
    }
    catch(const exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
