#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;
long int arr[100000]={0};
int main() {	
	long int n,ans1=0;
    cin >> n;
    for(long int j=0;j<n;j++) {
        cin>>arr[j];
        }
    int ans[64]={0};
    for (long int j=0;j<n;j++){
        int temp = arr[j],count=0;
        while (temp>0){
            ans[count]+=(temp&1);
            count++;
            temp/=2;
        }
    }
    int p=1;
    for (int j=0;j<64;j++){
        ans[j]%=3;
        ans1+=ans[j]*p;
        p*=2;
    }
    cout << ans1 << endl;  
    }