#include<iostream>
using namespace std;
long long int power(long long int a, long long int b){
    if (b==0) return 1;
    long long int ans = power(a,b/2);
    ans*=ans;
    if (b&1) return ans*=a;
    else return ans;
}
int main() {
    long long int a,b;
    cin >>a >>b;
    long long int pow = power(a,b);
    cout << pow <<  endl;
	return 0;
}