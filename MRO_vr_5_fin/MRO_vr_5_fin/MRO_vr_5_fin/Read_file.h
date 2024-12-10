#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sstream>

#ifndef POINT_GENERATOR_H
#define POINT_GENERATOR_H
using namespace std;



class PointGenerator{
    class Point {
    public:
        float x;
        float y;
        Point(float xCoord, float yCoord) : x(xCoord), y(yCoord) {}

    };

public:
           PointGenerator() { std::srand(static_cast<unsigned int>(std::time(nullptr))); }// »нициализаци€ генератора случайных чисел
      void generateRandomPoints(int count, float xMin, float xMax, float yMin, float yMax, std::vector<Point>& points);
      void savePointsToFile(const std::vector<Point>& points, const std::string& filename);
      void processInputFile(const std::string& inputFilename);
};

#endif  POINT_GENERATOR_H