#include<bits/stdc++.h>
#define M1 1000000007
#define M2 998244353
#define ll long long int
#define N (int)1e5+3
#define test(t) while(t--)
#define PI acos(-1.0)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define mii map<int,int>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repp(i,b,a) for(ll i=b-1;i>=a;i--)
#define clr(ar, val) memset(ar, val, sizeof(ar))
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
#define pr(a) cout<<a<<endl;
#define pr2(a,b) cout<<a<<" "<<b<<"\n"
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int dx[4] = { 0, -1, 0, 1 };
const int dy[4] = { -1, 0, 1, 0 };
using namespace std;

ll CalculateMex(set<ll> Set){
    ll Mex = 0;
    while(Set.find(Mex)!=Set.end()){
        Mex++;
    }
    return Mex;
}

inline void INP()
{
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);   
	    freopen("output.txt","w",stdout);
	#endif 
}

map<ll,list<ll>> adjList;
ll table[12][1002];
ll par[1002];
ll depth[1002];

void addEdge(ll u,ll v){
    adjList[u].PB(v);
    adjList[v].PB(u);
}

ll walk(ll node, ll k){
    ll p = 0;
    while(k>0){
        ll t = k&1;
        if (t == 1) node = table[p][node];
        k = k>>1;
        p++;
    }
    return node;
}

void dfs(ll node, ll dep){

    depth[node] = dep;
    for(ll child:adjList[node]){
        if (child != par[node]){
            dfs(child,dep+1);
        }
    }
}

ll lca(ll u, ll v){

    if (depth[u] < depth[v]) swap(u,v);
    if (depth[u] != depth[v]){
        u = walk(u,depth[u]-depth[v]);
    }
    if (u == v){
        return u;
    }

    // u and v are now at same  level
    repp(i,12,0){
        if (table[i][u] != table[i][v]){
            u = table[i][u];
            v = table[i][v];
        }
    }

    return table[0][u];
}

void solve()
{
    adjList.clear();
    clr(table,-1);
    clr(par,-1);
    clr(depth,0);
    ll n,m;
    cin>>n;
    rep(i,0,n){
        cin >> m;
        rep(j,0,m){
            ll c;
            cin >> c;
            par[c] = i+1;
            adjList[i+1].PB(c);
            adjList[c].PB(i+1);
        }
    }
    //Base Case for table - table[0][i] = par[i];
    rep(i,1,n+1){
        table[0][i] = par[i];
    }
    rep(i,1,n+1){
        rep(jump,1,12){
            if (table[jump-1][i] != -1) 
                table[jump][i]=table[jump-1][table[jump-1][i]];
        }
    }

    dfs(1,0);
    // cout << table[11][5] << " " << table[11][7] << endl;
    ll q;
    cin >> q;
    rep(i,0,q){
        ll v,w;
        cin >> v >> w;
        ll ans = lca(v,w);
        cout << ans << endl;
    }

}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    rep(i,1,t+1){
        cout << "Case "<<i<<":"<<endl;
        solve();
    }
    return 0;
}