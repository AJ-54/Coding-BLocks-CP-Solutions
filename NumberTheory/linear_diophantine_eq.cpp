#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// This tutorial will solve Ax+By = C. For integral solution to exist, C%gcd(A,B) should be zero.
// Secondly, if we find a sol, then infinite sol. exist.
// The solution is simply k times gcd(A,B). 
int x,y,GCD;
void extended_version(int a, int b){
    // Base Case
    if (b==0){
        x=1,y=0,GCD=a;
        return;
    }
    //Recursive Case
    extended_version(b,a%b);
    int x1 = x, y1 = y;
    x = y1;
    y = x1 - (a/b)*y1;
    
}

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    extended_version(a,b);
    if (c%GCD != 0) cout << "No Solution is possible";
    else{
        int k = c/GCD;
        x = k*x;
        y = k*y;
        //These are your principal values.
        cout << "The first 10 solutions are : " << endl;
        for(int t=0;t<=10;t++){
            cout << a << "*" << x + (b*t)/GCD << " + "<< b <<"*"<< y - (a*t)/GCD  << " =  " << c << endl;;
        }
    }
}