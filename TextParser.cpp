#include "TextParser.h"

#include <sstream>
#include <algorithm>

TextParser::TextParser()
{
    //ctor
}

TextParser::TextParser(const string& filename) : m_filename(filename), m_first_line(true), m_second_line(true)
{
    m_data.reserve(10);

    open_file();
}

TextParser::~TextParser()
{
    if(m_file.is_open())
    {
        m_file.close();
    }
}

// --------- PUBLIC ---------

vector<Data> TextParser::get_all_data()
{
    if(m_file)
    {
        m_line.clear();
        m_data.clear();

        while(std::getline(m_file, m_line))
        {
            //std::cout << m_line << std::endl;
            parse_line(m_line);
        }
    }

    return m_data;
}


// --------- PRIVATE ---------

void TextParser::open_file()
{
    m_file.open(m_filename, ifstream::in);

}

void TextParser::parse_line(string& line)
{
    std::stringstream ss(line);
    std::string tokens;
    const std::string OUTPUT = "Output";
    char del = '\t';

    if(m_first_line == true)
    {
        std::getline(ss, tokens);
        m_first_line= false;
    }
    else if(m_second_line == true)
    {
        int count = 0;
        while(std::getline(ss, tokens, del))
       {
            if(tokens.compare(OUTPUT) == 0)
            {
                m_index_output.push_back(count);
            }

            ++count;
       }

        m_second_line = false;
    }
    else
    {
        int count = 0;
        Data tmp;

         while(std::getline(ss, tokens, del))
        {
            if(std::find(m_index_output.begin(), m_index_output.end(), count) == m_index_output.end())
            {
                tmp.values.push_back(std::stod(tokens));
            }
            else
            {
                tmp.outputs.push_back(std::stod(tokens));
            }

            ++count;
        }

        m_data.push_back(tmp);
    }

}
