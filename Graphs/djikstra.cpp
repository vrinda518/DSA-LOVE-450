// link to the question - https://www.codingninjas.com/codestudio/problems/dijkstra-s-shortest-path_920469?topList=love-babbar-dsa-sheet-problems

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pd; // node, weight
class Graph
{
    int v;
    list<pd> *l;

    public:

    Graph(int vertex)
    {
        v = vertex;
        l = new list<pd>[v];
    }

    void addEdge(int u, pd p)
    {
        l[u].push_back(p);
    }

    vector<int> djikstra(int source)
    {
        vector<int> distance(v, INT_MAX);
        vector<bool> visited(v, false);
        set<pd> s; // first weight, second node

        distance[source] = 0;
        s.insert({0,source});
        while(!s.empty())
        {
            auto it = s.begin();
            int node = it->second;
            int distTillNow = it->first;
            s.erase(it);
            visited[node] = true;
            for (auto nbrPr : l[node])
            {
                int nbr = nbrPr.first;
                int wt = nbrPr.second;

                    if (distTillNow+wt<distance[nbr])
                {
                    auto temp = s.find({distance[nbr],nbr});
                    if (temp!=s.end())
                    {
                        s.erase(temp);
                    }
                    distance[nbr] = distTillNow+wt;
                    s.insert({distance[nbr],nbr});
                }

            }

        }

        return distance;
    }
};

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {

    // Write your code here.
    Graph g(vertices);

    for (auto edge : vec)
    {
        g.addEdge(edge[0],{edge[1],edge[2]});
        g.addEdge(edge[1],{edge[0],edge[2]});
    }

    return g.djikstra(source);

}
