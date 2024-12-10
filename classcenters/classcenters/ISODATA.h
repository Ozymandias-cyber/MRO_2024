#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <unordered_map>

class ISODATA
{
public:
    static std::vector<std::vector<std::vector<float>>> cluster(const std::vector<std::vector<float>>& points,\
        int maxClusters, float threshold, int maxIterations);

private:
    static void initializeCentroids(const std::vector<std::vector<float>>& points,\
        std::vector<std::vector<float>>& centroids, int maxClusters);
    static void assignPointsToClusters(const std::vector<std::vector<float>>& points, \
        const std::vector<std::vector<float>>& centroids, std::vector<int>& clusterAssignments);
    static void updateCentroids(const std::vector<std::vector<float>>& points, \
        const std::vector<int>& clusterAssignments, std::vector<std::vector<float>>& centroids);
    static bool checkConvergence(const std::vector<std::vector<float>>& centroids, const std::vector<std::vector<float>>& points, \
        const std::vector<int>& clusterAssignments, float threshold);
    static float euclideanDistance(const std::vector<float>& a, const std::vector<float>& b);
    static std::vector<std::vector<std::vector<float>>> groupPointsIntoClusters(const std::vector<std::vector<float>>& points, \
        const std::vector<int>& clusterAssignments, int maxClusters);
};

