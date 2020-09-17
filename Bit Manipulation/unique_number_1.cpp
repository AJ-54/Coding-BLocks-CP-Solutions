#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;

int main() {	
	long int n,ans,temp;
    cin >> n;
    for(long int j=0;j<n;j++) {
        cin>>temp;
        if (j==0)
            ans=temp;
        else ans^=temp;
        }
    cout<<ans<<endl;
    }