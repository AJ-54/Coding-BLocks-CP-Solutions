#include<bits/stdc++.h>
#define inf 1e9
#define endl '\n'
using namespace std;


class Graph{
    public:
    int v;
    list<pair<int,int>> *adjList;
    Graph(int z){
        this->v = z+1;
        adjList = new list<pair<int,int>>[v];
    }

    void addEdge(int u,int v, int w, bool bidir = true){
        adjList[u].push_back(make_pair(v,w));
        if (bidir){
            adjList[v].push_back(make_pair(u,w));
        }
    }

    int findMinVertex(int* weight, bool* visited, int v){
        int minvertex = -1;    
        for(int i=0;i<v;i++){
            if (!visited[i] && (minvertex == -1 || weight[i] < weight[minvertex])){
                minvertex = i;
            }
        }
        return minvertex;   
    }

    

    void Prims(){
        bool *visited = new bool[v];
        int *parent = new int[v];
        int *weight = new int[v];
        for(int i=0;i<v;i++){
            visited[i] = 0;
            weight[i] = inf;
        }
        weight[1] = 0;
        parent[1] = -1;
        for(int i=1;i<v;i++){
            int minvertex = findMinVertex(weight, visited, v);
            visited[minvertex] = 1;
            for(auto neighbour:adjList[minvertex]){
                if (!visited[neighbour.first]){
                    if (weight[neighbour.first] > neighbour.second){
                        weight[neighbour.first] = neighbour.second;
                        parent[neighbour.first] = minvertex;    
                    }
                }
            }
        }
        int tw = 0;
        for(int i=1;i<v;i++){
            tw += weight[i];
            cout << i << "--" << parent[i] << " has weight " << weight[i] << endl;
        }
        cout << tw << endl;
    }   
};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,e;
    cin >> n >> e;
    Graph g(n);
    for(int i=0;i<e;i++){
        int s,d,w;
        cin >> s >> d >> w;
        g.addEdge(s,d,w);
    }
    g.Prims();
}