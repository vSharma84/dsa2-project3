/***************************************************************
  Student Name: Vansh Sharma
  File Name: Graph.h
  Assignment number: 3

 Header file declaring the Graph class used to store and access 
 the city distance matrix. 
***************************************************************/

#ifndef GRAPH_H
#define GRAPH_H

class Graph
{
private:
    double dist[20][20];
    int numCities;

public:
    void readDistances();
    void setNumCities(int n);
    double getDistance(int i, int j);
};

#endif