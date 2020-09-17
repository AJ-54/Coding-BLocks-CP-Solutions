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

int dp[10002][10002];
int lcs_DP(string a, string b){
    
    int alen = a.length();
    int blen = b.length();

    //Base Case
    for (int i=0;i<=alen;i++) dp[i][0] = 0; // considering string a at column,filling the empty index.
    for (int j=0;j<=blen;j++) dp[0][j] = 0; // considering string b at row, filling empty indexes.

    //dp[i][j] will store length of largest increasing subseq upto index i in a and j in b.
    for(int i=1;i<=blen;i++){
        for(int j=1;j<=alen;j++){
            if(a[j-1]==b[i-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else {
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    // rep(k,0,alen+1){
    //     rep(l,0,blen+1){
    //         cout << dp[k][l] << " ";
    //     }
    //     cout << endl;
    // }
    
    return dp[blen][alen];
}

void solve()
{
    string a;
    string b;
    cin >> a >> b;
    ll index = lcs_DP(a,b);
    ll i=a.length(),j=b.length();
    
    string ans;
    while(i>0 && j>0){
        if (a[i-1] == b[j-1]){
            ans = a[i-1] + ans;
            i--;j--;index--;
        }
        else if (dp[j][i-1] > dp[j-1][i])
         i--;
        else
            j--;
    }
    cout << ans << endl;
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