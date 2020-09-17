#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<string> anw;
void compute(string str, int r){
    if (r == str.length()){
        anw.push_back(str);
        return;
    }
    
    for (int j=r;j<str.length();j++){

        // Since the given string has duplicates, at every step in loop, we are swaping the jth index with rth index
        //to create a new permutation, we wont swap if both the elemnts are equal. 
        if (j!=r && str[j]==str[r]) continue;
        swap(str[r],str[j]);
        compute(str,r+1);
        swap(str[j],str[r]);
    }

}


int main(){
    string str;
    cin >> str;
    compute(str,0);
    sort(anw.begin(),anw.end());
    auto it = unique(begin(anw), end(anw));
    for (auto it1 = anw.begin(); it1!=it;it1++) cout << *it1 << endl;
    // for (auto v: anw) cout  << v << endl;
}