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

    void print(){
        // Iterate the map
        for (auto obj:adjList){
            cout << obj.first << "->";
            for (auto i:obj.second){ // We can use T in place of auto as well!  
                cout << i << ",";
            }
            cout << endl;
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
    void dfsHelper(T node,map<T,bool> &visited){
        // By reference we are passing the visited map

        //whenever you come to node, mark it visited
        visited[node] = true;
        cout << node << " ";
        // Try to find out neighbour of current node not yet visited
        for (auto neighbour:adjList[node]){
            if (!visited[neighbour]){
                dfsHelper(neighbour, visited);
            }
        }
    } 

    void dfs(T src){
        //We will initiate the DFS call.
        // This is a wrapper function. 
        map<T,bool> visited;
        //By default the values of the bool are false

        dfsHelper(src, visited);
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
    // Printing the adjacency List.
    g.print();
    //Printing the DFS traversal.
    g.dfs(src);
}

// Entries are sorted on the basis of keys because maps store entries in sorted order!