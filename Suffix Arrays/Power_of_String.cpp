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

vector<int> suffix_array_cyclic(string s){
    int n = s.size(), N = n + 256;
    vector<int> sa(n), ra(n);
    for(int i = 0; i < n; i++) sa[i] = i, ra[i] = s[i];
    for(int k = 0; k < n; k ? k *= 2 : k++)
    {
        vector<int> nsa(sa), nra(n), cnt(N);
        for(int i = 0; i < n; i++) nsa[i] = (nsa[i] - k + n) % n;
        for(int i = 0; i < n; i++) cnt[ra[i]]++;
        for(int i = 1; i < N; i++) cnt[i] += cnt[i - 1];
        for(int i = n - 1; i >= 0; i--) sa[--cnt[ra[nsa[i]]]] = nsa[i];
 
        int r = 0;
        for(int i = 1; i < n; i++)
        {
            if(ra[sa[i]] != ra[sa[i - 1]]) r++;
            else if(ra[(sa[i] + k) % n] != ra[(sa[i - 1] + k) % n]) r++;
            nra[sa[i]] = r;
        }
        ra = nra;
    }
    return sa;
}
 
vector<int> kasai(string s, vector<int> sa)
{
    int n = s.size(), k = 0;
    vector<int> ra(n), lcp(n);
    for(int i = 0; i < n; i++) ra[sa[i]] = i;
    for(int i = 0; i < n; i++)
    {
        if(k) k--;
        if(ra[i] == n - 1) {k = 0; continue;}
        int j = sa[ra[i] + 1];
        while(k < n && s[(i + k) % n] == s[(j + k) % n]) k++;
        lcp[ra[i]] = k;
        if(ra[(sa[ra[i]] + 1) % n] > ra[(sa[ra[j]] + 1) % n]) k = 0;
    }
    return lcp;
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
	cin >> k  >> n;
    if (k == 1){
        cout << n << endl;
        return;
    }
    string s;
    cin >> s;
    s += '#';
    vector<int> sa = suffix_array_cyclic(s);
    vector<int> lcp = kasai(s,sa);
    lcp.erase(lcp.begin());
    // for(int i: lcp) cout << i << " ";cout << endl;
    deque<pair<int,int>> dq;
    int gmax = INT_MIN;
    rep(i,0,k-1){
        while(!dq.empty() and dq.back().F >= lcp[i]){
            dq.pop_back();
        }
        dq.push_back({lcp[i],i});
    }
    gmax = max(gmax,dq.front().F);
    rep(i,k-1,lcp.size()-1){
        while(!dq.empty() and dq.back().F >= lcp[i]){
            dq.pop_back();
        }
        dq.push_back({lcp[i],i});
        while(dq.front().S <= i-(k-1)) dq.pop_front();
        gmax = max(gmax,dq.front().F);
    }
    cout << gmax << endl;

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