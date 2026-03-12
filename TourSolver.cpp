/***************************************************************
  Student Name: Vansh Sharma
  File Name: TourSolver.cpp
  Assignment number: 3

 Main driver file that creates the TourSolver object, gathers 
 user input, and runs the brute force and genetic algorithm solutions.
***************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "TourSolver.h"

using namespace std;

int s[20];
int NUMELEMENTS;

/*****************************************************
Function: swapVals
Description: Swaps two elements in the tour.
Parameters: int i - first index
            int j - second index
Local Variables: int temp - temporary variable for swap
*****************************************************/
void swapVals(int i, int j)
{
    int temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

/*****************************************************
Function: perm1
Description: Generates the next permutation of the tour.
Parameters: none
Local Variables: int m, k, p, q - indices used in permutation
*****************************************************/
bool perm1()
{
    int m = NUMELEMENTS - 2;

    while(m >= 0 && s[m] > s[m+1])
        m--;

    if(m < 0)
        return false;

    int k = NUMELEMENTS - 1;

    while(s[m] > s[k])
        k--;

    swapVals(m, k);

    int p = m + 1;
    int q = NUMELEMENTS - 1;

    while(p < q)
    {
        swapVals(p, q);
        p++;
        q--;
    }

    return true;
}

/************************************************************
Function: initialize
Description: Prompts the user for program inputs and prepares
             the graph and solver variables.
************************************************************/
void TourSolver::initialize()
{
    cout << "Enter number of cities: ";
    cin >> numCities;

    cout << "Enter number of tours per generation: ";
    cin >> populationSize;

    cout << "Enter number of generations: ";
    cin >> generations;

    cout << "Enter mutation percentage: ";
    cin >> mutationRate;

    NUMELEMENTS = numCities;

    g.setNumCities(numCities);
    g.readDistances();

    srand(time(NULL));
}

/********************************************************
Function: computeCost
Description: Computes the total distance of a tour.
Parameters: int tour[] - order of cities in the tour
Local Variables: double cost - total distance of the tour
*********************************************************/
double TourSolver::computeCost(int tour[])
{
    double cost = 0;

    for(int i = 0; i < numCities - 1; i++)
        cost += g.getDistance(tour[i], tour[i+1]);

    cost += g.getDistance(tour[numCities-1], tour[0]);

    return cost;
}

/*******************************************************
Function: runBruteForce
Description: Finds the optimal tour by checking 
             all possible permutations.
Parameters: none
Local Variables: double cost - cost of current tour
                 double timeTaken - runtime of algorithm
********************************************************/
void TourSolver::runBruteForce()
{
    clock_t start = clock();

    for(int i = 0; i < numCities; i++)
        s[i] = i;

    optimalCost = 999999999;

    do
    {
        double cost = computeCost(s);

        if(cost < optimalCost)
            optimalCost = cost;

    } while(perm1());

    clock_t end = clock();

    double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

    cout << "Number of cities run: " << numCities << endl;
    cout << "Optimal cost from brute force: " << optimalCost << endl;
    cout << "Time the brute force algorithm took: " << timeTaken << " seconds" << endl;
}

/*******************************************************
Function: runGeneticAlgorithm
Description: Generates random tours and uses mutation to 
             find an approximate solution.
Parameters: none
Local Variables: int tour[] - generated tour
                 double bestCost - best tour cost found
*******************************************************/
void TourSolver::runGeneticAlgorithm()
{
    clock_t start = clock();

    double bestCost = 999999999;

    for(int gCount = 0; gCount < generations; gCount++)
    {
        for(int p = 0; p < populationSize; p++)
        {
            int tour[20];

            for(int i = 0; i < numCities; i++)
                tour[i] = i;

            for(int i = 1; i < numCities; i++)
            {
                int j = rand() % numCities;
                int temp = tour[i];
                tour[i] = tour[j];
                tour[j] = temp;
            }

            if(rand() % 100 < mutationRate)
            {
                int a = rand() % numCities;
                int b = rand() % numCities;
                int temp = tour[a];
                tour[a] = tour[b];
                tour[b] = temp;
            }

            double cost = computeCost(tour);

            if(cost < bestCost)
            {
                bestCost = cost;
            }
        }
    }

    clock_t end = clock();

    double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

    double percent = (bestCost / optimalCost) * 100;

    cout << "Cost from the GA: " << bestCost << endl;
    cout << "Time the GA took to run: " << timeTaken << " seconds" << endl;
    cout << "Percent of optimal: " << percent << "%" << endl;
}