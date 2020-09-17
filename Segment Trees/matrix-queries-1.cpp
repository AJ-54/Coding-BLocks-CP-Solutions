#include<bits/stdc++.h>
using namespace std;

int arr[100000][2][2];
int tree[4*100000 + 2][2][2];
int n,q,p;

//References - https://www.quora.com/How-do-I-return-multidimensional-array-using-two-parameters-in-C++

void buildTree(int index,  int ss, int se){

    // Base Case
    if (ss==se){
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                tree[index][i][j] = arr[ss][i][j];
            }
        }
        return;
    }

    //Rec Case
    int mid = (ss+se)/2;
    buildTree(2*index,ss,mid);
    buildTree(2*index+1,mid+1,se);
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            tree[index][i][j] = 0;
            for(int k=0;k<2;k++){
                tree[index][i][j] += (tree[2*index][i][k]*tree[2*index+1][k][j]);
            }
        }
    }
    
    return;
}

void* query(int l, int r, int ss, int se, int index){

    // Case of No Overlap
    if (l > se || r < ss){
        int (*a)[2] = new int[2][2];
         for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                (i==j)?a[i][j] = 1:a[i][j] = 0;
            }
         }
        return a;
    }

    // Case of Complete Overlap
    if (ss>=l  && se<=r){
        int (*a)[2] = new int[2][2];
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                a[i][j] = tree[index][i][j];
            }
        }
        return a;
    }

    //Case Of Partial Overlap
    int mid = (ss+se)/2;
    int(*leftAns)[2] = (int(*)[2])query(l,r,ss,mid,2*index);
    int(*rightAns)[2] = (int(*)[2])query(l,r,mid+1,se,2*index+1);
    int(*myans)[2] = new int[2][2];
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            myans[i][j] = 0;
            for(int k=0;k<2;k++){
                myans[i][j] += (leftAns[i][k]*rightAns[k][j]);
            }
        }
    }   
    // for(int i=0;i<2;i++){
    //     for(int j=0;j<2;j++){
    //         cout << leftAns[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // for(int i=0;i<2;i++){
    //     for(int j=0;j<2;j++){
    //         cout << rightAns[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // for(int i=0;i<2;i++){
    //     for(int j=0;j<2;j++){
    //         cout << myans[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    return myans;

}

int main(){
   
    cin >> p >> n >> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                cin >> arr[i][j][k];
            }
        }
    }
    buildTree(1,0,n-1);

    // for(int i=0;i<2;i++){
    //     for(int j=0;j<2;j++){
    //         cout << tree[5][i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for(int o=0;o<q;o++){
        int l,r;
        cin >> l >> r;
        int(*ans)[2] = (int(*)[2])query(l-1,r-1,0,n-1,1);
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                cout << ans[i][j]%p << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

}