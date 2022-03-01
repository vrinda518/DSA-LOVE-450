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




vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    // Write your code here.

    Graph g(n);

    for (auto p : edges)
    {
        g.addEdge(p[0],p[1]);
    }

    return g.print();

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

  vector<vector<int>> ans = printAdjacency(v,n,edges);

  for (auto temp : ans)
  {
    cout<<temp[0]<<"------>";
    for (int i = 1; i<temp.size(); i++)
    cout<<temp[i]<<"------>";
    cout<<endl;
  }

  return 0;
}
