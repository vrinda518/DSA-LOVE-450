// link to the question - https://www.codingninjas.com/codestudio/problems/topological-sort_982938?topList=love-babbar-dsa-sheet-problems

#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pd;
class Graph{
    int v;
    list<int> * l;
    vector<int> inDeg;

    public:

    Graph(int vertex)
    {
        v = vertex;
        l = new list<int>[v];
        vector<int> temp(v, 0);
        inDeg = temp;
    }

    void addEdge(int i, int j)
    {
        l[i].push_back(j);
        inDeg[j]++;
    }

    vector<int> topo()
    {

        queue<int> q;

        for (int i = 0; i<v; i++)
        {
            if (inDeg[i]==0)
                q.push(i);
        }
         vector<int> ans;

        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            ans.push_back(front);

            for (auto nbr : l[front])
            {
                inDeg[nbr]--;
                if (inDeg[nbr]==0)
                    q.push(nbr);
            }

        }

        return ans;
    }
};



vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    Graph g(v);

    for (auto edge : edges)
    {
        g.addEdge(edge[0],edge[1]);
    }

    return g.topo();

}
