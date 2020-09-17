#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

string minwindow(string s1, string s2){
    int l1 = s1.size();
    int l2 = s2.size();
    int hash_str[256] = {0};    
    int hash_ptr[256] = {0};

    if (l2>l1) return "No string";
    for (int j=0;j<l2;j++) hash_ptr[s2[j]]++;

    int start_shrink = 0,min_index=-1,min_length = INT_MAX,count=0;
    for (int j =0;j<l1;j++){
        hash_str[s1[j]]++;
        if (hash_ptr[s1[j]] > 0 && hash_str[s1[j]]<=hash_ptr[s1[j]]){
            count ++;
        }

        if (count == l2){
            while(hash_str[s1[start_shrink]]>hash_ptr[s1[start_shrink]]){       
                hash_str[s1[start_shrink]]--;
                start_shrink++;
            }
            int window_length = j - start_shrink + 1;
            if (min_length>window_length){
                min_length = window_length;
                min_index = start_shrink;
            }
        }
    }
    if (min_index == -1)  return "No string";
    return s1.substr(min_index,min_length);
}

int main(){
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    cout << minwindow(s1,s2) << endl;
}