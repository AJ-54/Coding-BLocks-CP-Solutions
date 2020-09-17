    #include<iostream>
    #include<bits/stdc++.h>
    #define ll long long int
    using namespace std;

    int n,c;
    int s[100001];

    bool ispossible(int val){
        int t = 1,dis=0;
        for (int i=1;i<n;i++){
            dis+=(s[i] - s[i-1]);
            if (dis >= val){
                dis=0,t++;
            }
            if (t==c) return 1;
        }
        return 0;
    }

    int main(){
        int t;
        cin >> t;
        while (t--){
        cin >> n >> c;
        for (int i=0;i<n;i++) cin>>s[i];
        sort(s,s+n);
        ll start = 1, end = s[n-1] - s[0];
        ll ans;
        while (start<=end){
            ll mid = (start+end)/2;
            if (ispossible(mid)){
                ans = mid;
                start = mid + 1;
            }
            else end = mid  - 1;
        }
        cout << ans << endl;
        }
    }