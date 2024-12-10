#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>
#include"Read_file.h"

class Ho_ckoshap
{
public: 

	std::vector<std::vector<float>> Initial_matrix(const std::string& filename);
	std::vector<std::vector<float>> Matrix_Transpose(std::vector<std::vector<float>> A);
	std::vector<std::vector<float>> Matrix_Multiple(const std::vector<std::vector<float>>& A, const std::vector<std::vector<float>>& B);
	std::vector<std::vector <float>> Removing_unnecessary(int a, int b, std::vector<std::vector <float>> C);
	float Get_determinant(std::vector<std::vector<float>> A);
	std::vector<std::vector<float>> Matrix_of_minors(const std::vector<std::vector<float>>& A);
	std::vector<std::vector <float>> Algebraic_complement_matrix(std::vector<std::vector<float>> A);
	std::vector<std::vector <float>>Inverse_matrix(std::vector<std::vector<float>> A);
	std::vector<std::vector <float>> Pseudoinverse_matrix(std::vector<std::vector<float>> A);
	void PrintMatrix(const std::vector<std::vector<float>>& matrix);
	std::vector<std::vector < float>> Creat_positive_vector(std::vector<std::vector<float>> A);
	std::vector<std::vector < float>> Checking_for_positivity(std::vector<std::vector<float>> A);

};

