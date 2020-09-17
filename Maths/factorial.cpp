#include <bits/stdc++.h>
#define inf 1000000000
#define ll long long int
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int ans = inf;
        int mp = 1;
        for(int i=2; i*i<=k; i++){ //prime factors less than sqrt(k)
            if(k % i == 0){ // a prime factor is i.    
                mp = 0; // number of occurences of i in k.
                while(k % i == 0){
                    mp++;
                    k /= i;
                    }
                int tmp = 0;
                ll p = i;
                while(p <= n){
                    tmp += n / p;
                    p*=i;
                    }
                ans = min(ans, tmp / mp);
            }
        }
        if(k > 1){ // prime factor greater than sqrt(k)
            int tmp = 0;
            ll p = k;
            while(p <= n){
                tmp += n / p;
                p *= k;
                }
            ans = min(ans, tmp);
        }
        if(ans == inf) ans = 0;
        cout << ans << endl;
}
return 0;
}