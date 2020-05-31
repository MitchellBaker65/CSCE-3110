#include <iostream>
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

#define MAX_NODES 20

vector<int> nodeNeighbour[MAX_NODES];
bool isVisited[MAX_NODES];

void backtrack(stack<int>& s)
{
	bool noUnvisitedNeighbor = true;

	while (!s.empty() && noUnvisitedNeighbor)
	{
		int t = s.top();

		noUnvisitedNeighbor = true;

		for (int n: nodeNeighbour[t])
		{
			if (!isVisited[n])
			{
				noUnvisitedNeighbor = false;
				break;
			}
		}

		if (noUnvisitedNeighbor)
		{
			t = s.top();
			s.pop();
			cout << "POP  " << t << endl;
		}
	}
}

void success(stack<int> s, int start, int goal)
{
	cout << "Path from " << goal << " to " << start << ": ";

	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}

	cout << endl;
}

void failure(stack<int> s, int start, int goal)
{
	cout << "No path from " << start << " to " << goal << endl;

	while (!s.empty())
	{
		s.pop();
	}

	cout << endl;
}

int main()
{
	int nodes;
	cout << "Enter number of nodes: ";
	cin  >> nodes;

	int edges;
	cout << "Enter number of edges: ";
	cin  >> edges;

	for (int i = 0; i < nodes; i++)
	{
		isVisited[i + 1] = false;
	}

	for (int i = 0; i < edges; i++)
	{
		int u, v;
		cout << "Enter two neighbors: ";
		cin  >> u >> v;
		nodeNeighbour[u].push_back(v);
		nodeNeighbour[v].push_back(u);
	}

	int start;
	cout << "Enter start node: ";
	cin  >> start;

	int goal;
	cout << "Enter goal node: ";
	cin  >> goal;

	stack<int> s;
	s.push(start);
	isVisited[start] = true;
	cout << "PUSH " << start << endl;

	while (!s.empty()) 
	{
		int t = s.top();

		if (t == goal)
		{
			success(s, start, goal);
			return 0;
		}

		bool unvisitedNeighbor = false;		
		for (int n: nodeNeighbour[t])
		{
			if (!isVisited[n])
			{
				unvisitedNeighbor = true;
				isVisited[n] = true;
				s.push(n);
				cout << "PUSH " << n << endl;
				break;
			}
		}
		
		if (!unvisitedNeighbor)
		{
			backtrack(s);
		}
	}

	failure(s, start, goal);

	return 0;
}
