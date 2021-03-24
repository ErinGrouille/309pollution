/*
** EPITECH PROJECT, 2021
** 309pollution
** File description:
** 309pollution header
*/

#ifndef POLLUTION
#define POLLUTION

#include <vector>
#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
//#include <sstream>

void usage(bool out);
int check_int(char *to_check);
float check_float(char *to_check);
std::vector<std::vector<double>> parse_file(std::string file);

float bezier(std::vector<std::vector<double>> data, int n, float u, float v);
int find_point(std::vector<std::vector<double>> data, int x, int y);
float bernstein_polynomial(int n, int i, float u);
double binomialCoefficients(int n, int k);

#endif /* !POLLUTION */