#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int n;
int arr[1000001];
int main(){
    cin >> n;
    for (int i=0;i<n;i++) cin >> arr[i];
    int s = 0;
    int e = n-1;
    while (s<=e){
        int mid = (s+e)/2;
        if (arr[mid]>arr[mid+1] && mid <= n-2){
            cout << mid;
            break;
        }
        if (arr[mid]<arr[mid-1] && mid >=1) {
            cout << mid-1;
            break;
        }
        if (arr[mid]>arr[0]){
            s = mid + 1;
        }
        else e = mid - 1;
    }
}