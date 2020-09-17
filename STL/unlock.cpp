#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;


int main() {	
	long long int n,k,inp;
    vector <int> vec;
    cin >> n >> k;
    vec.reserve(n);
    for (long long int j=0;j<n;j++){
        cin>>inp;
        vec.push_back(inp);
    }
    for(auto itr=vec.begin();itr!=vec.end();itr++){
        if (k==0) break;
        long long int curr = *itr,nmax;
        nmax = curr;
        auto its = vec.begin();
        for (auto it2=itr+1;it2!=vec.end();it2++){
            // cout << *it2 << ' ';
            if (*it2>nmax) {
                nmax=*it2;
                its = it2;
            }
        }
        // cout  << endl;
        if (nmax != curr){
        *its = *itr;
        *itr = nmax;
        // for (auto v:vec) cout << v << ' ';
        // cout << endl;
        k--;
        }
    }
    for (auto v:vec) cout << v << ' ';
}