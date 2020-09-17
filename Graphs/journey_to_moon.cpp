#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *l;

    public:
    Graph(int v){
        V = v;
        l = new list<int>[V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void dfsHelper(int i, bool *visited, int& csize){
        visited[i] = true;
        csize++;
        for(auto neighbour:l[i]){
            if(!visited[neighbour]){
                dfsHelper(neighbour,visited,csize);
            }
        }
    }

    int dfsMoon(){
        int ans = V*(V+1)/2;
        bool *visited = new bool[V];
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                int csize = 0;
                dfsHelper(i,visited,csize);
                ans -= csize*(csize+1)/2;
            }
        }
        return ans;
    }
};

int main(){
    int n,p;
    cin >> n >> p;
    Graph g(n);
    for(int i=0;i<p;i++){
        int u,v;
        cin >> u >> v;
        g.addEdge(u,v);
    }
    cout << g.dfsMoon() << endl;
}