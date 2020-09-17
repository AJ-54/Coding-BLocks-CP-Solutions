#include<bits/stdc++.h>
#define M1 1000000007
#define M2 998244353
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
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
using namespace std;

int n,m;
int a[1001][1001];

int dfshelper(int i, int j,int ctr, map<pii,bool> &visited ){

    if (visited[mp(i,j)]) return 0;
    
    visited[mp(i,j)] = true;
    // cout << i << " " << j << " " << ctr << endl;
    a[i][j] = ctr;
    int ans = 1;
    if (i>0 && a[i-1][j] == 1) ans+= dfshelper(i-1,j,ctr,visited);
    if (i<n-1 && a[i+1][j] == 1)ans+= dfshelper(i+1,j,ctr,visited);
    if (j<m-1 && a[i][j+1] == 1)ans+= dfshelper(i,j+1,ctr,visited);
    if (j>0 && a[i][j-1] == 1)ans+= dfshelper(i,j-1,ctr,visited);
    return ans;

}

void solve()
{
    cin>>n>>m;
    V(pii) ones;
    V(pii) zero;
    rep(i,0,n){
        rep(j,0,m){
            cin >> a[i][j];
            if (a[i][j]) ones.PB(mp(i,j));
            else zero.PB(mp(i,j));
        }
    }
    map<pii,bool> visited;
    int ctr = 2;
    map<int,int> mmp;
    rep(i,0,ones.size()){
        if (!visited[mp(ones[i].F,ones[i].S)]){
            int ans = dfshelper(ones[i].F,ones[i].S,ctr,visited);
            mmp[ctr] = ans;
        }
        ctr++;
    }
    int ans = 1;
    rep(i,0,zero.size()){
        int x = zero[i].F;
        int y = zero[i].S;
        int local = 0;
        set<int> s;
        if (x>0 && a[x-1][y] != 0) s.insert(a[x-1][y]);
        if (x<n-1 && a[x+1][y] != 0)s.insert(a[x+1][y]);
        if (y<m-1 && a[x][y+1] != 0)s.insert(a[x][y+1]);
        if (y>0 && a[x][y-1] != 0)s.insert(a[x][y-1]);
        for(auto elem:s){
            local += mmp[elem];
        }
        ans = max(ans,local+1);
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}