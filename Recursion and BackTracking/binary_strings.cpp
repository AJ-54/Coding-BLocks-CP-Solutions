#include<iostream>
#include<bits/stdc++.h>
#include<string>

using namespace std;
unsigned long long int final = 0;
void compute(int n){
    for (int k=0;k<=(n/2+1);k++){
            if (k>(n-k+1)) break;
            else if (k==0) final+=1;
            unsigned long long int ans=1;
            int i=1;
            for(int tk=n-k+1; tk>=(n-2*k+2);tk--){
                ans = (ans*(tk))/i;
                i++;
            }
            // cout << "I am ans for k = " << k << " : " << ans << endl;
            
            final += ans; 
        }
}

int main(){
    int t,n;
    cin >> t;
    for (int j=0;j<t;j++){
        cin >> n;
        compute(n);
        cout << final -1 << endl;
        final = 0;
        
    }
}