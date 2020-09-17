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
ll tree[800004],lazy[800004]={0};
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
int state[200005]={0};

void buildTree(ll s,ll e,ll index){
    
    if(s==e){
        tree[index] = state[v[s]];
        return ;
    }
    
    //Rec case
    ll mid = (s+e)/2;
    buildTree(s,mid,2*index);
    buildTree(mid+1,e,2*index+1);
    tree[index] = tree[2*index]+tree[2*index+1];
    
    return;
}

void updateRangeLazy(ll ss,ll se,ll l,ll r,ll inc,ll index){
    //First Step - Never we go down if you have lazy value at node, first resolve it 
    
    if(lazy[index]!=0){
        
        tree[index] = abs(lazy[index]*(se-ss+1) - tree[index]);
        
        //if not a leaf node 
        if(ss!=se){
            lazy[2*index] += lazy[index];
            lazy[2*index] %= 2;
            lazy[2*index+1] += lazy[index];
            lazy[2*index+1] %= 2;
        }
        lazy[index] = 0;
    }
    
    // Out of Bounds 
    if(ss>r || l > se){
        return;
    }
    // Complete Overlap- Beeche Raste Mei hi Return krna 
    if(ss>=l && se<=r){
        tree[index] = (se-ss+1) - tree[index];

        // Pass the lazy value to children 
        if(ss!=se){
            lazy[2*index] +=  inc;
            lazy[2*index] %= 2;
            lazy[2*index+1] += inc;
            lazy[2*index+1] %= 2;
        }
    return;
    }
    
    //Call on Left and Right 
    ll mid = (ss+se)/2;
    updateRangeLazy(ss,mid,l,r,inc,2*index);
    updateRangeLazy(mid+1,se,l,r,inc,2*index+1);
    tree[index] = tree[2*index]+tree[2*index+1];
    
    return;
    
}

ll queryLazy(ll ss,ll se,ll qs,ll qe,ll index){
    // First step - resolve the Lazy value
    if(lazy[index]!=0){
        tree[index] = abs(lazy[index]*(se-ss+1) - tree[index]);
        if(ss!=se){
            lazy[2*index] += lazy[index];
            lazy[2*index] %= 2;
            lazy[2*index+1] += lazy[index];
            lazy[2*index+1] %= 2;
        }
        lazy[index] = 0;
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
    ll left = queryLazy(ss,mid,qs,qe,2*index);
    ll right = queryLazy(mid+1,se,qs,qe,2*index+1);
    
    return left+right;
    
    
}

void solve()
{
    ll n;
    cin>>n;
    Graph g;
    rep(i,2,n+1){
        ll x;
        cin >> x;
        g.addEdge(x,i);
    }
    // for(auto i:g.adjList){
    //     cout << i.F << "->";
    //     for(ll child:g.adjList[i.F]){
    //         cout << child << " ";
    //     }
    //     cout << endl;
    // }
    rep(i,1,n+1) cin >> state[i];
    g.ETT();
    buildTree(0,n-1,1);
    ll q;
    cin >> q;
    rep(i,0,q){
        string s;
        cin >> s;
        ll t;
        cin >> t;
        if (s[0] == 'g'){
            ll ans = queryLazy(0,n-1,ms[t].F-1,ms[t].S-1,1);
            cout << ans << endl;
        }
        else{
            updateRangeLazy(0,n-1,ms[t].F-1,ms[t].S-1,1,1);
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