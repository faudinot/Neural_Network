#ifndef DATASET_H
#define DATASET_H

#include "data.h"

#include <string>
#include <set>

class DataSet
{
public:
    DataSet();

    DataSet(std::vector<Data> file_content, const double ratio_learning_set);

    std::vector<Data> getLearningSet();

    std::vector<Data> getGeneralizationSet();

    int getLearningSetSize();

private:
    double m_ratio_learning_set;
    std::vector<Data> m_file_content;
    std::set<int> m_learning_set;
    std::set<int> m_generalization_set;
};

#endif // DATASET_H
