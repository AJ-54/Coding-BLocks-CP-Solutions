#include<bits/stdc++.h>
#define M1 1000000007
#define M2 998244353
#define N (int)1e3+5
#define ll long long
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



class Graph{
    public:
    map<int,list<pii>> adjList;
    int v,e;

    Graph(int v, int e){
        this->v = v;
        this->e = e;
    }

    void addEdge(int u, int v, int w){
        adjList[u].push_back(mp(v,w));
        adjList[v].push_back(mp(u,w));
    }

    void dijkstra(int src){
        map<int,int> dist;
        rep(i,1,v+1) dist[i] = INT_MAX;
        set<pii> s;
        dist[src] = 0;
        s.insert(mp(0,src));
        while(!s.empty()){
            auto p = *(s.begin());
            int node = p.S;
            int dis = p.F;
            s.erase(s.begin());
            for(auto neighbour:adjList[node]){
                if (neighbour.S + dis < dist[neighbour.F]){
                    auto f = s.find(mp(dist[neighbour.F],neighbour.F));
                    if (f!=s.end()){
                        s.erase(f);
                    }
                    dist[neighbour.F] = neighbour.S + dis;
                    s.insert(mp(neighbour.S + dis,neighbour.F));
                }
            }
        }
        rep(i,1,v+1){
            if (i==src) continue;
            (dist[i] != INT_MAX)?cout << dist[i] << " ":cout << -1 << " ";
        }
    }
};

inline void INP()
{
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);   
	    freopen("output.txt","w",stdout);
	#endif 
}

void solve()
{
    int n,m;
    cin>>n>>m;
    Graph g(n,m);
    rep(i,0,m){
        int x,y,r;
        cin >> x >> y >> r;
        g.addEdge(x,y,r);
    }
    int s;
    cin >> s;
    g.dijkstra(s);
    
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    test(t){
        solve();
    }
    return 0;
}