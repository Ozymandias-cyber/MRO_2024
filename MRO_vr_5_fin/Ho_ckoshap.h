#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>
#include"Read_file.h"
#ifndef HO_CKOSHAP
#define HO_CKOSHAP
class Ho_ckoshap{
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
	static void PrintMatrix(std::vector<std::vector<float>> matrix);
	std::vector<std::vector <float>> Creat_positive_vector(std::vector<std::vector<float>> A);
	bool Checking_for_positivity(std::vector<std::vector<float>> A);
	std::vector<std::vector<float>> Fill_hockoshap_vector(std::vector<std::vector<float>> A, std::vector<std::vector<float>> B);
	std::vector<std::vector<float>> Ho__ckoshap(std::vector < std::vector < float>> A, std::vector < std::vector < float>> B, float C);
	std::vector<std::vector<float>> Multiply_matrix_by_number(std::vector<std::vector<float>> A, float Hk);
	std::vector<std::vector<float>> Matrix_addition(std::vector<std::vector<float>> A, std::vector<std::vector<float>> B);
	std::vector<std::vector<float>> Subtraction_matrices(std::vector<std::vector<float>> A, std::vector<std::vector<float>> B);
	void Save_ho_vector_to_txt(const std::vector<std::vector<float>>& A, const std::string& filename);
};
#endif HO_CKOSHAP
