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

ll w[200003];
int depth[200003];
vector<pair<ll,ll>> adjList[200003];
ll table[20][200003];
ll nodesum[200003];
void dfs(ll node, ll parent, ll deep, ll rans){
    table[0][node] = parent;
    depth[node] = deep;
    nodesum[node] = rans;
    ll ans = 0; 
    for(pair<ll,ll> child:adjList[node]){
        if (child.F!=parent){
            // psum[0][child.F] = child.S;
            dfs(child.F,node,deep+1,rans+child.S);
            ans = max(ans,w[child.F]+child.S);
        }
    }
    w[node] = ans;
}

void solve()
{
    rep(i,0,200003) nodesum[i]=0,w[i]=0,depth[i]=0,adjList[i].clear();
    clr(table,-1);
    // clr(nodesum,0);
    ll n,q;
    cin>>n>>q;

    rep(i,0,n-1){
        ll u,v,wi;
        cin >> u >> v >> wi;
        adjList[u].PB({v,wi});
        adjList[v].PB({u,wi});
    }
    dfs(1,-1,0,0);
    rep(i,2,n+1){
        rep(j,1,20){
            if (table[j-1][i] != -1)
            table[j][i] = table[j-1][table[j-1][i]];
            // psum[j][i] = (table[j][i] == 0?0:psum[j-1][i]+psum[j-1][table[j-1][i]]);           
        }
    }

    rep(j,0,q){
        ll u,v,x;
        cin >> u >> v >> x;
        ll ou = u, ov = v;
        ll lcasum = 0;       
        if (depth[u] < depth[v]) swap(u,v);
        if (depth[u] != depth[v]){
            ll k = depth[u]-depth[v];
            ll p = 0;
            while(k>0){
                ll t = k&1;
                if (t == 1) {
                    // lcasum += psum[p][u];
                    u = table[p][u];
                }
                k = k>>1;
                p++;
            }
        }
        // cout << "hi " << u << " " << v << endl;
            // cout << "hi " << psum[0][u] << " " << psum[0][v] << endl;
            // cout << lcasum << "!!" << endl;
        if (u!=v){
            // u and v are now at same  level
            repp(i,20,0){
                if (table[i][u] != table[i][v]){
                    // lcasum += psum[i][u];
                    // lcasum += psum[i][v];
                    u = table[i][u];
                    v = table[i][v];
                }
            }
            u = table[0][u];
            // lcasum += (psum[0][u] + psum[0][v]);        
        }
        lcasum = nodesum[ou] + nodesum[ov] - 2*nodesum[u];
        ll dist = max(lcasum,w[ou]+w[ov]+x);
        cout << dist << endl;      
    }
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