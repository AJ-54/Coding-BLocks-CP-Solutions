#include<bits/stdc++.h>
#define M1 1000000007
#define M2 998244353
#define ll long long
#define pll pair<ll,ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repp(i,b,a) for(ll i=b-1;i>=a;i--)
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define lb lower_bound
#define ub upper_bound
#define V(a) vector<a>
#define endl '\n'
using namespace std;

class Graph{

    public:
    int n;
    list<int> *adjList;

    Graph(int v){
        this->n = v;
        this->adjList = new list<int>[n+1];
    }

    void addEdge(int u, int v){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void shortest_path(int src){
        int distance[n+1];
        queue<int> q;
        for(int i=1;i<=n;i++) distance[i] = -1;
        distance[src] = 0;
        q.push(src);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto neighbour:adjList[node]){
                if(distance[neighbour] == -1){
                    distance[neighbour] = distance[node]+1;
                    q.push(neighbour);
                }
            }
        }
        for(int i=1;i<=n;i++){
            if (i==src) continue;
            cout << ((distance[i] != -1)?6*distance[i]:-1) << " ";
        }
        cout << endl;
    }

};

void solve()
{
    int n,m;
    cin>>n>>m;
    Graph g(n);
    rep(i,0,m) {
        int u,v;
        cin >> u >> v;
        g.addEdge(u,v);
    }
    int s;
    cin >> s;
    g.shortest_path(s);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}