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
        cout<<"adding edge"<<endl;
        l[i].push_back(j);
        l[j].push_back(i);
        cout<<"added"<<endl;
    }

    bool dfs(int source, bool * visited, int p)
    {
        visited[source] = true;
        for (int nbr : l[source])
        {
            if (visited[nbr] && nbr!=p) // cycle present
            {
                return true; // cycle present
            }
            else if (!visited[nbr])
            {
             	if (dfs(nbr,visited,source))
              return true; // cycle present
            }
        }
        return false; // cycle not present
    }
};



string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.

    Graph g(n);

    for (vector<int> v : edges)
    {
        g.addEdge(v[0],v[1]);
    }
    cout<<"are we here"<<endl;
    bool * visited = new bool[n]{0};
    cout<<"are we here"<<endl;
    for (int i = 0; i<n; i++)
    {
        if (!visited[i])
        {
            cout<<"calling dfs"<<endl;
            bool ans = g.dfs(i,visited,-1);
            if (ans)
                {
                  cout<<"Yes";
                  return "Yes";
                }
        }

     }
    cout<<"No";
    return "No";
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

  cout<<cycleDetection(edges,v,n);

  return 0;
}
