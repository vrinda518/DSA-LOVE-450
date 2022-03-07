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
        //l[j].push_back(i);
    }

    void bfs(int s, bool * visited, vector<int> &ans)
    {

        queue<int> q;


        q.push(s);
        visited[s] = true;

        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            ans.push_back(front);

            for (auto nbr : l[front])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                	visited[nbr] = true;
                }
            }
        }

    }
};

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    Graph g(vertex);

    for (auto p : edges)
    {
        g.addEdge(p.first,p.second);
    }

    bool * visited = new bool[vertex];
    vector<int> ans;

    for (int i = 0; i<vertex; i++)
    {
        if (!visited[i])
            g.bfs(i,visited,ans);
    }

    return ans;

}

int main()
{
  int v,n;
  cin>>v>>n;
  vector<pair<int,int>>edges;
  int x,y;
  pair <int,int> p;
  while(n--)
  {
    cin>>x>>y;
    p.first = x;
    p.second = y;
    edges.push_back(p);
  }

  vector<int> ans = BFS(v,edges);

  for (auto ele : ans)
  {
    cout<<ele<<"------->";
  }

  return 0;
}
