#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#define ll long long
using namespace std;

int main() {	
    int n,p;
    cin >> n >> p;
    int a[n];
    int max = -1,psum = 0;
    for (int j=0;j<n;j++) {
        cin >> a[j];
        psum += a[j];
        if (a[j]>max) max = a[j];
    }

    int s=max,e=psum;
    int ans = psum;
    while(s<=e){

        int mid = (s+e)/2;
        int stud = 1,slen=0;
        // Check if mid can be a potential ans!
        bool isans=true;

        for (int j=0;j<n;j++){
            slen += a[j];
            if (slen >mid){
                stud += 1;
                slen = 0;
                j-=1;
            }
            if (stud > p){
                isans = !isans;
                break;
            }
        }

        if (isans){
            ans = mid;
            e = mid-1;
        }
        else{
            s = mid + 1;
        }        
     }
     cout << ans << endl;
}
