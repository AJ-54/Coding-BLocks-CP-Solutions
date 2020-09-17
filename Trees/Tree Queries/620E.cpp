#include<bits/stdc++.h>
#define M1 1000000007
#define M2 998244353
#define ll unsigned long long int
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
map<ll,bitset<64>> color;
bitset<64> tree[1600004],lazy[1600004]={0};

ll countSetBits(ll n){
    ll cnt = 0;
    while(n){
        n = n&(n-1);
        cnt++;
    }
    return cnt;
}
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
// Denotes the state of bulb - ON/OFF;

void buildTree(ll s,ll e,ll index){
    
    if(s==e){
        tree[index] = color[v[s]];
        return ;
    }
    
    //Rec case
    ll mid = (s+e)/2;
    buildTree(s,mid,2*index);
    buildTree(mid+1,e,2*index+1);
    tree[index] = tree[2*index]|tree[2*index+1];
    
    return;
}

void updateRangeLazy(ll ss,ll se,ll l,ll r,ll clr,ll index){
    //First Step - Never we go down if you have lazy value at node, first resolve it 
    
    if(lazy[index].count()){
        
        tree[index] = lazy[index];
        
        //if not a leaf node 
        if(ss!=se){
            lazy[2*index] = lazy[index];
            lazy[2*index+1] = lazy[index];
        }
        lazy[index].reset();
    }
    
    // Out of Bounds 
    if(ss>r || l > se){
        return;
    }
    // Complete Overlap- Beeche Raste Mei hi Return krna 
    if(ss>=l && se<=r){
        tree[index].reset();
        tree[index][clr - 1] = 1;

        // Pass the lazy value to children 
        if(ss!=se){
            lazy[2*index].reset();
            lazy[2*index][clr - 1] = 1;
            lazy[2*index+1].reset();
            lazy[2*index+1][clr - 1] = 1;
        }
    return;
    }
    
    //Call on Left and Right 
    ll mid = (ss+se)/2;
    updateRangeLazy(ss,mid,l,r,clr,2*index);
    updateRangeLazy(mid+1,se,l,r,clr,2*index+1);
    tree[index] = tree[2*index]|tree[2*index+1];
    
    return;
    
}

bitset<64> queryLazy(ll ss,ll se,ll qs,ll qe,ll index){
    // First step - resolve the Lazy value
    if(lazy[index].count()){
        tree[index] = lazy[index];
        
        //if not a leaf node 
        if(ss!=se){
            lazy[2*index] = lazy[index];
            lazy[2*index+1] = lazy[index];
        }
        lazy[index].reset();
    }
    
    
    //No Overlap 
    if(ss>qe || se<qs){
        return 0;
    }
    
    // Complete Overlap 
    if(ss>=qs && se<=qe){
        
        return tree[index];
    }
    
    
    //Partial 
    ll mid = (ss+se)/2;
    bitset<64> left = queryLazy(ss,mid,qs,qe,2*index);
    bitset<64> right = queryLazy(mid+1,se,qs,qe,2*index+1);
    
    return left|right;
    
    
}

void solve()
{
    ll n,q;
    cin>>n>>q;
    Graph g;
    rep(i,1,n+1) {
        ll x;
        cin >> x;
        color[i][x-1] = 1;
    }
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
    
    g.ETT();
    buildTree(0,n-1,1);
    rep(i,0,q){
        ll s;
        cin >> s;
        if (s == 2){
            ll v;
            cin >> v;
            
            bitset<64> ans = queryLazy(0,n-1,ms[v].F-1,ms[v].S-1,1);
            cout << ans.count() << endl;
        }
        else{
            ll v,c;
            cin >> v >> c;
            // cout << ms[6].F-1 << " "<<ms[v].S-1 << endl;
            updateRangeLazy(0,n-1,ms[v].F-1,ms[v].S-1,c,1);
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