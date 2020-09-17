#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#define ll unsigned long long
#define MOD 1000000009
const ll maxN = 22;
using namespace std;
ll k;
vector<ll> a,initial,c;
map <int,int> mp;


vector<vector<ll>> multiply(vector<vector<ll>> A, vector<vector<ll>> B){
    
    vector<vector<ll>> c(k,vector<ll>(k));
    for(ll i=0;i<k;i++){           
        for(ll x=0;x<k;x++){
            c[i][x]=0;              
            for(ll j=0;j<k;j++){    
                c[i][x]=(c[i][x]+(A[i][j]*B[j][x])%MOD)%MOD;
            }
        }
    }
    return c;
}

vector<vector<ll>> power(vector<vector<ll>> A, ll p){
    
    if (p==1) return A;

   
    if (p&1) return multiply(A,power(A,p-1));
    else{ vector<vector<ll>> B= power(A,p/2);
        return multiply(B,B);}
}
ll compute(ll N, ll M){
    
    if (M<=N) return initial[M-1]; 
   
    vector<ll> F1(k); 
    ll  p = N-1;
    for (int z=k-1;z>=0;z--){
        F1[z]=initial[p];
        p--;
        }
    // for(auto v:F1) cout << v << ' ';cout<<endl;
   
    vector<vector<ll>> T(k,vector<ll>(k));
    for (ll i=0;i<k;i++){
        for (ll j=0;j<k;j++){
            if (i!=k-1){ 
                if (j==i+1) T[i][j]=1;
                else T[i][j]=0;
            }
         
            else T[i][j] = mp[k-j];           
        }
    }
    // for(auto v:T){for(auto m:v){ cout << m << ' ';}cout<<endl;}
    T = power(T,M+k-N-1);

    ll ans = 0;
   
    for (ll m=0;m<k;m++) ans=(ans+ (T[0][m]*F1[m])%MOD)%MOD;
    return ans;
}

int main() {
        ll N,M;
        cin >> N >> M >> k;

        for (int  j=0;j<N;j++){
            ll temp;
            cin >> temp;
            initial.push_back(temp);
        }
        // for(auto v:initial) cout << v << ' ';cout<<endl;
        ll tk=0;
        for (int  j=0;j<k;j++){
            ll temp;
            cin >> temp;
            mp[temp]++;
            if (temp>tk) tk=temp;    
        }
        k=tk;
        // cout << k << endl;
        cout << compute(N,M) << endl;
    return 0;
    }
