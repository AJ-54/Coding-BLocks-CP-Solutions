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
string s;
ll n;
ll ans[400005]={};
ll suffcount[400005][3]={};
ll prefcount[400005][3]={};
ll tot[400005]={};
void build(ll ind, ll l, ll r){
    if (l==r){
        ll v = s[l] - '0';
        if (v%3 == 0){
            ans[ind] = 1;
            prefcount[ind][0] = 1;
            suffcount[ind][0] = 1;
        }
        else if (v%3 == 1){
            suffcount[ind][1] = 1;
            prefcount[ind][1] = 1;
        }
        else{
            suffcount[ind][2] = 1;
            prefcount[ind][2] = 1;
        }
        tot[ind] = v%3;
        return;
    }
    ll mid = (l+r)/2;
    build(2*ind,l,mid);
    build(2*ind+1,mid+1,r);
    ans[ind] = ans[2*ind] + ans[2*ind+1];
    rep(i,0,3){
            ans[ind] += suffcount[2*ind][i]*prefcount[2*ind+1][(3-i)%3];
    }
    rep(i,0,3){
            prefcount[ind][i] = prefcount[2*ind][i] + prefcount[2*ind+1][(3 - tot[2*ind] + i)%3];
            suffcount[ind][i] = suffcount[2*ind+1][i] + suffcount[2*ind][(3-tot[2*ind+1] + i)%3];
    }
    tot[ind] = (tot[2*ind] + tot[2*ind+1])%3;
}

void update(ll ind, ll l, ll r, ll val, ll tar){
    if (tar < l || tar > r){
        return;
    }
    if (l == r){
        ll q = val;
        if (q == 0){
            ans[ind] = 1;
        }
        else ans[ind] = 0;
        rep(i,0,3){
            if(i == q){
                prefcount[ind][i] = 1;
                suffcount[ind][i] = 1;
            }
            else{
                prefcount[ind][i] = 0;
                suffcount[ind][i] = 0;
            }
        }
        tot[ind] = q;
        return;
    }
    ll mid = (l+r)/2;
    update(2*ind,l,mid,val,tar);
    update(2*ind+1,mid+1,r,val,tar);
    ans[ind] = ans[2*ind] + ans[2*ind+1];
    rep(i,0,3){
            ans[ind] += suffcount[2*ind][i]*prefcount[2*ind+1][(3-i)%3];
    }
    rep(i,0,3){
            prefcount[ind][i] = prefcount[2*ind][i] + prefcount[2*ind+1][(3 - tot[2*ind] + i)%3];
            suffcount[ind][i] = suffcount[2*ind+1][i] + suffcount[2*ind][(3-tot[2*ind+1] + i)%3];
    }
    tot[ind] = (tot[2*ind] + tot[2*ind+1])%3;
}
struct node{
  ll ans;
  int pre[3];
  int suff[3];
  int total;
  void init()
  {
    ans =0;
    total = 0;
    fo(i,3)
    pre[i]=0,suff[i]=0;
  }
}
node query(ll ind, ll l, ll r, ll qs, ll qe){
    if (qe < l || qs> r){
        node temp;
        temp.init();
        return temp;
    }
    if (qs <= l && qe >= r){
        node temp;
        rep(i,0,3){
            p.PB(prefcount[ind][i]);
            q.PB(suffcount[ind][i]);
        }
        return mp(mp(ans[ind],tot[ind]),mp(p,q));
    }
    ll mid = (l+r)/2;
    pair<pll,pair<V(ll),V(ll)>> left = query(2*ind,l,mid,qs,qe);
    pair<pll,pair<V(ll),V(ll)>> right = query(2*ind+1,mid+1,r,qs,qe);
    ll a,t;
    V(ll) p,s;
    a = left.F.F + right.F.F;
    rep(i,0,3){
            a += (left.S.S)[i]*(right.S.F)[(3-i)%3];
    }
    rep(i,0,3){
            p.PB((left.S.F)[i] + (right.S.F)[(3 - tot[2*ind] + i)%3]);
            s.PB((right.S.S)[i] + (left.S.S)[(3-tot[2*ind+1] + i)%3]);
    }
    t = (left.F.S + right.F.S)%3;
    return mp(mp(a,t),mp(p,s));
}

void solve()
{
    ll m;
    cin >> n >> m;
    cin  >> s;
    build(1,0,n-1);
    rep(i,0,m){
        ll t,x,y;
        cin >> t >> x >> y;
        if (t == 1){
            update(1,0,n-1,y%3,--x);
        }
        else{
            pair<pll,pair<V(ll),V(ll)>> final = query(1,0,n-1,--x,--y);
            cout << final.F.F << endl;
        }
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