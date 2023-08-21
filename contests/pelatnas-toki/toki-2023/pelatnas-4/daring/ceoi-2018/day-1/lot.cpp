#include <bits/stdc++.h>
#define ll long long
using namespace std;
int mod = 1723342759;
int key = 1474064957;
ll mul(ll a, ll b) {
	return (a * b) % mod;
}
int main() {
	// sub 1 -> brute force
	// sub 2 -> ?
	// sub 3 -> hashing
	// sub 4 -> ?
	// sub 5 -> ?
	int n, l;
	cin >> n >> l;
	int a[n + 1];
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	int q;
	cin >> q;
	int query[q + 1];
	for(int i = 1; i <= q; ++i)
		cin >> query[i];
	// for subtask 1, just compute for each l, r pair in O(N)
	if(n <= 300) {
		int diff[n + 1][n + 1];
		memset(diff, -1, sizeof(diff));
		for(int i = 1; i <= n; ++i) {
			for(int r = i + 1; r + l - 1 <= n; ++r) {
				diff[i][r] = 0;
				for(int k = 0; k < l; ++k) {
					if(a[i + k] != a[r + k])
						++diff[i][r];
				}
				//cout << i << " " << r << " " << diff[i][r] << endl;
			}
		}
		for(int i = 1; i <= q; ++i) {
			int res[n + 1];
			memset(res, 0, sizeof(res));
			for(int j = 1; j <= n; ++j) {
				for(int k = j + 1; k <= n; ++k) {
					//cout << diff[j][k] << endl;
					if(diff[j][k] != -1 && diff[j][k] <= query[i])
						++res[j], ++res[k];
				}
			}
			for(int j = 1; j <= n - l + 1; ++j)
				cout << res[j] << " ";
			cout << endl;
		}
	}
	else {
		// buat test case query = 0
		// pakai hashing utk cek sama atau tidak in O(1)
		ll hash[n + 1];
		for(int i = 1; i + l - 1 <= n; ++i) {
			hash[i] = 0;
			for(int j = i; j < i + l; ++j) {
				hash[i] = (mul(key, hash[i]) + a[j]) % mod;
			}
			//cout << hash[i] << " ";
		}
		//cout << endl;
		int res[n + 1];
		memset(res, 0, sizeof(res));
		for(int i = 1; i + l - 1 <= n; ++i) {
			for(int j = 1; j < i; ++j) {
				if(hash[i] == hash[j])
					++res[i], ++res[j];
			}
		}
		for(int i = 1; i + l - 1 <= n; ++i)
			cout << res[i] << " ";
		cout << endl;
	}
}