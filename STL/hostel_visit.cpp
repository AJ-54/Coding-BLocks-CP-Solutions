#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;


int main() {	
	long long n,j,k,typ,count=0;
	cin >> n >> k;
    vector <long long> vec;
    vec.reserve(n);
    for(j=0;j<n;j++){    
        cin >> typ;
        if (typ == 1){
            long long x,y;
            cin >> x >> y;
            if (count == 0) { 
                vec.push_back(x*x+y*y);
                count++;
                } 
            else {
            auto v = lower_bound(vec.begin(),vec.end(),x*x+y*y);
            // cout << vec[v-vec.begin()] <<" " << endl;
            // if (vec[v-vec.begin()]!=x*x+y*y)
                vec.insert(v,x*x+y*y);
            
            }
        }
        else if (typ == 2){
            // for (auto v:vec) cout << v << ' ';
            cout <<endl<< vec[k-1] << endl;
        }
    }
}