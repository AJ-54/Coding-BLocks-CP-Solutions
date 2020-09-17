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

ll bit[1000];
void update(ll ind, ll val, ll n){
    while(ind<=n){
        bit[ind] = max(bit[ind],val);
        ind += ind&(-ind);
    }
}

ll query(ll ind){
    ll ans = INT_MIN;
    // equality cant come as -0 is not defined.
    while(ind>0){
        ans = max(ans,bit[ind]);
        ind -= ind&(-ind);
    }
    return ans;
}

void solve()
{
    ll n;
    cin>>n;
    ll a[n];
    clr(bit,0);
    rep(i,0,n) {
        cin >> a[i];
        update(i+1,a[i],n);
    }
    // rep(i,0,n+1) cout << bit[i]<<" ";cout<<endl;
    ll q;
    cin >> q;
    rep(i,0,q){
        ll j;
        cin >> j;
        cout << query(j) << endl;
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