#include<iostream>
#include<bits/stdc++.h>
#define ll long long

using namespace std;

template<typename T>
class Graph{

    map<T,list<T>> adjList;
    public:
    // Calling constructor
    Graph(){

    }
    void addEdge(T u, T v, bool bidir = true){
        adjList[u].push_back(v);
        if (bidir){
            adjList[v].push_back(u);
        }
    }
    void bfs(T src){
        queue<T> q;
        map<T,int> distance;
        map<T,T> parent;
        for (auto v:adjList){
            distance[v.first] = INT_MAX;
        }
        q.push(src);
        distance[src] = 0;
        parent[src] = src;
        while (!q.empty()){
            // First Pop the node in front from queue. Then push all neighbours of node in queue.
            T node = q.front();
            cout << "Distance of Node " << node << " from " << src << " is "<<distance[node] << endl;
            q.pop();
            for (auto neighbour : adjList[node]){
                if (distance[neighbour] == INT_MAX){
                parent[neighbour] = node;
                distance[neighbour] = distance[node] + 1;
                q.push(neighbour);
                }
            }
        }
    }

    
};

int main(){
    Graph<string> g;
    string src;
    int n;
    cin >> n;
    for (int j=0;j<n;j++){   
        string i,k;
        cin >> i >> k;
        if (!j) src= i;
        g.addEdge(i,k);
    }
    g.bfs(src);
}