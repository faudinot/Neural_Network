#include "dataset.h"

#include <cmath>
#include <iostream>


#include "randomgenerator.h"

DataSet::DataSet()
{

}

DataSet::DataSet(std::vector<Data> file_content, const double ratio_learning_set)
{
    m_ratio_learning_set = ratio_learning_set;
    m_file_content = file_content;

    size_t size_learning_set = static_cast<size_t>(ceil(file_content.size() * ratio_learning_set));
    size_t size_generalization_set = static_cast<size_t>(ceil(file_content.size() * (1 - ratio_learning_set)));

    while(m_generalization_set.size() < size_generalization_set)
    {
        RandomGeneratorInt generator(0, file_content.size());

        int index = generator();

        m_generalization_set.insert(index);
    }


    for(size_t i=0 ; i < m_file_content.size(); ++i)
    {
        if(m_generalization_set.find(i) == m_generalization_set.end())
        {
            m_learning_set.insert(i);
        }
    }

    if(file_content.size() != m_learning_set.size() + m_generalization_set.size())
    {
        std::cout << "Problem with data set" << std::endl;
    }
}

std::vector<Data> DataSet::getLearningSet()
{
    std::vector<Data> res;
    res.reserve(m_learning_set.size());

    for(const auto& item : m_learning_set)
    {
        res.push_back(m_file_content.at(item));
    }

    return res;
}

std::vector<Data> DataSet::getGeneralizationSet()
{
    std::vector<Data> res;
    res.reserve(m_generalization_set.size());

    for(const auto& item : m_learning_set)
    {
        res.push_back(m_file_content.at(item));
    }

    return res;
}

int DataSet::getLearningSetSize()
{
    return m_learning_set.size();
}
