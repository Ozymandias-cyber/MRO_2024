#include <vector>
#include <iostream>
#include "Read_file.h"
#include "Simplest_Algorithm.h"
#include "Sifting_Algorithm.h"
#include "Maximin_Algorithm.h"
#include "Forel_Algoritm.h"
#include "ISODATA.h"

using namespace std;

int Simplest_Algorithm::k = 10;
float Simplest_Algorithm::h = 5;
int Sifting_Algorithm::maxIterations = 100;
int Maximin_Algorithm::numCenters = 10;
float radius = 15;
int main() {

setlocale(LC_ALL, "Russian");

//Simplest_Algorithm::Print_centrs(Simplest_Algorithm::kCenters\
	(Read_file:: Fill_vector(),Simplest_Algorithm::k,Simplest_Algorithm::h));

//Simplest_Algorithm::Print_centrs(Sifting_Algorithm::kMeans(Read_file::Fill_vector(),\
	Simplest_Algorithm::k, Sifting_Algorithm::maxIterations));

//Simplest_Algorithm::Print_centrs(Maximin_Algorithm::placeCenters\
	(Read_file::Fill_vector(), Maximin_Algorithm::numCenters));



//Forel_Algoritm::Print_ansver(Forel_Algoritm::cluster(Read_file::Fill_vector(), radius));

Forel_Algoritm::Print_ansver(ISODATA::cluster(Read_file::Fill_vector(), 10, 5.5, 100));
}