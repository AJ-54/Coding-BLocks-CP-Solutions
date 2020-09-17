#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#define ll long long
using namespace std;
int col_arr[10] = {0};
int row_arr[10] = {0};
int diags_arr[16] = {0};
int diagd_arr[16] = {0};

// N-Queens Problem and Implementation
void queen_compute(int arr[8][8], int n, int r){
    if (n+1==r){
        for (int row=1;row<r;row++){
            for (int col=1;col<n+1;col++){
                if (arr[row][col]) cout << 'Q' << '\t';
                else cout << '-' << '\t';
            }
            cout << endl;
        }
        cout << endl;
    }

    for (int col=1;col<n+1;col++){
            if (!col_arr[col] && !diags_arr[r+col] && !diagd_arr[r-col+n]){
                arr[r][col] = 1;
                col_arr[col]=1;
                diags_arr[r+col]=1;
                diagd_arr[r-col+n]=1;
                queen_compute(arr,n,r+1);
                arr[r][col] = 0;
                col_arr[col]=0;
                diags_arr[r+col]=0;
                diagd_arr[r-col+n]=0;
            }
        }
}


int main() {	
    int n;
    cin >> n;
    int arr[8][8]={0};
    if (n==2 || n==3) cout << "Not Possible" << endl;
    else queen_compute(arr,n,1);
}
    
