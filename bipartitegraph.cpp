#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
    int V;
    list<int> *adj;
    Graph(int V);
    void addEdge(int v, int w);
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}
class Bipartite
{
private:
    bool isBipartite;
    bool *color;
    bool *marked;
public:
    Bipartite(Graph G)
    {
        isBipartite = true;
        color = new bool [G.V];
        marked = new bool [G.V];
        for (int v = 0; v < G.V; v++)
        {
            if (!marked[v])
            {
                color[v] = false;
                dfs(G, v);
            }
        }
    }
    /*
     * DFS
     */
    void dfs(Graph G, int v)
    {
        marked[v] = true;
        list<int>::iterator w;
        for (w = G.adj[v].begin(); w != G.adj[v].end(); w++)
        {
            if (!marked[*w])
            {
                color[*w] = !color[v];
                dfs(G, *w);
            }
            else if (color[*w] == color[v])
            {
                isBipartite = false;

            }
        }
    }

    bool isBi()
    {
        return isBipartite;
    }
};
int main()
{   int t;
    cin>>t;
    int cnt=0;
    while(t--) {
        cnt++;
        int n,m;
        cin>>n>>m;
        Graph g1(n);
        while(m--){
            int u,v;
            cin>>u>>v;
        g1.addEdge(u-1, v-1);
        g1.addEdge(v-1, u-1);
            }
        Bipartite b(g1);
        if (b.isBi())
        {
            cout<<"Scenario #"<<cnt<<":"<<endl;
            cout<<"No suspicious bugs found!"<<endl;
        }

        else
        {
            cout << "Scenario #" << cnt << ":"<<endl;
            cout<<"Suspicious bugs found!"<<endl;
        }

    }
    return 0;
    }
