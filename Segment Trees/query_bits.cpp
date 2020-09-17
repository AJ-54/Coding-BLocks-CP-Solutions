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
ll n,q;
bitset<200000> tree[800003],lazy[800003]={0};

ll countSetBits(ll n){
    ll cnt = 0;
    while(n){
        n = n&(n-1);
        cnt++;
    }
    return cnt;
}

void buildTree(ll s,ll e,ll index){
    
    if(s==e){
        tree[index].reset();
        return ;
    }
    
    //Rec case
    ll mid = (s+e)/2;
    buildTree(s,mid,2*index);
    buildTree(mid+1,e,2*index+1);
    tree[index].reset();
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

bitset<200000> queryLazy(ll ss,ll se,ll qs,ll qe,ll index){
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
    
    cin>>n>>q;
    rep(i,0,n) v[i] = 0;
    buildTree(0,n-1,1);
    rep(i,0,q){
        ll s;
        cin >> s;
        if (s == 0){
            ll l,r;
            cin >> l >> r;
            
            updateRangeLazy(0,n-1,l,r,0,1);
        }
        else if (s == 1){
            ll l,r;
            cin >> l >> r;

            bitset<200000> ans = updateRangeLazy(0,n-1,l,r,1,1);
        }    
        else{
            ll l,r;
            cin >> l >> r;

            bitset<200000> ans = queryLazy(0,n-1,ms[v].F-1,ms[v].S-1,c,1);
            ll tans = 0;
            for(i,l,r+1){
                tans
            }
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