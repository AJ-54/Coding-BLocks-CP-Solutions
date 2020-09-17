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

ll query(ll* tree, ll ss, ll se, ll qs, ll qe, ll index){

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

void buildTree(ll *a , ll s, ll e, ll* tree, ll index){

    //Base Case
    if (s==e){
        tree[index] = a[s];
        return;
    }

    //Rec Case
    ll mid = (s+e)/2;
    buildTree(a,s,mid,tree,2*index);
    buildTree(a,mid+1,e,tree,2*index+1);
    tree[index] = min(tree[2*index],tree[2*index + 1]);
    return;

}

void updateNode(ll* tree, ll ss, ll se, ll i, ll increment, ll index){
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

int lazy[1600005] = {0};
void updateRangeLazy(ll* tree, ll ss, ll se, ll l, ll r, ll inc, ll index){

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
        return;
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

ll queryLazy(ll* tree, ll ss, ll se, ll  qs, ll qe, ll index){

    // First step - resolve the Lazy value
    if(lazy[index]!=0){
        tree[index] += lazy[index];
        if(ss!=se){
            lazy[2*index+1]  += lazy[index];
            lazy[2*index] += lazy[index];
        }
        lazy[index] = 0;
    }
    
    
    //No Overlap 
    if(ss>qe || se<qs){
        return INT_MAX;
    }
    
    // Complete Overlap 
    if(ss>=qs && se<=qe){
        
        return tree[index];
    }
    
    
    //Partial 
    ll mid = (ss+se)/2;
    ll left = queryLazy(tree,ss,mid,qs,qe,2*index);
    ll right = queryLazy(tree,mid+1,se,qs,qe,2*index+1);
    
    return min(left,right); 
}

void updateRange(ll* tree, ll ss, ll se, ll l, ll r, ll increment, ll index){

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

void solve()
{
    ll n;
    cin>>n;
    ll a[n];
    rep(i,0,n) cin >> a[i];
    ll tree[4*n + 1];
    buildTree(a,0,n-1,tree,1);
    ll m;
    cin >> m;
    // cout << m  << endl;
    rep(i,0,m){
        ll l,r,c;
        cin >> l>> r;
        string s;
        getline(cin,s);
        if(s.size()){
            // cout << "hi " << endl;
                c = stoi(s);
                // cout << c << "!!"<<endl;
                if (r<l) {
                    updateRangeLazy(tree,0,n-1,l,n-1,c,1);
                    updateRangeLazy(tree,0,n-1,0,r,c,1);
                }
                else updateRangeLazy(tree,0,n-1,l,r,c,1);
        }
        else{

            if (r<l){
                ll ans = min(queryLazy(tree,0,n-1,l,n-1,1),queryLazy(tree,0,n-1,0,r,1));
                cout << ans << endl;
            }
            else{
                ll ans = queryLazy(tree,0,n-1,l,r,1);
                cout << ans << endl;
            }
        }
    }

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