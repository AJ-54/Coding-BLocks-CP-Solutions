#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    
    map<T,list<T>> adjList;

    public:
    Graph(){

    }

    void addEdge(T u, T v, bool bidir = true){
        adjList[u].push_back(v);
        if (bidir){
            adjList[v].push_back(u);
        }
    }

    bool iscyclicBFS(T src){
        map<T,bool> visited;
        map<T,T> parent;
        queue<T> q;

        q.push(src);
        parent[src] = src;

        while(!q.empty()){
            T node = q.front();
            q.pop();
            for(T neighbour:adjList[node]){
                if (visited[neighbour] == true && parent[node] != neighbour){
                    return true;
                }
                else if (!visited[neighbour]){
                    visited[neighbour] = true;
                    parent[neighbour] = node;
                    q.push(neighbour);
                }
            }
        }
        return false;
    }

    bool iscyclicHelper(T node, map<T,bool> &visited, T parent){
        visited[node] = true;
        for (T neighbour : adjList[node]){
            if (!visited[neighbour]){
                bool cycleDetected = iscyclicHelper(neighbour,visited,node);
                if (cycleDetected){
                    return true;
                }
            }
            else if (neighbour != parent){
                return true;
            }
        }
        return false;
    }

    bool iscyclicDFS(T src){
        map<T,bool> visited;
        map<T,T> parent;

        for(auto i:adjList){
            T node = i.first;
            if (!visited[node]){
                bool ans = iscyclicHelper(node,visited,node);
                if (ans==true){
                    return true;
                }
            }
        }
        return false;

    }
};

int main(){
    Graph<int> g;
    int n,src;
    cin >> n;
    for(int i=0;i<n;i++){
        
        int x,y;
        cin >> x >> y;
        if (i==0) src = x;
        g.addEdge(x,y);
    }
    cout << g.iscyclicDFS(src) << endl;
}
