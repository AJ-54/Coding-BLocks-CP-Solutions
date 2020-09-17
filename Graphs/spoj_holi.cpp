#include <iostream>
#include <list>
using namespace std;


//Weighted Grapph
class Graph{
    
    int V;
    list<pair<int,int> > *l;
    
public:

    Graph(int v){
        V  = v;
        l = new list<pair<int,int> >[V];
    }
    
    void addEdge(int u,int v,int cost,bool bidir=true){
        l[u].push_back(make_pair(v,cost));
        if(bidir){
            l[v].push_back(make_pair(u,cost));
        }
    }
    //Return size of the subtre
    int dfsHelper(int node,bool *visited,int *count,int &ans){
        
        visited[node] = true;
        count[node] = 1;
        
        //You to recursively find out the size of its children/neighbours
        for(auto neighbour: l[node]){
            int v = neighbour.first;
            
            if(!visited[v]){
                count[node] += dfsHelper(v,visited,count,ans);
                //Cost -> Count
                int s = count[v];
                int N = V;
                int edgeCost = neighbour.second;
                ans += 2*min(s,N-s)*edgeCost;
                
            }
            
        }
        return count[node];
    }
    
    
    int dfs(){
        bool *visited = new bool[V]{0};
        int *count = new int[V]{0};
        
        int ans = 0;
        dfsHelper(0,visited,count,ans);
       
       /* for(int i=0;i<V;i++){
            cout<<count[i]<<" ";
        }*/
        return ans;
        
    }
    
    
    
    
};


int main() {
    
    Graph g(4);
    g.addEdge(0,1,3);
    g.addEdge(1,2,2);
    g.addEdge(3,2,2);
    //g.addEdge(2,4,2);
    
    cout<<g.dfs();
    
    
}
