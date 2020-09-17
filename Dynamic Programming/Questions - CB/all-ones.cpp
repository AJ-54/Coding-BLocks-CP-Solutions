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

void solve()
{
    ll n,m;
    cin>>n>>m;
    ll a[n][m];
    rep(i,0,n){
        rep(j,0,m){
            cin >> a[i][j];
        }
    }
    ll s[n][m];
    ll mx = -1;
    rep(i,0,n) s[i][0] = a[i][0];
    rep(j,0,m) s[0][j] = a[0][j];
    rep(i,1,n){
        rep(j,1,m){
            if (a[i][j]==0){
                s[i][j] = 0;
                continue;
            }
            else{
                s[i][j] = 1+ min(s[i-1][j],
                min(s[i][j-1],s[i-1][j-1]));
                mx = max(mx,s[i][j]); 
            }
        }
    }
    cout << mx << endl;

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