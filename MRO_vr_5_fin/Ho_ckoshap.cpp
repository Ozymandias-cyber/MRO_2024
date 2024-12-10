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

std::vector<std::vector<float>> Ho_ckoshap::Matrix_Multiple( const std::vector<std::vector<float>>& A, const std::vector<std::vector<float>>& B)
{
    {
        if (A.empty() || B.empty() || A[0].empty() || B[0].empty()) {
            throw std::invalid_argument("������� �� ������ ���� �������.");
        }

        int rowA = A.size();            // ���������� ����� � ������ �������
        int columnA = A[0].size();      // ���������� �������� � ������ �������
        int columnB = B[0].size();      // ���������� �������� �� ������ �������

        // �������� �� ����������� ���������
        if (columnA != B.size()) {
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
    return Matrix_Multiple(Inverse_matrix( Matrix_Multiple(Matrix_Transpose(A),A)), Matrix_Transpose(A));
}

void Ho_ckoshap::PrintMatrix(std::vector<std::vector<float>> A)
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
// �������� ������� �� ��������������� 
bool Ho_ckoshap::Checking_for_positivity(std::vector<std::vector<float>> A)
{
    for (const auto& innerVector : A) 
    {
        // �������� �� ������� �������� ����������� �������
        for (const auto& element : innerVector) 
        {//  ������� �� �������������  
            if (element <= 0)
            {
                return false;
            }
            return true;
        }
    }
}

std::vector<std::vector<float>> Ho_ckoshap::Fill_hockoshap_vector(std::vector<std::vector<float>> A, std::vector<std::vector<float>> B)
{
    std::vector<std::vector<float>> Over_lord_vector;
    std::vector<float> dop_vecor;
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[i].size(); j++) {
            dop_vecor.push_back(A[i][j]);
        }
        dop_vecor.push_back(1);
        Over_lord_vector.push_back(dop_vecor);
        dop_vecor.clear();
    }
    
    for (int i = 0; i < B.size(); i++) {
        for (int j = 0; j < B[i].size(); j++) {
            dop_vecor.push_back(B[i][j]*-1);
        }
        dop_vecor.push_back(-1);
        Over_lord_vector.push_back(dop_vecor);
        dop_vecor.clear();
    }

    return Over_lord_vector;
}

//��������� ������� �� �����
std::vector<std::vector<float>> Ho_ckoshap::Multiply_matrix_by_number(std::vector<std::vector<float>> A, float Hk)
{
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[0].size(); j++) {
            A[i][j] = A[i][j] * Hk;
        }
    }
    return A;
}
//�������� ���� ������
std::vector<std::vector<float>> Ho_ckoshap::Matrix_addition(std::vector<std::vector<float>> A, std::vector<std::vector<float>> B)
{
    std::vector<std::vector<float>> C(A.size(), std::vector<float>(A[0].size()));
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[0].size(); j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

// ��������� ���� ������
std::vector<std::vector<float>> Ho_ckoshap::Subtraction_matrices(std::vector<std::vector<float>> A, std::vector<std::vector<float>> B)
{
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[0].size(); j++) {
            A[i][j] = A[i][j] + B[i][j];
        }
    }
    return A;
}



std::vector<std::vector<float>> Ho_ckoshap::Ho__ckoshap(std::vector<std::vector<float>> A, std::vector<std::vector<float>> B, float Hk)
{
    std::vector<std::vector<float>> y = Creat_positive_vector(Fill_hockoshap_vector(A, B));
    // w = �������������� �� v �������� �� Y

    std::vector<std::vector<float>> V = (Fill_hockoshap_vector(A, B));
    std::vector<std::vector<float>> V_trans = Pseudoinverse_matrix(V);
    std::vector<std::vector<float>> W = Matrix_Multiple(V_trans, y);
    if (Checking_for_positivity(Matrix_Multiple(V, W))) {
        return W;
    }
    else {
        while (not (Checking_for_positivity(Matrix_Multiple(V_trans, y)))) {
            y = Matrix_addition( y ,Multiply_matrix_by_number( Subtraction_matrices(Matrix_Multiple(V, W), y), Hk));
            W = Matrix_Multiple(V_trans, y);

        }
        
    }
    return W;
}

void Ho_ckoshap::Save_ho_vector_to_txt(const std::vector<std::vector<float>>& A, const std::string& filename) {
    // ��������� ���� ��� ����������
    std::ofstream outFile(filename, std::ios::app);

    // ���������, ������� �� �������� ����
    if (!outFile) {
        std::cerr << "������ ��� �������� �����: " << filename << std::endl;
        return;
    }

    // ���������� ������� � ����
    for (size_t i = 0; i < A.size(); ++i) {
        for (const float& number : A[i]) {
            outFile << number << " "; // ���������� ����� � ��������
        }
        // ���� ��� �� ��������� ������ �������, ��������� ������ ����� ��������� �� ����� ������
        if (i == A.size() - 1) {
            outFile << std::endl; // ������� ������ ����� ��������� ������ �������
        }
    }

    // ��������� ����
    outFile.close();
    std::cout << "������� ������� ��������� � ����: " << filename << std::endl;
}