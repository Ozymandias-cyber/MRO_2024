#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Sifting_Algorithm
{
public:
    static int maxIterations;
    static float distance(const std::vector<float>& a, const std::vector<float>& b);
    static std::vector<float> calculateCentroid(const std::vector<std::vector<float>>& cluster);
    static std::vector<std::vector<float>> kMeans(const std::vector<std::vector<float>>& points, int k, int maxIterations);
};

