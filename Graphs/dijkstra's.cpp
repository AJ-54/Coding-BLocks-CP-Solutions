#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{

    unordered_map<T,list<pair<T,int>>> m;
    public:

    void addEdge(T u, T v,int dist, bidir=true){
        m[u].push_back(make_pair(v,dist));
        if (bidir){
            m[v].push_back(make_pair(u,dist));
        }
    }

    void dijkstraSSSP(T src){
        unordered_map<T,int> dist;

        //Set all dist to inf.
        for(auto j:m){
            dist[j.first]= INT_MAX;
        }


        //Make a SET to find out node with min. distance.
        set<pair<int,T>> s;
        dist[src] = 0;
        s.insert(make_pair(0,src));

        while(!s.empty()){
            //Find pair at front;
            auto p = *(s.begin());
            T node = p.second;
            int dis = p.first;
            s.erase(s.begin());

            //Iterate over neighbours of current node
            for(auto childPair:adjList[node]){
                if (dis + childPair.second < dist[childPair.first]){
                    //In set update is not possible
                    // remove old pair and insert new pair
                    auto f = s.find( make_pair(dist[childPair.first], childPair.first) );
                    if (f!=s.end()){
                        s.erase(f);
                    }
                    //Insert New Pair!
                    dist[childPair.first] = dis + childPair.second;
                    s.insert(make_pair(dist[childPair.first],childPair.first));
                }
            }
        }

        //Distances of all other nodes from source
        for(auto d:dist){
            cout << d.first << "-> " << d.second << "\n";
        }
    }

    
};