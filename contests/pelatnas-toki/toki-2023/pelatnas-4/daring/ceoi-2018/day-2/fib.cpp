#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define fi first
#define ll long long
#define se second
using namespace std;
using namespace __gnu_pbds;
int mod = 1e9 + 7;
int main() {
  int n;
  cin >> n;
	int ar[n + 1];
	for(int i = 1; i <= n; ++i)
			cin >> ar[i];
	priority_queue<int> check;
	gp_hash_table<int, int> a;
	// problem arise -> fib 1 and fib 2
	for(int te = 1; te <= n; ++te) {
		++a[ar[te]];
		check.push(ar[te]);
		check.push(ar[te] + 1);
		check.push(ar[te] - 1);
		while(check.size()) {
			int cur = check.top();
			check.pop();
			if(a[cur] == 0)
					continue;
			if(cur == 1) {
					// cur == 1 -> 
				if(a[cur] > 1)
					++a[cur + 1], a[cur] -= 2, check.push(cur), check.push(cur + 1);
			}
			else if(a[cur + 1]) {
				++a[cur + 2];
				--a[cur + 1];
				--a[cur];
				// lgsg masukkin cur + 2 aja?
				check.push(cur);
				check.push(cur + 1);
				check.push(cur + 2);
			}
			else if(a[cur] > 1) {
				++a[cur + 1];
				++a[max(1, cur - 2)];
				a[cur] -= 2;
				check.push(cur);
				check.push(cur + 1);
				check.push(max(1, cur - 2));
			}
			else if(a[cur - 1]) {
				++a[cur + 1];
				--a[cur];
				--a[cur - 1];
				check.push(cur);
				check.push(cur - 1);
				check.push(cur + 1);
			}
		}
		// kalo udah ada fib, tinggal calculate dia bisa turunkan berapa?
		vector<int> b;
		for(auto i : a) {
			if(i.se == 1)
				b.push_back(i.fi);
		}
		a.clear();
		for(auto i : b)
			a[i] = 1;
		sort(b.begin(), b.end());
		reverse(b.begin(), b.end());
		// b -> jarak min. 2 dan unique
		// state 0 -> bebas
		// state 1 -> harus berubah
		ll dp[b.size() + 1][2];
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for(int i = 0; i < b.size() - 1; ++i) {
			// compare with next, cari klo odd
			ll diff = b[i] - b[i + 1];
			if(diff & 1) {
				// odd diff -> gabisa lanjut
				// dp[i][0] += dp[i - 1][0] * (diff + 1) / 2
				// dp[i][0] += dp[i - 1][1] * (diff - 1) / 2
				//cout << "DEB1 " << dp[i][0] << " " << dp[i][1] << " " << diff << endl;
				dp[i + 1][0] = dp[i][0] * ((diff + 1) / 2) + dp[i][1] * ((diff - 1) / 2);
			}
			else {
				// even diff
				// dp[i][0] += dp[i - 1][0] * (diff) / 2
				// dp[i][0] += dp[i - 1][1] * (diff / 2) - 1 (karena harus berubah minimal 1)
				//cout << "DEB2 " << dp[i][0] << " " << dp[i][1] << " " << diff << endl;
				dp[i + 1][0] = dp[i][0] * ((diff + 1) / 2) + dp[i][1] * ((diff - 1) / 2);
				// dp[i][1] += dp[i - 1][1]
				// dp[i][1] += dp[i - 1][0]
				dp[i + 1][1] = dp[i][1] + dp[i][0];
			}
			dp[i + 1][0] %= mod;
			dp[i + 1][1] %= mod;
			//cout << dp[i + 1][0] << " " << dp[i + 1][1] << endl;
			// compare with next, cari klo even
		}
		//cout << b.back() << endl;
		cout << (((dp[b.size() - 1][0] * ((b.back() + 1) / 2)) % mod) + ((dp[b.size() - 1][1] * ((b.back() - 1) / 2)) % mod)) % mod << endl;
	}
}