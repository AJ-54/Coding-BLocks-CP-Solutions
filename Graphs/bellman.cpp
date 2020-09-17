#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int src,dest,weight;
};

class Graph{

    public:
    int v,e;
    Edge* edge;

    Graph(int v, int e){
        this->v = v;
        this->e = e;
        edge = new Edge[e];
    }

    void addEdge(int u, int v, int w, int count){
        edge[count].src = u;
        edge[count].dest = v;
        edge[count].weight = w;
    }

    void BellmanFord(int src){
        int distance[v];

        for(int i=0;i<v;i++){
            if (i==src) distance[i] = 0;
            else distance[i] = INT_MAX;
        }

        //Relaxation Code
        for(int i=1;i<v;i++){
            for(int j=0;j<e;j++){
                int src = edge[j].src;
                int dest = edge[j].dest;
                int wet = edge[j].weight;

                if (distance[src]!= INT_MAX && distance[src]+wet < distance[dest]){
                    distance[dest] = distance[src]+wet;
                }
            }
        }

        //Check for negative weight cycles
        for(int j=0;j<e;j++){
                int src = edge[j].src;
                int dest = edge[j].dest;
                int wet = edge[j].weight;

                if (distance[src]!= INT_MAX && distance[src]+wet < distance[dest]){
                    cout << "Graph has negative cycle" << endl;
                    return; 
                }
        }

        //Print distance array
        for(int i=0;i<v;i++){
            cout << i << " - " << distance[i] << "\n";
        }

    }
};

int main(){
    int v,e;
    cin >> v >> e;
    Graph g(v,e);
    for(int i=0;i<e;i++){
        int s,d,w;
        cin >> s >> d >> w;
        g.addEdge(s,d,w,i);
    }
    g.BellmanFord(0);
}