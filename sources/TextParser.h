#ifndef TEXTPARSER_H
#define TEXTPARSER_H

#include <iostream>
#include <fstream>
#include <string>

#include <data.h>

using std::string;
using std::vector;
using std::ifstream;


class TextParser
{
    public:
        TextParser();
        TextParser(const string& filename);
        ~TextParser();

        vector<Data> get_all_data();

    protected:

    private:
        bool m_first_line;  // Commentary
        bool m_second_line; // Input or Output
        string m_filename;
        string m_line;
        vector<Data> m_data;
        vector<int> m_index_output;
        ifstream m_file;

        void open_file();
        void parse_line(string& line);
        void fill_container();
};

#endif // TEXTPARSER_H
