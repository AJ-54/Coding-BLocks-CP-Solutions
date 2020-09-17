#include<iostream>
#include<bits/stdc++.h>
#include<string>

using namespace std;

int ans=0;
void  compute(int n, int r, string str, bool on){

    //Base Case
    if (r==n) ans++;

    else {
    // Obvious requirement
    if (on) compute(n,r+1,str+"0",!on);

    else {
        compute(n,r+1,str+"0",on);
        compute(n,r+1,str+"1",!on);
    }

    }

}

int main(){
    int  t,n;
    cin >> t;
    for (int j=0;j<t;j++){
        cin >> n;
        compute(n,0,"",false);
        cout << ans << endl;
        ans = 0;
    }
}