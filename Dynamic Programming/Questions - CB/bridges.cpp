#include<bits/stdc++.h>
#define M1 1000000007
#define M2 998244353
#define ll long long
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
// const ll INF = 0x3f3f3f3f3f3f3f3f;
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
void lis(pll a[], ll n){
    ll dp[n];
    ll ans = -1;
    rep(i,0,n) dp[i] = 1;
    rep(i,0,n){
        rep(j,0,i){
            if (a[j].S <= a[i].S && dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
            }
        }
        ans = max(ans,dp[i]);
    }   
    cout << ans << endl;
}
void solve()
{
    ll n;
    cin>>n;
    ll a1[n],a2[n];
    rep(i,0,n) cin >> a1[i];
    rep(i,0,n) cin >> a2[i];
    pll a[n];
    rep(i,0,n) a[i] = {a1[i],a2[i]};
    sort(a,a+n);
    // rep(i,0,n) cout << a[i].F << " " << a[i].S << endl;
    lis(a,n);

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