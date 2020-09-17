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

ll CalculateMex(set<int> Set){
    int Mex = 0;
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
    string s;
    cin >> s;
    ll n = s.size();
    ll pt = 0;
    ll pre[n],suff[n];
    char now = s[0];
    pre[0] = 1;
    ll ans = 0;
    rep(i,0,n){
        if (s[i] == now){
            pt++;
            pre[i] = ans^pt;
        }
        else{
            now = s[i];
            ans ^= pt;
            pre[i] = ans^1;
            pt = 1;
        }
    }
    suff[n-1] = 1;
    ans = 0;
    now = s[n-1];
    pt = 0;
    repp(i,n,0){
        if (s[i] == now){
            pt++;
            suff[i] = ans^pt;
        }
        else{
            now = s[i];
            ans ^= pt;
            suff[i] = ans^1;
            pt = 1;
        }
    }
    rep(i,0,n-1){
        if ((pre[i]^suff[i+1]) == 0){
            // cout << i << " " << pre[i] << " "  << suff[i+1] << " ";
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;

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