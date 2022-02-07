#include <bits/stdc++.h>
 
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#define ll long long
#define ld long double
#define si short int
#define i8 __int128
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pld pair<ld, ld>
#define psi pair<si, si>
#define pi8 pair<i8, i8>
#define pq priority_queue
#define fi first
#define se second
 
#define sqr(x) ((x)*(x))
#define pow2(x) (1ll << (x))
#define debug(x) cout << #x << " = " << (x) << '\n';
#define debugV(x, a) cout << #x << "[" << (a) << "] = " << (x[a]) << '\n';
 
#define yume using
#define wo namespace
#define kanaeyo std
 
yume wo kanaeyo;
 
const ll ModA = 998244353;
const ll ModC = 1e9 + 7;
const ll INF = 1e18;
const ll iINF = 1e9;
const ld EPS = 1e-9;
const ld iEPS = 1e-6;
 
// solution by albert yr

const ll maxN = 1e6 + 5, maxNr = 1e6;
ll spf[maxN];
 
void precomp() {
	for (ll i = 2; i <= maxNr; i++) {
		if (spf[i] != 0) {continue;}
 
		spf[i] = i;
		for (ll j = i*i; j <= maxNr; j += i) {
			if (spf[j] == 0) {
				spf[j] = i;
			}
		}
	}
}
 
ll modexp(ll x, ll y) {
	if (x == 0) return 0;
	if (y == 0) return 1;
 
	ll t = modexp(x, y >> 1);
	t *= t;
	if (y & 1ll) {
		t *= x;
	}
	return t;
}
 
void solve() {
	ll n;
	cin >> n;
	ll n8 = n;
 
	//debug(n);
 
	if (n == 1) {
		cout << "deficient\n";
		return;
	}
 
	map<ll, ll> primes;
	while (n > 1) {
		primes[spf[n]]++;
		n /= spf[n];
	}
 
	/*
	for (auto i : primes) {
		cout << i.fi << " " << i.se << '\n';
	}
	*/
 
	ll s = 1;
	for (auto i : primes) {
		ll cur = modexp(i.fi, i.se+1) - 1ll;
		ll denom = i.fi - 1ll;
		cur /= denom;
		s *= cur;
	}
 
	s -= n8;
	if (s > n8) {
		cout << "abundant\n";
	} else if (s == n8) {
		cout << "perfect\n";
	} else {
		cout << "deficient\n";
	}
}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
 
	precomp();
 
	/*
	for (ll i = 1; i <= 30; i++) {
		cout << i << " " << spf[i] << '\n';
	}
	*/
 
    int tc;
	cin >> tc;
	while (tc--) {solve();}
}