#include <vector>
#include <string>
#include <fstream>
#include <iostream>

std::vector<double> readValues(const std::string& filename)
{
    std::vector<double> result;
    std::string str;
    std::ifstream in(filename);
    while (std::getline(in, str))
    {
        if(!str.empty())
        {
            result.push_back(std::stod(str));
        }
    }
    return result;
}

int main()
{
    std::string filename("values.txt");
    auto values = readValues(filename);
}
