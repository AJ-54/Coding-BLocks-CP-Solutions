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
#define ps(y) 				fixed << setprecision(y)
#define all(x) 				begin(x),end(x)
#define allr(x) 			rbegin(x),rend(x)
const int inf= 				0x3f3f3f3f;
const ll INF= 				0x3f3f3f3f3f3f3f3f;
const int dx[4]= 			{ 0, -1, 0, 1 };
const int dy[4]= 			{ -1, 0, 1, 0 };

unsigned  int  randInt (){ 
    static  unsigned  int  tx  =  123456789 ,  ty = 362436069 ,  tz = 521288629 ,  tw = 88675123 ; 
    unsigned  int  tt  =  ( tx ^ ( tx << 11 )); 
    tx  =  ty ;  ty  =  tz ;  tz  =  tw ; 
    return  (  tw = ( tw^ ( tw >> 19 )) ^ ( tt ^ ( tt >> 8 ))  ); 
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename T>
#define o_set(T) tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

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

void solve()
{
    ll n;
    cin>>n;
    vector<pair<ll,pll>> v;
    rep(i,0,n){
        ll l,b,h;
        cin >> l >> b >> h;
        v.PB({l,{max(b,h),min(b,h)}});
        v.PB({b,{max(l,h),min(l,h)}});
        v.PB({h,{max(b,l),min(b,l)}});
    }
    sort(all(v),[](pair<ll,pll> a, pair<ll,pll> b){
        return a.S.F*a.S.S > b.S.F*b.S.S;
    });
    ll dp[3*n + 5];
    ll mxheight =  -1;
    rep(i,0,v.size()){
        dp[i] = v[i].F;
        rep(j,0,i){
            if(v[j].S.F > v[i].S.F and v[j].S.S > v[i].S.S){
                dp[i] = max(dp[i],dp[j]+v[i].F);
            }
        }
        mxheight = max(mxheight, dp[i]);
    }
    cout << mxheight << endl;


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


int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    vector<pair<int,pair<int,int>>> v;
    for(int i = 0; i< n; i++){
        int l,b,h;
        l = A[i][0];
        b = A[i][1];
        h = A[i][2];
        v.push_back({l,{max(b,h),min(b,h)}});
        v.push_back({b,{max(l,h),min(l,h)}});
        v.push_back({h,{max(b,l),min(b,l)}});
    }
    sort(begin(v),end(v),[](pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
        return ((long  long int)a.second.first*(long  long int)a.second.second) >= ((long  long int)b.second.first*(long  long int)b.second.second);
    });
    int dp[3*n + 5];
    int mxheight =  -1;
    for(int i = 0; i< v.size(); i++){
        dp[i] = v[i].first;
        for(int j = 0; j< i; j++){
            if(v[j].second.first > v[i].second.first and v[j].second.second > v[i].second.second){
                dp[i] = max(dp[i],dp[j]+v[i].first);
            }
        }
        mxheight = max(mxheight, dp[i]);
    }
    return mxheight;

}
