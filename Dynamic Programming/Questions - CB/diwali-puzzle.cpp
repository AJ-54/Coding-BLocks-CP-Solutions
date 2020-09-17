#include<bits/stdc++.h>
#define M1 1000000007
#define MOD 1000003
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

ll dp[105][105][2];


ll adjBitCount(ll n, ll k, ll first){

    //Base Case for recursive solution
    if (n==0) return 0;
    if (n==1) {
        if (k==0) return 1;
        else return 0;
    }

    // If solution is present in dp;
    if (dp[n][k][first] != -1) return dp[n][k][first];

    //If not then compute it and store it!
    
    ll retval = -1;
    if (first == 1){
        retval = (adjBitCount(n-1,k-1,1)%MOD + adjBitCount(n-1,k,0)%MOD)%MOD;
    }
    else {
        retval = (adjBitCount(n-1,k,1)%MOD + adjBitCount(n-1,k,0)%MOD)%MOD;
    }

    return dp[n][k][first] = retval;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    clr(dp,-1);
    ll x = adjBitCount(n,k,1)%MOD;
    x = (x + adjBitCount (n,k,0)%MOD)%MOD;
    cout <<  x << "\n";

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