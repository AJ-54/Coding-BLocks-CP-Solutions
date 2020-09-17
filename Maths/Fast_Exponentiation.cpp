#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#define ll long long
using namespace std;

// Fast Exponentiation  method to compute a^b ---------- O(logN) time complexity
// recursive approach
long long int power(long long int a,long long int b){
    // base case
    if (b == 0) return 1;
    // recursive case
    long long int SmallerAnswer = power(a,b/2);
    SmallerAnswer*=SmallerAnswer;
    if (b&1) return a*SmallerAnswer;
    else return SmallerAnswer;
}
int main() {	
    long long int ans,a,b;
    cin >> a >> b;
    ans = power(a,b);
    cout << "The answer of "<<a<<"^"<<b<<" is "<<ans;
     }
