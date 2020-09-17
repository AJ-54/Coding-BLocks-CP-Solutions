#include<bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
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

ll n;
ll a[100005];
ll tree[4*100005 + 2][3];
ll lazy[4*100005 + 2];
void process(ll ind, ll l){
    tree[ind][0] = tree[ind][1] = tree[ind][2] = 0;
    ll num = l;
    if (num == 0){
        tree[ind][0]++;
        return;
    }
    while(num%2 == 0){
        tree[ind][1]++;
        num/=2;
    }
    while(num%5 == 0){
        tree[ind][2]++;
        num/=5;
    }
    return;
}
void build(ll ind, ll l ,ll r){
    if (l == r){
        process(ind,a[l]);
        return;
    }

    ll mid = (l+r)/2;
    build(2*ind,l,mid);
    build(2*ind+1,mid+1,r);
    rep(i,0,3){
        tree[ind][i] = tree[2*ind][i] + tree[2*ind+1][i];
    }
}

void update(ll ind, ll l, ll r, ll us, ll ue, ll val){

    //First Step - Never we go down if you have lazy value at node, first resolve it 
    if (lazy[ind] != -1){
        process(ind,lazy[ind]);
        rep(i,0,3){
            tree[ind][i] *= (r-l+1);
        }
        //if not a leaf node, pass on the lazy value
        if ( l!=r ){
            lazy[2*ind] = lazy[2*ind + 1] = lazy[ind];
        }

        // Lazy value resolved.
        lazy[ind] = -1;
    }

    if (r < us || l > ue){
        return;
    }

    if (l >= us and r <= ue){
        process(ind,val);
        rep(i,0,3){
            tree[ind][i] *= (r-l+1);
        }
        if ( l!=r ){
            lazy[2*ind] = lazy[2*ind + 1] = val;
        }
        return;
    }

    ll mid = (l+r)/2;
    update(2*ind,l,mid,us,ue,val);
    update(2*ind+1,mid+1,r,us,ue,val);
    rep(i,0,3){
        tree[ind][i] = tree[2*ind][i] + tree[2*ind+1][i];
    }
}

V(ll) query(ll ind, ll l,ll r, ll qs, ll qe){
    //First Step - Never we go down if you have lazy value at node, first resolve it 
    if (lazy[ind] != -1){
        process(ind,lazy[ind]);
        rep(i,0,3){
            tree[ind][i] *= (r-l+1);
        }
        //if not a leaf node, pass on the lazy value
        if ( l!=r ){
            lazy[2*ind] = lazy[2*ind + 1] = lazy[ind];
        }

        // Lazy value resolved.
        lazy[ind] = -1;
    }

    if (r < qs || l> qe){
        V(ll) v(3,0);
        return v;
    }

    if (l>= qs and r<=qe){
        V(ll) v(3,0);
        rep(i,0,3) v[i] = tree[ind][i];
        return v;
    }

    ll mid = (l+r)/2;
    V(ll) left = query(2*ind, l, mid, qs,qe);
    V(ll) right = query(2*ind+1,mid+1,r,qs,qe);
    V(ll) v(3,0);
    rep(i,0,3) v[i] = left[i] + right[i];
    return v;

}
void solve()
{
	clr(lazy,-1);
	cin >> n;
	rep(i,0,n) cin >> a[i];
    build(1,0,n-1);
    ll q;
    cin >> q;
    rep(i,0,q){
        ll t;
        cin >> t;
        if (t == 0){
            ll l,r,v;
            cin >> l >> r >> v;
            update(1,0,n-1,--l,--r,v);
        }
        else{
            ll l,r;
            cin >> l >> r;
            V(ll) ans = query(1,0,n-1,--l,--r);
            if (ans[0]){
                cout << 1 << endl;
            }
            else{
                cout << min(ans[1],ans[2]) << endl;
            }

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