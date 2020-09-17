#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right= NULL;
    }
};

// For building BST

node* insertInBST(node*root,int data){
    if(root==NULL){
        node* n = new node(data);
        root = n;
        return root;
        // return new node(data);
    }

    if(data>root->data){
        root->right = insertInBST(root->right,data);
    }else{
        root->left = insertInBST(root->left,data);
    }

    return root;
}

node* construct(){
    node* root = NULL;

    int data;
    cin>>data;

    while(data!=-1){
        root = insertInBST(root,data);
        cin>>data;
    }

    return root;
}

// For building Binary Tree

node* buildTree(node* root){
    int data;
    cin>>data;

    if(data ==-1){
        return NULL;
    }

    if(root==NULL){
        node* n = new node(data);
        root=n;
    }

    root->left = buildTree(root->left);
    root->right = buildTree(root->right);

    return root;
}

void traverseInorder(node* root,int &k,int &ans){
    if(root==NULL){
        return;
    }

    traverseInorder(root->left,k,ans);

    k--;
    if(k==0){
        ans = root->data;
    }

    traverseInorder(root->right,k,ans);
}

int kthSmallest(node* root, int k) {
    int ans = 0;

    traverseInorder(root,k,ans);
    return ans;
}

void preorder(node*root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";

    preorder(root->left);
    preorder(root->right);
}

void inorder(node*root){
    if(root==NULL){
        return;
    }

    inorder(root->left);

    cout<<root->data<<" ";

    inorder(root->right);
}

int maxPath = INT_MIN;

int maxPathNodes(node*root){
    if(root==NULL){
        return 0;
    }

    int leftMax = max(0,maxPathNodes(root->left));
    int rightMax = max(0,maxPathNodes(root->right));

    maxPath = max(maxPath,leftMax + rightMax + root->data);

    return max(leftMax,rightMax) + root->data;
}

class TreeDetail{
public:
    int size;
    bool bst;
    int min;
    int max;

    TreeDetail(){
        size = 0;
        bst = true;
        min = INT_MAX;
        max = INT_MIN;
    }
};

TreeDetail largestBSTinBinaryTree(node*root){
    TreeDetail val;

    if(root==NULL){
        return val;
    }

    TreeDetail leftDetail = largestBSTinBinaryTree(root->left);
    TreeDetail rightDetail = largestBSTinBinaryTree(root->right);

    if(leftDetail.bst == false or rightDetail.bst==false or root->data < leftDetail.max or root->data > rightDetail.min){
        val.bst = false;
        val.size = max(leftDetail.size,rightDetail.size);
        return val;
    }

    val.bst = true;
    val.size = leftDetail.size + rightDetail.size + 1;

    val.min = root->left!=NULL ? leftDetail.min : root->data;

    val.max = root->right!=NULL ? rightDetail.max : root->data;

    return val;
}

void serialize(node* root){
    if(root==NULL){
        cout<<(-1)<<" ";
        return;
    }

    cout<<root->data<<" ";
    serialize(root->left);
    serialize(root->right);
}

int main(){

    node* root = construct();
    inorder(root);
    cout<<endl;

//    cout<<kthSmallest(root,3)<<endl;

    // node* root = NULL;
    // root = buildTree(root);

    // serialize(root);

//    maxPathNodes(root);
//    cout<<maxPath<<endl;
//
//    // node* root = construct();
//
//    TreeDetail val = largestBSTinBinaryTree(root);
//
//    cout<<val.size<<endl;

    return 0;
}


// Input for largest bst in a bt
// 8 4 2 1 -1 -1 3 -1 -1 6 5 -1 -1 7 -1 -1 9 7 -1 -1 10 -1 -1
//       8
//     /  \
//    4     3
//   /\   /
//  2  6  9
// /\  /\ /\
//1 3 5 7 7 10

// Input for kth Smallest element in a BST
// 4 2 1 3 6 5 7 -1

// Input for max sum path binary tree
// 8 6 2 3 -1 -1 -1 6 -11 -1 -1 -7 -1 -1 10 -1 -12 -1 11 -1 -1

// Input for serialization
// 1 2 3 -1 -1 4 -1 -1 5 -1 6 -1 -1