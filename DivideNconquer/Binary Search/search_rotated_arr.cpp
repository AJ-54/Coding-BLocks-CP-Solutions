#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#define ll long long
using namespace std;

int main() {	
    int n,p;
    cin >> n >> p;
    int a[n];
    for (int j=0;j<n;j++) cin >> a[j];
    int s= 0,e=n-1;
    while(s<=e){
        int mid = (s+e)/2;

        if (a[mid]==p) {cout << "Yes at index : " << mid << endl;break;}

        if (a[mid]<p){
            if (a[e] > a[mid] && a[e] >= p) s = mid + 1;
            else e = mid - 1;
        }

        else{
            if (a[s] < a[mid] && a[s] <= p) e = mid - 1;
            else s = mid + 1;
        }
    }
    if (e<s) cout << "NOT FOUND" << endl;
     }
