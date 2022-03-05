#include<bits/stdc++.h>
using namespace std;

// can be used to detect cycles in an undirected graph
// link to the question - https://www.codingninjas.com/codestudio/problems/minimum-spanning-tree_631769?topList=love-babbar-dsa-sheet-problems

struct cmp{
    bool operator()(const vector<int> &v1, const vector<int> &v2)
    {
        return v1[2]<v2[2];
    }
};

int findParent(int node, vector<int> &parent)
{
    if (node==parent[node])
        return node;
    else
        return parent[node] = findParent(parent[node], parent); // path compression
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  /*
    Don't write main().
    Don't read input, it is passed as function argument.
    No need to print anything.
    Taking input and printing output is handled automatically.
  */

    sort(edges.begin(), edges.end(), cmp());
//     for (auto edge : edges)
//     {
//         cout<<edge[2]<<endl;
//     }
    vector<int> parent(n,0);
    vector<int> rank(n,0);

    for (int i = 0; i<n; i++)
    {
        parent[i] = i;
    }
    int wt = 0;
    for (auto v : edges)
    {
        int p1 = findParent(v[0],parent);
        int p2 = findParent(v[1],parent);
        if (p1!=p2)
        {
            wt += v[2];
            if (rank[p1]<rank[p2])
            {
                parent[p1] = p2;
            }
            else if (rank[p1]>rank[p2])
            {
                parent[p2] = p1;
            }
            else
            {
                parent[p1] = p2;
                rank[p2]++;
            }
        }
    }

    return wt;
}

int main()
{
  int v,n;
  cin>>v>>n;
  vector<vector<int>>edges;
  int x,y,w;
  vector<int> temp(3);
  while(n--)
  {
    cin>>x>>y>>w;
    temp[0] = x;
    temp[1] = y;
    temp[2] = w;
    edges.push_back(temp);
  }

  cout<<minimumSpanningTree(edges,v);

  return 0;
}
