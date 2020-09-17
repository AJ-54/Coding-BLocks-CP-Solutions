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
const int dx[4] = { 0, -1, 0, 1 };
const int dy[4] = { -1, 0, 1, 0 };
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

char a[1005][1005];
int n,m;
pii st,ed;
string an;
class Graph{
    public:
    map<pii,list<pii>> adjList;

    void addEdge(pii x, pii y){
        adjList[x].PB(y);
        // adjList[y].PB(x);
    }

    void bfs(pii src, pii dest){
        map<pii,bool> visited;
        map<pii,int> distance;
        map<pii,pii> parent;
        queue<pii> q;
        for(auto i:adjList){
            distance[i.F] = inf;
        }
        distance[src] = 0;
        parent[src] = src;
        visited[src] = 1;
        q.push(src);
        bool isp = false;
        while(!q.empty()){
            pii p = q.front();
            int x = p.F, y=p.S;
            q.pop();
            for(ll d = 0; d < 4; ++d){
                int yy = y + dy[d], xx = x + dx[d];
                if( yy >= 0 && yy < m && xx >= 0 && xx < n && a[xx][yy] == '.' ){
                    pii neighbour = {xx,yy};
                
                if(!visited[neighbour]){
                    visited[neighbour] = true;
                    distance[neighbour] = distance[p] + 1;
                    parent[neighbour] = p;
                    if (neighbour == dest){
                        isp = true;
                        break;
                    }
                    else q.push(neighbour);
                }
                }  
            }
            if (isp) break;
        }
        if (distance[dest] == inf){
            cout << "NO" << endl;
            return;
        }
        cout << "YES" << endl;
        string ans;
        // cout << dest.F +1<< " " << dest.S+1 << endl; 
        while(parent[dest] != dest){
            pii pdest = parent[dest];
            // cout << pdest.F+1 << " " << pdest.S+1 << endl; 
            if (pdest.F == dest.F){
                if (pdest.S < dest.S) ans = 'R' + ans;
                else ans = 'L' + ans;
            }
            else{
                if (pdest.F > dest.F) ans = 'U' + ans;
                else ans = 'D' + ans;   
            }
            // cout << ans << endl;
            dest = pdest;
        }
        cout << ans.size() << endl;
        cout << ans << endl;
    }
};

void flood_fill(int i, int j,string ans, map<pii,bool> &visited){
    if (i<0 || j < 0 || i>=n || j>=m){
        return;
    }
    if (ed == mp(i,j)){
        if (an.size() == 0) an = ans;
        else{
            if (ans.size()<an.size()){
                an = ans;
            }
        }
        return;
    }

    visited[{i,j}] = 1;
    if (i>0 && a[i-1][j] == '.'){
        if (!visited[{i-1,j}]){
            flood_fill(i-1,j,ans+'U',visited);
        }
    }
    if (j>0 && a[i][j-1] == '.'){
        
        if (!visited[{i,j-1}]){
            flood_fill(i,j-1,ans+'L',visited);
        }
    }
    if (i<n-1 && a[i+1][j] == '.'){
        if (!visited[{i+1,j}]){
            flood_fill(i+1,j,ans+'D',visited);
        }
    }
    if (j<m-1 && a[i][j+1] == '.'){
        
        if (!visited[{i,j+1}]){ 
            flood_fill(i,j+1,ans+'R',visited);
        }
    }
    visited[{i,j}] = 0;

}
void solve()
{
    cin>>n>>m;
    Graph g;
    
    rep(i,0,n) {
        rep(j,0,m){
            cin >> a[i][j];
            if (a[i][j] == 'A'){
                a[i][j] = '.';
                st.F = i;st.S=j;
            }
            else if (a[i][j] == 'B'){
                a[i][j] = '.';
                ed.F=i;ed.S=j;
            }
        }
    }
    // map<pii,bool> visited;
    // flood_fill(st.F,st.S,"",visited);
    // if (an.size() == 0){
    //     cout << "NO" << endl;
    //     return;
    // }
    // else{
    //     cout << "YES" << endl;
    //     cout  << an.size() << endl;
    //     cout << an << endl;
    // }
    // for(auto i:g.adjList){
    //     cout << i.F.F << " " << i.F.S << "->";
    //     for(auto j:g.adjList[i.F]){
    //         cout << j.F << " " << j.S << ",";
    //     }
    //     cout << endl;
    // }
    g.bfs(st,ed);
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