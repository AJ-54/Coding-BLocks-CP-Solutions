#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;
// This was a two pointer approach!!
int maxoccurancewindow(string s,const char c, int k){
    // Creating two pointers - left,right;
    int left = -1,right = -1;
    int ans = INT_MIN, temp = k, lans = INT_MIN;
    for (int i=0;i<s.length();i++){
        if (s[i] != c && temp > 0){
            right++,temp--;
            lans = right-left;
            ans = max(ans,lans);
            continue;
        }
        else if (s[i] == c) {
            right++;
            lans = right-left;
            ans = max(ans,lans);
            continue;
        }

        // when temp becomes zero; shrink the window.
        if (temp == 0){
            int tans;
            while (temp == 0 && left < right - 1){
                left++;
                lans = right - left;
                if (s[left] != c) temp ++; // If the excluded value is the compromised one - increase temp;
            }
        } 
    }
    return ans;
}

int main(){
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = max(maxoccurancewindow(s,'a',k),maxoccurancewindow(s,'b',k));
    cout << ans << endl;
}