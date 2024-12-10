#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <utility>
class Maximin_Algorithm
{
public:
    static int numCenters;
    static std::vector<std::vector<float>> placeCenters(const std::vector<std::vector<float>>& points, int numCenters);

private:
    static float euclideanDistance(const std::vector<float>& a, const std::vector<float>& b);
};

