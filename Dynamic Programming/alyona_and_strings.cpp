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
int n,m,k;
string s,t;
int dp[1005][1005][12][2];
int solve(int ids, int idt, int rs, bool iscont)
{
    if (ids == n || idt == m){
        return (rs==0?0:INT_MIN);
    }
    if (rs < 0) return INT_MIN;
    if (dp[ids][idt][rs][iscont] != -1) return dp[ids][idt][rs][iscont];
 
    if (iscont == 1){
        dp[ids][idt][rs][iscont] = max(dp[ids][idt][rs][iscont],solve(ids+1,idt,rs,0));
        dp[ids][idt][rs][iscont] = max(dp[ids][idt][rs][iscont],solve(ids,idt+1,rs,0));
        if (s[ids] == t[idt]){
            dp[ids][idt][rs][iscont]=max(dp[ids][idt][rs][iscont],1+solve(ids+1,idt+1,rs,1));
            dp[ids][idt][rs][iscont]=max(dp[ids][idt][rs][iscont],1+solve(ids+1,idt+1,rs-1,1));
        }
    }
    else{
        dp[ids][idt][rs][iscont] = max(dp[ids][idt][rs][iscont],solve(ids,idt+1,rs,0));
        // cout << "hi bitch" << endl;
        dp[ids][idt][rs][iscont] = max(dp[ids][idt][rs][iscont],solve(ids+1,idt,rs,0));
        if (s[ids] == t[idt]){
            dp[ids][idt][rs][iscont] = max(dp[ids][idt][rs][iscont],1+solve(ids+1,idt+1,rs-1,1));
        }
    }
    // cout << dp[ids][idt][rs][iscont] << " " << ids << "-" << idt << "-" << iscont << "-" << rs<< endl;
    return dp[ids][idt][rs][iscont];

}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int w=1;
    // cin>>t;
    test(w){
        cin >> n >> m >> k;
        cin >> s >> t;
        clr(dp,-1);
        cout << solve(0,0,k,0) << endl;
    }
    return 0;
}