#include<iostream>
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

    int bfs(T src, T dest){

        queue<T> q;
        map<T,int> distance;
        map<T,T> parent;
        for (auto v: adjList) distance[v.first] =-1;

        parent[src] = src;
        distance[src] = 0;
        if (src == dest) distance[src] = 1;

        q.push(src);

        while (!q.empty()){
            // pop  the front element and update its distance and add its neighbour
            int node = q.front();
            q.pop();
            for (auto neighbour:adjList[node]){
                if (distance[neighbour] == -1){
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
   
    while (true){
        int n,m,s,l;
        cin >>n >> m >> s >> l;
        int board[n*m+1] = {0};
        // Update board for ladders    
        for (int j = 0; j<s;j++){
            int h,t;
            cin >> h >> t;
            board[h] = t - h;
        }
        //Update board for snake
        for (int j = 0; j<l;j++){
            int h,t;
            cin >> h >> t;
            board[h] = t - h;
        }
        // If snake at final position, return -1
        
        if (board[n*m] != 0 ){
            cout << -1 << endl;
            continue;
        }    

        //Creating Graph 
        Graph<int> g;    

        //Adding Edges to graph
        for (int i=1;i<n*m;i++){
            // At each node i, there are 6 dice throws possibility.
            for (int j=1;j<=6;j++){
                if (i+j <= n*m){
                    int temp = i + j ;
                    while (board[temp] != 0)
                        temp += board[i+j];
                if (temp<=n*m) g.addEdge(i,temp,false);
                }
            }
        }

        //Calling out our bfs function to compute the shortest path.
        cout << g.bfs(1,n*m) << endl;

    }

}