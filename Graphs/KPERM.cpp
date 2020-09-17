#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
typedef tree<int ,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
#define ll long long
#define siz(i) ((i) * ((i) - 1) / 2)
 
const ll INF = 1e18, N = 501;
 
vector<ll> dp[N];
 
inline ll get_sum(int idx, int l, int r){
	l = max(l, 0);
	r = min(r, siz(idx));
	ll sum = 0;
	for(int i = l; i <= r; i++){
		sum += dp[idx][i];
		if(sum >= INF)
			return INF;
	}
	return sum;
}
 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	for(int i = 1; i < N; i++)
		dp[i].resize(siz(i) + 1);
	for(int i = 1; i < N; i++){
		int s = siz(i);
		dp[i][0] = dp[i][s] = 1;
		for(int j = 1; j <= s / 2; j++)
			dp[i][j] = dp[i][s - j] = get_sum(i - 1, j - i + 1, j);
	}
	int t;
	cin >> t;
	while(t--){
		int n, inv;
		ll k;
		cin >> n >> inv >> k;
		if(inv > siz(n) || dp[n][inv] < k){
			cout << -1 << "\n";
			continue;
		}
		ordered_set remain;
		for(int i = 1; i <= n; i++)
			remain.insert(i);
		for(int i = 0; i < n; i++){
			int st = 1, en = n - i, lst = 1;
			while(st <= en && i < n - 1){
				int mid = (st + en)/2;
				if(inv - mid + 1 < 0)
					en = mid - 1;
				else if(dp[n-i-1][inv - (mid-1)]>= k){
					lst = mid, en = mid - 1;
				}
				else st = mid + 1;
			}
			k -= dp[n-i-1][inv - (lst-2)];
			inv -= lst - 1;
			lst = *remain.find_by_order(lst - 1);
			remain.erase(lst);
			cout << lst << ' ';
		}
		cout << "\n";
	}
}  