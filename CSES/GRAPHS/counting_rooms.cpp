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
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
using namespace std;

inline void INP()
{
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);   
	    freopen("output.txt","w",stdout);
	#endif 
}
char a[1011][1011];
int n,m;

void flood_fill(int i, int j){
    
    if (i<0 || i >= n || j<0 || j>=m){
        return;
    }

    if (a[i][j] == '#') return;
    a[i][j] = '#';  
    // visited[{i,j}] = 1;
    flood_fill(i+1,j);
    flood_fill(i-1,j);
    flood_fill(i,j-1);
    flood_fill(i,j+1);
    

}

void solve()
{    
    cin>>n>>m; 
    vector<pii> v;
    rep(i,0,n){
        rep(j,0,m){
            cin >> a[i][j];
            if (a[i][j] == '.') v.PB({i,j});
        }
    }
    int ans = 0;
    rep(i,0,v.size()){
            if (a[v[i].F][v[i].S] == '.'){
                // cout << i <<" " <<  j << endl;
                ans++;
                flood_fill(v[i].F,v[i].S);
            }
        }
    cout << ans << endl;
    
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