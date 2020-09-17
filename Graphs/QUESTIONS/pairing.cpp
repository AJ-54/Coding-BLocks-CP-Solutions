#include<bits/stdc++.h>
#define M1 1000000007
#define M2 998244353
#define N (int)1e3+5
#define ll long long int
#define test(t) while(t--)
#define PI acos(-1.0)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define mii map<int,int>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repp(i,b,a) for(ll i=b-1;i>=a;i--)
#define F first
#define S second
#define PB push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define V(a) vector<a>
#define M(a,b) map<a,b>
#define endl '\n'
#define all(x) begin(x),end(x)
#define allr(x) rbegin(x),rend(x)
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
using namespace std;

inline void INP()
{
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);   
	    freopen("output.txt","w",stdout);
	#endif 
}

class Graph{
    public:
    map<int,list<int>> adjList;
    int n;

    Graph(int v){
        this->n = v;
    }
    void addEdge(int u, int v){
        adjList[u].PB(v);
        adjList[v].push_back(u);
    }

    int dfshelper(int src, map<int,bool> &visited){
        int count = 1;
        visited[src] = true;
        for(int neighbour:adjList[src]){
            if(!visited[neighbour]){
                count += dfshelper(neighbour,visited);
            }
        }
        return count;
    }

    ll dfs(){
        map<int,bool> visited;
        ll ans = (n*(n-1))/2;
        for(auto node:adjList){
            if(!visited[node.F]){
                ll ct = dfshelper(node.F,visited);
                ans -= (ct*(ct-1))/2;
            }
        }
        return ans;
    }
};

void solve()
{
    int n,m;
    cin>>n>>m;
    Graph g(n);
    rep(i,0,m){
        int x,y;
        cin >> x >> y;
        g.addEdge(x,y);
    }
    cout << g.dfs() << endl;

}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    test(t){
        solve();
    }
    return 0;
}