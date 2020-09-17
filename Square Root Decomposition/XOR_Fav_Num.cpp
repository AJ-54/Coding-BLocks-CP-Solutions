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
ll block_size = 320;
struct query{
    ll L;
    ll R;
    ll ind;
};

bool cmp(query q1, query q2){
    if (q1.L/block_size != q2.L/block_size){
        return q1.L/block_size < q2.L/block_size;
    }
    return q1.R < q2.R;
}

// The count array - this array maintains count of prefix values we have encountered.
ll cnt[1050000];

void solve()
{
    ll n,m,k;
    cin>>n>>m>>k;
    ll a[n+1],pref[n+1];
    pref[0] = 0;
    rep(i,1,n+1) {
        cin >> a[i];
        pref[i] = pref[i-1]^a[i];
    }

    query q[m];
    rep(i,0,m){
        cin >> q[i].L >> q[i].R;
        q[i].ind = i;
    }
    //sort queries
    sort(q,q+m,cmp);

    // The answer array and global answer variable
    ll ans[m];
    ll tans = 0;
    
    //Have a look at queries
    ll lptr = 1,rptr = 0;
    clr(cnt,0);
    cnt[0] = 1; // Because lptr points to first element and pref[l-1] = 0;
    rep(i,0,m){

        while(lptr > q[i].L){
            // I am adding start index
            lptr--;
            tans += cnt[pref[lptr-1]^k];
            cnt[pref[lptr-1]]++;
            
        }
        while(rptr < q[i].R){
            // I am  adding  a new index which  is the ending point for my current r.
            rptr++;
            tans += cnt[k^pref[rptr]];
            cnt[pref[rptr]]++;
            
            // cout << rptr << " " << pref[rptr] << " " << tans << " " <<q[i].R << endl;
        }
        
        while(rptr > q[i].R){
            // I am removing from end index
            cnt[pref[rptr]]--;
            tans -= cnt[pref[rptr]^k];
            rptr--;
        }
        while(lptr < q[i].L){
            // I am removing from starting index
            cnt[pref[lptr-1]]--;
            tans -= cnt[pref[lptr-1]^k];
            lptr++;
        }

        // cout << "ans" << tans << endl;
        ans[q[i].ind] = tans;
        // rep(i,0,4) cout << cnt[i] << " ";cout << endl;
    }

    rep(i,0,m) cout << ans[i] << endl;

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