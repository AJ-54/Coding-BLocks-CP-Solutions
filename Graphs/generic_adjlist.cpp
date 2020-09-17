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
};

int main(){
    Graph<string> g;
    int n;
    cin >> n;
    for (int j=0;j<n;j++){
        string i,k;
        cin >> i >> k;
        g.addEdge(i,k);
    }
    g.print();
}

// Entries are sorted on the basis of keys because maps store entries in sorted order!