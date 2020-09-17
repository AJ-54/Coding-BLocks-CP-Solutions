#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#define ll long long
using namespace std;

int main() {	
   int n,sum=0,dsum=0,sqroot,num;
   cin >> n;
   num = n;
   while(num>1){
    //    cout << num << endl;
       for(int j =2; j < num+1; j++){
        if ((num%j)==0) {
            if((j%10)==j){
                sum+=j;}
            else {
                int temp = j;
                while (temp>0){
                    sum+= temp%10;
                    temp=temp/10;
                }
            }
            num = num/j;
            break;
            }
       }
   }

   while (n>0){
       dsum += n%10;
       n= n/10;
   }
   if (dsum==sum) cout << 1 << endl;
   else cout << 0 << endl;
     }
