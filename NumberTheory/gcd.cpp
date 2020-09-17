#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Euclid Algorithm to solve for GCD and LCM.
int mygcd(int a, int b){
    //BAse case
    if (b==0) return a;

    return mygcd(b,a%b);
}

int main(){
    int a,b;
    cin >> a >> b;
    int gans = mygcd(a,b);
    int lcm = a*b / gans;
    cout <<  gans << " " << lcm << endl;

}