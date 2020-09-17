#include<bits/stdc++.h>
using namespace std;


// https://www.geeksforgeeks.org/how-to-implement-text-auto-complete-feature-using-ternary-search-tree/
class TST{

    private:
    TST *left, *right, *equal;
    char data;
    bool endofword;

    public:
    TST(char val, bool isend){
        left = NULL;
        right = NULL;
        equal = NULL;
        data = val;
        endofword = isend;
    }

    void insert(TST **root, string word, int pos = 0){   
        if (pos == word.size()) return;
        if (root == NULL){
            TST *node = TST(word[pos],pos == word.size()-1);
            root = node;
            insert(root,word,pos+1);
        }
        if (root->data > word[pos]){
            insert(root->left,word,pos);
        }
        else if (root->data == word[pos]){
            if (pos == word.size()-1){
                root->endofword = 1;
                return;
            }
            insert(root->equal,word,pos+1);
        }
        else{
            insert(root->right,word,pos);
        }
    }

    void autocomplete(TST *root, string patt){

        TST *curr = root;
        for(char i:patt){
                
        }
    }
};

int main(){


    int n;
    cin >> n;
    string *arr = new string[n];
    for(int i=0;i<n;i++) cin >> arr[i];

    //TST ->

    return 0;
}