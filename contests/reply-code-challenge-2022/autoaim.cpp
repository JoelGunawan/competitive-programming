// "I assure you that you guys won't make it to the top 4"
// - Tzaph, 21 December 2021

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

void chmax(ll &a, ll b) {a = max(a, b);}

void solve() {
	ll R, C, N, S, D, H;
	cin >> R >> C >> N >> S >> D >> H;
	vector<pll> enemies(R);
	for (ll id, he, x, y, i = 1; i <= N; i++) {
		cin >> id >> he >> x >> y;
		chmax(enemies[x].fi, he);
	}

	ll num = 0;
	for (ll i = 0; i < R; i++) {
		if (enemies[i].fi > 0) {num++;}
	}
	ll crow = 0, shots = 0;
	while (num) {
		if (enemies[crow].fi > 0) {
			enemies[crow].fi -= D;
			if (enemies[crow].fi <= 0) {num--;}
		} else {
			ll targetRow = 1;
			while (enemies[(crow + targetRow) % N].fi < 0) {
				targetRow++;
			}
			enemies[(crow + targetRow) % N].fi -= max(0ll, D - 1ll * targetRow * H);
			if (enemies[(crow + targetRow) % N].fi <= 0) {num--;}
		}
		
		shots++;
		if ((shots % S) == 0) crow++;
		if (crow == R) crow = 0;
	}

	cout << shots << '\n';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

    int tc;
	cin >> tc;
	for (int i = 1; i <= tc; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
}