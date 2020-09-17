
#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

class Graph{
    unordered_map<int,list<int> > adjList;
public:
    void addEdge(int u,int v,bool bidir=true){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
    }

    int findNumberOfChilds(int src,unordered_map<int,list<int> > &directchild,int *freq){
        if(freq[src]==0){
            return 0;
        }
        int ans =0;
        for(auto node:directchild[src]){
            ans += 1 + findNumberOfChilds(node,directchild,freq);
        }
        return ans;
    }

    int BFS(int src,int n){
        unordered_map<int,list<int> > directchild;
        unordered_map<int,bool> visited;

        int *freq = new int[n+1];
        for(int i=0;i<n+1;i++){
            freq[i] = 0;
        }

        queue<int> q;
        q.push(src);
        visited[src] = true;

        while(!q.empty()){
            int parent=q.front();
            q.pop();
            for(auto child:adjList[parent]){
                if(!visited[child]){
                    q.push(child);
                    freq[parent]++;
                    visited[child] = true;
                    directchild[parent].push_back(child);
                }
            }
        }

        int ans = 0; // maximum edges that i can break
        q.push(src);

        while(!q.empty()){
            int parent = q.front();
            q.pop();

            for(auto child:directchild[parent]){
                q.push(child);
                int a = findNumberOfChilds(child,directchild,freq);
                // ab agar a ki value odd hui toh child ko include krke
                // total nodes ka count even ho jaega
                // thus we will break the edge of parent and child
                if(a%2){
                    ans++;// because ek node tut skti hai ab toh increment
                }
            }

        }

        return ans;

    }
};


int main(){
    Graph g;

    int n,e;
    cin>>n>>e;

    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }

    cout<<g.BFS(1,n)<<endl;

    return 0;
}