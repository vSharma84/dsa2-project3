#include <iostream>
#include <ctime>
#include <cstdlib>
#include "TourSolver.h"

using namespace std;

int s[20];
int NUMELEMENTS;

void swapVals(int i, int j)
{
    int temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

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

void TourSolver::initialize()
{
    cout << "Enter number of cities: ";
    cin >> numCities;

    NUMELEMENTS = numCities;

    g.setNumCities(numCities);
    g.readDistances();

    srand(time(NULL));
}

double TourSolver::computeCost(int tour[])
{
    double cost = 0;

    for(int i = 0; i < numCities - 1; i++)
        cost += g.getDistance(tour[i], tour[i+1]);

    cost += g.getDistance(tour[numCities-1], tour[0]);

    return cost;
}

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

    cout << "Number of cities: " << numCities << endl;
    cout << "Optimal cost from brute force: " << optimalCost << endl;
    cout << "Time for brute force: " << timeTaken << " seconds" << endl;
}

void TourSolver::runGeneticAlgorithm()
{
    int populationSize;
    int generations;
    int mutationRate;

    cout << "Enter number of tours per generation: ";
    cin >> populationSize;

    cout << "Enter number of generations: ";
    cin >> generations;

    cout << "Enter mutation percentage: ";
    cin >> mutationRate;

    clock_t start = clock();

    int bestTour[20];
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

                for(int i = 0; i < numCities; i++)
                    bestTour[i] = tour[i];
            }
        }
    }

    clock_t end = clock();

    double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

    double percent = (bestCost / optimalCost) * 100;

    cout << "Cost from GA: " << bestCost << endl;
    cout << "Time GA took: " << timeTaken << " seconds" << endl;
    cout << "Percent of optimal: " << percent << "%" << endl;
}