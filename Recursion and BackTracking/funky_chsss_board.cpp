#include<iostream>
#include<bits/stdc++.h>
#include<string>

using namespace std;

// This code returns all possible squares a knight can travel on modified board taking in account all possible paths.
int board[11][11] = {0};
int visited[11][11] = {0};

bool solve_board(int n, int r, int c){

    // Base case
    

    //Corner Cases
    if (r>n || r<1 || c>n || c<1) return false;

    //Check Blockage
    if (board[r][c] == 0) return false; 

    // Dont Visit if already visited.
    if (visited[r][c]) return true;

    //If above all is satisfied, means you have visited a valid cell
    visited[r][c] = 1;

    //Assume that blocks are free
    bool topl1 = solve_board(n, r-2, c-1);
    bool topl2 = solve_board(n, r-2, c+1);
    bool topr1 = solve_board(n, r-1, c-2);
    bool topr2 = solve_board(n, r-1, c+2);
    bool btml1 = solve_board(n, r+1, c+2);
    bool btml2 = solve_board(n, r+1, c-2);
    bool btmr1 = solve_board(n, r+2, c-1);
    bool btmr2 = solve_board(n, r+2, c+1);

    
}

int main(){
    int n;
    cin >> n;
    for (int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> board[i][j];
        }
    }
    bool solve = solve_board(n,1,1);

    int temp=0;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                // cout << visited[i][j] << ' ';
                if (visited[i][j]==0) temp++;
            }
            // cout << endl;
        }
        // cout << endl;

    cout << temp << endl;
    // else cout << n << endl;
}