#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int ranks[54];
int prata=0;
int cooks=0;

bool ispossible(int val){
    int p = prata;
    for (int i=0;i<cooks;i++){
        int c = (2*val)/ranks[i];
        int n = 1;
        while (n*(n+1) <= c){
            n++;
            p--;
        }
        if (p<=0) return 1;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> prata >> cooks;
        for (int i=0;i<cooks;i++)  cin >> ranks[i];
        sort(ranks,ranks+cooks);
        int s=0;
        int e=ranks[0]*prata*(prata+1)/2;
        int ans=0;
        while(s<=e){
            int mid = (s+e)/2;
            if (ispossible(mid)){
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        cout << ans << endl;
    }
}
