#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

const int MAX_CITIES = 20;

double dist[MAX_CITIES][MAX_CITIES];

int numCities;
int populationSize;
int generations;
double mutationRate;

void readDistances();
void getUserInput();
double computeCost(int tour[]);
void bruteForceTSP();
void geneticAlgorithmTSP();

int main()
{
    readDistances();
    getUserInput();

    cout << endl;

    bruteForceTSP();

    cout << endl;

    geneticAlgorithmTSP();

    return 0;
}
