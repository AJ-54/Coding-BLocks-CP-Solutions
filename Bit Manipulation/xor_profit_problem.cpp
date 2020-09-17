#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int main() {	
	long long int x,y;
    cin >> x >> y;
    long  long int max=0;
    for (long long int j=x;j<y+1;j++)
        for (long long int k=j;k<y+1;k++) if ((j^k) > max) max = j^k;
    cout << max;
    }
    //This is a naive solution. There exist  an efficient solution.
    