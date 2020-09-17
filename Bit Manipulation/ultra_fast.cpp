#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int main() {	
	string arr1,arr2;
    long int t;
    cin >> t;
    for (long int j=0;j<t;j++){
        cin>>arr1;
        cin>>arr2;
        int arr[arr1.length()]={0};
        for(long int j=0;j<arr1.length();j++)
            if (arr1[j]!=arr2[j]) arr[j]=1;
            
       for (long int j=0;j<arr1.length();j++) cout<<arr[j];
    }
   
    }
