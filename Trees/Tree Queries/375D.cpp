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
map<ll,pll> ms;
vector<ll> v;
class Graph{
    public:
    map<ll,list<ll>> adjList;

    void addEdge(ll u, ll v){
        adjList[u].PB(v);
        adjList[v].PB(u);
    }

    void dfsHelper(ll node, ll &ind, ll parent){
        ind++;
        pll myp = {ind,0};
        v.PB(node);
        for(ll child:adjList[node]){
            if (child == parent) continue;
            dfsHelper(child,ind,node);
        }
        
        myp.S = ind;
        ms[node] = myp;
    }

    void ETT(){
        v.PB(1);
        ll parent = 1;
        ll index = 1;
        for(ll node:adjList[1]){
            dfsHelper(node,index,parent);
        }
        ms[1] = {1,index};
        // for(auto node:details){
        //     cout << node.F << " has start " << node.S.F << " and end " << node.S.S << endl;
        // }
    }
};

ll color[100005]={0};
ll blk = 320;
struct query{
    ll L;
    ll R;
    ll cr;
    ll ind;
};

bool cmp(query a, query b){
    if (a.L/blk != b.L/blk){
        return a.L/blk < b.L/blk;
    }
    return a.R < b.R;
}

query q[100005];
ll ans[100005];
map<ll,ll> color_freq;


ll tans = 0;
void add(ll ptr, ll k){
    color_freq[color[v[ptr]]]--;
}
void solve(){
    ll n,m;
    cin>>n>>m;
    rep(i,1,n+1) cin >> color[i];
    Graph g;
    rep(i,1,n){
        ll x,y;
        cin >> x >> y;
        g.addEdge(x,y);
    }
    // for(auto i:g.adjList){
    //     cout << i.F << "->";
    //     for(ll child:g.adjList[i.F]){
    //         cout << child << " ";
    //     }
    //     cout << endl;
    // }

    //The tree is now flattened.
    g.ETT();
    rep(i,0,m){
        ll v,k;
        cin >> v >> k;
        q[i].L = ms[v].F;
        q[i].R = ms[v].S;
        q[i].cr = k; 
        q[i].ind = i;
    }
    sort(q,q+m,cmp);
    ll lptr = 0,rptr = -1;
    rep(i,0,m){
        ll L = q[i].L-1;
        ll R = q[i].R-1;
        ll k = q[i].cr;
        ll ind = q[i].ind;

        while(rptr < R){
            rptr++;
            add(rptr,k);
        }
        while(lptr > L){
            lptr--;
            add(lptr,k);
        }
        while(rptr > R){
            del(rptr,k);
            rptr--;
        }
        while(lptr < L){
            del(lptr,k);
            lptr--;
        }
    }

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