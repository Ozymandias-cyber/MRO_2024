#include "Read_file.h"
 

std::vector<std::vector<float>> Read_file::Fill_vector()
{
    std::ifstream inFile("points.txt");
    if (!inFile) {
        std::cerr << "Не удалось открыть файл для чтения." << std::endl;
    }

    std::vector<std::vector<float>> points; // Вектор векторов для хранения координат

    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        float x, y;

        // Чтение координат из строки
        if (iss >> x >> y) {
            points.push_back({ x, y }); // Добавление координат в вектор
        }
        else {
            std::cerr << "Ошибка чтения координат из строки: " << line << std::endl;
        }
    }
    return points;
    inFile.close();

}

