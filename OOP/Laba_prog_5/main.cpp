#include <cmath>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

double function(double x)
{
    if (x <= 0)
    {
        return (6 - 2 * x ) / 3;
    } else
    {
        return x;
    }
}

void tab(double a, double b, double step, const std::string& filename)
{
    std::ofstream file(filename);
    for (double x = a; x <= b; x += step)
    {
        file<<function(x) << std::endl;
    }
    file.close();
}

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
    tab(-5, 5, 0.1, filename);
    auto values = readValues(filename);

    if (!values.empty())
    {
        double minValue = values.front(), maxValue = values.front();
        size_t minIndex = 0, maxIndex = 0;

        for (size_t i = 0; i < values.size(); ++i)
        {
            if (values.at(i) < minValue)
            {
                minValue = values.at(i);
                minIndex = i;
            }
            if (values.at(i) > maxValue)
            {
                maxValue = values.at(i);
                maxIndex = i;
            }
        }
        std::cout << "Min element = " << minValue <<" min index = " << minIndex << std::endl
                  <<"Max element = " << maxValue <<" max index = " <<maxIndex<<std::endl;
    }
}
