#include<iostream>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int n,k;
int s[11];

bool ispossible(int val){
    int ptr = 1;
    int wrk = 0;
    for (int i=0;i<n;i++){
        wrk += s[i];
        if (wrk > val){
            wrk = 0;
            ptr++;
            i--;
        }
        if (ptr > k) return 0;
    }
    return 1;
}

int main(){
    cin >> k;
    cin >> n;
    ll sums = 0,maxs = 0;
    for (int i=0;i<n;i++) cin >> s[i],sums+= s[i],maxs=(maxs<s[i])?s[i]:maxs;
    if (k>=n) cout << maxs << endl;
    else{  
        int start = maxs,end = sums;
        int ans;
        while (start<=end){
            int mid = (start+end)/2;
            if (ispossible(mid)){
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        cout << ans << endl;
    }
    
}