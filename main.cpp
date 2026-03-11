/***************************************************************
  Student Name: Vansh Sharma
  File Name: main.cpp
  Assignment number: 3

 Main file that creates the TourSolver object, gathers user input,
 and runs the brute force and genetic algorithm solutions.
***************************************************************/

#include "TourSolver.h"

/*************************************************
Function: main
Description: Runs the program by creating the
             TourSolver object and executing the
             algorithms.
Parameters: none
Local Variables:
    TourSolver solver - solver used to run TSP
*************************************************/
int main()
{
    TourSolver solver;

    solver.initialize();

    solver.runBruteForce();

    solver.runGeneticAlgorithm();

    return 0;
}