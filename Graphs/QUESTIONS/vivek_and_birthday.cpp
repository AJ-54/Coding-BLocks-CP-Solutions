#include<bits/stdc++.h>
#define M1 1000000007
#define M2 998244353
#define N (int)1e3+5
#define ll long long int
#define test(t) while(t--)
#define PI acos(-1.0)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define mii map<int,int>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repp(i,b,a) for(ll i=b-1;i>=a;i--)
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
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
using namespace std;

inline void INP()
{
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);   
	    freopen("output.txt","w",stdout);
	#endif 
}

class Graph{
    public:
    map<int,list<int>> adjList;
    int n;

    Graph(int v){
        this->n = v;
    }

    void addEdge(int u, int v){
        adjList[u].push_back(v);
    }

    int party(){

        int fans = n;
        for(auto p:adjList){
            int node = p.F;
            queue<int> q;
            map<int,bool> visited;
            q.push(node);
            visited[node] = true;
            int ans = 1;
            while(!q.empty()){
                int t = q.front();
                q.pop();
                for(int neighbour:adjList[t]){
                    if(!visited[neighbour]){
                        visited[neighbour] = true;
                        q.push(neighbour);
                        ans++;
                    }
                }
            }
            fans = min(ans,fans);
            }
        
        return fans;
    }
    
};

void solve()
{
    int n,d;
    cin>>n>>d;
    Graph g(n);
    rep(i,0,d){
        int x,y;
        cin>>x>>y;
        g.addEdge(x,y);
    }
    cout << g.party() << endl;
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