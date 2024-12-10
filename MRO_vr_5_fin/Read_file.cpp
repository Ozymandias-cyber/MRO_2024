#include "Read_file.h"

// ������� ��� ���� ����� cout  � int �� float
void PointGenerator::generateRandomPoints(int count, float xMin, float xMax, float yMin, float yMax, std::vector<Point>& points)
{for (int i = 0; i < count; ++i) {
    float x = xMin + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (xMax - xMin)));
    float y = yMin + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (yMax - yMin)));
        points.emplace_back(x, y);
    }
}

void PointGenerator::savePointsToFile(const std::vector<Point>& points, const std::string& filename)
{
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& point : points) {
            outFile << point.x << " " << point.y << "\n";
        }
        outFile.close();
    }
    else {
        std::cerr << "�� ������� ������� ���� ��� ������: " << filename << std::endl;
    }
}

void PointGenerator::processInputFile(const std::string& inputFilename)
{
    std::ifstream inFile(inputFilename);
    if (!inFile.is_open()) {
        std::cerr << "�� ������� ������� ���� ��� ������." << std::endl;
        return;
    }

    std::string line;
    int setNumber = 1;
    PointGenerator::CountMatrix = 0;

    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        int pointCount;
        float xMax, xMin, yMax, yMin;

        if (!(iss >> pointCount >> xMax >> xMin >> yMax >> yMin)) {
            std::cerr << "������ ������ ������ �� ������: " << line << std::endl;
            continue; // ���������� ������ � �������
        }

        // ��������� ��������� �����
        std::vector<Point> points;
        generateRandomPoints(pointCount, xMin, xMax, yMin, yMax, points);

        // ���������� ����� � ����
        std::string outputFilename = "points_set_" + std::to_string(setNumber) + ".txt";
        savePointsToFile(points, outputFilename);
        std::cout << "��������� ����� ��������� � ����: " << outputFilename << std::endl;

        setNumber++;
        CountMatrix++;
    }
    inFile.close();
}


