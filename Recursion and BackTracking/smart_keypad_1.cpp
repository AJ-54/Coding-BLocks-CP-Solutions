#include<iostream>
#include<bits/stdc++.h>
#define ll long long

using namespace std;

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

void compute(string num, int r , int n , string str){

    //Base case
    if (r==n) cout << str << endl;

    //Recursive Case
    else {
        for (int k=0; k<table[num[r]-'0'].length();k++){
            compute(num,r+1,n,str + table[num[r]-'0'][k]);
        }
    }
    }

int main(){
    string s;
    cin >> s;
    int n = s.length();
    compute(s,0,n,"");
    }
