#include<iostream>
#include<list>
using  namespace std;

class Graph{

    int V;
    list<int> *l;

public:
    Graph(int v){
        V = v;
        //Array of linked list
        l = new list<int>[V];
    }

    void addEdge(int u, int v, bool bidir=true){
        l[u].push_back(v);
        if (bidir){
            l[v].push_back(u);
        }
    }

    void printAdjList(){
        for (int i=0;i<V;i++){
            cout << i << "->" ;
            // l[i] is a linked list
            for (int vertex : l[i]){
                cout << vertex<< ",";
            }
            cout << endl;
        }
    }
};

int main(){

    int n;
    cin >> n;
    Graph g(n);
    for (int j=0;j<n;j++){
        int source,dest;
        cin >> source >> dest;
        g.addEdge(source,dest);
    }
    g.printAdjList();
}