#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int v;
    list<int> * l;
    public :
    Graph(int vertex)
    {
        v = vertex;
        l = new list<int>[v];
    }

    void addEdge(int i, int j)
    {
        l[i].push_back(j);
        l[j].push_back(i);
    }

    bool dfs(int source, bool * visited, int p)
    {
        visited[source] = true;
        for (int nbr : l[source])
        {
            if (visited[nbr] && nbr!=p) // cycle present
            {
                return false; // not a tree
            }
            else if (!visited[nbr])
            {
             	if (!dfs(nbr,visited,source))
              return false;
            }
        }
        return true;
    }
};



bool isGraphTree(int n, vector<vector<int>> &edgeList)
{
	// Write your code here

    Graph g(n);

    	for (vector<int> p : edgeList)
    	{
        	g.addEdge(p[0],p[1]);
    	}

    	int components = 0;
    	bool * visited = new bool[n]{0};

    for (int i = 0; i<n; i++)
    {
        if (!visited[i])
        {
            if (!g.dfs(i,visited,i) || components>0) // if not a tree or more than 1 Component
            	return false; // not a tree
            components++;
        }
    }
    return true;
}

int main()
{
  int v,n;
  cin>>v>>n;
  vector<vector<int>>edges;
  int x,y;
  vector<int> temp(2);
  while(n--)
  {
    cin>>x>>y;
    temp[0] = x;
    temp[1] = y;
    edges.push_back(temp);
  }

  if(isGraphTree(v,edges))
  cout<<"1"; // graph is a tree
  else
  cout<<"0"; // graph not a tree

  return 0;
}
