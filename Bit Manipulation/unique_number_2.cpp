#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int arr[100000]={0};
int main() {	
	long int n,ans=0,ans1=0,ans2=0;
    cin >> n;
    for(long int j=0;j<n;j++) {
        cin>>arr[j];
        ans^=arr[j];
        }
    ans=ans&~(ans-1);
    for (long int j=0;j<n;j++){
        if (arr[j]&ans) ans1^=arr[j];
        else ans2^=arr[j];
    }
    cout<<ans2<<' '<<ans1<<endl;
    }