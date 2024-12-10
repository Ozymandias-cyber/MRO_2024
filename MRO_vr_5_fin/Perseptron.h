#pragma once
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>
#include <iostream>

#ifndef PERSEPTRON
#define PERSEPTRON

using namespace std;

class Perseptron
{
public:
	static std::vector<std::vector<float>> Multiple( std::vector<std::vector<float>>& A, std::vector<std::vector<float>>& B);
	static float Summator(std::vector<std::vector<float>> A);
	static float Func_activ(float x);
};

#endif PERSEPTRON

