#include<iostream>
#include<bits/stdc++.h>
#define ull long long int

using namespace std;

int  main(){

    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        ull fans = 0;
        for (int k = 1; k<=n/2; k++){
            int i = 1;
            ull ans = 1;
            for (int j = n; j>= (n-2*k + 1);j--){
                ans = (ans*j)/i;
                i++;
            }
            ans = ((ans*(2*k))*(2*k-1));
            fans += ans/2;
        }
        cout << fans+1 << endl;
       
    }
}