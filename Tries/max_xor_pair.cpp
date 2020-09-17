#include<bits/stdc++.h>
#define M1 1000000007
#define M2 998244353
#define ll long long int
#define N (int)1e5+3
#define test(t) while(t--)
#define PI acos(-1.0)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define mii map<int,int>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repp(i,b,a) for(ll i=b-1;i>=a;i--)
#define clr(ar, val) memset(ar, val, sizeof(ar))
#define F first
#define S second
#define PB push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define V(a) vector<a>
#define M(a,b) map<a,b>
#define endl '\n'
#define all(x) begin(x),end(x)
#define allr(x) rbegin(x),rend(x)
#define pr(a) cout<<a<<endl;
#define pr2(a,b) cout<<a<<" "<<b<<"\n"
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int dx[4] = { 0, -1, 0, 1 };
const int dy[4] = { -1, 0, 1, 0 };
using namespace std;

ll CalculateMex(set<ll> Set){
    ll Mex = 0;
    while(Set.find(Mex)!=Set.end()){
        Mex++;
    }
    return Mex;
}

inline void INP()
{
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);   
	    freopen("output.txt","w",stdout);
	#endif 
}

class TrieNode{
    public:
    TrieNode *left; // Represent 0 bit
    TrieNode *right; // Represent 1 bit

};

void insert(int n, TrieNode *head){
    TrieNode *curr = head;
    // Assuming 32 bit int
    repp(i,32,0){
        int bit = (n>>i)&1;
        if (bit == 0){
            if (curr->left == NULL){
                curr->left = new TrieNode();
            }
            curr = curr->left;
        }
        else{
            if (curr->right == NULL){
                curr->right = new TrieNode();
            }
            curr = curr->right;
        }
    }
}

int findMaxXorPair(TrieNode *head, int *arr, int n, int el){
    int max_xor = INT_MIN;
    TrieNode *curr = head;
    int value = el;
    int curr_xor = 0;
    repp(j,32,0){
        int bit = (value>>j)&1;
        if (bit == 0){
            if (curr->right != NULL){
                curr = curr->right;
                curr_xor += (1<<j);
            }
            else{
                curr = curr->left;
            }
        }
        else{
            if (curr->left != NULL){
                curr = curr->left;
                // xored bit is 1.
                curr_xor += (1<<j);
            }
            else{
                curr = curr->right;
            }
        }
        if (curr_xor > max_xor){
            max_xor = curr_xor;
        }
    }
    return max_xor;
}

void solve()
{
    int n;
    cin>>n;
    int a[n];
    rep(i,0,n) cin >> a[i];
    TrieNode *head = new TrieNode();
    int result = INT_MIN;
    rep(i,0,n){
        insert(a[i],head);
        int x = findMaxXorPair(head,a,n,a[i]);
        result = (result<x?x:result);
    }
    cout <<  result << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    test(t){
        solve();
    }
    return 0;
}