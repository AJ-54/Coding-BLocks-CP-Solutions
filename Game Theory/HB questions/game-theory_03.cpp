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
#define pr(a) cout<<a
#define pr2(a,b) cout<<a<<" "<<b<<"\n"
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int dx[4] = { 0, -1, 0, 1 };
const int dy[4] = { -1, 0, 1, 0 };
using namespace std;

inline void INP()
{
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);   
	    freopen("output.txt","w",stdout);
	#endif 
}

ll CalculateMex(set<ll> Set){
    ll Mex = 0;
    while(Set.find(Mex)!=Set.end()){
        Mex++;
    }
    return Mex;
}
ll dp [1000005];
ll CalculateGrundy(ll n){
    if (n == 1) return dp[n]=0;
    if (dp[n] != -1) return dp[n];
    set<ll> Set;
    for(ll i=2;i*i<=n;i++){
        if (n%i == 0){
            if(i%2){
                Set.insert(CalculateGrundy(i));
            }
            if ((n/i)%2 && n/i != i){
                Set.insert(CalculateGrundy(n/i));
            }
        }
    }
    Set.insert(0);
    return dp[n]=CalculateMex(Set); 
}

void solve()
{
    ll n;
    cin>>n;
    ll a[n];
    ll ans = 0;
    rep(i,0,n){
        cin >> a[i];
        ans = ans^(CalculateGrundy(a[i]));
        // cout << dp[a[i]] << endl;
    }
    if (ans == 0) cout << 2 << endl;
    else cout << 1 << endl;

}

int32_t main(){
    clr(dp,-1);
    ll p;
    rep(i,0,101) p = CalculateGrundy(i);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    test(t){
        solve();
    }
    return 0;
}