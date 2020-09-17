#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;
 
// This is a binary search approach!
int a[100001] = {0};
int b[100001] = {0};
int n,k;
bool ispossible(int val){
        // the first subarray string of length val 
        if (min(a[val-1], b[val-1]) <= k) {
            return true;
        }
        // checking for all possible subarrays of length val.
        for (int i=val;i<n;i++){
            if (min(a[i] - a[i - val], b[i] - b[i - val]) <=k){
                return true;
            }
        }
        return false;
}
 
int main(){
    cin >> n >> k;
    string s;
    cin >>s;
    int acount=0;
    for (int i=0;i<n;i++){
        if (s[i] == 'a'){
            acount++;
        }
        a[i] = acount;
        b[i] = i - acount + 1;
    }
    // a[i] denotes the count of a upto length i.
    // b[i] denotes the count of b upto length i.
 
    int start = 1, end = n;
    int ans = 0;
    while (start<=end){
        int mid = (start+end)/2;
        if (ispossible(mid)){
            ans = mid;
            start = mid + 1;
        }
        else end = mid - 1;
    }
    cout << ans  << endl;
}