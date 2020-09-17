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
    map<pii,list<pii>> adjList;

    void addEdge(pii x, pii y){
        adjList[x].PB(y);
        adjList[y].PB(x);
    }

    ll dfshelper(pii node, map<pii,bool> &visited){
        visited[node] = true;
        ll ans = 0;
        if (adjList[node].size()%2==1) ans++;
        for(auto neighbour:adjList[node]){
            if(!visited[neighbour]){
                ans += dfshelper(neighbour,visited);
            }
        }
        return ans;
    }

    void dfs(){
        map<pii,bool> visited;
        // map<pii,ll> indegree;
        // for(auto i:adjList){
        //     for(auto neighbour:adjList[i.F]){
        //         indegree[neighbour]++;
        //     }
        // }
        int ans = 0;
        for(auto i:adjList){
            if(!visited[i.F]){
                ans++;
                ll tans = dfshelper(i.F,visited);
                if (tans>2){
                    else ans += (tans-2);
                } 
            }
        }
        cout << ans-1 << endl;
    }
};

void solve()
{
    int n;
    cin>>n;
    Graph g;
    rep(i,0,n){
        int x,y,a,b;
        cin >> x>>y>>a>>b;
        g.addEdge({x,y},{a,b});
    }
    g.dfs();

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