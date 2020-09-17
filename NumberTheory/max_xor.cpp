#include<iostream>
#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

ll arr[1000001];

int main(){
    int n;
    cin >> n;
    ll xor_sum = 0;
    for (int i=0;i<n;i++) cin >> arr[i],xor_sum ^= arr[i];
    for (int i=0;i<n;i++) xor_sum = max(xor_sum,xor_sum^arr[i]);
    cout << xor_sum << endl;

}