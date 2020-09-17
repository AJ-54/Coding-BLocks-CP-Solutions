#include<iostream>
#include<bits/stdc++.h>
#include<string>

using namespace std;

vector<string> ans;
void generate_paranthesis(int n, int openB, int closeB, string str){

    // Base case
    if (closeB==n) ans.push_back(str);

    if (openB>closeB) generate_paranthesis(n,openB,closeB+1,str+")");

    if (openB<n) generate_paranthesis(n,openB+1,closeB,str+"(");
    
    
    }
int main(){
    int n;
    cin >> n;
    generate_paranthesis(n,0,0,"");
    sort(ans.begin(),ans.end(),greater<string>());
    for (auto v:ans) cout << v << endl;

}