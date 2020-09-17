#include<iostream>
#include<cmath>
using namespace std;

//This class makes nodes of Trees
class node{
    public:
        int data;
        node* left;
        node* right;

        //Calling the constructor to create first node!
        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

//This class makes trees!
node* buildRec(){
    //Read the input
    int d;
    cin >> d;
    
    //Base Case
    if (d==-1){
        return NULL;
    }

    //Recursive Case
    node* root = new node(d);
    root-> left = buildRec();
    root -> right = buildRec();
    return root;
}

void printPre(node* root){
    if (root==NULL){
        return;
    }
    cout << root->data << " ";
    printPre(root->left);
    printPre(root->right);
}

void printIn(node* root){
    if (root==NULL){
        return;
    }

    printPre(root->left);
    cout << root->data << " ";
    printPre(root->right);
}

void printPost(node* root){
    if (root==NULL){
        return;
    }

    printPre(root->left);   
    printPre(root->right);
    cout << root->data << " ";
}

int main(){
    node* root = buildRec();
    printPre(root);
    cout << endl;
    printIn(root);
    cout  << endl;
    printPost(root);
}
