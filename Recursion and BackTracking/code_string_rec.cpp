#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<sstream>
#define ull unsigned long long 

using namespace std;
 
vector<string> vec;
char hash_tbl[] = {'0','a','b','c','d','e','f','g','h','i','j','k','l',
'm','n','o','p','q','r','s','t','u','v','w','x','y','z'};

void compute(string str, int pos, string ans){
    //Base Case
    if (pos==str.length()) vec.push_back(ans);

    else{
    //Recursive Case
    compute(str,pos+1,ans+hash_tbl[str[pos] - '0']);
    if (pos != (str.length()-1)){   
    int tr=0;
    tr = 10*(str[pos] - '0') + (str[pos+1] - '0');
    if (tr<=26) compute(str,pos+2,ans+hash_tbl[tr]);
    }
    }
   
}

int main(){
    string str;
    cin >> str;
    compute(str,0,"");
    cout << "[" ;
    for (int j =0;j<vec.size();j++){
        if (j!=vec.size()-1) cout << vec[j] << ", ";
        else cout << vec[j] << "]";
    } 

    
}

