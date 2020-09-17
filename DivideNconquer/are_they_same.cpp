#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool solve(string s, string d ){
    int sz = s.length();
    int dz = d.length();
  
    //Base Case
    if (sz == 0) return 1;
    if (s == d) return 1;
    if (sz==1){
        if (s==d) return 1;
        return 0;
    }
    // (odd)
    if (sz%2) {    
         return 0;
    }
    //even
    string s0,s1,d0,d1;
    s0= s.substr(0,sz/2);
    s1= s.substr(sz/2+1,sz/2);
    d0= d.substr(0,dz/2);
    d1= d.substr(dz/2+1,dz/2);
    bool fir = solve(s0,d0);
    if (!fir){
        bool fir = solve(s0,d1);
        if (!fir){
            bool fir = solve(s1,d0);
            if (!fir){
                bool fir = solve(s1,d1);
                if (!fir) return 0;
                return 1; 
            }
            else return 1;
        
        }
        else return 1;
    }
    else return 1;
}

int main(){
    int t;
    cin >> t;
    while (t--){
    string a,b;
    cin >> a >> b;
    bool ans = solve(a,b);
    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;
    }
}