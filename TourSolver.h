#ifndef TOURSOLVER_H
#define TOURSOLVER_H

#include "Graph.h"

class TourSolver
{
private:
    Graph g;
    int numCities;

public:
    void initialize();
    void runBruteForce();
    void runGeneticAlgorithm();
    double computeCost(int tour[]);
};

#endif