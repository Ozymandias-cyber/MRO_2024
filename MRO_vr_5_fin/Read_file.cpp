#include "Read_file.h"

// именить все типы кроме cout  с int на float
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
        std::cerr << "Не удалось открыть файл для записи: " << filename << std::endl;
    }
}

void PointGenerator::processInputFile(const std::string& inputFilename)
{
    std::ifstream inFile(inputFilename);
    if (!inFile.is_open()) {
        std::cerr << "Не удалось открыть файл для чтения." << std::endl;
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
            std::cerr << "Ошибка чтения данных из строки: " << line << std::endl;
            continue; // Пропустить строку с ошибкой
        }

        // Генерация случайных точек
        std::vector<Point> points;
        generateRandomPoints(pointCount, xMin, xMax, yMin, yMax, points);

        // Сохранение точек в файл
        std::string outputFilename = "points_set_" + std::to_string(setNumber) + ".txt";
        savePointsToFile(points, outputFilename);
        std::cout << "Случайные точки сохранены в файл: " << outputFilename << std::endl;

        setNumber++;
        CountMatrix++;
    }
    inFile.close();
}


