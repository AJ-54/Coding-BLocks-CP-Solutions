#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define M1 					1000000007
#define M2 					998244353
#define ll 					long long int
#define pll 				pair<ll,ll>
#define mll 				map<ll,ll>
#define F 					first
#define S 					second
#define PB 					push_back
#define mp 					make_pair
#define lb 					lower_bound
#define ub 					upper_bound
#define V(a) 				vector<a>
#define endl 				'\n'
#define test(t) 			while(t--)
#define PI 					acos(-1.0)
#define rep(i,a,b) 			for(ll i=a;i<b;i++)
#define repp(i,b,a) 		for(ll i=b-1;i>=a;i--)
#define clr(ar, val)		memset(ar, val, sizeof(ar))
#define setbits(x) 			__builtin_popcountll(x)
#define zrobits(x) 			__builtin_ctzll(x)
#define ps(x,y) 			fixed << setprecision(y) << x
#define all(x) 				begin(x),end(x)
#define allr(x) 			rbegin(x),rend(x)
#define pr(a) 				cout<<a<<endl;
#define pr2(a,b) 			cout<<a<<" "<<b<<"\n"
const int inf= 				0x3f3f3f3f;
const ll INF= 				0x3f3f3f3f3f3f3f3f;
const int dx[4]= 			{ 0, -1, 0, 1 };
const int dy[4]= 			{ -1, 0, 1, 0 };

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename T>
#define o_set(T) tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

ll CalculateMex(set<ll> Set){
    ll Mex = 0;
    while(Set.find(Mex)!=Set.end()){
        Mex++;
    }
    return Mex;
}

ll floor_div(ll a, ll b) {
	return a / b - (((a ^ b) < 0) and a % b);
}
ll ceil_div(ll a, ll b){
    return a / b + (((a ^ b) >= 0) and a % b);
}

inline void INP()
{
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);   
	    freopen("output.txt","w",stdout);
	#endif 
}

ll dp[1000003];
void pre(ll n){
    ll ans = 0;
    rep(i,1,n+1){
        ll t  = i;
        mll m;
        bool flag = 0;
        while(t>0){
            if(m[t%10]==1){
                flag = 1;
                break;
            }
            m[t%10]++;
            t/=10;
        }
        if (flag) ans++;
        dp[i] = ans;
    }
}

void solve()
{
    ll l,r;
    cin>>l >> r;
   
    cout << dp[r] - dp[l-1] << endl;

}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    pre(1000000);
    cin>>t;
    test(t){
        solve();
    }
    return 0;
}