#include<bits/stdc++.h>
#define M1 1000000007
#define M2 998244353
#define ll unsigned long long int
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

struct query{
    ll L;
    ll R;
    ll ind;
};

ll a[200005];
ll ans[200005];
query q[200005];
ll blk = 500;
ll cnt[1000002];
ll tans = 0;
bool cmp(query a, query b){
    if (a.L/blk != b.L/blk){
        return a.L/blk < b.L/blk;
    }
    return a.R < b.R;
}

void add(ll ind){
    cnt[a[ind]]++;
    tans += a[ind]*(cnt[a[ind]]*cnt[a[ind]] - (cnt[a[ind]]-1)*(cnt[a[ind]]-1));
}

void remove(ll ind){
    cnt[a[ind]]--;
    tans+= a[ind]*(cnt[a[ind]]*cnt[a[ind]] - (cnt[a[ind]]+1)*(cnt[a[ind]]+1));
}

void solve()
{
    ll n,d;
    cin >> n >> d;
    rep(i,1,n+1) cin>>a[i];
    rep(i,0,d){
        query qt;
        ll l,r;
        cin >> l >> r;
        qt.L = l;
        qt.R = r;
        qt.ind = i;
        q[i] = qt;
    }
    sort(q,q+d,cmp);
    ll lptr = 1,rptr=0;
    rep(j,0,d){

        //Extend Range:
        while(lptr > q[j].L){
            lptr--;
            add(lptr);
        }
        while(rptr < q[j].R){
            rptr++;
            add(rptr);
            // cout << tans << endl;
        }  

        //Shrinking Range:
        while(lptr < q[j].L){
            remove(lptr);
            lptr++;
        }
        while(rptr > q[j].R){
            remove(rptr);
            rptr--;
        }
        ans[q[j].ind] = tans;
    }
    rep(i,0,d) cout << ans[i] << endl;

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