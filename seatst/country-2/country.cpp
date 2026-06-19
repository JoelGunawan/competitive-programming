#include <bits/stdc++.h>
//#include "country.h"
#define ll long long
#define pb push_back
#define f first
#define s second
using namespace std;
ll count_same_country(int n, vector<int> v) {
	vector<int> a, b, c(n,-1); ll ans = 0;
    cerr << n << endl;
    for (auto x : v) cerr << x << " ";
    cerr << endl;
	for(int i=0;i<n;i++) {
		if(v[i]) {
            int x = c[v[i]+1]+1; a[x]++, c[v[i]+1]++;
            cerr << v[i] + 1 << " " << x + 1 << endl;
			if(x == a.size() || a[x+1] != v[i]-1) b[x]++;
			else b[x] = 0, b[x+1] = -1;
			ans += max(0,b[x]);
			//cout << i << ' ' << x << ' ' << a.size() << ' ' << b[x] << '\n';
		} else {
			a.pb(0), b.pb(0); c[0] = i;
		}
	}
    cerr << "DEB " << ans << endl;
	return ans;
}
ll count_diff_country(int n, vector<int> v) {
	return 0;
}
/*
signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n; vector<int> v(n); for(int i=0;i<n;i++) cin >> v[i];
	cout << count_same_country(n,v);
}
*/