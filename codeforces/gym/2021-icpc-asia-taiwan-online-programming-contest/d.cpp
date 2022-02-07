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

const ll maxN = 305;
ll n;
ld drunk[maxN], f[maxN];
 
void solve() {
	cin >> n;
	cout << fixed << setprecision(12);
 
	ld ans = (long double)(1.0 * n / (2 * n - 2));
 
	cout << ans << '\n';
}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    int tc;
	//cin >> tc;
	tc = 1;
	while (tc--) {solve();}
}