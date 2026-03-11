#include "TourSolver.h"

int main()
{
    TourSolver solver;

    solver.initialize();

    solver.runBruteForce();

    solver.runGeneticAlgorithm();

    return 0;
}