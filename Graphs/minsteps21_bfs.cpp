#include<iostream>
#include<bits/stdc++.h>
#include<cstring>

template<typename T>
class Graph{

    map<T,list<T>> adjList;
    public:
    // Calling constructor
    Graph(){

    }
    void addEdge(T u, T v, bool bidir = false){
        adjList[u].push_back(v);
        if (bidir){
            adjList[v].push_back(u);
        }
    }
    int bfs(T src, T dest){
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
            q.pop();
            for (auto neighbour : adjList[node]){
                if (distance[neighbour] == INT_MAX){
                parent[neighbour] = node;
                distance[neighbour] = distance[node] + 1;
                q.push(neighbour);
                }
            }
        }
        return distance[dest];
    }

    
};

int main(){
    int t,n;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> n;
        Graph<int>  g;
        while(n>1){
            g.addEdge(n,n-1);
            if (n%2 == 0) g.addEdge(n,n/2);
            if (n%3 == 0) g.addEdge(n,n/3);
        }
        cout << "Case " << i+1 << ": "<< ans  << endl;
    }
}
