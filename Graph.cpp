#include <iostream>
#include <fstream>
#include "Graph.h"

using namespace std;

void Graph::readDistances()
{
    ifstream file("distances.txt");

    int i = 0;
    int j = 0;
    double value;

    for(int k = 0; k < 380; k++)
    {
        file >> value;

        if(i == j)
            j++;

        dist[i][j] = value;

        j++;

        if(j == 20)
        {
            i++;
            j = 0;
        }
    }

    file.close();
}

void Graph::setNumCities(int n)
{
    numCities = n;
}

double Graph::getDistance(int i, int j)
{
    return dist[i][j];
}