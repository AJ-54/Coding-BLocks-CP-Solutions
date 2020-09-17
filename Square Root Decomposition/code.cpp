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

// Square Root Decomp. = Range Sum

ll query(ll* blocks, ll* arr, ll L, ll R, ll rn){

    ll ans = 0;

    //Left Part
    while (L<R && L!=0 && L%rn != 0){
        ans += arr[L];
        L++;
    }

    //Middle Part
    while(L + rn <= R){
        ll block_id = L/rn;
        ans += blocks[block_id];
        L += rn;
    }

    //Right Part
    while(L<=R){
        ans += arr[L];
        L++;
    }

    return ans;
}

void update(ll* blocks,ll* arr, ll ind, ll val, ll rn){
    ll block_id = i/rn;
    blocks[block_id] += (val - arr[i]);
    arr[i] = val;
}

void solve()
{
    ll n;
    cin>>n;
    ll a[n];
    rep(i,0,n) cin >> a[i];
    ll rn = sqrt(n);

    // Build a Blocks Array
    ll* blocks = new ll[rn+1]{0};
    ll block_id = -1;
    rep(i,0,n){
        if (i%rn == 0){
            block_id++;
        }
        blocks[block_id] += a[i];
    }

    //Query
    ll q;
    cin >> q;
    rep(i,0,q){
        ll l,r;
        cin >> l >> r;
        cout << query(blocks,a,l,r,rn) << endl;
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