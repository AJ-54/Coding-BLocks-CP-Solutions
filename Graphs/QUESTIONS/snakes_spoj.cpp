#include <fstream>
#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    map<T,list<T>> adjList;
    public:
    void addEdge(T u, T v, bool bidir = true){
        adjList[u].push_back(v);
        if (bidir){
            adjList[v].push_back(u);
        }
    }

    void printAdjList(){
        for (auto k:adjList){
            int i = k.first;
            cout << i << "->" ;
            // l[i] is a linked list
            for (int vertex : adjList[i]){
                cout << vertex<< ",";
            }
            cout << endl;
        }
    }

    int bfs(T src, T dest){

        queue<T> q;
        map<int,int> distance;
        for(int i=1;i<=100;i++) distance[i] = -1;
        distance[src] = 0;
        q.push(src);
        while (!q.empty()){
            // pop  the front element and update its distance and add its neighbour
            int node = q.front();
            q.pop();
            for (auto neighbour:adjList[node]){
                if (distance[neighbour] == -1){
                    distance[neighbour] = distance[node] + 1;
                    // cout <<  node << " - " << neighbour << " has distance " << distance[neighbour] << endl;
                    q.push(neighbour);
                }
            }
        }
        return distance[dest];
    }
};


int main(){
    int t;
    while (scanf("%d",&t)!=EOF){
        int m,s,l;
        cin >> m >> s >> l;
        int board[t*m + 1] = {0};
        // Update board for snake
        for (int j = 0; j<s;j++){
            int h,t;
            cin >> h >> t;
            board[h] = t - h;
        }
        //Update board for ladder
        for (int j = 0; j<l;j++){
            int h,t;
            cin >> h >> t;
            board[h] = t-h;
        }   

        //Creating Graph 
        Graph<int> g;    

        //Adding Edges to graph
        for (int i=0;i<t*m;i++){

            // i denotes the possible cells where I can stand and throw a dice. But if there is a jump
            // at i, means it is a transient point.
             if (board[i] != 0) continue;

            // At each node i, there are 6 dice throws possibility.   
            for (int j=1;j<=6;j++){
                int temp = i+j;
                if (temp>t*m) break;
                while(board[temp] != 0){
                    temp = temp + board[temp];
                }
                // cout << temp << endl;
                if (temp<=t*m) g.addEdge(i,temp);
            }
        }
        //Calling out our bfs function to compute the shortest path.
        g.printAdjList();
        cout << g.bfs(0,t*m) << endl;

    }

}