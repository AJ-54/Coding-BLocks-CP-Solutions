#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// This is an extended euclid algorithm which computes the solution to the equations
// of the form Ax + By = GCD(A,B) !!

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
    int a,b;
    cin >> a >> b;
    extended_version(a,b);
    cout << a << "*" << x << " + "<< b <<"*"<<y << " =  " << GCD;
}