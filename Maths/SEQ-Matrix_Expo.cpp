#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#define ll long long
#define MOD 1000000000
using namespace std;
ll k;
vector<ll> a,b,c;
//  Matrix Exponentiation ..... SPOJ problem - SEQ

vector<vector<ll>> multiply(vector<vector<ll>> A, vector<vector<ll>> B){
    // The formula for computing F[n] = T^(n-1)*F1
    // we are using multiply function always only to create T^(n-1) as aakhri final multiplication hum yaha 
    // kar hi nai rahe, vo core compute function m hi krre h. So size is chill.
    vector<vector<ll>> c(k,vector<ll>(k));
    for(ll i=0;i<k;i++){            // The i controls the rows of A matrix
        for(ll x=0;x<k;x++){
            c[i][x]=0;              // The x controls the columns of B matrix
            for(ll j=0;j<k;j++){    // For fixed i and x, j varies to multiply values of one fixed row of A with 
                                    // one fixed column of B.
                c[i][x]=(c[i][x]+(A[i][j]*B[j][x])%MOD)%MOD;
            }
        }
    }
    return c;
}

vector<vector<ll>> power(vector<vector<ll>> A, ll p){
    //base case 
    if (p==1) return A;

    //recursive case
    if (p&1) return multiply(A,power(A,p-1));
    else{ vector<vector<ll>> B= power(A,p/2);
        return multiply(B,B);}
}
ll compute(ll n){
    // base case
    if (n<=k) return b[n-1]; // The answer is in  F1 vector itself

    //Step 2 - Determine F1 vector
    vector<ll> F1(k); // size of k because my indexing will start from 0
    F1 = b;

    //Step 3 - Create Transformation matrix
    vector<vector<ll>> T(k,vector<ll>(k));
    for (ll i=0;i<k;i++){
        for (ll j=0;j<k;j++){
            if (i!=k-1){ // T matrix has all elements zero except one ahead of digonal
                if (j==i+1) T[i][j]=1;
                else T[i][j]=0;
            }
            // Last row of T matrix will have coefficients of function in reverse order
            else T[i][j] = c[k-j-1];           
        }
    }

    //Step 4 - Use matrix exponentiation to compute T^(n-1)
    T = power(T,n-1);
    ll ans = 0;
    //Step 5 - use F[n] = T*F1 ki first entry
    for (ll m=0;m<k;m++) ans=(ans+ (T[0][m]*F1[m])%MOD)%MOD;
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--){
        cin >> k;

        for (int  j=0;j<k;j++){
            ll temp;
            cin >> temp;
            b.push_back(temp);
        }
        for (int  j=0;j<k;j++){
            ll temp;
            cin >> temp;
            c.push_back(temp);
        }

        ll  n;
        cin >> n;
        cout << compute(n) << endl;
        b.clear();
        c.clear();
    }
    return 0;
    }
