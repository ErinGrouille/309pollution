/*
** EPITECH PROJECT, 2021
** 309pollution
** File description:
** 309pollution main
*/

#include "309pollution.hpp"

int main(int ac, char**av)
{
    if (ac == 2 && (std::string(av[1])).find("-h") != std::string::npos) {
        usage(true);
        exit(EXIT_SUCCESS);
    } else if (ac != 5) {
        usage(false);
        exit(EXIT_FAILURE);
    }

    int n = check_int(av[1]);
    float x = check_float(av[3]);
    float y = check_float(av[4]);

    std::string file = std::string(av[2]);
    std::vector<std::vector<double>> data = parse_file(file);

    x = x / ((n)-1);
	y = y / ((n)-1);
    float res = bezier(data, n, x, y);
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    std::cout << res << std::endl;
    return 0;
}
