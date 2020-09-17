#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#define ll long long
using namespace std;

vector<vector<long int>> subsets(int *arr){
    int n = 8;
    // cout<<arr[0]<<endl;
    vector<vector<long int>> subset;
    for (long int j=0;j< (1<<n); j++){
        vector<long int> local;
        for (int k=0; k<n; k++){
            if (j&(1<<k)) local.push_back(arr[k]);
        }
    subset.push_back(local);
    }
    return subset;
}

int main() {	
    int arr[] = {2,3,5,7,11,13,17,19};
    int t;
    cin >> t;
    vector<vector<long int>> vec;
    vec = subsets(arr);
    // cout<<vec.size()<<endl;
    // for(auto v:vec){for(auto k:v){cout<<k<< ' ';}cout<<endl;}
    for (int j=0;j<t;j++){
        unsigned long long int n,ans=0;
        cin >> n;
        // cout << ans << endl;
        for (int k = 0; k<vec.size(); k++){
            {
                int npo=(vec[k].size()&1)?1:0,mul=1;
                // cout << vec[k].size()<<" hi "<< npo << endl;
                for (int m=0;m<vec[k].size();m++){
                    // cout << vec[k][m] <<' '<<mul<< endl;
                    mul*=vec[k][m];
                }
                if (npo) ans+=n/mul;
                else if(mul!=1) ans-=n/mul;
                // cout<<ans<<endl;
            }
        }
        cout << ans << endl;
    }
   
     }
