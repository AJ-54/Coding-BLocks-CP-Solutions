#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<sstream>
using namespace std;
#define ull unsigned long long  

char hash_tbl[] = {'0','a','b','c','d','e','f','g','h','i','j','k','l',
'm','n','o','p','q','r','s','t','u','v','w','x','y','z'};

vector<string> compute(string str, int pos, vector<string> vec){
    //Base Case
    if (pos==str.length()) return vec;

    //Recursive Case
    for(int j=pos;j<str.length();j++){
        string temp = str.substr(pos,j-pos+1);
        vector<string> nvec = vec;
        if (temp<="26"){
            stringstream obj(temp);
            int tmp;
            obj >> tmp;
            if (nvec.size()==0) nvec.push_back(temp);
            else{
            for (int k=0;k<nvec.size();k++){
                nvec[k]+=hash_tbl[tmp];
                compute(str,j+1,nvec);
            }
            } 
        }
        else {
            compute(str,j,vec);
            break;
        }
    }
}

int main(){
    string str;
    cin >> str;
    vector<string> v;
    vector<string> ans = compute(str,0,v);
    for (auto v:ans) cout << v << ' ';

}

