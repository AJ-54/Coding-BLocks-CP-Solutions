#include<bits/stdc++.h>
#define inf 1e13
#define ll unsigned long long
#define mp make_pair
#define pii pair<ll,ll>
#define S second
#define F first
#define endl '\n'
using namespace std;

struct compare {
    bool operator() (const pair<ll,int> &lhs, const pair<ll,int> &rhs) const{
        if(lhs.first!=rhs.first)
            return lhs.first>rhs.first;
        else
            return lhs.second>rhs.second;
    }
};

class Graph{
     ll v;
    unordered_map<ll,list<pair<ll,ll>>> adjList;
    public:
    Graph(ll z){
        this->v = z+1;
    }

    void addEdge(ll u,ll v, ll w, bool bidir = true){
        adjList[u].push_back(make_pair(v,w));
        if (bidir){
            adjList[v].push_back(make_pair(u,w));
        }
    }

    void Prims(map<ll,ll> &weights, ll cost){
        bool *visited = new bool[v];
        ll *parent = new ll[v];
        ll *weight = new ll[v];
        set<pair<ll,int>,compare> st;
        
        for(ll i=2;i<v;i++){
            visited[i] = 0;
            weight[i] = 0;
            st.insert({0,i});
        }
        weight[1] = inf;
        parent[1] = -1;
        st.insert({inf,1});
        for(ll i=1;i<v;i++){
            ll minvertex = st.begin()->second;
            st.erase(st.begin());
            visited[minvertex] = 1;

            for(auto neighbour:adjList[minvertex]){
                if (!visited[neighbour.first]){
                    if (weight[neighbour.first] < neighbour.second){
                        st.erase({weight[neighbour.first],neighbour.first});
                        weight[neighbour.first] = neighbour.second;
                        st.insert({neighbour.second,neighbour.first});
                        parent[neighbour.first] = minvertex;
                    }
                }
            }
        }
        
        for(ll i=1;i<v;i++){
            weights[weight[i]]--;
            // cout << i << "--" << parent[i] << " has weight " << weight[i] << endl;
        }
        ll tw=0,ct=0;
        for(auto p:weights){
            bool b = false;
            if (p.second <= 0) continue;
            if (tw + (p.first)*(p.second) <= cost){
                tw += (p.first)*(p.second);
                ct += p.second;
            }
            else{
                tw += (p.first)*((cost-tw)/p.first);
                ct += ((cost-tw)/p.first);
                break;
            }
        }
        cout << ct << " " << tw <<  endl;
    }   
};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,e,c;
    cin >> n >> e >> c;
    Graph g(n);
    map<ll,ll> weights;
    for(ll i=0;i<e;i++){
        ll s,d,w;
        cin >> s >> d >> w;
        // cout << i << endl;
        g.addEdge(s,d,w);
        weights[w]++;
    }
    g.Prims(weights,c);
}