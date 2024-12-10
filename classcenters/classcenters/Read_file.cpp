#include "Read_file.h"
 

std::vector<std::vector<float>> Read_file::Fill_vector()
{
    std::ifstream inFile("points.txt");
    if (!inFile) {
        std::cerr << "�� ������� ������� ���� ��� ������." << std::endl;
    }

    std::vector<std::vector<float>> points; // ������ �������� ��� �������� ���������

    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        float x, y;

        // ������ ��������� �� ������
        if (iss >> x >> y) {
            points.push_back({ x, y }); // ���������� ��������� � ������
        }
        else {
            std::cerr << "������ ������ ��������� �� ������: " << line << std::endl;
        }
    }
    return points;
    inFile.close();

}

