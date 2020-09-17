#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#define ll long long
using namespace std;

int n,m;
int l[20],r[20];
int compute(int row, bool pos, int k){
    // Base Case
    if (row==k-1){
        if (pos) return l[row];
        else return r[row];
    }

    //Recursive case
    if (pos){
        // Currently at row from left side.
        //Calling the next row from left side then right side:
        int left = 2*l[row] + 1 + compute(row+1,pos,k);
        int right = m+2+compute(row+1,!pos,k);
        return min(left,right);
    }
    else{
        // Currently at row from right side.
        //Calling the next row from left side then right side:
        int left = m+2+compute(row+1,!pos,k);
        int right = 2*r[row] + 1 + compute(row+1,pos,k);
        return min(left,right);
    }
}

int main() {
    int ans=0;	
    cin >> n >> m;
    bool zero = true;
    int t=n;
    for (int j=0;j<n;j++){
        string temp;
        cin >> temp;
        if (zero and temp.find("1") == string::npos){t--; continue;}
        zero = false;
        int min_index=INT_MAX,max_index=-1;
        for (int z=0;z<temp.length();z++){
            if (temp[z] == '1'){
                if (z<min_index) min_index = z;
                if (z>max_index) max_index = z;
            }
        }
        if (max_index==-1) l[j]=r[j]=0;
        else{
        l[n-j-1] = max_index;
        r[n-j-1] = m+1-min_index;
        }
    }
    if (zero) cout << "0" << endl;
    else{
    ans = compute(0,true,t);
    cout << ans << endl;
    }
}
    
