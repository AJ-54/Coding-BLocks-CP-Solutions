#include<iostream>
#include<bits/stdc++.h>
#include<string>

using namespace std;

// This is the original code - which asks for longest possible path in the modified chess board.
int board[11][11] = {0};
int visited[11][11] = {0};
int ans=INT_MAX;
bool solve_board(int n, int r, int c){

    //Corner Cases
    if (r>n || r<1 || c>n || c<1) return false;

    //Check Blockage
    if (board[r][c] == 0) return false; 

    //If visited
    if(visited[r][c]) return false;

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

   
    if (topl1 || topl2 || topr1 || topr2 || btml1 || btml2 || btmr1 || btmr2) {visited[r][c] = 0;return true;}
    else {
        // Coming to this block indicates that now the knight is in a position from where each potential move
        // is a dead end. SO we conclude that a path is complete. Now we need to count the cells left out and 
        // backtrack the path by clearing our visit.
        int temp=0;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (visited[i][j]==0 && board[i][j]) temp++;
            }
        }
        if (temp<ans) ans = temp;
        // This is a backtracking step
        visited[r][c] = 0;
        return true;
    }

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

    
        // cout << endl;
    cout << ans << endl;
    // else cout << n << endl;
}