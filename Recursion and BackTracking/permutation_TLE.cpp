#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<string> anw;
void compute(string str, int r, string ans){
    if (r == str.length()){
        if (find(anw.begin(),anw.end(),ans) == anw.end()) anw.push_back(ans);
    }
    else{
        for (int j=r;j<str.length();j++){
            swap(str[r],str[j]);
            compute(str,r+1,ans+str[r]);
            swap(str[j],str[r]);
        }
    }
}


int main(){
    string str;
    cin >> str;
    compute(str,0,"");
    sort(anw.begin(),anw.end());
    for (auto v: anw) cout  << v << endl;
}