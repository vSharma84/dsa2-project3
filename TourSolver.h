/***************************************************************
  Student Name: Vansh Sharma
  File Name: TourSolver.h
  Assignment number: 3

 Header file declaring the TourSolver class and the functions 
 used to solve the traveling salesman problem.
***************************************************************/

#ifndef TOURSOLVER_H
#define TOURSOLVER_H

#include "Graph.h"

class TourSolver
{
private:
    Graph g;
    int numCities;
    int populationSize;
    int generations;
    int mutationRate;
    double optimalCost;

public:
    void initialize();
    void runBruteForce();
    void runGeneticAlgorithm();
    double computeCost(int tour[]);
};

#endif