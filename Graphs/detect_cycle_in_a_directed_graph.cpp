#include<bits/stdc++.h>
using namespace std;

// one test case failing in code studio


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
       // l[j].push_back(i);
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

    bool contains_cycle(int source, vector<bool>& visited, vector<bool>& stack)
    {
       visited[source] = true;
       stack[source] = true;

        for (auto nbr : l[source])
        {
            if (stack[nbr]==true) // node present in call stack
            {
                return true; // cycle present
            }
            else if (!visited[nbr])
            {
                bool ans = contains_cycle(nbr, visited, stack);
                if (ans)
                    return true;
            }
        }
        stack[source] = false;
        return false;
    }
};


bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
	// Write your code here
    Graph g(v);

    for (auto p : edges)
    {
        g.addEdge(p[0], p[1]);
    }

    vector<bool>visited(v,false);
    vector<bool>stack(v,false);
    set<int> s;
    for (int i = 0; i<v; i++)
    {
        if (!visited[i])
        {
            if (g.contains_cycle(i,visited,stack))
                return true; // cycle present
        }
    }
    return false;

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

  bool ans = isCyclic(edges,v,n);

  if (ans)
    cout<<"true"<<endl;
  else
    cout<<"false"<<endl;

  return 0;
}
