#include<bits/stdc++.h>
#define M1 1000000007
#define M2 998244353
#define ll long long int
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
const ll INF = 1e16;
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

int weights[400000];
int table[20][400000];
ll wsum[20][400000];
void solve()
{   
    weights[0] = INT_MAX;
    weights[1] = 0;
    clr(table,0);
    // clr(wsum,0);
    // clr(par,-1);
    ll ind = 1;
    ll la = 0;
    ll Q;
    cin >> Q;
    for(int i=0;i<20;i++)wsum[i][1]=INF;
    while(Q--){
        ll t;
        cin>> t;
        if (t == 1){
            ind++;
            ll anc,w;
            cin >> anc>>w;
            anc = anc^la;
            w = w^la;
            weights[ind] = w;  
            if (weights[anc]>=w){
                table[0][ind] = anc;
            } 
            else{
                repp(i,20,0){
                    if (weights[table[i][anc]] < w){
                        anc = table[i][anc];
                    }
                }
                table[0][ind] = table[0][anc];
            }   
            wsum[0][ind] = (table[0][ind]==0?INF:weights[table[0][ind]]);
            
            rep(i,1,20){  
                table[i][ind] = table[i-1][table[i-1][ind]];
                wsum[i][ind] = (table[i][ind]==0?INF:(wsum[i-1][ind] + wsum[i-1][table[i-1][ind]]));     
            }
            
        }
        else{
            ll strt,w;
            cin >> strt>>w;
            strt = strt^la;
            w = w^la;
            if (w < weights[strt]){
                cout << 0 << endl;
                la = 0;
                // continue;
            }
            // if (par[strt] == -1){
            //     if (w >= weights[strt]){
            //         cout << 1 << endl;
            //         la = 1;
            //     }
            //     else{
            //         cout << 0 << endl;
            //         la = 0;
            //     }
            // }
            else{
                //Binary Search for sol.
                int ans = 1;
                w -= weights[strt];
                ll end = strt;
                repp(i,20,0){
                        if (wsum[i][end]<=w){
                            ans += (1<<i);
                            end = table[i][end];
                            w -= wsum[i][end];
                        }
                }
                // cout << end << "!" << endl;
                // while(end != strt){
                //     strt = par[strt];
                //     ans++;
                // }
                la = ans;
                cout << ans << endl;
            }
        }
    }
    // for(auto i:adjList){
    //     cout << i.F << "->";
    //     for(ll j: i.S){
    //         cout << j << " ";
    //     }
    //     cout << endl;

    // }
    

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