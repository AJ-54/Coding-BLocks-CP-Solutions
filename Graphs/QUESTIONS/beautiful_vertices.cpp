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
        n = v;
    }

    void addEdge(int u, int v){
        adjList[u].PB(v);
        adjList[v].PB(u);
    }

    void mastry(){
        map<int,bool> visited;
        mii parent;
        map<int,int> psize;
        int ans=0;
        rep(i,1,n+1){
            if(!visited[i]){

                //for each connected component this is the algorithm
                visited[i] = true;
                psize[i] = adjList[i].size();
                parent[i] = i;
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    if (psize[node] > psize[parent[node]]) ans++;
                    for(auto child:adjList[node]){
                        if(!visited[child]){
                            visited[child] = true;
                            psize[child] = adjList[child].size()-1;
                            parent[child] = node;
                            q.push(child);
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }

};

void solve()
{
    ll n,m;
    cin>>n>>m;
    Graph g(n);
    rep(i,0,m){
        int x,y;
        cin >> x>>y;
        g.addEdge(x,y);
    }
    g.mastry();

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