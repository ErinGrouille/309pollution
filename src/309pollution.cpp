/*
** EPITECH PROJECT, 2021
** 309pollution
** File description:
** 309pollution func
*/

#include "309pollution.hpp"

void usage(bool out)
{
    std::string msg = "USAGE\n" \
        "\t./309pollution n file x y\n" \
        "DESCRIPTION\n" \
        "\tn\tnumber of points on the grid axis\n" \
        "\tfile\tcsv file containing the data points x;y;p\n" \
        "\tx\tabscissa of the point whose pollution level we want to know\n" \
        "\ty\tordinate of the point whose pollution level we want to know";

    if (out)
        std::cout << msg << std::endl;
    else
        std::cerr << msg << std::endl;
}

int check_int(char *to_check)
{
    int res = -1;

    try
    {
        res = std::stoi(std::string(to_check));
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
    return res;
}

float check_float(char *to_check)
{
    float res = -1;

    try
    {
        res = std::stof(std::string(to_check));
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
    return res;
}

std::vector<std::vector<double>> parse_file(std::string file)
{
    std::vector<std::vector<double>> data = std::vector<std::vector<double>>();
    std::ifstream data_file;
    size_t delim1 = 0;
    size_t delim2 = 0;
    int x = 0;
    int y = 0;
    int p = 0;

    data_file.open(file);
    if (!data_file.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line = "";
    std::vector<double> vect = std::vector<double>();
    while(std::getline(data_file, line)) {
        //check line validity ?
        vect.clear();
        delim1 = line.find(";");
        delim2 = line.find(";", delim1 + 1);
        x = std::stod(line.substr(0, delim1));
        y = std::stod(line.substr(delim1 + 1, delim2 - delim1));
        p = std::stod(line.substr(delim2 + 1));
        vect.push_back(x);
        vect.push_back(y);
        vect.push_back(p);
        data.push_back(vect);
    }

    data_file.close();
    return data;
}

//MATHS funcs

float bezier(std::vector<std::vector<double>> data, int n, float u, float v)
{
    float res = 0;
    float pol = 0;

    double corresp = 0;
    int point = -1;
    int i = 0;
    int j = 0;

    while (i < n) {
        while (j < n) {
            point = find_point(data, j, i);
            corresp = 0;
            if (point >= 0)
                corresp = data[point][2];
            pol = bernstein_polynomial(n - 1, i, v);
            pol *= bernstein_polynomial(n - 1, j, u);
            pol *= corresp;
            res += pol;
            j++;
        }
        j = 0;
        i++;
    }
    return res;
}

int find_point(std::vector<std::vector<double>> data, int x, int y)
{
    int i = 0;

    while (i < (int) data.size()) {
        if (data[i][0] == x && data[i][1] == y)
            return i;
        i++;
    }
    return -1;
}

float bernstein_polynomial(int n, int i, float u)
{
    float res = binomialCoefficients(n, i) * pow(u, i) * pow((1 - u),(n - i));
    return res;
}

double binomialCoefficients(int n, int k)
{
    if (k == 0 || k == n)
        return 1;
    return binomialCoefficients(n - 1, k - 1) + binomialCoefficients(n - 1, k);
}