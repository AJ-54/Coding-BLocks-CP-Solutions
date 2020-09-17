#include<bits/stdc++.h>
using namespace std;

int query(int* tree, int ss, int se, int qs, int qe, int index){

    //Case of Complete overlap
    if (ss>=qs && se<= qe){
        return tree[index];
    }
    // NO Overlap
    if (qe<ss || qs>se) return INT_MAX;

    //Partial Overlap - Call both sides and update current answer
    int mid = (ss+se)/2;
    int leftAns = query(tree,ss,mid,qs,qe,2*index);
    int rightAns = query(tree,mid+1,se,qs,qe,2*index + 1);
    return min(leftAns,rightAns);
}

void buildTree(int *a , int s, int e, int* tree, int index){

    //Base Case
    if (s==e){
        tree[index] = a[s];
        return;
    }

    //Rec Case
    int mid = (s+e)/2;
    buildTree(a,s,mid,tree,2*index);
    buildTree(a,mid+1,e,tree,2*index+1);
    tree[index] = min(tree[2*index],tree[2*index + 1]);
    return;

}

void updateNode(int* tree, int ss, int se, int i, int increment, int index){
    // i denotes which index in array to update and increment denotes its increase!

    // Out of bounds - NO Overlap
    if (i>se || i < ss) {
        return;
    }

    //Leaf Node
    if (ss==se){
        tree[index] += increment;
        return;
    }

    //Left and Right Call
    int mid = (ss+se)/2;
    updateNode(tree,ss,mid,i,increment,2*index);
    updateNode(tree,mid+1,se,i,increment,2*index+1);
    tree[index] = min(tree[2*index],tree[2*index+1]);
    return;

    
}

int lazy[10000] = {0};
void updateRangeLazy(int* tree, int ss, int se, int l, int r, int inc, int index){

    //First Step - Never go down if you have lazy value at node, first resolve it.
    if (lazy[index] != 0){

        tree[index] += lazy[index];

        //if not a leaf node - pass lazy to children
        if (ss!=se){
            lazy[2*index] += lazy[index];
            lazy[2*index+1] += lazy[index];
        }

        lazy[index] = 0;
    }

    // Out Of Bounds - No Overlap
    if  (ss>r || l > se) {
        return
    }

    //Complete Overlap
    if (ss>=l && se <= r){
        tree[index] += inc;
        //pass lazy value to children
        if (ss!=se){
            lazy[2*index] += inc;
            lazy[2*index+1] += inc;
        }
        return;
    }

    //Partial Overlap - Call on left and right
    int mid = (ss+se)/2;
    updateRangeLazy(tree,ss,mid,l,r,inc,2*index);
    updateRangeLazy(tree,mid+1,se,l,r,inc,2*index+1);
    tree[index] = min(tree[2*index],tree[2*index+1]);
    return;
}

int queryLazy(int* tree, int ss, int se, int  qs, int qe, int index){

    //First Step is to resolve value
    if (lazy[index] != 0){
        tree[index] += lazy[index];

        if (ss!=se){
            lazy[2*index] += lazy[index];
            lazy[2*index+1] += lazy[index];
        }

        lazy[index] = 0;
    }

    //No Overlap
    if (ss>qe || se < qs) {
         return INT_MAX;
    }

    //Complete Overlap
    if (ss>=qe && se <= qs){
        return tree[index]; // Cos lazy is already resolved!
    }

    //Partial Overlap
    int mid = (ss+se)/2;
    int leftAns = queryLazy(tree,ss,mid,qs,qe,2*index);
    int rightAns = queryLazy(tree,mid+1,se,qs,qe,2*index+1);
    return min(leftAns,rightAns);   
}

void updateRange(int* tree, int ss, int se, int l, int r, int increment, int index){

    // Out of BOunds - No Overlap 
    if (r < ss || se < l){
        return;
    }

    // Complete Overlap in Leaf Node
    if (ss==se){
        tree[index] += increment;
    }

    //Partial Overlap - Call Left and Right
    int mid = (ss+se)/2;
    updateRange(tree,ss,mid,l,r,increment,2*index);
    updateRange(tree,mid+1,se,l,r,increment,2*index+1);
    tree[index] = min(tree[2*index],tree[2*index+1]);
    return;
}

int main(){
    int a[] = {1,3,2,-5,6,4};
    int n = sizeof(a)/sizeof(int);
    
    int* tree = new int[4*n + 1];

    buildTree(a,0,n-1,tree,1);

    //Lets print the tree!
    for(int i=1;i<=13;i++) cout << tree[i] << " ";
    cout << endl;

    int l,r;
    cin >> l >> r;
    cout << query(tree,0,n-1,l,r,1) << endl;

    int i,inc;
    cin >> i >> inc;
    updateNode(tree,0,n-1,i,inc,1);

    int q=2;
    while(q--){
        int l,r;
        cin >> l >> r;
        cout << query(tree,0,n-1,l,r,1) << endl;
    }
    return 0;

}