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
ll n,l;
vector<pll> v;
ll dp[1002][5002];
ll fun(ll i, ll w){
    if (w == 0){
        return 0;
    }
    if (w<0){
        return -2;
    }
    if (i>=v.size()){
        return 0;
    }
    
    if (dp[i][w] != -1) return dp[i][w];

    // you pick this interval;
    ll a1 = 2 + fun(i+2,w-(v[i].S - v[i].F));
    //you leave this:
    ll a2 = fun(i+1,w);
    return dp[i][w] = max(a1,a2);
}

void solve(ll t)
{
    v.clear();
    clr(dp,-1);
    cin>>n>>l;
    ll a[n];
    rep(i,0,n) cin >> a[i];
    
    rep(i,0,n-1){
        v.PB({a[i],a[i+1]});
    }
    ll ans = fun(0,l);
    
    cout << "Case "<<t<<": "<<ans << endl;

}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    rep(i,1,t+1){
        solve(i);
    }
    return 0;
}