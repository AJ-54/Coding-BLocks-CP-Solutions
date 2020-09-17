#include<iostream>
#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{

    map<T,list<T>> adjList;

    public:
    // Calling the constructor
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
        map<T,bool> visited; // default is false

        q.push(src);
        visited[src] = true;
        while (!q.empty()){

            T node = q.front();
            cout << node << " ";
            q.pop();

            //for the neighbours of current node, find out the nodes which are not visited
            for (auto neighbour: adjList[node]){
                if (!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }

    }

    void dfsTHelper(T node , map<T,bool> &visited, list<T> &ordering){

        visited[node] = true;

        //we call dfs on all unvisited neighbours of node.
        for(T neighbour:adjList[node]){
                if (!visited[neighbour]){
                    dfsTHelper(neighbour,visited,ordering);
                }
        }

        ordering.push_front(node);
    }

    void dfsTopologicalSort(){
        map<T,bool> visited;
        list<T> ordering;

        //since its a DAG - we need to loop over all nodes to check if they are visited or not
        for (auto i:adjList){
            T node = i.first;
            if (!visited[node]){
                dfsTHelper(node,visited,ordering);
            }
        }

        //Print all elements of ordering
        for (auto element: ordering){
            cout << element << "--->";
        }
    }

    void bfsTopologicalSort(){
        map<T,bool> visited;
        map<T,int> indegree;
        queue<T> q;

        for(auto i:adjList){
            // i is pair of node and its list.
            T node = i.first;
            visited[node] = false;
            indegree[node] = 0;
        }
        
        //init indegrees
        for(auto i:adjList){
            T u = i.first;
            for(T v: adjList[u]){
                indegree[v]++;
            }
        }

        //Find Out all nodes with zero indegree
        for(auto i:adjList){
            if (indegree[i.first] == 0){
                q.push(node);
            }
        }

        //Start Algorithm
        while(!q.empty()){
            T node = q.front();
            q.pop();
            for (T neighbour:adjList[node]){
                indegree[neighbour]--;

                if (indegree[neighbour]==0){
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
        g.addEdge(i,k, false);
    }
    g.dfsTopologicalSort();
}