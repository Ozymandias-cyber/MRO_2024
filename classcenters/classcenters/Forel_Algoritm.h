#pragma once
#ifndef FOREL_ALGORITM_H
#define FOREL_ALGORITM_H
#include <vector>
#include <cmath>
#include <iostream>
class Forel_Algoritm
{
public:
    static std::vector<std::vector<std::vector<float>>> cluster(const std::vector<std::vector<float>>& points, float radius);
    static void Print_ansver(std::vector<std::vector<std::vector<float>>> A);

private:
    static bool isInCluster(const std::vector<float>& center, const std::vector<float>& point, float radius);
};

#endif // FOREL_ALGORITM_H

