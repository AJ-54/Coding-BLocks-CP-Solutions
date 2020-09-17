#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;
bool compare(string a, string b){
    // cout<<a<<" and " <<b<<" "<<endl;
    if (a.find(b) != string::npos) {
        return a.length()>b.length();
        }
	return a<b;
}
int main() {	
	int n,j;
	cin >> n;
    string arr[n];
	for (j=0;j<n;j++) cin>>arr[j] ; 
	sort(arr, arr+n, compare);
	for (int j=0;j<n;j++) cout<< arr[j] << endl ; 
	return 0;
}