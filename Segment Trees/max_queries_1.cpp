#include<bits/stdc++.h>
using namespace std;

void buildTree(vector<int>* tree, int index, int* arr, int s, int e){

    //Base Case - when I reach a leaf node in my tree
    if (s==e){
        tree[index].push_back(arr[s]);
        return;
    }

    //Recursive Calls
    int mid = (s+e)/2;
    buildTree(tree,2*index,arr,s,mid);
    buildTree(tree,2*index+1,arr,mid+1,e);
    tree[index].resize(tree[2*index].size()+tree[2*index+1].size());
    merge(tree[2*index].begin(),tree[2*index].end(),
            tree[2*index+1].begin(),tree[2*index+1].end(),tree[index].begin());
    return;
}

int Query(vector<int>* tree, int index, int as, int ae, int qs, int  qe, int threshold){

    //NO Overlap 
    if (qs > ae || qe < as){
        return 0;
    }

    //Complete Overlap 
    if (as >= qs  && ae <= qe){
        auto it = lower_bound(tree[index].begin(),tree[index].end(),threshold);
        return (tree[index].end() - it);
    }

    //In Other cases call left and right sides
    int mid = (as+ae)/2;
    int leftAns = Query(tree,2*index,as,mid,qs,qe,threshold);
    int rightAns = Query(tree,2*index + 1, mid + 1, ae, qs, qe, threshold);
    return leftAns + rightAns;

}


int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    vector<int> tree[4*n+1];
    buildTree(tree,1,arr,0,n-1);

    int q;
    cin >> q;
    while(q--){
        int l,r,k;
        cin >> l >> r >> k;
        int ans = Query(tree,1,0,n-1,l-1,r-1,k);
        cout << ans << endl;
    }
    return 0;
}