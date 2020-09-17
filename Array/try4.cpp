#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#define ll long long
using namespace std;

int main() {	
    int n,m;
    cin >> n >> m;
    int arr[n][m];
    for (int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>arr[i][j];
    int ans = 0,uf,jf,kf,lf;
    for (int i=1;i<n-1;i++){
        for (int j=1; j<m-1; j++){
            for (int k=i; k<n-1; k++){
                int l=1;
                if (k==i){
                    if (j-3<1) l=j+3;
                }
                if (k==i+1){
                    if (j-2<1)l=j+2;
                }
                if (k==i+2){
                    if (j-1<1) l=j+1;
                }
                while(l<m-1){
                    // cout << " i " <<i<<" j "<<j<<" k "<<k<<" l "<<l<<endl; 
                    int sum = arr[i-1][j]*arr[k-1][l] + 
                    arr[i+1][j]*arr[k+1][l] + arr[i][j-1]*arr[k][l-1] +
                    arr[i][j]*arr[k][l] + arr[i][j+1]*arr[k][l+1];
                    if (sum>ans){
                         ans = sum;
                         uf=i;lf=l;jf=j;kf=k;
                    }
                    l++;
                    if (l==j-2 && k==i) l=j+3;
                    else if (k==i+1 && l==j-1) l=j+2;
                    else if (k==i+2 && l==j) l=j+1;
                }
                
            }
        }
    }
    cout << ans << endl;
    // cout << " i "<<uf<<" j "<<jf<<" k "<<kf<<" l "<<lf<<endl;
     }
