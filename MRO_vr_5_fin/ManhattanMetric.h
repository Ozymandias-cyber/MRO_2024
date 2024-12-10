#pragma once
#include <vector>
#include <iostream>
using namespace std;
class Metrix
{
public:
	static float  Evclid(std::vector<float> A, std::vector<float>  B);
	static float Manhatans(std::vector<float> A, std::vector <float> B);
	static bool Upgrate_for_simple_Evclid(std::vector<std::vector<float>> A, std::vector<float> B);
};

