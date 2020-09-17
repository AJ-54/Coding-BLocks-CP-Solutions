#include<iostream>
#include<list>
#include<vector>
#include<unordered_map>
#include<set>
#define inf 1e9
#define ll long long
using namespace std;

// https://ide.codingblocks.com/s/179383?_ga=2.201080046.1553854027.1581743244-947397410.1575384467

struct compare {
    bool operator() (const pair<ll,int> &lhs, const pair<ll,int> &rhs) const{
        if(lhs.first!=rhs.first)
            return lhs.first>rhs.first;
        else
            return lhs.second>rhs.second;
    }
};

class Graph{
    public:
    ll v;
    list<pair<ll,ll>> *adjList;
    Graph(ll z){
        this->v = z+1;
        adjList = new list<pair<ll,ll>>[v];
    }

    void addEdge(ll u,ll v, ll w, bool bidir = true){
        adjList[u].push_back(make_pair(v,w));
        if (bidir){
            adjList[v].push_back(make_pair(u,w));
        }
    }

    void Prims(unordered_map<ll,ll> &weights, ll cost){
        bool *visited = new bool[v];
        ll *parent = new ll[v];
        ll *weight = new ll[v];
        set<pair<ll,int>,compare> st;
        for(ll i=2;i<v;i++){
            visited[i] = 0;
            weight[i] = 0;
            st.insert({0,i});
        }
        st.insert({inf,1});
        weight[1] = inf;
        parent[1] = -1;
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
    ll n,e,c;
    cin >> n >> e >> c;
    Graph g(n);
    unordered_map<ll,ll> weights;
    for(ll i=0;i<e;i++){
        ll s,d,w;
        cin >> s >> d >> w;
        g.addEdge(s,d,w);
        weights[w]++;
    }
    g.Prims(weights,c);
}
