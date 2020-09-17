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

vector<ll> v;
// void prime(ll n){
//     p[1] = 1;
//     for (ll i=2;i<=n;i+=2) p[i] = 2;
//     for(ll i=3;i<=n;i+=2){
//         if (p[i] == 0){
//             for(ll j=i;j<=n;j+=i){
//                 p[j] = i;
//             }
//         }
//     }
// }

void solve()
{
    ll n;
    cin>>n;
    cout << v[n-1] << endl;

}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll p2c=0,p3c=0,p5c=0;
    v.PB(1);
    while(v.size() != 10000){
        ll p2n = v[p2c]*2;
        ll p3n = v[p3c]*3;
        ll p5n = v[p5c]*5;
        ll mn = min(p2n,min(p3n,p5n));
        v.PB(mn);
        if (p2n == mn) p2c++;
        if (p3n == mn) p3c++;
        if (p5n == mn) p5c++;
    }
    // rep(i,0,20){
    //     rep(j,0,20){
    //         v.insert(p2[i]*p3[j]);
    //         v.insert(p2[i]*p5[j]);
    //         v.insert(p5[i]*p3[j]);
    //     }
    // }
    // rep(i,0,20){
    //     rep(j,0,20){
    //         rep(k,0,20){
    //             v.insert(p2[i]*p3[j]*p5[k]);
    //         }
    //     }
    // }
    // clr(v,-1);
    // cout << v.size() << endl;
    // rep(i,0,11) cout << v[i] << " ";
    int t=1;
    cin>>t;
    test(t){
        solve();
    }
    return 0;
}