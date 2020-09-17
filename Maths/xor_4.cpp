#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#define ll unsigned long long
#define MOD 1000000009
using namespace std;
// using piegon-hole principle
int main() {
        unsigned long long int n;
        cin >> n;
        if (n>= 130) cout<<"Yes"<<endl;
        else{
        unsigned long long int arr[n];
        for (int j=0;j<n;j++) cin >> arr[j];
        for(int j=0;j<n;j++){
            for (int k=j+1;k<n;k++){
                for (int l=k+1;l<n;l++){
                    for (int i=l+1;i<n;i++){
                        if (!(arr[j]^arr[k]^arr[l]^arr[i])){
                            cout << "Yes" << endl;
                            return 0;
                        }
                    }
                }
            }
        }
        cout << "No" << endl;
        return 0;
        }
    }
