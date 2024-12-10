#include "Ho_ckoshap.h"

//������ ��������� ������ � ���������� �� � ��������� ������� 
std::vector<std::vector<float>> Ho_ckoshap::Initial_matrix(const std::string& filename)
{
    std::vector<std::vector<float>> points; // ������ ��� �������� �����
    std::ifstream inFile(filename); // ��������� ����

    if (!inFile.is_open()) {
        std::cerr << "�� ������� ������� ����: " << filename << std::endl;
        return points; // ���������� ������ ������ � ������ ������
    }

    std::string line;
    while (std::getline(inFile, line)) { // ������ ���� ���������
        std::istringstream iss(line);
        float x, y;

        // ��������� ���������� �� ������
        if (iss >> x >> y) {
            points.push_back({ x, y }); // ��������� ���� ��������� � ������
        }
        else {
            std::cerr << "������ ������ ������ �� ������: " << line << std::endl;
        }
    }

    inFile.close(); // ��������� ����
    return points; // ���������� ������ ��������
}



std::vector<std::vector<float>> Ho_ckoshap::Matrix_Transpose(std::vector<std::vector<float>> A)
{
    int row = A.size();
    int column = A[0].size();
    std::vector<std::vector<float>> Transposed_Matrix(column, std::vector<float>(row)); // ������������� �����������

    for (int r = 0; r < row; r++) {
        for (int c = 0; c < column; c++) {
            Transposed_Matrix[c][r] = A[r][c];
        }
    }
    return Transposed_Matrix;
}

std::vector<std::vector<float>> Ho_ckoshap::Matrix_Multiple(const std::vector<std::vector<float>>& A, const std::vector<std::vector<float>>& B)
{
    int rowA = A.size();            // ���������� ����� � ������ �������
    int columnA = A[0].size();      // ���������� �������� � ������ �������
    int columnB = B[0].size();      // ���������� �������� �� ������ �������

    // �������� �� ����������� ���������
    if (B.size() != columnA) {
        throw std::invalid_argument("���������� �������� ������ ������� ������ ���� ����� ���������� ����� ������ �������.");
    }

    // ������������� �������������� ������� C �������� rowA x columnB
    std::vector<std::vector<float>> Multiplied_Matrix(rowA, std::vector<float>(columnB, 0));

    // ��������� ������
    for (int r = 0; r < rowA; r++) {
        for (int c = 0; c < columnB; c++) {
            for (int k = 0; k < columnA; k++) {
                Multiplied_Matrix[r][c] += A[r][k] * B[k][c];
            }
        }
    }

    return Multiplied_Matrix;
}

std::vector<std::vector<float>> Ho_ckoshap::Removing_unnecessary(int a, int b, std::vector<std::vector<float>> C)
{
    std::vector<std::vector <float>> fin;
    std::vector<float> add;
    for (int i = 0; i < C.size(); i++) {
        add.clear();
        if (i == a)continue;
        for (int j = 0; j < C[0].size(); j++) {
            if (j == b)continue;
            add.push_back(C[i][j]);
        }
        fin.push_back(add);
    }
    return fin;
}

float Ho_ckoshap::Get_determinant(std::vector<std::vector<float>> A)
{
    // �������� �� ������ �������
    if (A.empty() || A[0].empty()) return 0;
    float b = 0;  
    if (A.size() == 1) return A[0][0];
    if (A.size() == 2) return A[0][0] * A[1][1] - A[1][0] * A[0][1];

    for (int element = 0; element < A[0].size(); element++) {
        // ������� ������ 0 � ������� ������� element
        auto subMatrix = Removing_unnecessary(0, element, A);
        b += A[0][element] * Get_determinant(subMatrix) * pow(-1, element);
    }
    return b;
}

std::vector<std::vector<float>> Ho_ckoshap::Matrix_of_minors(const std::vector<std::vector<float>>& A)
{
    std::vector<std::vector<float>> minors(A.size(), std::vector<float>(A[0].size()));
    for (int row = 0; row < A.size(); row++) {
        for (int element = 0; element < A[0].size(); element++) {
            minors[row][element] = Get_determinant(Removing_unnecessary(row, element, A));
        }
    }
    return minors;
}

std::vector<std::vector<float>> Ho_ckoshap::Algebraic_complement_matrix(std::vector<std::vector<float>> A)
{
    for (int row = 0; row < A.size(); row++) {
        for (int element = 0; element < A[0].size(); element++) {
            if ((row + element) % 2 != 0) A[row][element] = (A[row][element] * (-1));
        }
    }
    return A;

}

std::vector<std::vector<float>> Ho_ckoshap::Inverse_matrix(std::vector<std::vector<float>> A)
{
    std::vector < std::vector<float>> inversive(A.size(), std::vector<float>(A[0].size()));

    for (int row = 0; row < A.size(); row++) {
        for (int element = 0; element < A[0].size(); element++) {
            inversive[row][element] = ((1 / Get_determinant(A)) * Matrix_Transpose(Algebraic_complement_matrix(Matrix_of_minors(A)))[row][element]);
        }
    }
    return inversive;
}
std::vector<std::vector<float>> Ho_ckoshap::Pseudoinverse_matrix(std::vector<std::vector<float>> A)
{
    return Matrix_Multiple(Inverse_matrix(Matrix_Multiple(A, Matrix_Transpose(A))), Matrix_Transpose(A));
}

void Ho_ckoshap::PrintMatrix(const std::vector<std::vector<float>>& A)
{
    int row = A.size();
    int column = A[0].size();
    for (const auto& row : A) {
        for (const auto& element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

}

std::vector<std::vector<float>> Ho_ckoshap::Creat_positive_vector(std::vector<std::vector<float>> A)
{
    std::vector<std::vector<float>>newVector(A.size(), std::vector<float>({1}));
    return newVector;
}
// TODO �������� ���, �������� ������ ������� ������� ���� � � ����� ��� �������� ����
std::vector<std::vector<float>> Ho_ckoshap::Checking_for_positivity(std::vector<std::vector<float>> A)
{
    for (const auto& innerVector : A) 
    {
        // �������� �� ������� �������� ����������� �������
        for (const auto& element : innerVector) 
        {
            //  ������� �� �������������  
            while (element <= 0)
            {
                return A;
            }  
            return A;
        }
    }
}
    
  










