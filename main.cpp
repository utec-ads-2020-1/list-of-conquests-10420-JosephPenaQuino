#include <iostream>
#include <string>
#include <sstream>
#include <map> 
#include <stdio.h>

int main()
{
    int lines_number;
    std::cin >> lines_number;
    std::string current_line;
    std::string current_word;
    std::map<std::string, int> country_names_set;
    std::map<std::string, int>::iterator itr; 

    getline(std::cin, current_line);
    for (int i=0; i < lines_number; ++i)
    {
        getline(std::cin, current_line);
        std::istringstream cl_ss(current_line);

        // Read country
        cl_ss >> current_word;
        std::string current_country = current_word;
        if (country_names_set.find(current_country)==country_names_set.end())
            country_names_set.insert(std::pair<std::string, int>(current_country, 0));

        // Read names
        while(cl_ss >> current_word)
        {
            country_names_set[current_country]++;
        }
        // Print results
        // std::cout << current_country << " " << country_names_set[current_country] <<  std::endl;
    }
    
    for (itr = country_names_set.begin(); itr != country_names_set.end(); ++itr) 
        std::cout << itr->first << " " << itr->second <<  std::endl;
}   