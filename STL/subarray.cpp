#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;

int main() {	
	unsigned long long int m,ans=0;
    cin >> m;
    vector<unsigned long long int> vec;

    for (unsigned long long int j=0;j<m;j++){
        unsigned long long int temp;
        cin >> temp;
        vec.push_back(temp);     
    }

    for (unsigned long long int j=0;j<m;j++){
        unordered_set<int> st;
        st.insert(vec[j]);
        int k=j+1;
        while (k<m && (st.find(vec[k]) == st.end())){
           
            st.insert(vec[k]);
            k++;
        }
        ans+=st.size()*(st.size()+1)/2;
        }
    // for (auto v:arr) cout << v<< ' ';
    // cout << endl;
    cout << (ans)%1000000007 << endl;
}