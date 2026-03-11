/***************************************************************
  Student Name: Vansh Sharma
  File Name: Graph.cpp
  Assignment number: 3

 Implements the Graph class functions for reading the distance 
 file and retrieving distances between cities.
***************************************************************/

#include <iostream>
#include <fstream>
#include "Graph.h"

using namespace std;

/*****************************************************
Function: readDistances
Description: Reads city distances from the file into 
             the distance matrix.
Parameters: none
Local Variables: double value - distance read from file
*****************************************************/
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

/*****************************************************
Function: setNumCities
Description: Sets the number of cities used in the graph.
Parameters: int n - number of cities
Local Variables: none
*****************************************************/
void Graph::setNumCities(int n)
{
    numCities = n;
}

/****************************************************
Function: getDistance
Description: Returns the distance between two cities.
Parameters: int i - starting city
            int j - destination city
Local Variables: none
****************************************************/
double Graph::getDistance(int i, int j)
{
    return dist[i][j];
}