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
    ll n,k;
    cin>>n>>k;
    ll a[n];
    rep(i,0,n) cin >> a[i];
    ll strt = 0;
    ll end = -1;
    ll ans = 0;
    ll use = 0;
    ll sans,eans;
    rep(i,0,n){
        if (a[i] == 1){
            end  = i;
            if (ans<end-strt+1){
                ans = end-strt+1;
                sans = strt;
                eans = end;
            }
        }
        else{
            if (use != k){
                use ++;
                end = i;
                if (ans<end-strt+1){
                    ans = end-strt+1;
                    sans = strt;
                    eans = end;
                }
            }
            else{
                while(a[strt] != 0 && strt<=i){
                    strt++;
                }
                if (a[strt] == 0){
                    strt++;
                    if (ans<end-strt+1){
                        ans = end-strt+1;
                        sans = strt;
                        eans = end;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    rep(i,0,n){
        if (i >= sans && i <= eans){
            cout << 1 << " ";
        }
        else cout << a[i] << " ";
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