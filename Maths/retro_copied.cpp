#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1000000009;
const ll maxN = 22;

ll sz, sz1, T[maxN][maxN], b[maxN], c[maxN], F[maxN]; 

void mult(ll A[maxN][maxN], ll B[maxN][maxN]) {
	ll i, j, k;
	ll C[maxN][maxN] = {};
	for(i = 0; i < sz; i++) {
		for(j = 0; j < sz; j++) {
			for(k = 0; k < sz; k++) {
				C[i][j] = (C[i][j] + ((A[i][k] * B[k][j]) % mod)) % mod;
 			}
		}
	}
	for(i = 0; i < sz; i++) {
		for(j = 0; j < sz; j++) {
			A[i][j] = C[i][j];
		}
	}
}

void pow(ll n) {
	ll ans[maxN][maxN], A[maxN][maxN], i, j, k;
	for(i = 0; i < sz; i++) {
		for(j = 0; j < sz; j++) {
			A[i][j] = T[i][j];
			ans[i][j] = 0;
		}
		ans[i][i] = 1;
	}
	while(n) {
		if(n % 2) {
			mult(ans, A);
		}
		mult(A, A);
		n /= 2;
	}
	for(i = 0; i < sz; i++) {
		for(j = 0; j < sz; j++) {
			T[i][j] = ans[i][j];
		}
	}
}

ll solve(ll n) {
	ll i, j, k;
	if(n <= sz1) {
		return b[n - 1];
	}
	j = sz1 - 1; 
	for(i = sz - 1; i >= 0; i--) {
		F[i] = b[j];
		j--;
	}
	j = sz - 1;
	for(i = 0; i < sz; i++) {
		T[sz - 1][i] = c[j];
		j--;
	}
	for(i = 0; i < sz - 1; i++) {
		T[i][i + 1] = 1; 
	}
	pow(n - sz1);
	ll ans = 0;
	for(i = 0; i < sz; i++) {
		ans = (ans + ((T[sz - 1][i] * F[i]) % mod)) % mod;
	}
	return ans;
}

int main() {
	ll n, m, no, i, j, k;
	scanf("%lld %lld %lld", &n, &m, &no);
	sz1 = n;
	for(i = 0; i < n; i++) {
		scanf("%lld", &b[i]);
	}
	ll maxi = 0;
	for(i = 0; i < no; i++) {
		ll a;
		scanf("%lld", &a);
		maxi = max(maxi, a);
		a--;
		c[a]++;
	}
	sz = maxi;
	printf("%lld\n", solve(m));
	return 0;
}

