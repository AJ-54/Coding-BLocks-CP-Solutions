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
#define prime 119
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

ll createHashValue(string  str, ll n){
    ll result = 0;
    rep(i,0,n){
        result += (ll)(str[i]*((ll)(pow(prime,i))));
    }
    return result;
}

ll recalculateHash(string str, int oldindex, int newindex, ll oldhash, int patlength){
    ll newhash = (ll)((oldhash - str[oldindex])/prime + (ll)(str[newindex]*pow(prime,patlength-1)));
    return newhash;
}

bool checkEqual(string str1,string str2, int strt1, int  end1, int strt2, int end2){
    if (end2-strt2 != end1-strt1){
        return false;
    }
    while(strt1<=end1 && strt2<=end2){
        if (str1[strt1] != str2[strt2]){
            return false;
        }
        strt1++;
        strt2++;
    }
    return true;
}

void solve()
{
    string s,pt;
    cin >> s >>pt;
    ll n = s.size();
    ll p = pt.size();
    ll pathash = createHashValue(pt,p);
    ll strhash = createHashValue(s,p);
    ll ct = 0;
    rep(i,0,n-p+1){
        if (pathash == strhash && checkEqual(s,pt,i,i+p-1,0,p-1)){
            ct++;
            cout << i+1 << endl;
        }
        if (i<n-p){
            strhash = recalculateHash(s,i,i+p,strhash,p);
        }
    }
    cout << ct << endl;

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