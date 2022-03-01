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

    void dfs(int source, bool * visited)
    {
        visited[source] = true;
        for (int nbr : l[source])
        {
            if (!visited[nbr])
            {
                cout<<nbr<<" ";
                dfs(nbr,visited);
            }
        }
    }

    vector< vector<int> > print()
    {
        vector< vector<int> > ans;
        for (int i = 0; i<v; i++)
        {
            vector<int> temp;
            temp.push_back(i);
            for (auto nbr : l[i])
                temp.push_back(nbr);
            ans.push_back(temp);
        }
        return ans;
    }
};



void depthFirstSearch(int V, int E, vector<vector<int>> &graph)
{
    // Write your code here
    Graph g(V);

    	for (vector<int> p : graph)
    	{
        	g.addEdge(p[0],p[1]);
    	}
    vector<vector<int>> a = g.print();
  cout<<"PRINT THE GRAPH: "<<endl;
  for (auto temp : a)
  {
    cout<<temp[0]<<"------>";
    for (int i = 1; i<temp.size(); i++)
    cout<<temp[i]<<"------>";
    cout<<endl;
  }
    bool * visited = new bool[V]{0};
  cout<<"DFS TRAVERSAL: "<<endl;
    for (int i = 0; i<V; i++)
    {
        if (!visited[i])
        {
            cout<<i<<"----->";
            g.dfs(i,visited);
            cout<<endl;
        }
    }

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

  depthFirstSearch(v,n,edges);

  return 0;
}
