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

ll dp[1001][1001][2];
string s,p;
bool solve(ll i, ll j, bool cont)
{
    if (i==s.size()){
        // cout << i << "-" << j << "-" << cont << endl;
        if (j!=p.size()){
            if (cont && j == p.size()-1) return 1;
            else return 0;
        }
        else{
            return 1;
        }
    }

    if (dp[i][j][cont] != -1){
        return dp[i][j][cont];
    }
    bool p1 = 0,p2=0,p3=0,p4=0;
    if (cont){
        p1 = solve(i+1,j,cont); // I maintain continuity of *
        p4 = solve(i,j+1,0); // I break the continuity of *
    }
    else{
        if ((p[j] == '?') || (s[i]==p[j])){
            p2 = solve(i+1,j+1,0);
        }
        else if (p[j] == '*'){
            p3 = solve(i+1,j,1);
        }
        else{
            return dp[i][j][cont] = 0;
        }
    }
    return dp[i][j][cont] = (p1||(p2||(p3||p4)));
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    test(t){
        clr(dp,-1);
        cin >> s >> p;
        cout << (solve(0,0,0)?"MATCHED":"NOT MATCHED") << endl;
    }
    return 0;
}