#ifndef GRAPH_H
#define GRAPH_H

#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>


class Graph
{
public:
	std::vector<int>* vtab;
    int e;
    int v;

    Graph(char *NameOfFile)
    {
		v = e = 0;

		file.open(NameOfFile, std::ios::in);
		file >> v;

		vtab = new std::vector<int>[v];

		int a,b;
		while (file >> a >> b)
		{
			if(a > v || b > v)
			{
				std::cout << "ignoruje krawedz " << a << " " << b << std::endl;
				continue;
			}

			vtab[a].push_back(b);

			if( a != b )
				vtab[b].push_back(a);
			++e;
		}
		file.close();
	}

	Graph(const Graph& other)
	{
		v = other.v;
		e = other.e;
		vtab = new std::vector<int>[v];
		vtab = other.vtab;
	}

    ~Graph()
    {
		delete[] vtab;
	}


private:
    std::fstream file;
};




class Isomorphism
{
	typedef int value_type;

public:
	static int* permutationTab;

	Graph firstGraph;
	Graph secondGraph;

	Isomorphism(char* f, char* s) : firstGraph(f), secondGraph(s) {}
	~Isomorphism() {}



	bool isTheSameDegreeList()
	{
		int degsFirstGraph[firstGraph.v]; // lista wierzcholkow danego grafu
		int degsSecondGraph[secondGraph.v];

		for(int i = 0; i < firstGraph.v; i++)
		{
			degsFirstGraph[i] = firstGraph.vtab[i].size(); // zliczmay wszytkie krawedzie jesli sa miedzy dwoma wierzcholakmi roznymi to dwukrotnie
			degsSecondGraph[i] = secondGraph.vtab[i].size();
		}

		std::sort(degsFirstGraph, degsFirstGraph+firstGraph.v); // sortujemy stopnie wiercholkow
		std::sort(degsSecondGraph, degsSecondGraph+secondGraph.v);

		for(int i = 0; i < firstGraph.v; i++)
			if(degsFirstGraph[i] != degsSecondGraph[i]) // jesli stopnie wierzcholkmow sie nie pokrywaja zwracamy fałsz wtedy na pewno nei sa izomorficzne
				return false;
		return true;
	}

	static bool permutationTabOrder(int a, int b)
	{
		return permutationTab[a] < permutationTab[b];
	}


	bool checkPermutation()
	{
		for(int i = 0; i < firstGraph.v; i++)
		{
			if(firstGraph.vtab[i].size() != secondGraph.vtab[permutationTab[i]].size()) // jesli liczba pod - wierzcholkow danego wierzcholka sie nei zgada wracamy -> zla permutacja
				return false;

			std::sort(firstGraph.vtab[i].begin(), firstGraph.vtab[i].end(), permutationTabOrder); // posortuj pod - wierzcholki danego wiercholka do latwego porownywania

			for(size_t j = 0; j < firstGraph.vtab[i].size(); j++)
            {
                if(permutationTab[firstGraph.vtab[i][j]] != secondGraph.vtab[permutationTab[i]][j])     // sprawdzenei czy tablice permutacji sie pokrywaja
					    return false;
            }
		}
		return true;
	}



	bool isItIsomorphic()
	{
		//checks if there is the same number of vertices and edges
		if (firstGraph.v != secondGraph.v || firstGraph.e != secondGraph.e)
			return false;

		//checks if the lists of degrees of vertices of both graphs are the same
		if(!isTheSameDegreeList())
		   return false;

        for(int i = 0; i < secondGraph.v; i++)
			std::sort(secondGraph.vtab[i].begin(), secondGraph.vtab[i].end());

		do
		{
            if(checkPermutation())
				return true;
		}while(std::next_permutation(permutationTab,permutationTab+firstGraph.v));

	return false;

	}

};
#endif //GRAPH_H
