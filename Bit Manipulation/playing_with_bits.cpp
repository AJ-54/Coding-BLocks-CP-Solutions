#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;

int main() {	
	long int q;
    cin >> q;
    for (long int j=0;j<q;j++){
        long int a,b;
        cin >> a >> b ;
        long int ans=0;
        for (long int m=a;m<b+1;m++){
            long int t=m;
            while(t>0){
                ans++;
                t=t&(t-1);
            }
        }
        cout<<ans<<endl;
    }
}