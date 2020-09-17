#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int a,b;
int dist;
int mans=2;

bool ispossible(int val){
    int c = 2*val - dist*dist - dist;
    for (int i=0;i<=dist;i++){
        if (2*(i*i) - 2*dist*i <= c) return 1;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int c,d;
    cin >> c >> d;
    a = min(c,d), b=max(c,d);
    dist = b-a;
    int s=1;
    int e=dist*(dist+1)/2;
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
