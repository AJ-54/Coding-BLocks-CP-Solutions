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

struct comp{
    bool operator() (const pair<int,string> &lhs, const pair<int,string> &rhs) const{
        // cout << lhs.F << " " << rhs.F << endl;
        return lhs.F > rhs.F;
    }
};

class Graph{
    public:
    map<string,list<string>> adjList;

    void addEdge(string u, string v){
        adjList[u].push_back(v);
    }

    void topological(map<string,int> &m,int t){
        map<string,bool> visited;
        map<string,int> indegree;
    
        priority_queue<pair<int,string>,vector<pair<int,string>>,comp> q;
        for(auto i:m){
            indegree[i.F] = 0;
            visited[i.F] = false;
        }
        for(auto i:adjList){
            for(auto j:adjList[i.F]){
                indegree[j]++;
            }
        }
        for(auto i:m){
            if (indegree[i.F] == 0){
                q.push({m[i.F],i.F});
            }
        }
        vector<string> v;
        while(!q.empty()){
            auto node = q.top();
            v.PB(node.S);
            q.pop();
            for(string neighbour:adjList[node.S]){
                indegree[neighbour]--;

                if (indegree[neighbour] == 0){
                    q.push({m[neighbour],neighbour});
                }
            }
        }
        cout << "Case #" << t << ": Vivek should drink beverages in this order: ";
        rep(i,0,v.size()) cout << v[i] << " ";
    }

};

void solve()
{
    int n;
    int t=1;
    cin >> n;
    while(1){
        map<string,int> m;
        // cout << n << endl;
        rep(i,0,n){
            string a;
            cin >> a;
            m[a] = i;
        }
        int e;
        cin >>e;
        Graph g;
        // cout << "hi " << endl;
        rep(i,0,e){
            string a,b;
            cin >> a >> b;
            g.addEdge(a,b);
        }
        g.topological(m,t);
        cout << endl;
        t++;
        if(scanf("%d",&n) == EOF) break;
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