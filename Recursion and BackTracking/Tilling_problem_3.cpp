#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#define ll long long
#define MOD 1000000007
using namespace std;
// Tilling Problem with matrix exponentiation

int m;
vector<vector<ll>> multiply(vector<vector<ll>> A, vector<vector<ll>> B){
    vector<vector<ll>> c(m+1,vector<ll>(m+1));
    int vsize = m+1;
    for (int i=1;i<vsize;i++){
        for (int k=1;k<vsize;k++){
                c[i][k] = 0;
            for (int j=1;j<vsize;j++){
                c[i][k] =( c[i][k] + ( A[i][j]*B[j][k] ) % MOD ) %MOD;
            }
        }
    }
    return c;
}

vector<vector<ll>> power(vector<vector<ll>> T, int n){
    //Base case
    if (n==1) return T;

    //Recursive  case
    vector<vector<ll>> temp = power(T,n/2);
    temp = multiply(temp,temp);
    if (n&1) return multiply(T,temp);
    return temp;
}

ll compute(int n){
    // Initial Values:
    if (n<m) return 1;
    if (n==m) return 2;


    // create F1 vector
    int F1[m+1];
    for (int j=1;j<=m;j++){
        if (j==m) F1[j] = 2;
        else F1[j] = 1;
    }
    //Create Transformation Matrix
    vector<vector<ll>> T(m+1,vector<ll>(m+1));
    for (int j=1;j<m+1;j++){
        for (int k=1;k<m+1;k++){
            if (j!=m){
                if (k==j+1) T[j][k] = 1;
                else T[j][k] = 0;
            }
            else {
                if (k==1 || k==m) T[j][k] = 1;
                else T[j][k] = 0;
            }
        }
    }
    T = power(T,n-1);

    // Compute the first entry of T*F1;
     ll ans = 0;
    for (int j=1;j<=m;j++){
        ans =(ans + (T[1][j]*F1[j])%MOD )%MOD ;
    }
    return ans;

}
int main(){
    int t,n;
    cin >> t;
    for (int i=0;i<t;i++){
        cin >> n >> m;
        ll ans = compute(n);
        cout << ans << endl;
    }
}