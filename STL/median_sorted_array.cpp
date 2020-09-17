#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {	
	int n,j;
	cin >> n;
    int arr1[2*n];
    for (j=0;j<2*n;j++) cin>>arr1[j];
    sort(arr1,arr1+2*n);
    cout << arr1[n-1] << endl;
	return 0;
}